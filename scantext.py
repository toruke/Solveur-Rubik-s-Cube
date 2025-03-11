import cv2
import numpy as np

def get_dominant_color(image, k=1):
    data = image.reshape((-1, 3))
    data = np.float32(data)
    criteria = (cv2.TERM_CRITERIA_EPS + cv2.TERM_CRITERIA_MAX_ITER, 10, 1.0)
    _, labels, palette = cv2.kmeans(data, k, None, criteria, 10, cv2.KMEANS_RANDOM_CENTERS)
    dominant = palette[np.argmax(np.bincount(labels.flatten()))]
    return tuple(map(int, dominant))

def capture_rubik_colors():
    cap = cv2.VideoCapture(0)
    if not cap.isOpened():
        print("Error: Could not open camera.")
        return
    
    while True:
        ret, frame = cap.read()
        if not ret:
            print("Error: Could not read frame.")
            break
        
        h, w, _ = frame.shape
        grid_size = 3
        step_x, step_y = w // (grid_size + 1), h // (grid_size + 1)
        colors = []
        
        for i in range(grid_size):
            row_colors = []
            for j in range(grid_size):
                x, y = (j + 1) * step_x, (i + 1) * step_y
                roi = frame[y - 10:y + 10, x - 10:x + 10]
                color = get_dominant_color(roi)
                row_colors.append(color)
                cv2.rectangle(frame, (x - 10, y - 10), (x + 10, y + 10), color, -1)
            colors.append(row_colors)
        
        cv2.imshow("Rubik's Cube Scanner", frame)
        
        key = cv2.waitKey(1) & 0xFF
        if key == ord('c'):
            print("Captured Colors (RGB):", colors)
        elif key == ord('q'):
            break
    
    cap.release()
    cv2.destroyAllWindows()

if __name__ == "__main__":
    capture_rubik_colors()

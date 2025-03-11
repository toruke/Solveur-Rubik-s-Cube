import cv2
import numpy as np

##################################################################
# Simple code: Rubik capture 
##################################################################

# Define known colors in HSV format for comparison
color_ranges = {
    "white": ([0, 0, 180], [180, 50, 255]),
    "yellow": ([20, 100, 100], [30, 255, 255]),
    "red": ([0, 120, 100], [10, 255, 255]),
    "orange": ([10, 100, 100], [20, 255, 255]),
    "green": ([40, 50, 50], [80, 255, 255]),
    "blue": ([90, 50, 50], [130, 255, 255])
}

def classify_color(bgr):
    """Convert BGR to HSV and determine the color."""
    hsv = cv2.cvtColor(np.uint8([[bgr]]), cv2.COLOR_BGR2HSV)[0][0]
    
    for color, (lower, upper) in color_ranges.items():
        if all(lower[i] <= hsv[i] <= upper[i] for i in range(3)):
            return color
    return "unknown"

# Start camera
vid = cv2.VideoCapture(0)

# Create empty lists
rubik = []
core = []

for i in range(6):
    while True:
        # Read camera
        ret, frame = vid.read()
        # Draw rectangle on captured image
        cv2.rectangle(frame, (100,100), (400,400), (0, 255, 0), 2)
        
        # Show images
        cv2.imshow("camera", frame)
        
        # Break by pressing "z" (not "Z")
        if cv2.waitKey(10) == ord('z'):
            # Get color from 9 positions
            positions = [(150, 150), (150, 250), (150, 350), (250, 150), (250, 250), (250, 350), (350, 150), (350, 250), (350, 350)]
            colors = [frame[y, x] for x, y in positions]
            
            # Add color to Rubik list
            rubik.extend(colors)
            
            # Add core color
            core.append(colors[4])
            
            # Close window
            cv2.destroyAllWindows()
            break

# Close window and release camera
cv2.destroyAllWindows()
vid.release()

# Identify colors for each square
classified_rubik = [classify_color(color) for color in rubik]
classified_core = [classify_color(color) for color in core]

# Print identified colors
print("Classified Rubik's cube squares:")
print(classified_rubik)
print("Classified core colors:")
print(classified_core)

# Further processing can be added here to format the cube state for a solving algorithm.

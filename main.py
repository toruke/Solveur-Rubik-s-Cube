##################################################################
# Simple code: Rubik capture 
##################################################################
import cv2
import kociemba
import numpy as np

# NOTE: B G R color

# Start camera
vid = cv2.VideoCapture(0)

# Create empty list
rubik = []
core = []


for i in range(6):
    while True:
        # Read camera
        ret, frame = vid.read()
        # Draw rectangle on captured image
        cv2.rectangle(frame, (100, 100), (400, 400), (0, 255, 0), 2)

        # Show images
        cv2.imshow("camera", frame)

        # Break by pressing "q" (not "Q")
        if cv2.waitKey(10) == ord('q'):
            # Get color from 9 positions
            color1 = frame[150, 150]
            color2 = frame[150, 250]
            color3 = frame[150, 350]
            color4 = frame[250, 150]
            color5 = frame[250, 250]
            color6 = frame[250, 350]
            color7 = frame[350, 150]
            color8 = frame[350, 250]
            color9 = frame[350, 350]

            # Add color to Rubik list
            rubik.append(color1)
            rubik.append(color2)
            rubik.append(color3)
            rubik.append(color4)
            rubik.append(color5)
            rubik.append(color6)
            rubik.append(color7)
            rubik.append(color8)
            rubik.append(color9)

            # Add color to Core list
            core.append(color5)

            # Close window
            cv2.imshow("camera", frame)
            print(f"__ Face {i+1} done __")
            break

# Close window
cv2.destroyAllWindows()
# Release camera
vid.release()

# Color list of 54 squares
#print("Color list of 54 squares:")
#print(rubik)
# Color list of 6 faces
#print("Color list of 6 faces:")
#print(core)


# ------Compare color of each square to decide that is the color of which face-------------
D_color = {
    "White":core[0].tolist(),
    "Red":core[1].tolist(),
    "Green":core[2].tolist(),
    "Yellow":core[3].tolist(),
    "Orange":core[4].tolist(),
    "Blue":core[5].tolist()
}

def compare(color):
    for i in core :
        abs(core[i][0] - color[0]) + abs(core[i][1] - color[1]) + abs(core[i][2] - color[2])


for i in rubik:
    print( compare(i))

"""
up = white
right = red
face = green
down = yellow 
left = orange 
back = blue 
"""
# ------Apply algorithm using data of the Rubik's cube above to get the solving moves--------

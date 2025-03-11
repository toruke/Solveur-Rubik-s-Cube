import time
import serial
import cv2
import kociemba
from collections import Counter


# Start video capture
vid = cv2.VideoCapture(0)
if not vid.isOpened():
    print("Error: Unable to open the camera.")
    exit()

rubik = []
core = []
face_order = ["U", "R", "F", "D", "L", "B"]

# For each face, we capture 9 color values in row-major order:
# The positions list is now defined as (x, y) coordinates:
# Row 1: (150,150), (250,150), (350,150)
# Row 2: (150,250), (250,250), (350,250)
# Row 3: (150,350), (250,350), (350,350)
positions = [(150, 150), (250, 150), (350, 150),
             (150, 250), (250, 250), (350, 250),
             (150, 350), (250, 350), (350, 350)]

# Capture the 6 faces of the Rubik's Cube
for i in range(6):
    while True:
        ret, frame = vid.read()
        if not ret:
            print("Error: Unable to capture the image.")
            break

        # Draw a central square to help align the cube
        cv2.rectangle(frame, (100, 100), (400, 400), (0, 255, 0), 2)
        cv2.imshow("Camera", frame)

        # Press 'q' to capture the face
        key = cv2.waitKey(1) & 0xFF
        if key == ord('q'):
            # Read the colors from the defined positions (row-major order)
            colors = [frame[y, x] for x, y in positions]
            rubik.append(colors)
            core.append(colors[4])  # Center color of the face
            print(f"__ Face {i + 1} ({face_order[i]}) captured __")

            break

vid.release()
cv2.destroyAllWindows()

if len(core) != 6:
    print("Error: The 6 center colors were not properly recorded.")
    exit()

# Define the color mapping: each face's center color is associated with a letter and name.
color_map = {
    "U": ('W', "White"),
    "R": ('R', "Red"),
    "F": ('G', "Green"),
    "D": ('Y', "Yellow"),
    "L": ('O', "Orange"),
    "B": ('B', "Blue")
}

# Associate each center color with its letter and name.
D_color = {face_order[i]: (core[i].tolist(), color_map[face_order[i]]) for i in range(6)}


def compare(color):
    """Return the letter and name corresponding to the center color that is closest to 'color'."""
    min_distance = float("inf")
    best_match = None
    best_name = None
    for face, (center_color, (letter, name)) in D_color.items():
        distance = sum(abs(center_color[i] - color[i]) for i in range(3))
        if distance < min_distance:
            min_distance = distance
            best_match = letter
            best_name = name
    return best_match, best_name


# Generate the rubik_string and a list of color names for each face.
rubik_string = ""
rubik_named_faces = []

# Here, each face is already read in row-major order thanks to our positions list.
for i, face in enumerate(rubik):
    face_colors = []
    for color in face:
        letter, name = compare(color.tolist())
        rubik_string += letter
        face_colors.append(name)
    rubik_named_faces.append(face_colors)

# Verify that each color appears exactly 9 times
color_count = Counter(rubik_string)
if any(count != 9 for count in color_count.values()):
    print("\n❌ Error: Some colors are not present in exactly 9 instances!")
    print("\n🟢 Number of each detected color:")
    for color, count in color_count.items():
        print(f"{color}: {count} times")
    exit()

print("\n✅ Detected colors on each face:")
for i, face in enumerate(rubik_named_faces):
    print(f"Face {i + 1} ({face_order[i]}): {face}")

print("\n✅ Detected Rubik’s Cube (standard notation):")
print(rubik_string)
solution = ""
for i in rubik_string:
    if i == "G":
        solution+="F"
    if i == "W":
        solution+="U"
    if i == "Y":
        solution+="D"
    if i == "R":
        solution+="R"
    if i == "B":
        solution+="B"
    if i == "O":
        solution+="L"
print(solution)
resolution = kociemba.solve(solution)
print(resolution)
# ------------------ SOLVE THE CUBE ------------------ #


# Séquence de mouvements pour le cube de Rubik
moves = resolution

# Ouverture du port série pour communiquer avec l'Arduino
arduino = serial.Serial(port='COM10', baudrate=9600)

# Attente pour s'assurer que la connexion est établie
time.sleep(20) #pour avpir le temps de placer le cube au milieu de pince avant quelles ne se referment

# Envoi du signal de prise du cube
arduino.write(bytes("START", 'utf-8'))

    # Attente pour s'assurer que l'Arduino a bien reçu "START"
time.sleep(2)

    # Envoi des mouvements au microcontrôleur
arduino.write(bytes(moves, 'utf-8'))

    # Attente pour s'assurer que les mouvements sont bien exécutés
time.sleep(2)

    # Envoi du signal de libération du cube
arduino.write(bytes("END", 'utf-8'))

    # Fermeture du port série
arduino.close()

import cv2
import numpy as np

# Définition des plages de couleurs en HSV
color_ranges = {
    "Blanc": ((0, 0, 180), (180, 50, 255)),
    "Jaune": ((20, 100, 100), (40, 255, 255)),
    "Rouge": ((0, 100, 100), (10, 255, 255)),
    "Bleu": ((100, 100, 100), (130, 255, 255)),
    "Vert": ((40, 100, 100), (80, 255, 255)),
    "Orange": ((10, 100, 100), (20, 255, 255)),
}

def detect_color(bgr):
    """Convertit une couleur BGR en HSV et retourne le nom de la couleur détectée"""
    hsv = cv2.cvtColor(np.uint8([[bgr]]), cv2.COLOR_BGR2HSV)[0][0]

    for name, (lower, upper) in color_ranges.items():
        lower = np.array(lower)
        upper = np.array(upper)
        if np.all(lower <= hsv) and np.all(hsv <= upper):
            return name

    return "Inconnu"  # Si aucune couleur ne correspond

# Ouvrir la webcam
vid = cv2.VideoCapture(0)

rubik = []

for i in range(6):
    print(f"Scanne la face {i+1} et appuie sur 'q' pour capturer.")

    while True:
        ret, frame = vid.read()
        if not ret:
            print("Erreur de capture vidéo.")
            break

        # Appliquer un léger flou pour stabiliser les couleurs
        frame = cv2.GaussianBlur(frame, (5, 5), 0)

        # Dessiner un carré central pour la capture
        cv2.rectangle(frame, (100, 100), (400, 400), (0, 255, 0), 2)
        cv2.imshow("Camera", frame)

        # Capture quand on appuie sur 'q'
        if cv2.waitKey(1) & 0xFF == ord('q'):
            colors = [
                frame[150, 150], frame[150, 250], frame[150, 350],
                frame[250, 150], frame[250, 250], frame[250, 350],
                frame[350, 150], frame[350, 250], frame[350, 350]
            ]
            rubik.append(colors)
            break  # Passe à la face suivante

print("Capture terminée !")
vid.release()
cv2.destroyAllWindows()

# Affichage des couleurs détectées
for i, face in enumerate(rubik):
    print(f"Face {i + 1}:")
    for j, color in enumerate(face):
        detected_color = detect_color(color)
        print(f"  Case {j + 1}: {detected_color} - BGR: {color}")

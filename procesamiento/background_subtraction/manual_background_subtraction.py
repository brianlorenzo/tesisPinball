import cv2
import numpy as np
import os
import gdown

def check_and_download_file(file_name, file_url):
    if os.path.isfile(file_name):
        print("El archivo ya existe en la carpeta actual.")
    else:
        print("Descargando el archivo...")
        gdown.download(file_url, file_name)
        print("Descarga completada.")

# Especifica el nombre del archivo y el enlace de Google Drive
nombre_archivo = "media/piso_y_bola.mp4"
enlace_google_drive = "https://drive.google.com/file/d/1J3HI8k-S2PXvz7wv5uAn7syd-sCjXO19/view?usp=drive_link"

# Llama a la función para verificar y descargar el archivo si es necesario
check_and_download_file(nombre_archivo, enlace_google_drive)

# Source del video: https://drive.google.com/file/d/1J3HI8k-S2PXvz7wv5uAn7syd-sCjXO19/view?usp=drive_link

cap = cv2.VideoCapture("piso_y_bola.mp4")
_, first_frame = cap.read()
first_gray = cv2.cvtColor(first_frame, cv2.COLOR_BGR2GRAY)
first_gray = cv2.GaussianBlur(first_gray, (5, 5), 0)

while True:
    _, frame = cap.read()
    gray_frame = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    gray_frame = cv2.GaussianBlur(gray_frame, (5, 5), 0)
    difference = cv2.absdiff(first_gray, gray_frame)
    _, difference = cv2.threshold(difference, 25, 255, cv2.THRESH_BINARY)
    
    cv2.imshow("First frame", first_frame)
    cv2.imshow("Frame", frame)
    cv2.imshow("difference", difference)

    if cv2.waitKey(1) == ord('q'):
        break
cap.release()
cv2.destroyAllWindows()
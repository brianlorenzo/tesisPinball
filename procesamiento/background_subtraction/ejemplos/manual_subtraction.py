import cv2
import numpy as np

img_size = (720,1280,3)

cap = cv2.VideoCapture("./piso_y_bola.mp4")
 _, frame = cap.read()
first_frame = cv2.imread("piso.jpg")
first_frame = cv2.resize(first_frame, (1280,720))
first_gray = cv2.cvtColor(first_frame, cv2.COLOR_BGR2GRAY)
first_gray = cv2.GaussianBlur(first_gray, (3, 3),0)


while True:
    _, frame = cap.read()
   
   # frame = cv2.resize(frame, dsize = (first_frame.shape[1],first_frame.shape[0]), interpolation=cv2.INTER_AREA)

    gray_frame = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    gray_frame = cv2.GaussianBlur(gray_frame, (3, 3), 0)
    diff = cv2.absdiff(first_gray, gray_frame)
    _, diff = cv2.threshold(diff, 60, 255, cv2.THRESH_BINARY)
    
    cv2.imshow("First frame", first_frame)
    cv2.imshow("Frame", frame)
    cv2.imshow("difference", diff)

    if cv2.waitKey(1) == ord('q'):
            break

cap.release()
cv2.destroyAllWindows()

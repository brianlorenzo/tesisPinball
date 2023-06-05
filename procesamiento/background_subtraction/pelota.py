from ctypes import resize, sizeof
from telnetlib import NOP
import cv2 as cv
import numpy as np

def background_sustraction(ref, new_frame):
    gray_frame = cv.cvtColor(new_frame, cv.COLOR_BGR2GRAY)
    gray_frame = cv.GaussianBlur(gray_frame, (5, 5), 0)

    gray_ref = cv.cvtColor(ref, cv.COLOR_BGR2GRAY)
    gray_ref = cv.GaussianBlur(gray_ref, (5, 5), 0)
   
    diff = cv.absdiff(gray_ref, gray_frame)
    _, diff = cv.threshold(diff, 25, 255, cv.THRESH_BINARY)
    
    return diff

def resizeImg(matrix,scale):
    # Reescalado
    # 'scale' : Porcentaje de escalado
    w = int(matrix.shape[1] * scale / 100)
    l = int(matrix.shape[0] * scale / 100)
    dim = (w, l)

    imgResized = cv.resize(matrix, dim, interpolation = cv.INTER_AREA)

    return imgResized

def SubMatrix(
    matrix, 
    rowStartIdx, rowEndIdx,
    colStartIdx, colEndIdx):

    result = [
        x[ colStartIdx : colEndIdx ]
        for x in matrix[ rowStartIdx : rowEndIdx ]
    ]

    return result

# Pelota a 35cm 
# Resolución
l = 4160
w = 1920
fondo = cv.imread("fondo.jpg")
bola1 = cv.imread("bola1.jpg")
bola2 = cv.imread("bola2.jpg")      # Al mover la bola, con mi mano, cambió
bola3 = cv.imread("bola3.jpg")      # el enfoque de la cámara y se nota. 

# Imagen resized
scale = 1
fondoResized = resizeImg(fondo,scale)
bola1Resized = resizeImg(bola1,scale)
#bola2Resized = resizeImg(bola2,scale)
#bola3Resized = resizeImg(bola3,scale)

bola1Detected = background_sustraction(fondoResized,bola1Resized)
#bola2Detected = background_sustraction(fondo,bola2)
#bola3Detected = background_sustraction(fondo,bola3)

print(bola1Detected.shape)
print(bola1Detected)

N,M = bola1Detected.shape # N horizontal M vertical

h_step = int(N / 5)
v_step = int(M / 10)

vx = 0           # Vértice superior izquierdo
vy = 0           # Vértice inferior derecho

for i in range(0,min(h_step,v_step)+1):

    cuadrante = SubMatrix(bola1Detected, vx, vx+h_step, vy,vy+v_step) 
    
    if (  (vx + h_step >= N) or (vy+v_step)):
        break
    else:
            vx = vx + h_step
            vy = vy + v_step
        
print(cuadrante)
print(M,N)
print(h_step,v_step)
cv.imshow("Bola 1 - BS", bola1Detected)
"""
for i in range(vx, vx + h_step):
    for j in range(vy,vy + v_step):

        # Recorro submatriz 

        
        # Reasignación de vértices
        






#cv.imshow("Bola 2 - BS", bola2Detected)
#cv.imshow("Bola 3 - BS", bola3Detected)
"""
while True:
    NOP




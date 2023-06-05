import numpy as np


a = [
        [1,2,3,4,5],
        [6,7,8,9,10],
        [11,12,13,14,15],
        [16,17,18,19,20]
    ]

print("Matriz A: \n\n", a)

def extractSubMatrix(
    matrix, 
    rowStartIdx, rowEndIdx,
    colStartIdx, colEndIdx):

    result = [
        x[ colStartIdx : colEndIdx ]
        for x in matrix[ rowStartIdx : rowEndIdx ]
    ]

    return result

b = extractSubMatrix(a, 0,10,0,3)
print("Matriz B: \n\n", b)
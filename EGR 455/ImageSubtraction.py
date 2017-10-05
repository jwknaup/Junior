import numpy as np
import cv2

cap=cv2.VideoCapture(1)

while(1):
    _,frame=cap.read()

    red=np.matrix(frame[:,:,2])
    green=np.matrix(frame[:,:,1])
    blue=np.matrix(frame[:,:,0])

    redOnly = np.int16(red)-np.int16(green)-np.int16(blue)
    redOnly[redOnly<0]=0
    redOnly[redOnly>255]=255
    redOnly=np.uint8(redOnly)

    columnSums=np.matrix(np.sum(redOnly,0))
    column_numbers=np.matrix(np.arange(640))
    columnMult = np.multiply(columnSums,column_numbers)
    total = np.sum(columnMult)
    totalTotal = np.sum(np.sum(redOnly))
    columnLocation = total/totalTotal

    print(columnLocation)
    
    cv2.imshow('rgb', frame)
    cv2.imshow('red', red)
    cv2.imshow('green', green)
    cv2.imshow('blue', blue)
    cv2.imshow('red only', redOnly)
    
    k=cv2.waitKey(5)
    if k==25:
        break

cv2.destroyAllWindows()

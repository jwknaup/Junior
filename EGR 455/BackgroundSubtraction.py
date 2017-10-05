import numpy as np
import cv2

cap=cv2.VideoCapture(1)

while(1):
    _,frame=cap.read()

    gray1 = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

    cv2.imshow('background', gray1)
 
    k=cv2.waitKey(5)
    if k==27:
        break

while(1):
    _,frame=cap.read()

    gray2 = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

    cv2.imshow('foreground', gray2)

    difference = np.absolute(np.matrix(np.int16(gray1))- np.matrix(np.int16(gray2)))
    difference[difference>255]=255
    difference=np.uint8(difference)

    cv2.imshow('difference', difference)

    bw=difference
    bw[bw<=100]=0
    bw[bw>100]=1

    columnSums=np.matrix(np.sum(bw,0))
    column_numbers=np.matrix(np.arange(640))
    columnMult = np.multiply(columnSums,column_numbers)
    total = np.sum(columnMult)
    totalTotal = np.sum(np.sum(bw))
    columnLocation = total/totalTotal

    rowSums=np.matrix(np.sum(bw,1))
    row_numbers=np.transpose(np.matrix(np.arange(480)))
    rowMult = np.multiply(rowSums,row_numbers)
    total = np.sum(rowMult)
    totalTotal = np.sum(np.sum(bw))
    rowLocation = total/totalTotal

    print(columnLocation, rowLocation)
 
    k=cv2.waitKey(5)
    if k==27:
        break

cv2.destroyAllWindows()


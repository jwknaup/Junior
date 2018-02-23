import numpy as np
import cv2
import time

cap=cv2.VideoCapture(1)

while(1):
    _,frame=cap.read()

    red1=np.matrix(frame[:,:,2])
    green1=np.matrix(frame[:,:,1])
    blue1=np.matrix(frame[:,:,0])

    redOnly1 = 1.0*np.int16(red1)-np.int16(green1)-np.int16(blue1)
    redOnly1[redOnly1<5]=0
    redOnly1[redOnly1>5]=255
    redOnly1=np.uint8(redOnly1)
    
    time.sleep(0.01)
    
    _,frame=cap.read()

    red2=np.matrix(frame[:,:,2])
    green2=np.matrix(frame[:,:,1])
    blue2=np.matrix(frame[:,:,0])

    redOnly2 = np.int16(red2)-np.int16(green2)-np.int16(blue2)
    redOnly2[redOnly2<5]=0
    redOnly2[redOnly2>5]=255
    redOnly2=np.uint8(redOnly2)
    
    motion = redOnly2-redOnly1
    
    motion[motion<0]=0
    motion[motion>255]=255
    motion=np.uint8(motion)

    columnSums=np.matrix(np.sum(motion,0))
    column_numbers=np.matrix(np.arange(640))
    columnMult = np.multiply(columnSums,column_numbers)
    total = np.sum(columnMult)
    totalTotal = np.sum(np.sum(motion))
    columnLocation = total/totalTotal

    print(columnLocation)
    
    cv2.imshow('rgb', frame)
    cv2.imshow('motion', motion)
# =============================================================================
#     cv2.imshow('green', green)
#     cv2.imshow('blue', blue)
#     cv2.imshow('red only', redOnly)
# =============================================================================
    
    k=cv2.waitKey(5)
    if k==27:
        break

cv2.destroyAllWindows()

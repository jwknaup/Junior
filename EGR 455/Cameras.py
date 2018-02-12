import numpy as np
import cv2

cap=cv2.VideoCapture(1)

while(1):
    _,frame=cap.read()

    red=frame[:,:,2]
    green=frame[:,:,1]
    blue=frame[:,:,0]
    
    cv2.imshow('rgb', frame)
    cv2.imshow('red', red)
    cv2.imshow('green', green)
    cv2.imshow('blue', blue)
    
    k=cv2.waitKey(5)
    if k==27:
        break

cv2.destroyAllWindows()

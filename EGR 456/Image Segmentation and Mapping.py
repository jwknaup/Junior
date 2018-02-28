# -*- coding: utf-8 -*-
"""
Created on Thu Feb 08 16:49:18 2018

@author: Jacob
"""

import numpy as np
import cv2

cap=cv2.VideoCapture(0)

while 1:
    _, frame=cap.read()
    
    red=frame[:,:,2]
    green=frame[:,:,1]
    blue=frame[:,:,0]
    
    greenOnly = np.int16(green)-0.25*np.int16(red)-0.75*np.int16(blue)
    greenOnly[greenOnly<25]=0
    greenOnly[greenOnly>25]=255
    greenOnly=np.uint8(greenOnly)

    mask=np.ones((5,5),np.uint8)
    opening=cv2.morphologyEx(greenOnly, cv2.MORPH_OPEN, mask)
    cv2.imshow('masked', opening)

    _,labels=cv2.connectedComponents(opening, 4)
    b=np.matrix(labels)

    obj1=b==0
    obj1=np.uint8(obj1)
    obj1[obj1>0]=255

    obj2=b==1
    obj2=np.uint8(obj2)
    obj2[obj2>0]=255

    obj3=b==2
    obj3=np.uint8(obj3)
    obj3[obj3>0]=255

    obj4=b==3
    obj4=np.uint8(obj4)
    obj4[obj4>0]=255

    cv2.imshow('Obj 1',obj1)
    cv2.imshow('Obj 2',obj2)
    cv2.imshow('Obj 3',obj3)
    cv2.imshow('Obj 4',obj4)

    
    cv2.imshow('Frame',frame)
    cv2.imshow('green', greenOnly)
    
    k=cv2.waitKey(5)
    if k==27:
        break

cv2.destroyAllWindows()

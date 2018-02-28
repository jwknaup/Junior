# -*- coding: utf-8 -*-
"""
Created on Thu Feb 08 16:49:18 2018

@author: Jacob
"""

import numpy as np
import cv2
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

cap=cv2.VideoCapture(0)
fig = plt.figure()
ax = fig.add_subplot(111,projection='3d')

while 1:
    _, frame=cap.read()
    
    red=frame[:,:,2]
    green=frame[:,:,1]
    blue=frame[:,:,0]

    redOnly = np.int16(red)-0.25*np.int16(green)-0.75*np.int16(blue)
    redOnly[redOnly<25]=0
    redOnly[redOnly>=25]=255
    redOnly=np.uint8(redOnly)
    
    greenOnly = np.int16(green)-0.25*np.int16(red)-0.75*np.int16(blue)
    greenOnly[greenOnly<25]=0
    greenOnly[greenOnly>=25]=255
    greenOnly=np.uint8(greenOnly)

    blueOnly = np.int16(blue)-0.25*np.int16(red)-0.75*np.int16(green)
    blueOnly[blueOnly<25]=0
    blueOnly[blueOnly>=25]=255
    blueOnly=np.uint8(blueOnly)

    allOnly = redOnly + greenOnly + blueOnly

    mask=np.ones((5,5),np.uint8)
    opening=cv2.morphologyEx(allOnly, cv2.MORPH_OPEN, mask)
    cv2.imshow('masked', opening)

    _,labels=cv2.connectedComponents(opening, 4)
    b=np.matrix(labels)

    for i in labels:
        obj=b==i
        obj=np.uint8(obj)
        obj[obj>0]=255
        cv2.imshow('object '+str(i),obj)
        if (i > 10):
            break
        
    cv2.imshow('Frame',frame)
    cv2.imshow('allOnly', greenOnly)
    
    k=cv2.waitKey(5)
    if k==27:
        break

cv2.destroyAllWindows()

avgRed=[]
avgGreen=[]
avgBlue=[]

for i in labels:
    obj=b==i
    redValues=np.array(obj)*np.array(red)
    greenValues=np.array(obj)*np.array(green)
    blueValues=np.array(obj)*np.array(blue)

    size=np.sum(obj)
    avgRed=np.append(avgRed,np.sum(redValues)/size)
    avgGreen=np.append(avgGreen,np.sum(greenValues)/size)
    avgBlue=np.append(avgBlue,np.sum(blueValues)/size)

    if i > 10:
        break

ax.scatter(avgRed,avgGreen,avgBlue)
ax.set_xlabel('red')
ax.set_ylabel('green')
ax.set_zlabel('blue')

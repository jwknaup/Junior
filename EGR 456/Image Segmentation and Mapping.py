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

    
    #_,labels=cv2.connectedComponents(greenOnly, 4)
    
    cv2.imshow('Frame',frame)
    
    k=cv2.waitKey(20)
    if k==27:
        break

cv2.destroyAllWindows()
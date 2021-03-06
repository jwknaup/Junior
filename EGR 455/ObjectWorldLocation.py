import numpy as np
import cv2
import serial

s = serial.Serial()
s.baudrate=9600
s.port='COM7'
s.open()

cap=cv2.VideoCapture(1)

cm2pixel = 10.5/640.0

R180x = [[1,0,0],[0,np.cos(np.pi),-np.sin(np.pi)],[0,np.sin(np.pi),np.cos(np.pi)]]
rad=90.0/180.0*np.pi
Rz=[[np.cos(rad),-np.sin(rad),0], [np.sin(rad),np.cos(rad),0], [0,0,1]]
R0_C=np.dot(R180x,Rz)

d0_C=[[8.8],[11.9],[0]]

H0_C=np.concatenate((R0_C,d0_C),1)
H0_C=np.concatenate((H0_C,[[0,0,0,1]]),0)

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

    xLocation = columnLocation*cm2pixel

    rowSums=np.matrix(np.sum(bw,1))
    row_numbers=np.transpose(np.matrix(np.arange(480)))
    rowMult = np.multiply(rowSums,row_numbers)
    total = np.sum(rowMult)
    totalTotal = np.sum(np.sum(bw))
    rowLocation = total/totalTotal

    yLocation=rowLocation*cm2pixel

    P = [[xLocation],[yLocation],[0],[1]]
    P = np.dot(H0_C,P)

    x=P[0]
    y=P[1]

    print(x, y)
 
    k=cv2.waitKey(5)
    if k==27:
        break

u = int(np.round_(x))
s.write(bytearray([u]))
#s.write('\n')
while(1):
    if k==27:
        break
v= int(np.round_(y))
s.write(bytearray([v]))

cv2.destroyAllWindows()


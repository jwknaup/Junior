import numpy as np
import cv2

cap = cv2.VideoCapture(0)

import serial
import time
import numpy as np

ser = serial.Serial()
ser.baudrate = 9600
ser.port='/dev/ttyS2'
try:
    ser.close()
except:
    pass
ser.open()

dError = 0
errorLast=0

while (1):
    _, frame = cap.read()

    red = np.matrix(frame[:, :, 2])
    green = np.matrix(frame[:, :, 1])
    blue = np.matrix(frame[:, :, 0])

    redOnly = np.int16(red) - 0.75*np.int16(green) - 0.75*np.int16(blue)
    redOnly[redOnly < 75] = 0
    redOnly[redOnly > 75] = 255
    redOnly = np.uint8(redOnly)

    columnSums = np.matrix(np.sum(redOnly, 0))
    column_numbers = np.matrix(np.arange(640))
    columnMult = np.multiply(columnSums, column_numbers)
    total = np.sum(columnMult)
    totalTotal = np.sum(np.sum(redOnly))
    columnLocation = total / totalTotal

    print(columnLocation)

    error = columnLocation - 320
    dError = (error - errorLast)/0.1
    kP = 0.7
    kD = 0.01
    speed = kP*error + kD*dError
    errorLast = error

    if(speed > 100):
        speed = 100
    elif(speed < -100):
        speed = -100;
    if(speed > 0):
        direction = 2
    else:
        direction = 1

    i = bytearray([np.uint8(abs(speed))])
    ser.write(i)
    time.sleep(0.1)
    i = bytearray([np.uint8(direction)])
    ser.write(i)
    time.sleep(0.1)

    # cv2.imshow('rgb', frame)
    cv2.imshow('red', redOnly)

    k = cv2.waitKey(5)
    if k == 27:
        break

cv2.destroyAllWindows()
ser.close()
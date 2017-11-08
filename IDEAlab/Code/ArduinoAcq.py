# -*- coding: utf-8 -*-
"""
Created on Mon Nov 06 18:27:39 2017

@author: Jacob
"""

import serial
import time

s = serial.Serial()
s.baudrate=115200
s.port='COM6'
s.open()
s.flush()

output =[]
#o=s.readline()
#output=s.readline()
#l = str.split(output)

start = time.time();
for j in range(0,500):
    #s.write("?\r")
    o=s.readline();
    output.append(o)
fin = time.time()
print(fin-start)

s.close()

file=open("pydata.csv", "w")

for i in output:
    file.write("%s" % i)

file.close()


# =============================================================================
# file=open("data.txt", "w")
# 
# for j in range(0,400):
#     file.write("%d\n" % d[j])
# 
# file.close()
# =============================================================================

# -*- coding: utf-8 -*-
"""
Created on Mon Nov 06 20:14:17 2017

@author: Jacob
"""

# -*- coding: utf-8 -*-
"""
Created on Tue Nov 07 12:19:01 2017

@author: Jacob
"""
import matplotlib.pyplot as plt
import numpy as np
import multiprocessing
import serial
import time
import os

force = np.zeros([200,2])
def loadcell(queue):
    z = 0;
    lc = serial.Serial()
    lc.baudrate=115200
    lc.port='COM12'
    lc.open()
    i=0
    while z<3:
       lc.write("?\r")
       f = lc.readline()
       t=time.clock()
       force[i,:] = [t, f]
       if (force[i,1]<0.001):
           z+=1
       else:
           z=0
       i+=1
    queue.put(force)
       
VI = np.zeros([100,3])
def arduino(queue):
    i = 0
    ar = serial.Serial()
    ar.baudrate=115200
    ar.port='COM6'
    ar.open()
    ar.flush()
    for i in range(100):
        o = ar.readline()
        a = o.split()
        print(a)
        t=time.clock()
        VI[i,:] = [a[0], a[1],t]        
    queue.put(VI)
    
if __name__ == '__main__':

    queue = multiprocessing.Queue()
    lcProc = multiprocessing.Process(target=loadcell, args=((queue),))
#   reader_p.daemon = True
    ardProc = multiprocessing.Process(target=arduino, args=((queue),))

    _start = time.time()
    
    lcProc.start()
    
    ardProc.start()
    
    ardProc.join()
    lcProc.join()
    print(queue.get())

    print(queue.get())

    lcProc.terminate()
    ardProc.terminate()

#os.system("pause")

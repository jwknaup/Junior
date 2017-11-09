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

def func(queue):
    o = "1 2"
    output = np.zeros([9,2])
    a = o.split()
    for i in np.arange(9):
        output[i,:] = a
        output[i,:] *= i
    queue.put(output)

force = np.zeros([20,2])
def loadcell(queue):
    lc = serial.Serial()
    lc.baudrate=115200
    lc.port='COM12'
    lc.open()
    i=0
    while True:
# =============================================================================
#        lc.write("?\r")
#        f = lc.readline()
#        t=time.clock()
# =============================================================================
       force[i,:] = [1, 2]
       i+=1
       if (queue.get() == 'DONE'):
           queue.put(force)
           break
       
VI = np.zeros([100,2])
def arduino(queue):
    i = 0
    ar = serial.Serial()
    ar.baudrate=115200
    ar.port='COM6'
    ar.open()
    ar.flush()
    for i in range(100):
        o = ar.readline()#'0 1'
        a = o.split()
        VI[i,:] = a
        #i+=1           
        # Write 'count' numbers into the queue
    queue.put(VI)
    queue.put('DONE');
    
if __name__ == '__main__':

    queue = multiprocessing.Queue()
    lcProc = multiprocessing.Process(target=loadcell, args=((queue),))
#   reader_p.daemon = True
    ardProc = multiprocessing.Process(target=arduino, args=((queue),))

    _start = time.time()
    
    lcProc.start()
    
    ardProc.start()
    
    ardProc.join()
    print(queue.get())
    lcProc.join()

    print(queue.get())

    lcProc.terminate()
    ardProc.terminate()

os.system("pause")

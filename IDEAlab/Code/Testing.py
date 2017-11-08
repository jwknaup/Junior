# -*- coding: utf-8 -*-
"""
Created on Tue Nov 07 12:19:01 2017

@author: Jacob
"""
import matplotlib.pyplot as plt
import numpy as np
import multiprocessing
#from multiprocessing import Process

#from queue import Queue
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

def reader(queue):
   while True:
       msg = queue.get()         # Read from the queue and do nothing
       if (msg == 'DONE'):
           break
       
def writer(count, queue):
   for ii in range(0, count):
       queue.put(ii)             # Write 'count' numbers into the queue
   queue.put('DONE')
    
if __name__ == '__main__':
    for count in [10**4, 10**5, 10**6]:
        queue = multiprocessing.Queue()
#        queue = Queue()   # reader() reads from queue
                         # writer() writes to queue
        #reader_p = multiprocessing.Process(target=reader, args=((queue),))
        proc = multiprocessing.Process(target=func, args=((queue),))
#        reader_p.daemon = True
        proc.start()        # Launch reader() as a separate python process
        _start = time.time()

        #writer(count, queue)    # Send a lot of stuff to reader()
        proc.join()         # Wait for the reader to finish

        print(queue.get())
        print ("Sending %s numbers to Queue() took %s seconds" % (count,(time.time() - _start))) 

    proc.stop()

os.system("pause")
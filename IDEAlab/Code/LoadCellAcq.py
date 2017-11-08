import serial
import time

s = serial.Serial()
s.baudrate=115200
s.port='COM12'
s.open()

output=[]

start = time.time();
for i in range(0,300):
    s.write("?\r")
    o = s.readline();
    output.append(o)
fin = time.time()
print(fin-start)

s.close()

file=open("pydata.csv", "w")

for i in output:
    file.write("%s " % i)

file.close()
# =============================================================================
# file=open("data.txt", "w")
# 
# for j in range(0,400):
#     file.write("%d\n" % d[j])
# 
# file.close()
# =============================================================================

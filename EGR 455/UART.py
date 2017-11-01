import serial

s = serial.Serial()
s.baudrate=9600
s.port='COM7'
s.open()

i=bytearray([200])
s.write(i)
a=[]
b=[]
c=[]
d=[]

for j in range(0,200):
    a=bytearray([s.read()])
    b=bytearray([s.read()])
    c=a[0]*256+b[0]
    d.append(c)

for j in range(0,200):
    a=bytearray([s.read()])
    b=bytearray([s.read()])
    c=a[0]*256+b[0]
    d.append(c)


s.close()

file=open("data.txt", "w")

for j in range(0,400):
    file.write("%d\n" % d[j])

file.close()

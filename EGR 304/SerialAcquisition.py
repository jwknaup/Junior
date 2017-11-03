import serial

s = serial.Serial()
s.baudrate=9600
s.port='COM10'
s.open()
b = []

for i in range(0,50):
    a=s.read()
    b.append(a)
print(a)


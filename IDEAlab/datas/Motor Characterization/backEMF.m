data2 = csvread('F:/DATA_2.csv');
freeCurrent = data2(data2 > 0.1);
Ifree=mean(freeCurrent)
Ra = R;
Ia = Ifree;
Va = 5.05;
VbackEMF = Va-Ra*Ia

frequency = 1.3195e3;
rpm = frequency/3.0*60
angularVelocity = frequency/3.0*2*pi;
freeW = angularVelocity;

K = VbackEMF/freeW

%K = Vemf/w = T/I
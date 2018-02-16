data3 = csvread('./friction/DATA_3.csv');
maxI = max(data3)
torqueStaticFriction = K*maxI
finI = data3(end)
torqueKineticFriction = K*finI

%T = Bw = KI

constantFreq = [163, 322, 435, 550, 850, 1.16e3];
constantW = constantFreq/3.0*2.0*pi;
constantI = [0.103, 0.111, .110, .112, .119, .112 ];

B = K.*constantI./constantW
T = K.*constantI
%more or less constant
%Tf0 = TfAve
TfAve = mean(T)
%T = Bw + Tk = KI

%B = (K*constantI - torqueKineticFriction)./constantW

%%%%%%with gear 30 reduction

maxI = .114
torqueStaticFriction = K*maxI
finI = .103
torqueKineticFriction = K*finI

constantFreq = [150,  270, 330, 495, 630, 900, 1.23e3, 1.585e3];
constantW = constantFreq/3.0*2.0*pi;
constantI = [.100, .102, .105, .110, .118, .129, .134, .139];

plot(K.*constantI, constantW)
B = (K.*constantI - TfAve)./constantW
%B = (K*constantI - torqueKineticFriction)./constantW
%T=L.*constantI


%%%%%%%%%with gear 300 reduction

constantFreq = [220,330, 417, 480, 600, 860, 1170, 1440];
constantW = constantFreq/3.0*2.0*pi;
constantI = [.099, 0.107, .109, .111, .111, .119, .124, .132];

figure(2)
plot(K.*constantI, constantW)
B = (K.*constantI - TfAve)./constantW

%final friction model is Tf = Bw + Tf0

%T=0=Tm-Tf=K*I - (B*w-Tf0)
%B*w-Tf0=K*I
%B*w=K*I + Tf0
%B = (K*I + Tf0)/w


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
constantW = constantFreq/3.0*2.0*pi
constantI = [.100, .102, .105, .110, .118, .129, .134, .139];

plot(constantW, K.*constantI, 'bo')
B = (K.*constantI./constantW - TfAve);
%B = (K*constantI - torqueKineticFriction)./constantW
%T=L.*constantI
%B=K*I/w - T0
%T0w + Bw = KI

%%%%%%%%%with gear 300 reduction

constantFreq = [220,330, 417, 480, 600, 860, 1170, 1440];
constantW = constantFreq/3.0*2.0*pi;
constantI = [.099, 0.107, .109, .111, .111, .119, .124, .132];

hold on
plot(constantW, K.*constantI, 'ro')
title('Motor Friction Characterization')
xlabel('steady-state angular velocity (rad/s)')
ylabel('frictional torque (Nm)')
lege = legend('1:30', '1:300');
title(lege,'gear ratio')

B = (K.*constantI./constantW - TfAve);

%final friction model is Tf = Bw + Tf0

%T=0=Tm-Tf=K*I - (B*w-Tf0)
%B*w-Tf0=K*I
%B*w=K*I + Tf0
%B = (K*I + Tf0)/w

%%%%%%%%%%with gear 75 reduction

constantI = [.115,.122, .127, .125, .126, .130,.128,.129];
constantFreq = [223,369,480,620,720,914,1280,1570];
constantW = constantFreq/3.0*2.0*pi;

%plot(constantW, K.*constantI, 'go')

lsline
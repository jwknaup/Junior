data3 = csvread('F:/DATA_3.csv');
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

B = K.*constantI./constantW
%B = (K*constantI - torqueKineticFriction)./constantW
T=L.*constantI
%needs linear fit


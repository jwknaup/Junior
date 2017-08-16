% In The Name Of GOD
clc 
clear

Q0 = [1 0 0 0];
Q1 = [sqrt(2)/2 sqrt(2/3)/2 sqrt(2/3)/2 sqrt(2/3)/2];
Q2 = [-sqrt(2)/2 sqrt(2/3)/2 sqrt(2/3)/2 sqrt(2/3)/2];
Q3 = [sqrt(2)/2 -sqrt(2/3)/2 -sqrt(2/3)/2 -sqrt(2/3)/2];
Q4 = [sqrt(2)/2 sqrt(2)/2 0 0];
Q5 = [-sqrt(2)/2 sqrt(2)/2 0 0];
Q6 = [sqrt(2)/2 -sqrt(2)/2 0 0];

UQ0 = UnitQuaternion([1 0 0 0])

UQ1 = UnitQuaternion([sqrt(2)/2 sqrt(2/3)/2 sqrt(2/3)/2 sqrt(2/3)/2])

UQ2 = UnitQuaternion([-sqrt(2)/2 sqrt(2/3)/2 sqrt(2/3)/2 sqrt(2/3)/2]);

UQ3 = UnitQuaternion([sqrt(2)/2 -sqrt(2/3)/2 -sqrt(2/3)/2 -sqrt(2/3)/2]);

UQ4 = UnitQuaternion([sqrt(2)/2 sqrt(2)/2 0 0]);

UQ5 = UnitQuaternion([-sqrt(2)/2 sqrt(2)/2 0 0]);

UQ6 = UnitQuaternion([sqrt(2)/2 -sqrt(2)/2 0 0]);

Q0inv = ([1 0 0 0]);
Q1inv = ([sqrt(2)/2 -sqrt(2/3)/2 -sqrt(2/3)/2 -sqrt(2/3)/2]);
Q2inv = ([-sqrt(2)/2 -sqrt(2/3)/2 -sqrt(2/3)/2 -sqrt(2/3)/2]);
Q3inv = ([sqrt(2)/2 +sqrt(2/3)/2 +sqrt(2/3)/2 +sqrt(2/3)/2]);
Q4inv = ([sqrt(2)/2 -sqrt(2)/2 0 0]);
Q5inv = ([-sqrt(2)/2 -sqrt(2)/2 0 0]);
Q6inv = ([sqrt(2)/2 +sqrt(2)/2 0 0]);


animate(UQ0,UQ1)
% figure
% animate(Q0,Q2)
% figure
% animate(Q0,Q3)
% figure
% animate(Q0,Q4)
% figure
% animate(Q0,Q5)
% figure
% animate(Q0,Q6)

T01 =  angle(UQ0,UQ1) * 180/pi
d01 =  QuatMult(Q1,Q0inv)
myAngle = 2*acos(d01)
A01 = 2*atan2(sqrt((d01(2))^2 +(d01(3))^2 + (d01(4))^2),d01(1))* 180/pi

T02 =  angle(UQ0,UQ2) * 180/pi
d02 =  QuatMult(Q2,Q0inv);
A02 = 2*atan2(sqrt((d02(2))^2 +(d02(3))^2 + (d02(4))^2),d02(1))* 180/pi

T03 =  angle(UQ0,UQ3) * 180/pi
d03 =  QuatMult(Q3,Q0inv);
A03 = 2*atan2(sqrt((d03(2))^2 +(d03(3))^2 + (d03(4))^2),d03(1))* 180/pi

T04 =  angle(UQ0,UQ4) * 180/pi
d04 =  QuatMult(Q4,Q0inv);
A04 = 2*atan2(sqrt((d04(2))^2 +(d04(3))^2 + (d04(4))^2),d04(1))* 180/pi

T05 =  angle(UQ0,UQ5) * 180/pi
d05 =  QuatMult(Q5,Q0inv);
A05 = 2*atan2(sqrt((d05(2))^2 +(d05(3))^2 + (d05(4))^2),d05(1))* 180/pi

T06 =  angle(UQ0,UQ6) * 180/pi
d06 =  QuatMult(Q6,Q0inv);
A06 = 2*atan2(sqrt((d06(2))^2 +(d06(3))^2 + (d06(4))^2),d06(1))* 180/pi



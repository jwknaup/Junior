
%% Velo DifEq

syms theta(t);
syms v(t);
moment_arm = 1.01;
w = v/moment_arm/cos(theta);
%ode1 = diff(theta, t) == w
Tmax = 0.4943*2;
wmax = 100*2*pi()/60;
mass = .021;

T = Tmax - w * Tmax/wmax;
F = T/moment_arm / cos(theta) - 9.81*mass;
%initialForce = vpa(Tmax/moment_arm/cos(THETA) - 9.81*mass)
a = F/mass;

ode2 = diff(v,t) == a
cond = v(0) == 0;
velocity = dsolve(ode2, cond)
RPM = velocity/moment_arm/cosd(45)*60/6.28318;
fplot(RPM, [0 .1])

%ezplot(velocity, [0 .1])
title('y velocity');

%% Energy
syms velo;
h1 = sind(45)*moment_arm*2;
h2 = .2 + h1;

U0 = 0;
U1 = mass * 9.81 * h1;
U2 = mass * 9.81 * h2;

K0 = 0;
K1 = 1/2*mass*velo^2;
K2 = 0;

velo = solve(K1+U1 == K2+U2);
velo = vpa(velo(2), 5)

rpm = vpa(velo/moment_arm/cosd(45)*60/6.28318, 5)

time = solve(velocity == velo)

%% Power

w = velocity/moment_arm/cosd(45);
T = Tmax - w * Tmax/wmax;
power = T*w
figure(2);
ezplot(power, [0 .1])
title('power');
Power_At_Launch = vpa(subs(power, t, time), 5)
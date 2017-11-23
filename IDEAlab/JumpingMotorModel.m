% Velo DifEq
clear
clc
 
%.187 jumped .6759 left gnd at 44 deg & .25897m -> 1.233

global Tmax wmax mass moment_arm gear_ratio;
gear_ratio = 17;
Tmax =.0013*2*gear_ratio;%0.4943*2/gear_ratio; 
wmax = 11100/gear_ratio*2*pi()/60;%gear_ratio*100*2*pi()/60;
moment_arm = .05;
mass = .015*2+.006*2;%13557594%.019 + .04*moment_arm

start_angle = 5*pi/180;
end_angle = 85*pi/180;

tFinal = 2.5*moment_arm/gear_ratio + .4;
tspan = [0,tFinal];
x0 = [0; start_angle];
options = odeset('MaxStep', tFinal*.01);
[time, x] = ode45(@odes, tspan, x0, options);
velocity = x(:, 1);
angle = x(:, 2);
acceleration = diff(velocity)./diff(time);
force = acceleration*mass+9.81*mass;
indexAngle = find(end_angle-angle < .1, 1);
v1= velocity(indexAngle);
scatter(time, velocity)
hold on
scatter(time, angle)
%scatter(time(1:length(time)-1), acceleration)
legend('velocity', 'angle');
xlabel('time (s)');
ylabel('v (m/s), angle (rad)');
title('jump .0714 kg');
hold off

figure(2)
plot([force, acceleration])

h1 = sin(end_angle)*moment_arm*2;
%final height
syms h2;
    
%potential energies
U1 = mass * 9.81 * h1;
U2 = mass * 9.81 * h2;
 
%kinetic energy when leaving the ground
K1 = 1/2*mass*v1^2;
K2 = 0;

%solve for h2
finalHeight = vpa(solve(K1+U1 == K2+U2))

jumpHeight = finalHeight - moment_arm*2

function dxdt = odes(t, x)
    global Tmax wmax mass moment_arm;
    
    w = 0.5*x(1)/moment_arm/cos(x(2));
    T = (Tmax - w * Tmax/wmax);
    F = T*cos(x(2))/moment_arm - 9.81*mass;
    a = F/mass;


    dxdt = [ a
        w];
end

%% Velo DifEq
clear
clc
 
global Tmax wmax mass moment_arm gear_ratio;
gear_ratio = 3
Tmax =0.4943*2/gear_ratio; 
wmax = gear_ratio*100*2*pi()/60;
moment_arm = .1;
mass = .02;%.019 + .04*moment_arm;

start_angle = 5*pi/180;
end_angle = 85*pi/180;

tFinal = moment_arm/gear_ratio + .15;
tspan = [0,tFinal];
x0 = [0; start_angle];
options = odeset('MaxStep', tFinal*.01);
[time, x] = ode45(@odes, tspan, x0, options);
velocity = x(:, 1);
angle = x(:, 2);
indexAngle = find(end_angle-angle < .1, 1)
time(indexAngle)
[~, indexVelo] = max(velocity)
height = cumtrapz(time, velocity) + 2*sin(start_angle)*moment_arm;
scatter(time, velocity);
hold on
scatter(time, angle);
scatter(time, height);
height2 = moment_arm*sin(angle)*2;
scatter(time, height2)
legend('velocity', 'angle', 'height int', 'height theta');
hold off



results = [time velocity height]
csvwrite('matlabOne.csv', results);


function dxdt = odes(t, x)
    global Tmax wmax mass moment_arm;
    
    w = 0.5*x(1)/moment_arm/cos(x(2));
    T = (Tmax - w * Tmax/wmax);
    F = T*cos(x(2))/moment_arm - 9.81*mass;
    a = F/mass;

    dxdt = [ a
        w];
end

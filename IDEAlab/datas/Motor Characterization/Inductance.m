change = [0.224, 2.24, 3.00];
final = [0.0, 0.0, 0.0];
start = [-0.352, -3.44, -3.44];
t = [2.24*10^-6, 2.24*10^-6, 3.12*10^-6];

tau = -t/log(1-(change/(final-start)))
tau_aver = mean(tau);

%tau = L/R
L = R*tau_aver

%%%%%%%%%%%%AC method

currentAC = .4807e-3;
voltagePP = 5.0;
frequency = 50e3;

%z^2 = x^2 + R^2
%x^2 = V/I-R^2 = (2pi*fL)^2

z = voltagePP/2.0/currentAC;
x = sqrt(z^2-R^2);
L=x/(2*pi*frequency)

%530 uH per LCR meter
%52.9 ohm per LCR meter
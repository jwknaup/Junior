clear
delete(instrfindall);
loadcell = serial('COM12');
%arduino = arduino();
set(loadcell, 'BaudRate', 115200);
fopen(loadcell);
num = 50;
force(num) = single(0);
current(num) = single(0);
t = zeros(num, 1);
t0 = cputime;
% writeDigitalPin(arduino, 'D2', 1); 
% writeDigitalPin(arduino, 'D3', 0); 
% writeDigitalPin(arduino, 'D6', 1); 
% writeDigitalPin(arduino, 'D7', 1);
tic
for i = 1:num
    fprintf(loadcell, '?');
    fprintf(loadcell, char(13));
    a = fscanf(loadcell, '%f');
    force(i)=a(1);
    %b = readVoltage(arduino, 'A1');
    %current(i) = b(1);
end
toc
tf = cputime;
% writeDigitalPin(arduino, 'D2', 0); 
% writeDigitalPin(arduino, 'D3', 0); 
% writeDigitalPin(arduino, 'D6', 0); 
% writeDigitalPin(arduino, 'D7', 1);
data = [t,force'];
plot(t, force, 'x');
csvwrite('force12.csv', data);
fclose(loadcell);
delete(loadcell);
clear s
clear
delete(instrfindall);
loadcell = serial('COM12');
arduino = arduino();
set(loadcell, 'BaudRate', 115200);
fopen(loadcell);
num = 50;
force(num) = single(0);
current(num) = single(0);
t = zeros(num, 1);
writeDigitalPin(arduino, 'D2', 1); 
writeDigitalPin(arduino, 'D3', 0); 
writeDigitalPin(arduino, 'D6', 1); 
writeDigitalPin(arduino, 'D7', 1);
t0 = cputime;
tic
for i = 1:num
    fprintf(loadcell, '?');
    fprintf(loadcell, char(13));
    a = fscanf(loadcell, '%f');
    t(i) = cputime-t0;
    force(i)=a(1);
    b = readVoltage(arduino, 'A1');
    current(i) = b(1);
end
toc
writeDigitalPin(arduino, 'D2', 0); 
writeDigitalPin(arduino, 'D3', 0); 
writeDigitalPin(arduino, 'D6', 0); 
writeDigitalPin(arduino, 'D7', 1);
data = [t,force']
csvwrite('force3.csv', data);
fclose(loadcell);
delete(loadcell);
clear s
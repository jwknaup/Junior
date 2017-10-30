clear
delete(instrfindall);
loadcell = serial('COM12');
arduino = arduino();
set(loadcell, 'BaudRate', 115200);
fopen(loadcell);
num = 100;
force(num) = single(0);
current(num) = single(0);
tic
for i = 1:num
    fprintf(loadcell, '?');
    fprintf(loadcell, char(13));
    a = fscanf(loadcell, '%f');
    force(i)=a(1);
    b = readVoltage(arduino, 'A1');
    current(i) = b(1);
end
toc
fclose(loadcell);
delete(loadcell);
clear s
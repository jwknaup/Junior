delete(instrfindall);
arduino = serial('COM6');
%arduino = arduino();
set(arduino, 'BaudRate', 115200);
fopen(arduino);

num=100;
tic
for i = 1:num
    fprintf(arduino, '?');
%     fprintf(loadcell, char(13));
    a = fscanf(arduino, '%c', 1);
    %force(i)=a(1);
    %b = readVoltage(arduino, 'A1');
    %current(i) = b(1);
end
toc
double(a)
fclose(arduino);
delete(arduino);
clear s
clear
delete(instrfindall);
s = serial('COM12');
set(s, 'BaudRate', 115200);
fopen(s);
num = 100;
out(num) = single(0);
tic
for i = 1:num
    fprintf(s, '?');
    fprintf(s, char(13));
    a = fscanf(s, '%f');
    out(i)=a(1);
end
toc
fclose(s);
delete(s);
clear s
%b=str2num(out)
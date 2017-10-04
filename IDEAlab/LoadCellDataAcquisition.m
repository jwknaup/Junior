delete(instrfindall);
s = serial('COM12');
set(s, 'BaudRate', 115200);
fopen(s);
while(cputime<1000)
    fprintf(s, '?');
    fprintf(s, char(13));
    out = fscanf(s)
end
fclose(s);
delete(s);
clear s
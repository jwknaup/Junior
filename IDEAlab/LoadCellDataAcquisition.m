delete(instrfindall);
s = serial('COM12');
set(s, 'BaudRate', 115200);
fopen(s);
fprintf(s, '?');
fprintf(s, char(13));
out = fscanf(s)
fclose(s);
delete(s);
clear s
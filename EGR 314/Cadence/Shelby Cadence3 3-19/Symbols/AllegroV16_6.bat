cd %~dp0
allegro -s CustomShapes.scr
pad_designer -s AllegroV16_6_pads.scr
CALL :checkfile "RX262Y304D0T.pad"
CALL :checkfile "RX35Y55D0T.pad"
CALL :checkfile "RX264Y316D0T.pad"
CALL :checkfile "RX39Y79D0T.pad"
CALL :checkfile "RX260Y292D0T.pad"
CALL :checkfile "RX37Y67D0T.pad"
allegro -s AllegroV16_6_brd.scr
CALL :checkfile "DPAK.psm"
CALL :checkfile "DPAK-M.psm"
CALL :checkfile "DPAK-L.psm"

exit

:checkfile
@echo off
dir %1 1>nul 2>nul
if errorlevel 1 goto checkfile_err
goto end
:checkfile_err
echo Expected file %1 not found
pause > nul
exit
:end
@echo on

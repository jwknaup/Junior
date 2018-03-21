cd %~dp0
allegro -s CustomShapes.scr
pad_designer -s AllegroV16_6_pads.scr
CALL :checkfile "RX18Y46D0T.pad"
CALL :checkfile "RX22Y70D0T.pad"
CALL :checkfile "RX20Y58D0T.pad"
allegro -s AllegroV16_6_brd.scr
CALL :checkfile "TQFP44_10x10MC.psm"
CALL :checkfile "TQFP44_10X10MC-M.psm"
CALL :checkfile "TQFP44_10X10MC-L.psm"

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

 
 
 
**********************************************************
*************  Important Instructions Follow  ************
**********************************************************
 
All files exported to: C:\EMA\ExportFolder\1\991\Output\AllegroV16_6\AllegroV16_6
 
 
To import your new library parts into Allegro:

1. Using your Windows explorer, find the file that was included
in your zip file that ends in ".bat".  This is a batch file
set of instructions for your computer.  Double clicking this
file should start the batch file.  You must already have Allegro
installed and runnning on the computer that the batch file was
created on, or you will need to modify the pathing of the
batch file.

2. It will create more files for you by first loading the
padstack tool, and then the part building software.

3. Once completed, you will want to move the files that have
been created to your appropriate directory structure, so that
the parts are available for use in your board.

This requires that you have Allegro installed in the normal
locations and that it can be found in your pathing.  If this
is not the case, simply edit the lines in your batch file that
refer to your Allegro tools to find them in the correct location.

You may be running a newer version of the Allegro Software than the
template file we are distributing.  In this case you will be asked
to okay the loading of the file each time the script requires a
file load.  You can update the template files found in the
\installationpath\CadInfos\Allegro\*.pcb files by simply opening
them in Allegro and then saving them again in your current version
of Allegro.  You should do this with the *.dra files as well.

In recent versions of Allegro we have found that the path to the executable
is not installed with the software like it has been in the past.
This causes our software to fail with a "path not found" error.
Your Cadence executables are normally found at some place similar to
"C:\Cadence\SPB_17.2\tools\pcb\bin".  Once you locate your path
you need to add it to the system enviornment statement.

This can be done by right clicking on you r computer and selecting
"properties".  From this selection you should select "Advanced
System Settings" and then "Environment Variables".   In the system
variables box search for "path", and edit this path.  You will want
to select new, and add your cadence path into the environmental
statement.  After doing this any of the batch files or scripts
run by our tool (and a host of others) will work as intended.

For additional information, please visit this site:
http://www.accelerated-designs.com/help/Allegro_import.html

For a video tutorial, please visit:
http://youtu.be/x842nPhbryE
 
 
Symbol "PIC18F47J53-X/PT" renamed to "PIC18F47J53-XPT"
Component "PIC18F47J53-X/PT" renamed to "PIC18F47J53-XPT"


Ultra Librarian Gold 8.2.139 Process Report


Message - Pattern "TQFP44_10x10MC", entity (639-LINE) is a LINE with matching start and end points.
Message - Pattern "TQFP44_10x10MC", entity (641-LINE) is a LINE with matching start and end points.
Message - Pattern "TQFP44_10x10MC", entity (643-LINE) is a LINE with matching start and end points.
Message - Pattern "TQFP44_10x10MC", entity (645-LINE) is a LINE with matching start and end points.
Message - Pattern "TQFP44_10X10MC-M", entity (639-LINE) is a LINE with matching start and end points.
Message - Pattern "TQFP44_10X10MC-M", entity (641-LINE) is a LINE with matching start and end points.
Message - Pattern "TQFP44_10X10MC-M", entity (643-LINE) is a LINE with matching start and end points.
Message - Pattern "TQFP44_10X10MC-M", entity (645-LINE) is a LINE with matching start and end points.
Message - Pattern "TQFP44_10X10MC-L", entity (639-LINE) is a LINE with matching start and end points.
Message - Pattern "TQFP44_10X10MC-L", entity (641-LINE) is a LINE with matching start and end points.
Message - Pattern "TQFP44_10X10MC-L", entity (643-LINE) is a LINE with matching start and end points.
Message - Pattern "TQFP44_10X10MC-L", entity (645-LINE) is a LINE with matching start and end points.

TextStyle count:  25
Padstack count:   3
Pattern count:    3
Symbol count:     1
Component count:  1

Export

Starting to Export Allegro Padstacks
Starting to Export Allegro Parts
Exporting TQFP44_10x10MC
Exporting TQFP44_10X10MC-M
Exporting TQFP44_10X10MC-L
Completing output of Allegro netlist, placement and device files

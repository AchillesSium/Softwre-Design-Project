

This is a prototype of an application which lets user view and compare weather data
from weather stations of their choice.



There are two methods to run this prototype:

Method 1. Navigate into the application folder and open the prototype.exe file. This
	  will only require a windows operating system.


Method 2. For this method user will need a "Qt Creator" program.
	  - Open "Qt creator"
	  - Select "Open Project" and find the .pro file found in the source folder.
	  - Configure it to run on Qt 5.9.9 MinGW 32bit (Older versions may work if they supprot QtCharts)
	  - Make sure a Qt module "QtCharts" is installed. (This can be done via the Qt Maintenance Tool)
	  - Build and run the prototype


This is in no way a finished product so it doesn't yet have real weather data. All values
shown in charts are arbitrary and represent neither SMEAR or STATFI.

For more information see the design document of this project.
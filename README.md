
This is an application which lets user view and compare greenhouse gas emission data 
from different sources and stations. Data is fetched via online APIs, parsed, and
displayed in a graph.

To run the program the user will need the "Qt Creator" program.
  - Open "Qt creator"
  - Select "Open Project" and locate the .pro file found in the project_group_anyone folder.
  - Configure it to run on Qt 5.9.9 MinGW 32bit (newer versions will NOT work).
  - Make sure the following Qt modules are installed (can be done via the Qt Maintenance Tool):
    - QtCore
    - QtGUI
    - QtCharts
    - QtNetwork
  - Build and run

Note: We attempted to make an executable of the app, but the executable would crash with no
indication as to why and we ran out of time trying to get it to work.

For more information about the software see the design document of this project.

Development team:
  Mohammad Hassan
  Sakari Klemola
  Aatu Laurikainen
  Aleksi Sirviö

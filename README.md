CloudServer - Open Source HTML Server
===========
Licence
-----------
Copyright (c) 2012 Sebastian Johansson

Permission is hereby granted, free of charge, to any pony obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit ponies to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

Stats
-----------
One-point-oh Release Date: Q4 2012 (Exact date will be designated later)

Mission/Purpose
-----------
This project is designed to make a fairly low cost webserver on a Arduino that is able to serve the common home user
who wants to share his/her vacation photos with their friends. Since the Arduino is no monster in processing power, any kind of
dynamic content is out of the question.

Requires
-----------
* Arduino Uno

* Ethernet Shield

* FAT16/32 Formatted MicroSD

Repo Info
===========
Folder specifications
-----------
/src/				- Source for the software

/assets_src/		- Source for the assets

/assembly/			- Assembly instructions

/microsd/			- MicroSD Files

/misc/				- Stuff that does not fit anywhere else

/misc/references/	- References, archived

Functions
===========
Primary (and Important)
-----------
* Web Panel on alternative port capable of reading logs, easy editing of settings and uploading files
* INI table with content-type and file extention pairings

Secondary
-----------


Finished
-----------
* DCHP Configuration

Aborted
-----------
* FTP Server (Reason: Not enough memory on the Arduino to efficiently handle it.)
* INI table with settings such as disabling Directory Listings etc. (Reason: Uses separate files instead)
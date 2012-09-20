CloudServer - Open Source HTML Server
===========
Copyright 2012, Sebastian Johansson
-----------

You are allowed to create and adapt this project for private, non-commercial use. I may change this at any point I want.

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
*Arduino Uno

*Ethernet Shield

*MicroSD

Repo Info
===========
/src/				Source for the software

/assets_src/		Source for the assets

/assembly/			Assembly instructions

/microsd/			MicroSD Files

/misc/				Stuff that does not fit anywhere else

/misc/references/	References, archived

Functions
===========
Primary (and Important)
-----------
* Web Panel on alternative port capable of reading logs, easy editing of settings and uploading files

* INI table with content-type and file extention pairings

* INI table with settings such as disabling Directory Listings etc.

Secondary
-----------
* DCHP Configuration

* FTP Server
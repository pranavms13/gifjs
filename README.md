gifjs
=======

Tool to inject javascript into a valid gif file.  
Currently supported image type is gif.

Building:

To build this tool, `build-essential` and `cmake` are required (this is for Ubuntu based systems).
After installing the dependencies, run the following commands:

```
$ git clone https://github.com/pranavms13/gifjs.git
$ cd gifjs
$ mkdir build
$ cd build
$ cmake ..
$ make
```

Usage:

Run `gifjs option jsfile.js`.
The outcoming image file will be named like the input file + the image ending..
Options are currently only `gif`.

Example:

Code can now be embedded into existing gif files by using the flag `-i` with a gif file as argument.  
Example:  
`$ ./gifjs gif code.js -i giffile.gif`

Usage of GIF file as script is as simple as :
`$ <script src="giffile.gif">`

Background:
-----------

This tool allows you to create a picture file that is able to run javascript code.

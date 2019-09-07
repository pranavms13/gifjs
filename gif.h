/*
File: gif.h
Project: gifjs
Author: Pranav M S
*/


#ifndef GIF_H
#define GIF_H

#include <stdlib.h>
#include <string.h>


#define GIFJSHEAD 19
#define GIFJSHEAD_E 6
#define GIFEND 5

char *gif_js(char*, int);
char *gif_js_i(char*, int, char*, int);
char *gif_filename(char*, int);

#endif

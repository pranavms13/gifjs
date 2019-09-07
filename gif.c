/*
File: gif.c
Project: gifjs
Author: Pranav M S
*/


#include "gif.h"

char *gif_js(char *content, int size){
	const char _gif_header[GIFJSHEAD] = {0x47, 0x49, 0x46, 0x38, 0x39, 0x61, 0x2f, 0x2a, 0x00, 0x30, 0x00, 0x00, 0x3b, 0x2a, 0x2f, 0x3d, 0x30, 0x3b, 0x0a};
	char *buffer = (char*)malloc(GIFJSHEAD + size);
	memcpy(buffer, _gif_header, GIFJSHEAD);
	memcpy(&buffer[GIFJSHEAD], content, size);
	return buffer;
}

char *gif_js_i(char *content, int csize, char *image, int isize){
	const char _gif_header[8] = {0x47, 0x49, 0x46, 0x38, 0x39, 0x61, 0x2f, 0x2a};
	const char _gif_header_end[GIFJSHEAD_E] = {0x2a, 0x2f, 0x3d, 0x30, 0x3b, 0x0a};
	char *buffer = (char*)malloc(csize + isize + GIFJSHEAD_E);
	memcpy(buffer, _gif_header, 8);
	memcpy(&buffer[8], &image[8], isize - 8);
	memcpy(&buffer[isize], _gif_header_end, GIFJSHEAD_E);
	memcpy(&buffer[isize + GIFJSHEAD_I], content, csize);
	return buffer;
}

char *gif_filename(char *fn, int size){
        const char _GIFEND[GIFEND] = {0x2e, 0x67, 0x69, 0x66, 0x00};
	char *newfile = (char*)malloc(size + GIFEND);
	memcpy(newfile, fn, size);
	memcpy(&newfile[size], _GIFEND, GIFEND);
        return newfile;
}

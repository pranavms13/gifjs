/*
File: main.c
Project: gifjs
Author: Pranav M S
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "meta.h"
#include "gif.h"

int getlen(char* str){
	int i;
	for(i = 0; str[i] != 0; i++);
	return i;
}

void _help(char *name, int type){
	switch(type){
		case 0:
			printf("gifjs %d\n", VERSION);
			printf("Usage: %s [option] [javascript file] [flags] [args]\n", name);
			printf("Options available:  gif\n");
			printf("Flags (optional):	-l	Prints image as viewable line.\n");
			printf("			-i	Injects code into an existing image. Needs an image file as argument.\n");
			break;
		case 1:
			printf("The flag \"%s\" is currently not supported for this type of file.\n", name);
			break;
		case 2:
			printf("The flag \"%s\" needs an argument.\n", name);
			break;
		case 3:
			printf("The file %s could not be opened.\n", name);
			break;
		default:
			_help(name, 0);
			break;
	}
}

int main(int argc, char *argv[]){
	if(argc < 3){
		_help(argv[0], 0);
		return 1;
	}
	FILE *in;
	FILE *out;
	int filesize;
	char *buf;
	in = fopen(argv[2], "rb");
	if(in){
		fseek(in, 0, SEEK_END);
		filesize = ftell(in);
		rewind(in);
		buf = (char*)malloc(filesize * sizeof(char));
		fread(buf, 1, filesize, in);
		fclose(in);
	}else{
		_help(argv[2], 3);
		return 2;
	}
	char *outbuf;
    if(strcmp(argv[1], "gif") == 0){
		if(argc > 3){
			if(argc > 4){
				FILE *im = fopen(argv[4], "rb");
				if(im){
					fseek(im, 0, SEEK_END);
					int imsize = ftell(im);
					rewind(im);
					char *imbuf = (char*)malloc(imsize * sizeof(char));
					fread(imbuf, 1, imsize, im);
					fclose(im);
					outbuf = gif_js_i(buf, filesize, imbuf, imsize);
					out = fopen(gif_filename(argv[2], getlen(argv[2])), "wb");
					for(int i = 0; i < (filesize + imsize + GIFJSHEAD_E); i++){
						fprintf(out, "%c", outbuf[i]);
					}
					free(imbuf);
				 }else{
					 _help(argv[4], 3);
					 return 2;
				 }
			}else if(strcmp(argv[3], "-i") == 0){
				_help(argv[3], 2);
				return 2;
			}else{
				_help(argv[3], 1);
				return 3;
			}
		}else{
			outbuf = gif_js(buf, filesize);
			out = fopen(gif_filename(argv[2], getlen(argv[2])), "wb");
			for(int i = 0; i < filesize + GIFJSHEAD; i++){
				fprintf(out, "%c", outbuf[i]);
			}
		}
	}
	else{
		_help(argv[0], 0);
		free(buf);
		return 1;
	}
	fclose(out);
	free(buf);
	free(outbuf);
	return 0;
}
	

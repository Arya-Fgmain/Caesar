#ifndef CAESAR_H
#define CAESAR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char text_cipher(const char c);
char cipher_text(const char c);
char *encode_text(const char *text);
char *decode_text(const char *cipher);
unsigned int encode_to_file(char *dest, char *src, unsigned int max_len);
unsigned int decode_to_file(char *dest, char *src, unsigned int max_len);

#endif
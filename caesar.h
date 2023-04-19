#ifndef CAESAR_H
#define CAESAR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char text_cipher(const char c);

char cipher_text(const char c);

void encode_line(char *src);

void decode_line(char *src);

unsigned int encode_to_file(char *dest, char *src, unsigned int max_len);

unsigned int decode_to_file(char *dest, char *src, unsigned int max_len);

#endif
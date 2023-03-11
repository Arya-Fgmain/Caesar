#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *ALPHABET = "abcdefghijklmnopqrstuvwxyz";

char text_cipher(const char c) {
    unsigned int c_index = c; // automatic casting since it's casting down
    if (c >= 'A' && c <= 'Z') {
        c_index -= 'A';
    } else if (c >= 'a' && c <= 'z') {
        c_index -= 'a';
    } else {
        return c;
    }
    return ALPHABET[(c_index + 3) % 26];
}

char cipher_text(const char c) {
    unsigned int c_index = c; // automatic casting since it's casting down
    if (c >= 'A' && c <= 'Z') {
        c_index -= 'A';
    } else if (c >= 'a' && c <= 'z') {
        c_index -= 'a';
    } else {
        return c;
    }
    return ALPHABET[(c_index + 23) % 26];
}

char *encode_text(const char *text) {
    unsigned int length_text = strlen(text);
    char *cipher = malloc(sizeof(char) * (length_text + 1));
    for (int i = 0; i < length_text; i++) {
        cipher[i] = text_cipher(text[i]);
    }
    return cipher;
}

char *decode_text(const char *cipher) {
    unsigned int length_cipher = strlen(cipher);
    char *text = malloc(sizeof(char) * (length_cipher + 1));
    for (int i = 0; i < length_cipher; i++) {
        text[i] = cipher_text(cipher[i]);
    }
    return text;
}

char readline(FILE *file, char *dest, unsigned int capacity) {
    for (int i = 0; i < capacity; i++) {
        dest[i] = fgetc(file);
    }
    return dest[capacity-1]; // return last char if successful
}

int main(void) {

    FILE *text = fopen("text.txt", "r");
    unsigned int capacity = 101;
    FILE *cipher = fopen("cipher.txt", "w");

    while (!feof(text)) {
        char *original = (char*)malloc(sizeof(char) * capacity);
        fgets(original, capacity, text);
        fprintf(cipher, encode_text(original), "%s\n");
        printf("%d\n", strchr(original, '\n') == NULL);
        
    }

    fclose(text);
    fclose(cipher);


    // Code below reads a line from file tex.txt
   FILE *f = fopen("tex.txt", "r");
   unsigned int length = 10, used = 0;
   char *text = malloc(sizeof(char) * length);
   char curr_c = fgetc(f);
   while (curr_c != EOF && curr_c != '\n') {
      if (used == length - 1) {
         length *= 2;
         char *temp = realloc(text, length);
         if (temp != NULL) { 
            text = temp;
         } else {
            puts("Memory allocation error");
            exit(1);
         }
      }
      text[used++] = curr_c;
      curr_c = fgetc(f);
   }
   text[used] = '\n';
   fclose(f);





    return EXIT_SUCCESS;
}




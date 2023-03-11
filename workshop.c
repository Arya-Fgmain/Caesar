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
        // bug: even if there is more than 100 characters, fgets raeds it? lol
        // so fgets: n-1 characters read from the file, last one is \0 (no null pointer put here)
    }

    fclose(text);
    fclose(cipher);


    // try implementing this with fgets(), way more efficient
    // Code below reads a line from file tex.txt
   FILE *f = fopen("tex.txt", "r");
   unsigned int length = 10, used = 0;
   char *text = malloc(sizeof(char) * length);
   char curr_c = fgetc(f);
   while (curr_c != EOF && curr_c != '\n') {
      if (used == length - 1) {
         length *= 2;
         char *temp = realloc(text, length);
         if (temp != NULL) { // hopefully realloc doesn't fail
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





    return 0;
}

/*

Done:
- Check if it is in [65,90] or [97, 122], then subtract 65 or 97 from its 
integer representation appropriately
- If a special character, such as space, ', ;, ., :. BASICALLY if not in the 
[65,90] or [97, 122] range, just return the character
next up: file reading
- Also consider this: pointer arithmetic, so (c_location - ALPHABET) / sizeof(char)
- Actually nvm! just find index using char to int conversion, and use those conversion methods (addd to either 65 or 97)

To add:
- why can't we simply use a null pointer so that we can store indefinite lengths?
worst case: just assume every line is at most 100 characters
- why can't we use a null pointer (for original) so that we can store indefinite lengths?
*/



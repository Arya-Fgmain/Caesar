#include "caesar.h"

#define ALPHABET "abcdefghijklmnopqrstuvwxyz"

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

char *encode_line(const char *text) {
    unsigned int length_text = strlen(text);
    char *cipher = malloc(sizeof(char) * (length_text + 1));
    for (int i = 0; i < length_text; i++) {
        cipher[i] = text_cipher(text[i]);
    }
    return cipher;
}

char *decode_line(const char *cipher) {
    unsigned int length_cipher = strlen(cipher);
    char *text = malloc(sizeof(char) * (length_cipher + 1));
    for (int i = 0; i < length_cipher; i++) {
        text[i] = cipher_text(cipher[i]);
    }
    return text;
}

/*
Writes the contents of src in caesar cipher
to dest, assuming a max line length of max_len 
0 - incorrect length input (less than 1)
1 - file reading issue
2 - memory allocation failure
Upon success - returns number of lines read
*/

unsigned int encode_to_file(char *dest, char *src, unsigned int max_len) {

    if (max_len < 1) { return 0; }

    FILE *text = fopen(src, "r");
    FILE *cipher = fopen(dest, "w");

    if (text == NULL || cipher == NULL) { return 1; }

    int buffer_size = max_len + 2; 
    // 2 extra characters for null termiantor and \0

    char *read_text = (char*)malloc(sizeof(char) * buffer_size);

    if (read_text == NULL) { return 2; }

    int counter = 0;

    while (!feof(text)) {
        fgets(read_text, buffer_size, text);
        if (strcmp(read_text, "\n") != 0) {
            fprintf(cipher, encode_line(read_text));
        }
        counter++;
    }

    free(read_text);
    fclose(text);
    fclose(cipher);
    read_text = NULL;
    text = NULL;
    cipher = NULL;

    return counter;
}

/*
Writes the contents of src in caesar cipher
to dest, assuming a max line length of max_len 
0 - incorrect length input (less than 1)
1 - file reading issue
2 - memory allocation failure
Upon success - returns number of lines read
*/
unsigned int decode_to_file(char *dest, char *src, unsigned int max_len) {

    if (max_len < 1) { return 0; }

    FILE *cipher = fopen(src, "r");
    FILE *text = fopen(dest, "w");

    if (cipher == NULL || text == NULL) { return 1; }

    int buffer_size = max_len + 2;
    char *read_cipher = (char*)malloc(sizeof(char) * buffer_size);

    if (read_cipher == NULL) { return 2; }

    int counter = 0;

    while (!feof(cipher)) {
        fgets(read_cipher, buffer_size, cipher);
        if (strcmp(read_cipher, "\n") != 0) {
            fprintf(text, decode_line(read_cipher));
        }
        counter++;
    }

    free(read_cipher);
    fclose(cipher);
    fclose(text);
    read_cipher = NULL;
    cipher = NULL;
    text = NULL;

    return counter;
}
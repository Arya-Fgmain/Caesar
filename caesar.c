#include "caesar.h"

char text_cipher(const char c) {

    if (c == '\n' || c == ' ') { return c; } // no need to convert these
    if (c == '\"') { return '\"'; }
    int ascii_index = c; // automatic casting since it's casting down
    return (char)((ascii_index+3) % 127);

}

char cipher_text(const char c) {

    if (c == '\n' || c == ' ') { return c; }
    if (c == '\"') { return '\"'; }
    int ascii_index = c;
    return (char)((ascii_index+124) % 127); 

}

void encode_line(char *src) {

    unsigned int length_src = strlen(src);
    for (int i = 0; i < length_src; i++) {
        src[i] = text_cipher(src[i]);
    }

}

void decode_line(char *src) {

    unsigned int length_src = strlen(src);
    for (int i = 0; i < length_src; i++) {
        src[i] = cipher_text(src[i]);
    }

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
            encode_line(read_text);
            fprintf(cipher, read_text);
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
            decode_line(read_cipher);
            fprintf(text, read_cipher);
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
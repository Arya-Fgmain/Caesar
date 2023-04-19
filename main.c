#include "caesar.h"
#include <stdio.h>

int main(void) {
    
    char src[101], dest[101];
    int max_len = 0;

    int option = 0;
    printf("Would you like to encode (1) or decode (0)? ");
    scanf("%d", &option);

    printf("Enter source file name: ");
    scanf("%s", src);
    printf("Enter target file name: ");
    scanf("%s", dest);
    printf("What is the maximum no. characters per line: ");
    scanf("%d", &max_len);


    int lines_read = 0;

    if (option) {
        lines_read = encode_to_file(dest, src, max_len);
    } else {
        lines_read = decode_to_file(dest, src, max_len);
    }
    
    printf("Read %d lines\n", lines_read);

    return 0;
}
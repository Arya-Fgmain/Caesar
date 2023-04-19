#include "caesar.h"
#include <stdio.h>

int main(void) {
    char src[101], dest[101];
    int max_len = 0;
    printf("Enter source file name: ");
    scanf("%s", src);
    printf("Enter target file name: ");
    scanf("%s", dest);
    printf("What is the maximum no. characters per line: ");
    scanf("%d", &max_len);
    int read = encode_to_file(dest, src, max_len);
    printf("Encoded %d lines into %s\n", read, dest);

    return 0;
}
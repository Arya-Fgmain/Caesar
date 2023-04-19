## So what's all this about?
Caesar is a C-library for encoding and decoding English text using the classic Caesar cipher! :sunglasses:
*Currently the library uses a 3-character shift, meaning a becomes d & so on*
Read more below for the full details...

## How does Caesar work?
As of now, the Caesar library uses:
* Casting
* Modular Arithmetic
* File I/O


## Function Descriptions
*Refer to caesar.h and caesar.c

**char text_cipher(const char c), char cipher_text(const char c)**: 'text-to-cipher' takes ascii alphabetical character c and returns its caesar cipher equivalent. 'cipher-to-text' does the opposite: c is the caesar-encoded character, so the function returns the original character.

**char \*encode_line(const char \*text), char \*decode_line(const char \*text)**: encode_line uses text_cipher to encode an entire string. decode_line again does the reverse, taking a string in caesar cipher and then translating it back to English.

**unsigned int encode_to_file(char \*dest, char \*src, unsigned int max_len), unsigned int decode_to_file(char \*dest, char \*src, unsigned int max_len)**: encode_to_file reads all the text from src and encodes them to dest, with the assumption that each line in src has at most 100 characters. decode_to_file does the opposite, taking cipher text and writing it to dest in english.

Enjoy! :tada:

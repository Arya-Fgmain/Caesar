## So what's all this about?
Caesar is a C-library for encoding and decoding English text using the classic Caesar cipher! :sunglasses:
*Currently the library uses a 3-character shift, meaning a becomes d & so on*
Read more below for the full details...

## The library functions

**char text_cipher(const char c), char cipher_text(const char c)**: 'text-to-cipher' takes ascii alphabetical character c and returns its caesar cipher equivalent. 'cipher-to-text' does the opposite: c is the caesar-encoded character, so the function returns the original character.

**char \*encode_line(const char \*text) char \*decode_line(const char \*text)**: encode_line uses text_cipher to encode an entire string. decode_line again does the reverse, taking a string in caesar cipher and then translating it back to English.

**unsigned int encode_to_file(char \*dest, char \*src, unsigned int max_len), unsigned int decode_to_file(char \*dest, char \*src, unsigned int max_len)**

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
*Refer to caesar.h and caesar.c*

**char text_cipher(const char c)**
Takes an ascii character and encodes it into caesar cipher by shifting it 3 positions to the right in the ascii chracter line.   
Ex. text_cipher('a') returns 'd'.  
Special cases: newline '\n', space ' ' and double-quotes '\"' are not converted.

**char cipher_text(const char c)** 
Takes an ascii character (in caesar cipher) and shifts it back to its original ascii value.  
Ex. cipher_text('d') returns 'a'.  
Special cases: same as text_cipher

**void encode_line(char \*src)**
Takes a string of ascii characters and shifts all of them to their caesar cipher equivalent.  
Ex. "Julius Caesar" becomes "Mxolxv Fdhvdu".

**void decode_line(char \*src)**
Takes a string of caesar cipher text and translates it back to its original form.  
Ex. "Mxolxv Fdhvdu" becomes "Julius Caesar".

**unsigned int encode_to_file(char \*dest, char \*src, unsigned int max_len)**
Reads lines from src and translates them into caesar cipher, assuming each line in src is no more than max_len characters long.

**unsigned int decode_to_file(char \*dest, char \*src, unsigned int max_len)**
Reads lines from src and translates them from caesar cipher back into their original form, assuming each line in src is no more than max_len characters long.

## Check it out!
Download the repo. Use the Makefile in the Terminal: run 'make main', then run './main'.  
For source file use "text.txt" and for target file use "cipher.txt".

Enjoy! :tada:

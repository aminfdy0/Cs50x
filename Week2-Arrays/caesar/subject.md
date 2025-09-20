# PROBLEM TO SOLVE
Supposedly, Caesar (yes, that Caesar) used to “encrypt” (i.e., conceal in a reversible way) confidential messages by shifting each letter therein by some number of places. For instance, he might write A as B, B as C, C as D, …, and, wrapping around alphabetically, Z as A. And so, to say HELLO to someone, Caesar might write IFMMP instead. Upon receiving such messages from Caesar, recipients would have to “decrypt” them by shifting letters in the opposite direction by the same number of places.

The secrecy of this “cryptosystem” relied on only Caesar and the recipients knowing a secret, the number of places by which Caesar had shifted his letters (e.g., 1). Not particularly secure by modern standards, but, hey, if you’re perhaps the first in the world to do it, pretty secure!

Unencrypted text is generally called plaintext. Encrypted text is generally called ciphertext. And the secret used is called a key.

To be clear, then, here’s how encrypting ```HELLO``` with a key of 1 yields ```IFMMP```

More formally, Caesar’s algorithm (i.e., cipher) encrypts messages by “rotating” each letter by 𝑘 positions. More formally, if 𝑝 is some plaintext (i.e., an unencrypted message), 𝑝𝑖 is the 𝑖𝑡⁢ℎ character in 𝑝, and 𝑘 is a secret key (i.e., a non-negative integer), then each letter, 𝑐𝑖, in the ciphertext, 𝑐, is computed as

 ```𝑐𝑖=(𝑝𝑖+𝑘) % 26```
wherein % 26 here means “remainder when dividing by 26.” This formula perhaps makes the cipher seem more complicated than it is, but it’s really just a concise way of expressing the algorithm precisely. Indeed, for the sake of discussion, think of A (or a) as 0, B (or b) as 1, …, H (or h) as 7, I (or i) as 8, …, and Z (or z) as 25. Suppose that Caesar just wants to say ```Hi``` to someone confidentially using, this time, a key, 𝑘, of 3. And so his plaintext, 𝑝, is ```Hi```, in which case his plaintext’s first character, 𝑝0, is H (aka 7), and his plaintext’s second character, 𝑝1, is ```i``` (aka 8). His ciphertext’s first character, 𝑐0, is thus ```K```, and his ciphertext’s second character, 𝑐1, is thus ```L```. Make sense?

In a file called ```caesar.c``` in a folder called ```caesar```, write a program that enables you to encrypt messages using Caesar’s cipher. At the time the user executes the program, they should decide, by providing a command-line argument, what the key should be in the secret message they’ll provide at runtime. We shouldn’t necessarily assume that the user’s key is going to be a number; though you may assume that, if it is a number, it will be a positive integer

```
caesar/ $ ./caesar 
Usage: ./caesar key
```
```
caesar/ $ ./caesar 1 2 3
Usage: ./caesar key
```
```
caesar/ $ ./caesar 5x
Usage: ./caesar key
```
```
caesar/ $ ./caesar 13
plaintext: FDY
ciphertext: SQL
```
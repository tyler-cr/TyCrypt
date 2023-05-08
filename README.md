# SimpleCrypto- The standard update v2

This branch will begin the implementation of adding 'std' and removing 'using namespace' throughout the code.

5/7/22  - Added comments explaining each function
        - NOTE: Ciphers and encrypted messages are typically formatted without spaces, punction, etc. While some of the functions
                may currently be implemented to handle that, I plan on later creating a universal "strip" function that changes a
                string through it's address removing all of said stuff for formatting consistency.
        - DEVELOPMENT: 
                Considering creating a 'strip' function that given a string, removes anything that isnt alphanumeric / just alphabetic

                Substitution has both encryption and decryption built into the same function. Considering implementation for other ciphers
                for consistency.

                May create a substitution cipher generator, similar to nihilist cipher.  For consistency. Don't need for shift, because that's literally just a rand()%25 thing. 

## CREATED BY TYLER CRIMANDO

Free for personal and professional use

Some simple forms of cryptography!

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    // break if no key argument provided (or too many arguments)
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // declare key length variable
    int key_len = strlen(argv[1]);

    // break if not all characters are numeric
    int invalid_characters = 0;

    for (int i = 0; i < key_len; i++)
    {
        if (!(argv[1][i] >= 48 && argv[1][i] <= 57))
        {
            invalid_characters++;
        }
    }

    if (invalid_characters > 0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // convert key to integer
    int key = atoi(argv[1]);

    // get string and assign it to string variable plaintext
    string plaintext = get_string("plaintext: ");

    // declare text length variable
    int text_len = strlen(plaintext);
    
    // initiate ciphertext variable
    int ciphertext[text_len];
    
    // cipher each character (or leave untouched if non-alphabetical) and add it to ciphertext
    for (int i = 0; i < text_len; i++)
    {
        if (plaintext[i] >= 65 && plaintext[i] <= 90) // if upper case
        {
            // get the integer value of the character in plaintext, subtract 65 so 0 = A, add the key, modulo 26 and then add the 65 back
            ciphertext[i] = ((int) plaintext[i] - 65 + key) % 26 + 65;
        }
        else if (plaintext[i] >= 97 && plaintext[i] <= 122) // if lower case
        {
            // similar to the above, but switch 65 for 97 for lower case equivalent
            ciphertext[i] = ((int) plaintext[i] - 97 + key) % 26 + 97;
        }
        else // if non-alphabetical
        {
            ciphertext[i] = plaintext[i];
        }
    }

    // print text that precedes ciphertext
    printf("ciphertext: ");
    
    // print cipher text
    for (int i = 0; i < text_len; i++)
    {
        printf("%c", ciphertext[i]);
    }
    
    // print new line
    printf("\n");
}
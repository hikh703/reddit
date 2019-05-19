#include <cs50.h>
#include <stdio.h>

string cypher(string plaintext, int key);

int main(int argc, string argv[])
{
    if(argc != 2)
    {
        printf("Usage: ./caesar key");
        return 1;
    }
    
    int key = atoi(argv[1]);
    
    if(key = 0)
    {
        printf("The key must be an int");
        return 2; //atoi return 0 if we give text, and if the user put 0 as a key there is no reason to use the program
    }
    string plaintext = get_string("Plaintext: ");
    string ciphertext = cypher(plaintext, key);
    printf("ciphertext: %s\n",ciphertext);
    return 0;
    
}

string cypher(string plaintext, int key) // cypher the text
{
    int index = 0;
    while(plaintext[index] != '\0')
    {
        if((plaintext[index] >= 65 && plaintext[index] <= 90) || (plaintext[index] >= 97 && plaintext[index] <= 122))
        {
            int tmp = plaintext[index];
            if(tmp <= 90)
            {
                tmp = tmp - 65;
                plaintext[index] = 65 + ((tmp + key) % 26);
            }
            else
            {
                tmp = tmp - 97;
                plaintext[index] = 97 + ((tmp + key) % 26);
            }
            index += 1;
        }
        else
        {
            index += 1;
        }
    }
    return plaintext;
}

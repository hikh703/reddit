#include <cs50.h>
#include <stdio.h>
#include <crypt.h>
#include <string.h>

void compteur(char array[5]);

int main(int argc, string argv[])
{
    char array[6] = {'a','\0','\0','\0','\0','\0'};
    array[5] = '\0';
    char salt[3] = {argv[1][0],argv[1][1],'\0'}; //the two first char of the argv[1]
    
    while(array[4] != 122)
    {
        for(int i = 65; i <= 122; i++)
        {
            array[0] = i;  
            
            if(strcmp(argv[1], crypt(array,salt)) == 0)
            {
                printf("%s\n",array);
                return 0;   
            }
            
            if(argc != 2)
            {
                printf("Your input should be ./program hashedpasseword");
                return 1;
            }
        }
        compteur(array);
    }
    printf("Could not find the passeword"); //if we are going out of the while loop that's mean that we try all the possibilities for an array of 5 chars
    return 2;
}

//change the characters in the array starting fron array[1], array[0] is changed in the main function
void compteur(char array[5])
{
    for(int i = 0; i < 4; i++)
    {
        if (array[i] == 122)
        {
            array[i] = 65;
            
            if(array[i +1] <= 65 || array[i +1] >= 122)
            {
                array[i+1] = 65;
            }
            array[i+1] += 1;
        }  
    }
}

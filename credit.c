#include <cs50.h>
#include <stdio.h>

int nbr_digit(long n);
int mult_sum(long n, int number_digit);
void card(long n, int number_digit);

int main(void)
{

    long input = get_long("Number: ");
    int number = nbr_digit(input);
    int sum = mult_sum(input,number);
    if (sum % 10 == 0)
    {
        card(input,number);
        return 0;
    }
    else
    {
        printf("INVALID\n");
        return 0;
    }
        
        
        
    
    
}

int nbr_digit(long n)
{
    int nbr = 0;
    while (n != 0)
    {
        n = n / 10;
        nbr ++;
    }
    return nbr;
}

int mult_sum(long n, int number_digit)
{
    int sum = 0;
    
    for(int i = 0; i < number_digit; i++)
    {
        int mult = 0;
        if (i % 2 ==0)
        {
            sum += n % 10;
            n /= 10;
        }
        else
        {
            mult += (n%10) * 2;
            if (mult > 9)
            {
                sum += mult % 10;
                sum += mult / 10;
            }
            else
            {
                sum += mult;
            }
            n /= 10;
        }
    }
    return sum;
}

void card(long n, int number_digit)
{
    int first_digit;
    int first_second_digit;
    for(int i = 0; i < number_digit; i++)
    {
        n /= 10;
        if(i == number_digit - 3)
        {
            first_second_digit = n;
        }
        else if(i == number_digit - 2)
        {
            first_digit = n;
        }
    }
    if (number_digit == 15 && (first_second_digit == 34 || first_second_digit == 37))
    {
        printf("AMEX\n");
    }

    else if (number_digit == 16 && (first_second_digit == 51 || first_second_digit == 52 || first_second_digit == 53 || first_second_digit == 54 || first_second_digit == 55))
    {
        printf("MASTERCARD\n");
    }
    else if ((number_digit == 13 || number_digit == 16) && first_digit == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}



#include <cs50.h>
#include <stdio.h>

void conca(string s, int n);
void pyramide(int n);

int main(void)
{
    while (true)
    {
        int input = get_int("How tall should the pyramid be: \n");
        if (input < 9 && input > 0)
        {
            pyramide(input);
            return 0;
        }
    }
}

void conca(string s, int n)
{
    for(int i = 0; i <= n; i++)
    {
        printf("%s",s);
    }
}
    
void pyramide(int n)
{
    string bloc = "#";
    string space = " ";
    string middle = "  ";
    for(int i = 0; i < n; i ++)
    {
        conca(space, n - i);
        conca(bloc, i);
        printf("%s",middle);
        conca(bloc,i);
        printf("\n");
        
    }
}
    


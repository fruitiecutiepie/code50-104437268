#include <cs50.h>
#include <stdio.h>

void meow(int n);

int main(void)
{
    {
        meow(get_int("How many times do you want to \"meow\"? "));
    }
}

void meow(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("meow\n");
    }
}
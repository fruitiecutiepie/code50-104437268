#include <stdio.h>

void meow(void)
{
    printf("meow\n");
}

int main(void)
{
    //int i = 0;
    // while (i < 3)
    {
        //printf("meow\n");
        //i += 1;
    }

    for (int i = 0; i < 3; i++)
    {
        meow();
    }
}
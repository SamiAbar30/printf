#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int len;
    int len2;

    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    printf("Let's try to printf a simple sentence %i %i .\n",len,len2);
    _printf("Let's try to printf a simple sentence.%c \n",'c');
    printf("Let's try to printf a simple sentence.%c \n",'c');
    _printf("Let's try to printf a simple sentence.%s \n","sami");
    printf("Let's try to printf a simple sentence.%s \n","sami");
    return (0);
}

#include <stdio.h>
#include "printf.h"

int sum(int n, ...)
{
    int result = 0;
    va_list factor;         //указатель va_list
    va_start(factor, n);    // устанавливаем указатель
    for(int i=0;i<n; i++)
    {
        result += va_arg(factor, int);  // получаем значение текущего параметра типа int
    }
    va_end(factor); // завершаем обработку параметров
    return result;
}


int     summ(int count, ...)
{
    int     *param_ptr;
    int     result = 0;

    while (count >= 0)
    {
        param_ptr = &count;
        result += *param_ptr;
        count--;
    }
    return(result);
}

void    display(char* format, ...)
{
    int d;
    double f;
    va_list factor;         // указатель на необязательный параметр
    va_start(factor, format);   // устанавливаем указатель

    for(char *c = format;*c; c++)
    {
        if(*c!='%')
        {
            printf("%c", *c);
            continue;
        }
        switch(*++c)
        {
            case 'd':
                d = va_arg(factor, int);
                printf("%d", d);
                break;
            case 'f':
                f = va_arg(factor, double);
                printf("%.2lf", f);
                break;
            default:
                printf("%c", *c);
        }
    }
    va_end(factor);
}

int     main(void)
{
    int test = sum(10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
    int res = summ(10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
    printf("Моя функция :%d\n", res);
    printf("Тестовая функция :%d\n", test);
    printf("---------------->\n");
    display("Age:%d \t Weight:%f", 21, 76.4);
}

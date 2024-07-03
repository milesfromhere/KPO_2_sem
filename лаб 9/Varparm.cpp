#include "Varparm.h"

int Varparm::ivarparm(int a, ...)
{
    int mul = 1;
    va_list args; 
    va_start(args, a); 
  
    for (int i = 1; i <= a; i++)
    {
        int number = va_arg(args, int);
        if (number == 0)
            break;
        mul = mul * number;
    }
 
    va_end(args);
    return mul;
}

int Varparm::svarparm(short b, ...)
{
    va_list args;
    va_start(args, b);

    int max = 0;

    for (int i = 1; i <= b; i++)
    {
        int number = va_arg(args, short);
        if (max < number)
            max = number;
    }   

    va_end(args);
    return max;
}

double Varparm::fvarparm(float a, ...)
{
    float mul = 0.0;
    va_list args;
    va_start(args, a);

    for (int i = 0; i <= a; i++)
    {
        float number = va_arg(args, double);
        mul += number;
    }

    va_end(args);
    return mul+a;
}
double Varparm::dvarparm(double a, ...)
{
    double mul = 0.0;
    va_list args;
    va_start(args, a);

    for (int i = 0; i <= a; i++)
    {
        double number = va_arg(args, double);
        mul += number;
    }

    va_end(args);
    return mul + a;
}

int main()
{
    setlocale(LC_ALL, "ru");

    std::cout << "Произведение: " << Varparm::ivarparm(1, 10) << std::endl;
    std::cout << "Максимальное число: " << Varparm::svarparm(4, 0, 1, 3, 2) << std::endl;
    std::cout << "Сумма: " << Varparm::fvarparm(2.14, 0.12, 1.124, 3.12, FLT_MAX_10_EXP) << std::endl;
    std::cout << "Сумма2: " << Varparm::dvarparm(2.1454, 0.132, 3.124, 5.1345, DBL_MAX_10_EXP) << std::endl;
}


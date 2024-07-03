#include <iostream>

int defaultparm(int a, int b, int c, int a1, int a2, int d = 6, int e = 7)
{
    int sum = a + b + c + d + e + a2 + a1;

    int average = sum / 7;
    return average;
}

int main() 
{
    setlocale(LC_ALL, "ru");
    std::cout << "Среднее арифметическое: " << defaultparm(1, 2, 3, 4, 5) << std::endl;
    std::cout << "Среднее арифметическое: " << defaultparm(1, 2, 3, 4, 5, 100, 1001) << std::endl;
    return 0;
}


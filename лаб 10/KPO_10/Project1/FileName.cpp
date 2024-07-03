#include <iostream>

int main()
{
    auto checkPositive = [](int n) { return n > 0; };
    setlocale(LC_ALL, "ru");
    int number;

    std::cout << "Введите число: ";
    std::cin >> number;

    if (checkPositive(number))
        std::cout << "Число положительное." << std::endl;

    else
        std::cout << "Число не положительное." << std::endl;

    return 0;
}

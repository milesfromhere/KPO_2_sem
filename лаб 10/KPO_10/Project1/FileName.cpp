#include <iostream>

int main()
{
    auto checkPositive = [](int n) { return n > 0; };
    setlocale(LC_ALL, "ru");
    int number;

    std::cout << "������� �����: ";
    std::cin >> number;

    if (checkPositive(number))
        std::cout << "����� �������������." << std::endl;

    else
        std::cout << "����� �� �������������." << std::endl;

    return 0;
}

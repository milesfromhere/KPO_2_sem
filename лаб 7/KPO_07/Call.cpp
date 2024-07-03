#include <iostream>
#include "Call.h"

int main()
{
	setlocale(LC_ALL, "ru");

    int result_cdecl = Call::cdeclFunction(1, 2, 3);
    std::cout << "��������� ������ cdeclFunction: " << result_cdecl << std::endl;

   
    int a = 2, b = 3, c = 4;    
    int result_stdcall = Call::stdcallFunction(a, b, c);
    std::cout << "��������� ������ stdcallFunction: " << result_stdcall << std::endl;

    int result_fastcall = Call::fastcallFunction(1, 2, 3, 4);
    std::cout << "��������� ������ fastcallFunction: " << result_fastcall << std::endl;

	return 0;
}
#include "stdafx.h"
#include "macros.h"
#include "C:\Users\nikit\OneDrive\Рабочий стол\SE_Lab06S\SE_Lab06L\Dictionary.h"
#include "C:\Users\nikit\OneDrive\Рабочий стол\SE_Lab06S\SE_Lab06L\SE_Lab06L.cpp"

int main()
{
    setlocale(LC_ALL, "ru");

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int choice, size = 0, size_num = 1, id = 0;
    char name[DICTNAMEMAXSIZE];

    Dictionary::Instance new_dictionary[DICTMAXSIZE];
    Dictionary::Entry inst[ENTRYNAMEMAXSIZE];
    Dictionary::menu();

    std::cout << "Выберите действие: ";
    std::cin >> choice;

    do
    {
        try
        {
            switch (choice)
            {
            case 1:
            {
                new_dictionary[size] = Dictionary::Create(name, size);
                size++;
                break;
            }

            case 2:
                Dictionary::AddEnrty(new_dictionary, inst, size_num);
                size_num++;
                break;

            case 3:
                Dictionary::DelEntry(new_dictionary, id, size_num);
                break;

            case 4:
                Dictionary::GetEntry(new_dictionary, id, size_num);
                break;

            case 5:
                Dictionary::UpdEntry(new_dictionary, inst, size_num);
                std::cout << "Элемент изменен!!!" << std::endl;
                break;

            case 6:
                Dictionary::Delete(new_dictionary);
                std::cout << "Все элементы словаря удалены" << std::endl;
                break;

            case 7:
                Dictionary::Print(new_dictionary, size);
                break;

            }
        }
        catch (const std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }

        std::cout << "Выберите действие: ";
        std::cin >> choice;

    } while (choice != 0);

    TEST_DICTIONARY;

    return 0;
}
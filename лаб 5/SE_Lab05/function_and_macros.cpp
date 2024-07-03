#include "stdafx.h"
#include "macros.h"
#pragma warning(disable : 4996)

void Dictionary::menu()
{
	std::cout << "1 - Создать экземпляр словаря " << std::endl;
	std::cout << "2 - Добавить элемент словаря " << std::endl;
	std::cout << "3 - Удалить элемент словаря " << std::endl;
	std::cout << "4 - Получить элемент словаря " << std::endl;
	std::cout << "5 - Изменить элемент словаря " << std::endl;
	std::cout << "6 - Удалить элементы словаря " << std::endl;
	std::cout << "7 - Распечатать элементы словаря " << std::endl;
	std::cout << "0 - Выход " << std::endl << std::endl;
}
//10. Место в программе, где используется память из кучи
//14. Пространство имен применяется в коде через префикс `Dictionary::`
Dictionary::Instance Dictionary::Create(char name[DICTNAMEMAXSIZE], int size)
{
	Instance new_dictionary;
	Instance fake;
	new_dictionary.dictionary = new Entry[DICTMAXSIZE];

	std::cout << "Введите название нового словаря: ";
	std::cin >> name;
	strcpy(new_dictionary.name, name);

	if (strlen(name) > DICTNAMEMAXSIZE)
	{
		throw std::length_error(THROW01);
		return fake;
	}

	if (size >= DICTMAXSIZE)
	{
		throw std::overflow_error(THROW02);
		return fake;
	}

	return new_dictionary;
}

void Dictionary::AddEnrty(Instance inst[], Entry ed[], int size_num)
{
	int i;

	std::cout << "Выберите для какого словаря вы хотите вписать элементы: ";
	std::cin >> i;
	i--;

	if (i < 0 || i >= size_num)
	{
		std::cout << "Недопустимый номер словаря" << std::endl;
		return;
	}

	if (inst[i].maxsize >= DICTMAXSIZE)
	{
		throw std::exception(THROW03);
		return;
	}


	std::cout << "Введите имя: ";
	std::cin >> inst[i].dictionary[inst[i].maxsize].name;

	std::cout << "Введите id: ";
	std::cin >> inst[i].dictionary[inst[i].maxsize].id;

	for (int j = 0; j < inst[i].maxsize; j++)
	{
		if (inst[i].dictionary[j].id == inst[i].dictionary[inst[i].maxsize].id)
			throw std::exception(THROW04);
	}

	inst[i].maxsize++;
}

void Dictionary::UpdEntry(Instance inst[], Entry new_ed[], int size_num)
{
	int i, choice_number;

	std::cout << "Выберите номер словаря, элемент которого вы хотите изменить: ";
	std::cin >> i;
	i--;

	std::cout << "Выберите номер элемента: ";
	std::cin >> choice_number;
	choice_number--;

	if (choice_number < 1 && choice_number > inst[i].maxsize)
	{
		throw std::exception(THROW07);
		return;
	}



	if (i < 0 || i >= size_num)
	{
		std::cout << "Недопустимый номер словаря" << std::endl;
		return;
	}


	int new_id;
	bool id_exists = false;

	std::cout << "Введите id: ";
	std::cin >> new_id;


	for (int j = 0; j < inst[i].maxsize; j++)
	{
		if (j != choice_number && inst[i].dictionary[j].id == new_id)
		{
			id_exists = true;
			throw std::overflow_error(THROW08);
			return;
			break;
		}
	}

	if (!id_exists)
		inst[i].dictionary[choice_number].id = new_id;

}

Dictionary::Entry Dictionary::GetEntry(Instance inst[], int id, int size_num)
{
	Entry element;
	int i;

	std::cout << "Выберите номер словаря, элемент которого вы хотите найти: ";
	std::cin >> i;
	i--;

	if (i < 0 || i >= size_num)
	{
		std::cout << "Недопустимый номер словаря" << std::endl;
		return element;
	}
	std::cout << "Введите id для поиска элемента: ";
	std::cin >> id;

	for (int j = 0; j < inst[i].maxsize; j++)
	{
		if (inst[i].dictionary[j].id == id)
		{
			std::cout << inst[i].dictionary[j].name << std::endl;
			std::cout << inst[i].dictionary[j].id << std::endl << std::endl;
			return element;
		}
	}

	throw std::exception(THROW05);
}

void Dictionary::Print(Instance d[], int size)
{

	for (int i = 0; i < size; i++)
	{
		std::cout << "------------ " << d[i].name << " ------------ " << std::endl;
		for (int j = 0; j < d[i].maxsize; j++)
		{
			std::cout << d[i].dictionary[j].name << std::endl;
			std::cout << d[i].dictionary[j].id << std::endl << std::endl;
		}
	}


}

void Dictionary::DelEntry(Instance inst[], int id, int size_num)
{
	int i;

	std::cout << "Выберите для какого словаря вы хотите вписать элементы: ";
	std::cin >> i;
	i--;

	if (i < 0 || i >= size_num)
	{
		std::cout << "Недопустимый номер словаря" << std::endl;
		return;
	}

	if (inst[i].maxsize >= DICTMAXSIZE)
	{
		std::cout << "Слишком много элементов в словаре" << std::endl;
		return;
	}
	std::cout << "Введите id для удаления элемента: ";
	std::cin >> id;

	for (int j = 0; j < inst[i].maxsize; j++)
	{
		if (inst[i].dictionary[j].id == id)
		{

			inst[i].dictionary[j] = inst[i].dictionary[inst[i].maxsize - 1];
			inst[i].maxsize--;
			std::cout << "Элемент успешно удален" << std::endl;
			return;
		}
	}

	throw std::exception(THROW06);

}

void Dictionary::Delete(Instance d[])
{
	int i;
	std::cout << "Выберите номер словаря для удаления: ";
	std::cin >> i;
	i--;

	if (i < 0 || i >= DICTMAXSIZE)
	{
		std::cout << "Недопустимый номер словаря" << std::endl;
		return;
	}

	delete[] d[i].dictionary;
	d[i].dictionary = nullptr;
	d[i].maxsize = 0;
}

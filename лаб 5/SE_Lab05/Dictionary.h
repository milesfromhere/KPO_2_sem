#include <cstring>
#include <iostream>

#define DICTNAMEMAXSIZE 20
#define DICTMAXSIZE 10
#define ENTRYNAMEMAXSIZE 30

#define THROW01 "Create: превышен размер имени словаря"
#define THROW02 "Create: превышен размер максимальной емкости словаря"
#define THROW03 "AddEntry: переполнение словаря"
#define THROW04 "AddEntry: дублирование идентификатора"
#define THROW05 "GetEntry: не найден элемент"
#define THROW06 "DelEntry: не найден элемент"
#define THROW07 "UpdEntry: не найден элемент"
#define THROW08 "UpdEntry: дублирование идентификатора"

namespace Dictionary
{

	struct Entry
	{
		int id;
		char name[ENTRYNAMEMAXSIZE];
	};

	struct Instance
	{
		char name[DICTNAMEMAXSIZE];
		int maxsize = 0;
		Entry* dictionary;
	};

	void menu();
	Instance Create(char name[DICTNAMEMAXSIZE], int size);
	void AddEnrty(Instance inst[], Entry ed[], int size_num);
	void DelEntry(Instance inst[], int id, int size_num);
	void UpdEntry(Instance inst[], Entry new_ed[], int size_num);
	Entry GetEntry(Instance inst[], int id, int size_num);
	void Print(Instance d[], int size);
	void Delete(Instance d[]);

}

#if defined(TEST_DICTIONARY) + defined(TEST_CREATE_01) + defined(TEST_CREATE_02) + defined(TEST_ADDENTRY_03) + defined(TEST_ADDENTRY_04) + defined(TEST_GETENTRY_05) + defined(TEST_DEL_ENTRY_06) + defined(TEST_UPD_ENTRY_07) + defined(TEST_UPD_ENTRY_08) > 1
#error "Можно использовать только один макрос из списка"
#endif

/*
13 Условная компиляция применяется в функции `main` с помощью директив `#ifdef`,
`#ifndef`, `#if`, `#elif`, `#else` и `#endif`, чтобы определить, будет ли включен код,
зависящий от определения макросов.
*/
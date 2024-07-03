#include <cstring>
#include <iostream>

#define DICTNAMEMAXSIZE 20
#define DICTMAXSIZE 10
#define ENTRYNAMEMAXSIZE 30

#define THROW01 "Create: �������� ������ ����� �������"
#define THROW02 "Create: �������� ������ ������������ ������� �������"
#define THROW03 "AddEntry: ������������ �������"
#define THROW04 "AddEntry: ������������ ��������������"
#define THROW05 "GetEntry: �� ������ �������"
#define THROW06 "DelEntry: �� ������ �������"
#define THROW07 "UpdEntry: �� ������ �������"
#define THROW08 "UpdEntry: ������������ ��������������"

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
#error "����� ������������ ������ ���� ������ �� ������"
#endif

/*
13 �������� ���������� ����������� � ������� `main` � ������� �������� `#ifdef`,
`#ifndef`, `#if`, `#elif`, `#else` � `#endif`, ����� ����������, ����� �� ������� ���,
��������� �� ����������� ��������.
*/
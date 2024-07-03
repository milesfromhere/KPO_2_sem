// pch.h: это предварительно скомпилированный заголовочный файл.
// Перечисленные ниже файлы компилируются только один раз, что ускоряет последующие сборки.
// Это также влияет на работу IntelliSense, включая многие функции просмотра и завершения кода.
// Однако изменение любого из приведенных здесь файлов между операциями сборки приведет к повторной компиляции всех(!) этих файлов.
// Не добавляйте сюда файлы, которые планируете часто изменять, так как в этом случае выигрыша в производительности не будет.

#ifndef PCH_H
#define PCH_H
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

#endif //PCH_H

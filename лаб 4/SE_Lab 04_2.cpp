#include <iostream>
#include <string>

using Format = std::string;
using Size = int;
using Title = std::string;
using Author = std::string;
using ForChildren = bool;
using PageCount = int;
using UploadDate = std::string; 

struct ElectronicLibrary 
{
    Format format;
    Size fileSize;
    Title bookTitle;
    Author bookAuthor;
    ForChildren isForChildren;
    PageCount pageCount;
    UploadDate uploadDate;

    void printInfo() const {
        std::cout << "Информация о книге:\n"
            << "Формат: " << format << "\n"
            << "Размер файла: " << fileSize << " КБ\n"
            << "Название: " << bookTitle << "\n"
            << "Автор: " << bookAuthor << "\n"
            << "Для детей: " << (isForChildren ? "Да" : "Нет") << "\n"
            << "Количество страниц: " << pageCount << "\n"
            << "Дата загрузки: " << uploadDate << "\n";
    }

    bool operator<(const ElectronicLibrary& other) const {
        return fileSize < other.fileSize;
    }
};

int main() 
{
    setlocale(LC_ALL, "rus");

    ElectronicLibrary book;
    book.format = "pdf";
    book.fileSize = 1024;
    book.bookTitle = "Книга 1";
    book.bookAuthor = "А.С.Пушкин";
    book.isForChildren = false;
    book.pageCount = 300;
    book.uploadDate = "1830-04-17";

    book.printInfo();

    ElectronicLibrary anotherBook;
    anotherBook.format = "txt";
    anotherBook.fileSize = 512;
    anotherBook.bookTitle = "Книга 2";
    anotherBook.bookAuthor = "М.Ю.Лермонтов";
    anotherBook.isForChildren = true;
    anotherBook.pageCount = 200;
    anotherBook.uploadDate = "1830-04-15";

    anotherBook.printInfo();

    if (book < anotherBook) {
        std::cout << "Размер файла первой книги меньше размера файла второй книги.\n";
    }
    else {
        std::cout << "Размер файла первой книги больше или равен размеру файла второй книги.\n";
    }

    return 0;
}
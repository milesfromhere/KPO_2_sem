#include <iostream>

typedef unsigned char Day; 
typedef unsigned char Month; 
typedef unsigned short Year; 

struct Date 
{
    Day dd;
    Month mm;
    Year yyyy;
    
    bool operator<(const Date& other) const 
    {
        if (yyyy != other.yyyy)
            return yyyy < other.yyyy;
        if (mm != other.mm)
            return mm < other.mm;
        return dd < other.dd;
    }
    
    bool operator>(const Date& other) const {
        return other < *this;
    }
    
    bool operator==(const Date& other) const {
        return yyyy == other.yyyy && mm == other.mm && dd == other.dd;
    }
};

int main() {
    setlocale(LC_ALL, "rus");
    Date date1 = { 7,1,1980 };
    Date date2 = { 7,2,1993 };
    Date date3 = { 7,1,1980 };

    if (date1 < date2)
        std::cout << "истина" << std::endl;
    else
        std::cout << "ложь" << std::endl;

    if (date1 > date2)
        std::cout << "истина" << std::endl;
    else
        std::cout << "ложь" << std::endl;

    if (date1 == date2)
        std::cout << "истина" << std::endl;
    else
        std::cout << "ложь" << std::endl;

    if (date1 == date3)
        std::cout << "истина" << std::endl;
    else
        std::cout << "ложь" << std::endl;

    return 0;
}
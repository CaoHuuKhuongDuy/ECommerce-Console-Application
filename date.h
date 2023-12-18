#pragma once 

#include <iostream>
#include <fstream>
#include <ctime>

struct Date {
    int day, month, year;
    friend std::istream& operator>>(std::istream& is, Date& date);
    friend std::ostream& operator<<(std::ostream& os, const Date& date);
    bool operator==(const Date& date) const {
        return day == date.day && month == date.month && year == date.year;
    }
};

class CurrentDateProvider {
public:
    static Date getCurrentDate();
};


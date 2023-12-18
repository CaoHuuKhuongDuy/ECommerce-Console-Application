#include "date.h"

std::istream& operator>>(std::istream& is, Date& date) {
    is >> date.day >> date.month >> date.year;
    return is;
}

std::ostream& operator<<(std::ostream& os, const Date& date) {
    os << date.day << " " << date.month << " " << date.year;
    return os;
}

Date CurrentDateProvider::getCurrentDate() {
    std::time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);

    Date currentDate;
    currentDate.day = now->tm_mday;
    currentDate.month = now->tm_mon + 1;  // Months are 0-indexed, so add 1
    currentDate.year = now->tm_year + 1900;  // Years are years since 1900

    return currentDate;
}
    
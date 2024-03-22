#include "CheckDate.h"

bool CheckDate::leapYear(int year) {
    if (year % 4 != 0) return false;
    if (year % 100 != 0) return true;
    if (year % 400 != 0) return false;
    return true;
}

bool CheckDate::incorrectDate(int day, int month, int year) {
    if (day > 31 || month > 12 || day < 1 || month < 0 || year < MIN_ALLOWED_YEAR || year > MAX_ALLOWED_YEAR) return true;
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        if (day > 30) {
            return true;
        }
    }
    if (month == 2) {
        if (leapYear(year) && (day > 29)) {
            return true;
        }
        if (!leapYear(year) && (day > 28)) {
            return true;
        }
    }
    return false;
}
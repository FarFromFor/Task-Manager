#ifndef MAIN_CPP_CHECKDATE_H
#define MAIN_CPP_CHECKDATE_H

#include "Event.h"

using namespace std;
/**
 * @brief class for working with date \n
 * Implemented functions:
 *  leapYear(int year)
 *  incorrectDate(int day, int month, int year)
 */
class CheckDate {
public:
    //! checks if year is leap
    bool static leapYear(int year);

    //! checks if date is correct
    bool static incorrectDate(int day, int month, int year);
};

#endif //MAIN_CPP_CHECKDATE_H

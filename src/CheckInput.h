#ifndef MAIN_CPP_CHECKINPUT_H
#define MAIN_CPP_CHECKINPUT_H

#include <iostream>
#include <limits>
#include "Config.h"
using namespace std;
/**
 * @brief class for working with input \n
 * Implemented functions:
 *  numberFailInt(int &tmp, int from, int to)
 *  stringInputFail(string &str)
 *  numberInputFail(int &comm, int from, int to)
 */
class CheckInput {
public:
    //! check if number is in interval from "from" to "to:
    bool static numberFailInt(int &tmp, int from, int to);

    //! read string from cin with length checking
    bool static stringInputFail(string &str);

    //! read int from cin and check if number is in interval from "from" to "to:
    bool static numberInputFail(int &comm, int from, int to);
};


#endif //MAIN_CPP_CHECKINPUT_H

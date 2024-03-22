#ifndef MAIN_CPP_ACTIVITYTOPICKWITH_H
#define MAIN_CPP_ACTIVITYTOPICKWITH_H

#include "Activity.h"

/**
 * @brief Child class for Activity, parent class for Party and Task \n
 * Added attributes:
 *  vector<string> toPickWith \n
 * Implemented functions:
 *  printThings(ostream &out)
 */
class ActivityToPickWith : public Activity {
public:
    //! prints things to pick with
    void printThings(ostream &out) const;

    //! things to pick with
    vector<string> toPickWith;
};


#endif //MAIN_CPP_ACTIVITYTOPICKWITH_H

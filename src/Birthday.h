#ifndef MAIN_CPP_BIRTHDAY_H
#define MAIN_CPP_BIRTHDAY_H

#include "Activity.h"

/**
 * @brief Child class for Activity. Represents event "Birthday" \n
 *  Implemented functions:
 *  clone()
 *  print(ostream &out)
 *  write(ostream &out)
 */
class Birthday : public Activity {
public:
    //! event constructor
    Birthday();

    //! returns pointer on new allocated meeting
    Event *clone() const override;

    //! print event to "out"
    void print(ostream &out) const override;

    //! dress code for this event
    void write(ostream &out) const override;
};


#endif //MAIN_CPP_BIRTHDAY_H

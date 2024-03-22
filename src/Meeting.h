#ifndef MAIN_CPP_MEETING_H
#define MAIN_CPP_MEETING_H

#include "Activity.h"

/**
 * @brief Child class for Activity. Represents event "Meeting" \n
 * Added attributes:
 *  string dressCode \n
 * Implemented functions:
 *  clone()
 *  print(ostream &out)
 *  write(ostream &out)
 */
class Meeting : public Activity {
public:
    //! event constructor
    Meeting();

    //! returns pointer on new allocated meeting
    Event *clone() const override;

    //! print event to "out"
    void print(ostream &out) const override;

    //! write event to "out"
    void write(ostream &out) const override;

    //! dress code for this event
    string dressCode;
};


#endif //MAIN_CPP_MEETING_H

#ifndef MAIN_CPP_REMINDER_H
#define MAIN_CPP_REMINDER_H

#include "Event.h"

/**
 * @brief Child class for Event. Represents event "Reminder" \n
 * Implemented functions:
 *  clone()
 *  getTitle()
 *  getLocation()
 *  getMembers()
 *  getTags()
 *  print(ostream &out)
 *  write(ostream &out)
 */
class Reminder : public Event {
public:
    //! event constructor
    Reminder();

    //! returns pointer on new allocated reminder
    Event *clone() const override;

    //! returns title
    string getTitle() const override;

    //! returns location
    string getLocation() const override;

    //! returns empty vector
    vector<string> getMembers() const override;

    //! returns empty vector
    vector<string> getTags() const override;

    //! print event to "out"
    void print(ostream &out) const override;

    //! write event to "out"
    void write(ostream &out) const override;
};

#endif //MAIN_CPP_REMINDER_H

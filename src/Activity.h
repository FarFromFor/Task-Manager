#ifndef MAIN_CPP_ACTIVITY_H
#define MAIN_CPP_ACTIVITY_H

#include "Event.h"
#include "CheckDate.h"

/**
 * @brief Child class for Event, parent class for Meeting, Birthday, ActivityToPickWith \n
 * Added attributes:
 *  vector<string> members
 *  vector<string> tags
 *  string title
 *  string location \n
 * Implemented functions:
 *  getTitle()
 *  getLocation()
 *  getMembers()
 *  getTags()
 *  printMembers(ostream &out)
 *  printTags(ostream &out)
 *  setTitle(const string & titleIn)
 *  setLocation(const string & locationIn)
 *  writeToFile(ostream &out, int eventNumber)
 */
class Activity : public Event {
public:
    //! returns title
    string getTitle() const override;

    //! returns location
    string getLocation() const override;

    //! returns vector of invited persons
    vector<string> getMembers() const override;

    //! returns vector of tags
    vector<string> getTags() const override;

    //! prints invited persons in out
    void printMembers(ostream &out) const;

    //! prints tags persons in out
    void printTags(ostream &out) const;

    //! sets title
    void setTitle(const string &titleIn);

    //! sets title
    void setLocation(const string &locationIn);

    //! writes event to file
    void writeToFile(ostream &out, int eventNumber) const;

    //! invited persons
    vector<string> members;

    //! tags
    vector<string> tags;

    //event title
    string title;

    //event location
    string location;
};


#endif //MAIN_CPP_ACTIVITY_H

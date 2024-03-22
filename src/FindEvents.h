#ifndef MAIN_CPP_FINDEVENTS_H
#define MAIN_CPP_FINDEVENTS_H
#include "DeleteEvent.h"
#include "ExportEvents.h"
#include "CheckInput.h"
#include "Meeting.h"
/**
 * @brief class for searching for events by attributes and conjunctions \n
 * Implemented functions:
 * findEvents(vector<Event *> &events)
 * findByTag(vector<Event *> &summaryEv, vector<Event *> &tmpEven, string &strTmp, int command)
 * findByPerson(vector<Event *> &summaryEv, vector<Event *> &tmpEven, string &strTmp, int command)
 * findByLocation(vector<Event *> &summaryEv, vector<Event *> &tmpEven, string &strTmp, int command)
 * findByNote(vector<Event *> &summaryEv, vector<Event *> &tmpEven, string &strTmp, int command)
 * findByTitle(vector<Event *> &summaryEv, vector<Event *> &tmpEven, string &strTmp, int command)
 * findByDate(vector<Event *> &summaryEv, vector<Event *> &tmpEven, int command, Event &tmpM)
 */
class FindEvents {
public:
    //! find events by chosen parameters and write into file if needed
    bool findEvents(vector<Event *> &events);

private:
    //! search for events by tag (case sensitive) and add them in vector depending on parameters chosen
    bool findByTag(vector<Event *> &summaryEv, vector<Event *> &tmpEven, string &strTmp, int command);

    //! search for events by invited person (case sensitive) and add them in vector depending on parameters chosen
    bool findByPerson(vector<Event *> &summaryEv, vector<Event *> &tmpEven, string &strTmp, int command);

    //! search for events by location (case sensitive) and add them in vector depending on parameters chosen
    bool findByLocation(vector<Event *> &summaryEv, vector<Event *> &tmpEven, string &strTmp, int command);

    //! search for events by note (case sensitive) and add them in vector depending on parameters chosen
    bool findByNote(vector<Event *> &summaryEv, vector<Event *> &tmpEven, string &strTmp, int command);

    //! search for events by title (case sensitive) and add them in vector depending on parameters chosen
    bool findByTitle(vector<Event *> &summaryEv, vector<Event *> &tmpEven, string &strTmp, int command);

    //! search for events by date and add them in vector depending on parameters chosen
    bool findByDate(vector<Event *> &summaryEv, vector<Event *> &tmpEven, int command, Event &tmpM);
protected:
    ExportEvents ExportEv;
};


#endif //MAIN_CPP_FINDEVENTS_H

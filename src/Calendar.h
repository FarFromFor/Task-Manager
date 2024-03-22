#ifndef MAIN_CPP_CALENDAR_H
#define MAIN_CPP_CALENDAR_H

#include <algorithm>
#include <fstream>
#include <map>
#include "Meeting.h"
#include "Birthday.h"
#include "Party.h"
#include "Task.h"
#include "ShowEvents.h"
#include "Reminder.h"
#include "AddNewEvent.h"
#include "CheckEvent.h"
#include "ImportEvents.h"
#include "FindEvents.h"
#include "DeleteEvent.h"
#include "PrintEvents.h"
#include "ShowWeekEvents.h"
#include "random"
#include <ctime>


/**
 * @brief consummates the whole application \n
 * Added attributes:
 *  FindEv
 *  AddEv
 *  DelEv
 *  ExportEv
 *  ImportEv
 * Implemented functions:
 *  startApplication()
 *  greetings()
 *  exitApplication(bool &exitIn)
 *  printEv(vector<Event*> &events, vector<Event *> &repeatingEvents)
 */
class Calendar {
public:
    //! starts application
    void startApplication();

private:
    //! prints motivational greetings
    void greetings();

    //! finish program and save events
    bool exitApplication(bool &exitIn);

protected:
    //! class for searching for events by attributes and conjunctions
    FindEvents FindEv;

    //! class for adding new event
    AddNewEvent AddEv;

    //! class for deleting events
    DeleteEvent DelEv;

    //! class for exporting events
    ExportEvents ExportEv;

    //! class for importing events
    ImportEvents ImportEv;

    //! class for printing events
    PrintEvents PrintEv;
};

#endif //MAIN_CPP_CALENDAR_H

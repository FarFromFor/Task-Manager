#ifndef MAIN_CPP_IMPORTEVENTS_H
#define MAIN_CPP_IMPORTEVENTS_H

#include "Activity.h"
#include "CheckInput.h"
#include "CheckEvent.h"
#include "Meeting.h"
#include "Birthday.h"
#include "Party.h"
#include "Task.h"
#include "Reminder.h"
#include <random>
#include <algorithm>
#include <fstream>

/**
 * @brief class for importing events \n
 * Implemented functions:
 * importEvents(vector<Event *> &events, const string &fileName)
 * readFromFile(Activity &tmp, ifstream &file)
 * returnState(vector<Event *> &eventsTmp)
 */
class ImportEvents {
public:
    //! import events from file "filename" to temporary vector. If file if broken, dont' import anything
    bool importEvents(vector<Event *> &events, const string &fileName);

private:
    //! read Activity parameters from file and write them into tmp
    bool readFromFile(Activity &tmp, ifstream &file);

    //! delete temporary allocated events
    void returnState(vector<Event *> &eventsTmp);
};


#endif //MAIN_CPP_IMPORTEVENTS_H

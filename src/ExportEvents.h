#ifndef MAIN_CPP_EXPORTEVENTS_H
#define MAIN_CPP_EXPORTEVENTS_H

#include "Activity.h"
#include <fstream>
/**
 * @brief class for exporting events \n
 * Implemented functions:
 * exportEvents(vector<Event *> &events, const string &fileName)
 */
class ExportEvents {
public:
    //! export events into file "fileName"
    bool exportEvents(vector<Event *> &events, const string &fileName);
};

#endif //MAIN_CPP_EXPORTEVENTS_H

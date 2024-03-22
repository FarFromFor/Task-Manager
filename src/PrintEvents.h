#ifndef MAIN_CPP_PRINTEVENTS_H
#define MAIN_CPP_PRINTEVENTS_H

#include <map>
#include "ShowHourEvents.h"
#include "ShowDayEvents.h"
#include "ShowWeekEvents.h"
#include "ShowMonthEvents.h"
#include "ShowAllEvents.h"

class PrintEvents {
public:
    bool printEv(vector<Event *> &events);
};


#endif //MAIN_CPP_PRINTEVENTS_H

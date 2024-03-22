#include "PrintEvents.h"

bool PrintEvents::printEv(vector<Event *> &events) {
    cout << SHOW_FOR << endl;
    cout << SHOW_FOR_OPT1 << endl;
    cout << SHOW_FOR_OPT2 << endl;
    cout << SHOW_FOR_OPT3 << endl;
    cout << SHOW_FOR_OPT4 << endl;
    cout << SHOW_FOR_OPT5 << endl;
    cout << SHOW_FOR_OPT6 << endl;
    cout << SHOW_FOR_OPT7 << endl;
    int command;
    if (CheckInput::numberInputFail(command, 1, 7)) {
        cout << INPUT_FAIL << endl;
        return false;
    }
    if (command == 6) {
        Meeting tmp;
        if (!tmp.setDate()) return false;
        tmp.date.setTime(1, 1);
        cout << SHOW << endl;
        cout << SHOW_OPT1 << endl;
        cout << SHOW_OPT2 << endl;
        cout << SHOW_OPT3 << endl;
        cout << SHOW_OPT4 << endl;
        if (CheckInput::numberInputFail(command, 1, 4)) {
            cout << INPUT_FAIL << endl;
            return false;
        }
        if (command == 4) return false;
        //za napad dekuju panu Danielu Breinerovi
        map<int, ShowEvents *> showTypes = {
                {1, new ShowDayEvents},
                {2, new ShowWeekEvents},
                {3, new ShowMonthEvents},
        };
        ShowEvents *showType = showTypes.at(command);
        showType->showAt(events, tmp);
        for (auto &pair: showTypes) {
            delete pair.second;
        }
        return true;
    }
    if (command == 7) return false;
    map<int, ShowEvents *> showTypes = {
            {1, new ShowHourEvents},
            {2, new ShowDayEvents},
            {3, new ShowWeekEvents},
            {4, new ShowMonthEvents},
            {5, new ShowAllEvents}
    };
    ShowEvents *showType = showTypes.at(command);
    showType->showNow(events);
    for (auto &pair: showTypes) {
        delete pair.second;
    }
    return true;
}
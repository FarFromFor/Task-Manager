#include "Calendar.h"

void Calendar::startApplication() {
    vector<Event *> events;
    bool exit = false;
    greetings();
    int command;
    string strTmp;
    if (!ImportEv.importEvents(events, SAVE_FILE_NAME)) {
        cout << IMPORT_FAIL << endl;
    } else {
        cout << EVENT_IMPORT_SUCCESS << endl;
    }
    if (events.empty()) {
        cout << NO_EVENTS << endl;
    }
    if (events.size() == 1) {
        cout << U_HAVE << 1 << S_EVENT << endl;
    }
    if (events.size() > 1) {
        cout << U_HAVE << events.size() << S_EVENTS << endl;
    }
    cout << ENTER_NUMBER << endl;
    while (true) {
        if (cin.eof()) {
            if (!ExportEv.exportEvents(events, SAVE_FILE_NAME)) {
                cout << EXPORT_FAIL << endl;
            } else {
                cout << EVENT_SAVE_SUCCESS << endl;
            }
            break;
        }
        cout << OPTIONS << endl;
        cout << OPT1 << endl;
        cout << OPT2 << endl;
        cout << OPT3 << endl;
        cout << OPT4 << endl;
        cout << OPT5 << endl;
        cout << OPT6 << endl;
        cout << OPT7 << endl;
        if (CheckInput::numberInputFail(command, 1, 7)) {
            cout << INPUT_FAIL << endl;
            continue;
        }
        switch (command) {
            case 1:
                AddEv.addNewEvent(events);
                break;
            case 2:
                DelEv.deleteEvent(events);
                break;
            case 3:
                PrintEv.printEv(events);
                break;
            case 4:
                FindEv.findEvents(events);
                break;
            case 5:
                cout << ENTER_SAVE_FILE << endl;
                if (CheckInput::stringInputFail(strTmp) || cin.eof()) continue;
                if (!ExportEv.exportEvents(events, strTmp)) {
                    cout << EXPORT_FAIL << endl;
                } else {
                    cout << EVENT_EXPORT_SUCCESS << endl;
                }
                break;
            case 6:
                cout << ENTER_FILE << endl;
                if (CheckInput::stringInputFail(strTmp) || cin.eof()) continue;
                if (!ImportEv.importEvents(events, strTmp)) {
                    cout << IMPORT_FAIL << endl;
                } else {
                    cout << EVENT_IMPORT_SUCCESS << endl;
                }
                break;
            case 7:
                if (!exitApplication(exit)) {
                    continue;
                } else {
                    if (!ExportEv.exportEvents(events, SAVE_FILE_NAME)) {
                        cout << EXPORT_FAIL << endl;
                    } else {
                        cout << EVENT_SAVE_SUCCESS << endl;
                    }
                }
                break;
        }
        if (exit) break;
    }

    for (size_t i = 0; i < events.size(); ++i) {
        if (events[i] != nullptr) {
            delete events[i];
        }
    }
}

bool Calendar::exitApplication(bool &exitIn) {
    cout << ARE_U_SURE << endl;
    cout << YES << endl;
    cout << NO << endl;
    int sure;
    if (CheckInput::numberInputFail(sure, 1, 2))return false;
    if (sure == 1){
        exitIn = true;
        return true;
    }
    return false;
}

void Calendar::greetings() {
    srand(time(nullptr));
    switch (rand() % 6) {
        case 0:
            cout << MSG1;
            break;
        case 1:
            cout << MSG2;
            break;
        case 2:
            cout << MSG3;
            break;
        case 3:
            cout << MSG4;
            break;
        case 4:
            cout << MSG5;
            break;
        case 5:
            cout << MSG6;
            break;
    }
    cout << MSG0 << endl;
}
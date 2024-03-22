#include "FindEvents.h"

bool FindEvents::findEvents(vector<Event *> &events) {
    cout << CHOOSE_CONNECTIVE << endl;
    cout << CON_OPT1 << endl;
    cout << CON_OPT2 << endl;
    cout << CON_OPT3 << endl;
    int command;
    if (CheckInput::numberInputFail(command, 1, 3) || cin.eof()) {
        cout << INPUT_FAIL << endl;
        return false;
    }
    vector<Event *> summaryEv = events;
    vector<Event *> tmpEven;
    string strTmp;
    if (command == 3) return false;
    while (true) {
        Meeting tmpM;
        cout << CHOOSE_PARAM << endl;
        cout << PARAM_OPT1 << endl;
        cout << PARAM_OPT2 << endl;
        cout << PARAM_OPT3 << endl;
        cout << PARAM_OPT4 << endl;
        cout << PARAM_OPT5 << endl;
        cout << PARAM_OPT6 << endl;
        cout << PARAM_OPT7 << endl;
        int command1;
        if (CheckInput::numberInputFail(command1, 1, 7)) {
            cout << INPUT_FAIL << endl;
            return false;
        }
        switch (command1) {
            case 1:
                if (!findByDate(summaryEv, tmpEven, command, tmpM)) return false;
                break;
            case 2:
                if (!findByTitle(summaryEv, tmpEven, strTmp, command)) return false;
                break;
            case 3:
                if (!findByNote(summaryEv, tmpEven, strTmp, command)) return false;
                break;
            case 4:
                if (!findByLocation(summaryEv, tmpEven, strTmp, command)) return false;
                break;
            case 5:
                if (!findByPerson(summaryEv, tmpEven, strTmp, command)) return false;
                break;
            case 6:
                if (!findByTag(summaryEv, tmpEven, strTmp, command))return false;
                break;
            case 7:
                if (command == 1) {
                    for (size_t i = 0; i < summaryEv.size(); ++i) {
                        cout << *summaryEv[i] << endl;
                    }
                }
                if (command == 2) {
                    for (size_t i = 0; i < tmpEven.size(); ++i) {
                        cout << *tmpEven[i] << endl;
                    }
                }
                if ((command == 1 && !summaryEv.empty()) || (command == 2 && !tmpEven.empty())) {
                    cout << WANNA_SAVE << endl;
                    cout << YES << endl;
                    cout << NO << endl;
                    int command2;
                    if (CheckInput::numberInputFail(command2, 1, 2)) {
                        cout << INPUT_FAIL << endl;
                        return false;
                    }
                    switch (command2) {
                        case 1:
                            if (command == 1) {
                                cout << ENTER_SAVE_FILE << endl;
                                if (CheckInput::stringInputFail(strTmp)) {
                                    cout << INPUT_FAIL << endl;
                                    return false;
                                };
                                if (!ExportEv.exportEvents(summaryEv, strTmp)) {
                                    cout << EXPORT_FAIL << endl;
                                };
                            } else {
                                cout << ENTER_SAVE_FILE << endl;
                                if (CheckInput::stringInputFail(strTmp)) {
                                    cout << INPUT_FAIL << endl;
                                    return false;
                                }
                                if (!ExportEv.exportEvents(tmpEven, strTmp)) {
                                    cout << EXPORT_FAIL << endl;
                                } else{
                                    cout << EVENT_EXPORT_SUCCESS << endl;
                                }
                            }
                            return true;
                        case 2:
                            return false;
                    }
                } else {
                    cout << EVENT_PARAM_FIND_FAIL << endl;
                    return false;
                }
        }
    }
}

bool FindEvents::findByTag(vector<Event *> &summaryEv, vector<Event *> &tmpEven, string &strTmp, int command) {
    cout << ENTER_TAG << endl;
    if (CheckInput::stringInputFail(strTmp)) {
        cout << INPUT_FAIL << endl;
        return false;
    }
    for (size_t i = 0; i < summaryEv.size(); ++i) {
        if (!summaryEv[i]->potentialCollision) continue;
        for (size_t j = 0; j < summaryEv[i]->getTags().size(); ++j) {
            if (summaryEv[i]->getTags()[j] == strTmp) {
                tmpEven.push_back(summaryEv[i]);
                if (command == 2) {
                    summaryEv.erase(summaryEv.begin() + i);
                    i--;
                }
                break;
            }
        }
    }
    if (command == 1) {
        summaryEv = tmpEven;
        tmpEven.clear();
    }
    return true;
}

bool FindEvents::findByPerson(vector<Event *> &summaryEv, vector<Event *> &tmpEven, string &strTmp, int command) {
    cout << ENTER_PERSON << endl;
    if (CheckInput::stringInputFail(strTmp)) {
        cout << INPUT_FAIL << endl;
        return false;
    }
    for (size_t i = 0; i < summaryEv.size(); ++i) {
        if (!summaryEv[i]->potentialCollision) continue;
        for (size_t j = 0; j < summaryEv[i]->getMembers().size(); ++j) {
            if (summaryEv[i]->getMembers()[j] == strTmp) {
                tmpEven.push_back(summaryEv[i]);
                if (command == 2) {
                    summaryEv.erase(summaryEv.begin() + i);
                    i--;
                }
                break;
            }
        }
    }
    if (command == 1) {
        summaryEv = tmpEven;
        tmpEven.clear();
    }
    return true;
}

bool FindEvents::findByLocation(vector<Event *> &summaryEv, vector<Event *> &tmpEven, string &strTmp, int command) {
    cout << ENTER_LOCATION << endl;
    if (CheckInput::stringInputFail(strTmp)) {
        cout << INPUT_FAIL << endl;
        return false;
    }
    for (size_t i = 0; i < summaryEv.size(); ++i) {
        if (!summaryEv[i]->potentialCollision) continue;
        if (summaryEv[i]->getLocation() == strTmp) {
            tmpEven.push_back(summaryEv[i]);
            if (command == 2) {
                summaryEv.erase(summaryEv.begin() + i);
                i--;
            }
        }
    }
    if (command == 1) {
        summaryEv = tmpEven;
        tmpEven.clear();
    }
    return true;
}

bool FindEvents::findByNote(vector<Event *> &summaryEv, vector<Event *> &tmpEven, string &strTmp, int command) {
    cout << ENTER_NOTE << endl;
    if (CheckInput::stringInputFail(strTmp)) {
        cout << INPUT_FAIL << endl;
        return false;
    }
    for (size_t i = 0; i < summaryEv.size(); ++i) {
        if (!summaryEv[i]->potentialCollision) continue;
        if (summaryEv[i]->note == strTmp) {
            tmpEven.push_back(summaryEv[i]);
            if (command == 2) {
                summaryEv.erase(summaryEv.begin() + i);
                i--;
            }
        }
    }
    if (command == 1) {
        summaryEv = tmpEven;
        tmpEven.clear();
    }
    return true;
}

bool FindEvents::findByTitle(vector<Event *> &summaryEv, vector<Event *> &tmpEven, string &strTmp, int command) {
    cout << ENTER_TITLE<< endl;
    if (CheckInput::stringInputFail(strTmp)){
        cout << INPUT_FAIL << endl;
        return false;
    }
    for (size_t i = 0; i < summaryEv.size(); ++i) {
        if (!summaryEv[i]->potentialCollision) continue;
        if (summaryEv[i]->getTitle() == strTmp) {
            tmpEven.push_back(summaryEv[i]);
            if (command == 2) {
                summaryEv.erase(summaryEv.begin() + i);
                i--;
            }
        }
    }
    if (command == 1) {
        summaryEv = tmpEven;
        tmpEven.clear();
    }
    return true;
}

bool FindEvents::findByDate(vector<Event *> &summaryEv, vector<Event *> &tmpEven, int command, Event &tmpM) {
    if (!tmpM.setDate())return false;
    if (!tmpM.setTime())return false;
    for (size_t i = 0; i < summaryEv.size(); ++i) {
        if (summaryEv[i]->date == tmpM.date) {
            tmpEven.push_back(summaryEv[i]);
            if (command == 2) {
                summaryEv.erase(summaryEv.begin() + i);
                i--;
            }
        }
    }
    if (command == 1) {
        summaryEv = tmpEven;
        tmpEven.clear();
    }
    return true;
}
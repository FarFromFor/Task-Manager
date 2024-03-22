#include "Event.h"

ostream &operator<<(ostream &out, const Event &elem) {
    elem.print(out);
    return out;
}

pair<size_t,size_t> Event::getID() const {
    return id;
}


void Event::setID(size_t newID1, size_t newID2) {
    id.first=newID1;
    id.second=newID2;
}

bool Event::setDate() {
    int newYear;
    int newMonth;
    int newDay;
    cout << ENTER_DATE << endl;
    if (scanf(" %d . %d . %d", &newDay, &newMonth, &newYear) != 3 || cin.eof()) {
        cout << INPUT_FAIL << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if (CheckInput::numberFailInt(newYear, MIN_ALLOWED_YEAR, MAX_ALLOWED_YEAR)){
    	cout << INPUT_FAIL << endl;
    	return false;
    }
    if (CheckInput::numberFailInt(newMonth, 1, 12)){
    	cout << INPUT_FAIL << endl;
    	return false;
    }
    if (CheckInput::numberFailInt(newDay, 1, 31)){
    	cout << INPUT_FAIL << endl;
    	return false;
    }
    if (CheckDate::incorrectDate(newDay, newMonth, newYear)){
    	cout << INPUT_FAIL << endl;
    	return false;
    }
    date.setDate(newDay, newMonth, newYear);
    return true;
}

bool Event::setTime() {
    int newHour;
    int newMinute;
    cout << ENTER_TIME << endl;
    if (scanf(" %d : %d", &newHour, &newMinute) != 2 || cin.eof()) {
        cout << INPUT_FAIL << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if (CheckInput::numberFailInt(newMinute, 0, 59)){
    	cout << INPUT_FAIL << endl;
    	return false;
    }
    if (CheckInput::numberFailInt(newHour, 0, 23)){
    	cout << INPUT_FAIL << endl;
    	return false;
    }
    date.setTime(newHour, newMinute);
    return true;
}

bool Event::setDuration() {
    int hours;
    int minutes;
    cout << ENTER_DURATION_TIME << endl;
    if (scanf(" %d : %d", &hours, &minutes) != 2 || cin.eof()) {
        cout << INPUT_FAIL << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if (CheckInput::numberFailInt(hours, 0, MAX_DURATION_HOURS)){
    	cout << INPUT_FAIL << endl;
    	return false;
    }
    if (CheckInput::numberFailInt(minutes, 0, MAX_DURATION_MINUTES)){
    	cout << INPUT_FAIL << endl;
    	return false;
    }
    time_t duration = hours*SECONDS_IN_HOUR + minutes*SECONDS_IN_MINUTE;
    date.setDuration(duration);
    return true;
}

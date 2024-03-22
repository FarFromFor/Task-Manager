#include "CheckInput.h"

bool CheckInput::numberFailInt(int &tmp, int from, int to) {
    if (tmp < from || tmp > to) {
        return true;
    }
    return false;
}

bool CheckInput::stringInputFail(string &str) {
    cin.width(MAX_STRING_LENGTH+1);
    getline(cin, str);
    if (str.size() > MAX_STRING_LENGTH || cin.eof()) {
        str.clear();
        cin.clear();
        return true;
    }
    if (str.empty()) str = " ";
    return false;
}

bool CheckInput::numberInputFail(int &comm, int from, int to) {
    double tmp;
    char a;
    cin >> tmp;
    if (cin.eof()) {
        return true;
    }
    if (cin.fail() || tmp < from || tmp > to || tmp != (int) tmp) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return true;
    }
    a = (char) getchar();
    if (a != '\n') {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return true;
    }
    comm = (int) tmp;
    return false;
}
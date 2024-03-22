#include "ExportEvents.h"

bool ExportEvents::exportEvents(vector<Event *> &events, const string &fileName) {
    if (events.empty()) {
        ofstream file(fileName);
        if (file.is_open()) {
            file.clear();
            file.close();
        }
        return false;
    }
    ofstream file(fileName);
    if (file.is_open()) {
        for (size_t i = 0; i < events.size(); ++i) {
            events[i]->write(file);
            if (i != events.size() - 1) file << endl;
            if (!file) {
                return false;
            }
        }
        file.close();
        if (!file) {
            return false;
        }
        return true;
    }
    return false;
}

#include "Task.h"

Task::Task() {
    potentialCollision = true;
}

Event *Task::clone() const {
    return new Task(*this);
};

void Task::print(ostream &out) const {
    out << date;
    out << CUR_EV_MAX << allowedNumberOfCollisions << NOW << actualNumberOfCollisions << endl;
    out << TASK << title << endl << NOTE << note << endl << IN << location << endl << INVITED;
    printMembers(out);
    printTags(out);
    out << COMPLEXITY << complexityLevel << endl;
    printThings(out);
    cout << endl;
}

void Task::write(ostream &out) const {
    writeToFile(out, 4);
    out << endl;
    out << complexityLevel << endl;
    for (size_t i = 0; i < toPickWith.size(); ++i) {
        out << toPickWith[i] << endl;
    }
    out << INPUT_END;
}
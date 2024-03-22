#include "Birthday.h"

Birthday::Birthday() {
    potentialCollision = true;
}

Event *Birthday::clone() const {
    return new Birthday(*this);
};

void Birthday::print(ostream &out) const {
    out << date;
    out << CUR_EV_MAX << allowedNumberOfCollisions << NOW << actualNumberOfCollisions << endl;
    out << BIRTHDAY<< title << endl << NOTE << note << endl << IN << location << endl << INVITED;
    printMembers(out);
    printTags(out);
    cout << endl;
}

void Birthday::write(ostream &out) const {
    writeToFile(out, 2);
}
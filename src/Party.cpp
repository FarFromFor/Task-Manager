#include "Party.h"

Party::Party() {
    potentialCollision = true;
}

Event *Party::clone() const {
    return new Party(*this);
};

void Party::print(ostream &out) const {
    out << date;
    out << CUR_EV_MAX << allowedNumberOfCollisions << NOW << actualNumberOfCollisions << endl;
    out << PARTY << title << endl << NOTE << note << endl << IN << location << endl << INVITED;
    printMembers(out);
    printTags(out);
    printThings(out);
    cout << endl;
}

void Party::write(ostream &out) const {
    writeToFile(out, 3);
    out << endl;
    for (size_t i = 0; i < toPickWith.size(); ++i) {
        out << toPickWith[i] << endl;
    }
    out << INPUT_END;
}
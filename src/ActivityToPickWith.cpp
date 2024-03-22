#include "ActivityToPickWith.h"

void ActivityToPickWith::printThings(ostream &out) const {
    out << THINGS_TO_PICK;
    for (size_t i = 0; i < toPickWith.size(); ++i) {
        out << toPickWith[i];
        if (i != (toPickWith.size() - 1)) out << COMMA;
    }
    out << endl;
}
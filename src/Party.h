#ifndef MAIN_CPP_PARTY_H
#define MAIN_CPP_PARTY_H

#include "ActivityToPickWith.h"

/**
 * @brief Child class for ActivityToPickWith. Represents event "Party" \n
 * Implemented functions:
 *  clone()
 *  print(ostream &out)
 *  write(ostream &out)
 */
class Party : public ActivityToPickWith {
public:
    //! event constructor
    Party();

    //! returns pointer on new allocated party
    Event *clone() const override;

    //! print event to "out"
    void print(ostream &out) const override;

    //! write event to "out"
    void write(ostream &out) const override;
};


#endif //MAIN_CPP_PARTY_H

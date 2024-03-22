#ifndef MAIN_CPP_TASK_H
#define MAIN_CPP_TASK_H

#include "ActivityToPickWith.h"

/**
 * @brief Child class for ActivityToPickWith. Represents event "Task \n
 * Added attributes:
 *  int complexityLevel \n
 * Implemented functions:
 *  clone()
 *  print(ostream &out)
 *  write(ostream &out)
 */
class Task : public ActivityToPickWith {
public:
    //! event constructor
    Task();

    //! returns pointer on new allocated task
    Event *clone() const override;

    //! print event to "out"
    void print(ostream &out) const override;

    //! write event to "out"
    void write(ostream &out) const override;

    //! complexity level
    int complexityLevel = 0;
};


#endif //MAIN_CPP_TASK_H

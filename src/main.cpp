#include "Calendar.h"
/**
 * @mainpage Calendar
 *
 * @section intro This is the documentation for the program "Calendar".
 * Here, you can find descriptions for functions, classes and other components of this program.
 *
 * @section description You are able to:
 *
 *  - Add new events manually or import them from a file.
 *
 *  - Delete events by their date and time, or delete all events at once.
 *
 *  - Show events for specific periods of time.
 *
 *  - Find events by using conjunctions OR and AND.
 *
 *  - Export events to a file.
 *
 *  - After finishing the program, all changes will be saved.
 *
 * The implementation of the calendar is ruled by commands in a console application. The calendar displays the available
 * commands at any given time. Calendar allows importing, exporting, saving, and removing events. The calendar can
 * provide an overview of daily, weekly, and monthly events for any date, and it also has the option to display events
 * for the next hour for the current date.
 * Upon launching the calendar, it attempts to load saved events from the "save_events.txt" file. If successful, the
 * events will be loaded. Otherwise, an error message will be displayed, and the events will not be loaded.
 * Manual addition of new events is possible in the "Add new event" section. The program offers various types of events
 * to be added: "Meeting," "Birthday," "Party," "Task," and "Reminder." The user can enter parameters specific to the
 * chosen event type, which may vary depending on the event type. The program checks the validity of the entered
 * parameters, and in case of incorrect inputs, it terminates the addition of the new event and returns to the "main
 * menu." Attributes such as "members" and "tags" are stored without repetition but are case-sensitive.
 * The calendar allows defining whether each specific event (except "Reminder") is a recurring event and also specifies
 * the frequency and number of repetitions.
 * For each event (except "Reminder"), it is possible to define the permissible number of collisions, including
 * recurring events. If a newly added event would exceed the permissible number of collisions with any existing event or
 * with itself, it will not be added, and an alert message will be displayed.
 * Event deletion is based on the event type, date, and time. There is also an option to delete all events.
 * Event searching is possible based on individual attributes using the "AND" and "OR" operators. The user first selects
 * the operator and then specifies the attributes for the search. After the search is completed, all found events will
 * be printed on the screen, and the option to save found events to a file will be offered. If no events are found,
 * the program returns to the "main menu". For exporting events, the user can choose the filename to which the events
 * will be exported.
 * For importing events, the user can also select the filename from which the events will be imported. Upon program
 * termination, all saved events will be written to the "save_events.txt" file.
 *
 * I hope you will enjoy this app.
 *
 * Aleksandr Riabov
 */
int main() {
    Calendar tmp;
    tmp.startApplication();
    return 0;
}
#ifndef MAIN_CPP_CONFIG_H
#define MAIN_CPP_CONFIG_H

using namespace std;

// --Dialogs--
//event dialogs
const string TAGS = "Tags: ";
const string TAG_SYMBOL = "#";
const string THINGS_TO_PICK = "Things to pick with: ";
const string COMMA = ", ";
const string CUR_EV_MAX = "Concurrent events: Max: ";
const string NOW = " Now: ";
const string BIRTHDAY = "Birthday: ";
const string NOTE = "Note: ";
const string IN = "In: ";
const string INVITED = "Invited: ";
const string MEETING = "Meeting: ";
const string DRESS_CODE = "Dress code: ";
const string PARTY = "Party: ";
const string ATTENTION = "Attention! ";
const string DOT = ".";
const string SPACE = " ";
const string AT = " at ";
const string COLON = ":";
const string TASK = "Task: ";
const string COMPLEXITY = "Complexity: ";
const string ENTER_DATE = "Enter the date in the format: DD.MM.YYYY:";
const string ENTER_TIME = "Enter the time in the format: HH:MM:";
const string ENTER_DURATION_TIME = "Enter the time the event will last in the format: HH:MM:";
//adding event dialogs
const string ENTER_TITLE = "Enter event title:";
const string ENTER_LOCATION = "Enter event location:";
const string ENTER_NOTE = "Enter note:";
const string ENTER_MEMBERS = "Enter members (each on a new line). If entering is done enter \"end\":";
const string ENTER_TAGS = "Enter tags (each on a new line). If entering is done enter \"end\":";
const string MAKE_REPEATING = "Would you like to make this event daily repeating?";
const string YES = "1. Yes";
const string NO = "2. No";
const string ENTER_REPEATING_INTERVAL = "Enter repeating interval in days (1 - every day...):";
const string ENTER_REPETITIONS_NUMBER = "Enter number of repetitions:";
const string ENTER_ALLOWED_CONCURRENT_EV = "Enter allowed number of concurrent events:";
const string ENTER_DRESS_CODE = "Enter dress code:";
const string ENTER_COMPLEXITY = "Enter complexity level (from 1):";
const string WHAT_TO_ADD = "What kind of event would you like to add?";
const string ADD_OPT1 = "1. Meeting";
const string ADD_OPT2 = "2. Birthday";
const string ADD_OPT3 = "3. Party";
const string ADD_OPT4 = "4. Task";
const string ADD_OPT5 = "5. Reminder";
const string ADD_OPT6 = "6. Return to main menu";
const string ENTER_THINGS = "Enter things to pick with (each on a new line). If entering is done enter \"end\":";
//calendar dialogs
const string NO_EVENTS = "You dont have scheduled events yet!";
const string U_HAVE = "You have ";
const string S_EVENT = " scheduled event";
const string S_EVENTS = " scheduled events";
const string ENTER_NUMBER = "To select an option, enter its number";
const string OPTIONS = "Options:";
const string OPT1 = "1: Add new event";
const string OPT2 = "2: Delete event";
const string OPT3 = "3: Show events";
const string OPT4 = "4: Find events";
const string OPT5 = "5: Export all events";
const string OPT6 = "6: Import events";
const string OPT7 = "7: Exit";
const string ENTER_SAVE_FILE = "Enter the save file name:";
const string ENTER_FILE = "Enter the file name:";
const string ARE_U_SURE = "Are you sure?";
//delete dialogs
const string WHAT_TO_DELETE = "Would you like to delete one-time event or repeating event?";
const string DEL_OPT1 = "1. One-time event";
const string DEL_OPT2 = "2. Repeating";
const string DEL_OPT3 = "3. Delete all events";
const string DEL_OPT4 = "4. Return tto main menu";
//date dialogs
const string EVENT_START = "The event starts: ";
const string EVENT_FINISH = "The event finishes: ";
//find dialogs
const string CHOOSE_CONNECTIVE = "Choose connective:";
const string CON_OPT1 = "1. AND";
const string CON_OPT2 = "2. OR";
const string CON_OPT3 = "3. Return to main menu";
const string CHOOSE_PARAM = "Choose parameter:";
const string PARAM_OPT1 = "1. Start date";
const string PARAM_OPT2 = "2. Title";
const string PARAM_OPT3 = "3. Note";
const string PARAM_OPT4 = "4. Location";
const string PARAM_OPT5 = "5. Invited person";
const string PARAM_OPT6 = "6. Tag";
const string PARAM_OPT7 = "7. Done";
const string WANNA_SAVE = "Would you like to save the events?";
const string ENTER_PERSON = "Enter invited person";
const string ENTER_TAG = "Enter tag";
//print dialogs
const string SHOW_FOR = "Show events for: ";
const string SHOW_FOR_OPT1 = "1. Next hour";
const string SHOW_FOR_OPT2 = "2. This day";
const string SHOW_FOR_OPT3 = "3. This week";
const string SHOW_FOR_OPT4 = "4. This month";
const string SHOW_FOR_OPT5 = "5. Show all events";
const string SHOW_FOR_OPT6 = "6. Select date";
const string SHOW_FOR_OPT7 = "7. Return to main menu";
const string SHOW = "Show:";
const string SHOW_OPT1 = "1. Day events";
const string SHOW_OPT2 = "2. Week events";
const string SHOW_OPT3 = "3. Month events";
const string SHOW_OPT4 = "4. Return to main menu";
//greetings dialogs
const string MSG1 = "About 100.000 pepople are going to die today. ";
const string MSG2 = "You look awesome! Just like my granddad. ";
const string MSG3 = "You are still alive somehow. ";
const string MSG4 = "You look even younger today! Just about 60. ";
const string MSG5 = "Wow! You look awesome! Wait... it's you... ";
const string MSG6 = "Today is payday! Just kidding. ";
const string MSG0 = "Glad to see you!";

// --Fail notes--
const string INPUT_FAIL = "Incorrect input!";
const string EXPORT_FAIL = "Export failed!";
const string IMPORT_FAIL = "Import failed!";
const string COLLISIONS_FAIL = "Maximum amount of allowed collisions reached!";
const string EVENT_FIND_FAIL = "Event wasn't found!";
const string NO_EVENTS_FAIL = "No events found!";
const string EVENT_PARAM_FIND_FAIL = "There are no events with these parameters!";
const string TOO_MANY_TAGS_FAIL = "Too many tags!";
const string TOO_MANY_MEMBERS_FAIL = "Too many members!";
const string TOO_MANY_THINGS_FAIL = "Too many things to pick with!";
const string REPEATING_INTERVAL_FAIL = "Repeating interval must be longer than duration!";

// --Success notes--
const string EVENT_ADD_SUCCESS = "Event added successfully";
const string EVENT_IMPORT_SUCCESS = "Events successfully imported";
const string EVENT_EXPORT_SUCCESS = "Events successfully exported";
const string EVENT_SAVE_SUCCESS = "Events successfully saved";
const string EVENT_ERASE_SUCCESS = "Event erased";
const string EVENT_ERASE_ALL_SUCCESS = "All events erased";

// --Technical--
const string INPUT_END = "end";
const string SAVE_FILE_NAME = "save_events.txt";

// --Numeric constants--
const int SECONDS_IN_MINUTE = 60;
const int SECONDS_IN_HOUR = 3600;
const int SECONDS_IN_DAY = 86400;
const int SECONDS_IN_WEEK = 604800;
const int MAX_DURATION_HOURS = 23;
const int MAX_DURATION_MINUTES = 59;
const int MAX_ALLOWED_YEAR = 3000;
const int MIN_ALLOWED_YEAR = 1971;
const int MAX_REPETITIONS = 1000;
const int MAX_REPEATING_INTERVAL = 10;
const int MAX_ELEMENTS = 1000;
const int MAX_COMPLEXITY_LEVEL = 10;
const int MAX_ALLOWED_COLLISIONS = 10;
const int MAX_STRING_LENGTH = 100;
const size_t SIZE_T_MAX = 4294967295;

#endif //MAIN_CPP_CONFIG_H

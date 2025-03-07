/////////////////////////////////////////////////////////////////////////////////////////
// INTEGRITY STATEMENT (v4)
//
// By signing your name and ID below you are stating that you have agreed
// to the online academic integrity statement posted on edX:
// (Course > Assignments > Assignment Information & Policies > Academic Integrity Policy)
/////////////////////////////////////////////////////////////////////////////////////////
// I received help from and/or collaborated with:

// ERROR_NO_INTEGRITY_STATEMENT
//
// Name: ERROR_NO_NAME
// login ID: ERROR_NO_LOGIN
//////////////////////////////////////////////////////////////////////////////////////////

#include "course.h"

//
// DO NOT MODIFY THESE CONSTANTS
//
// see course.h for documentation
const int MAX_CAPACITY = 128;
// see course.h for documentation
const int MAX_COURSE_TITLE_LENGTH = 128;
// see course.h for documentation
const int SUBJECT_LENGTH = 3;

// see course.h for documentation
void course_init(struct course *c, const char subject[], const int number,
		 const char title[], const int capacity) {
  //
  // ADD CODE
  //
}

// see course.h for documentation
const char* course_subject(const struct course *c) {
  //
  // ADD CODE
  //
  return NULL;
}

// see course.h for documentation
int course_number(const struct course *c) {
  //
  // ADD CODE
  //
  return 0;
}

// see course.h for documentation
bool course_is_full(const struct course *c) {
  //
  // ADD CODE
  //
  return false;  
}

// see course.h for documentation
void course_enroll(struct course *c, struct student *s) {
  //
  // ADD CODE
  //
}

// see course.h for documentation
void course_drop(struct course *c, struct student *s) {
  //
  // ADD CODE
  //
}

// see course.h for documentation
void course_print(const struct course *c) {
  //
  // ADD CODE
  //
}

/////////////////////////////////////////////////////////////////////////////////////////
// INTEGRITY STATEMENT (v4)
//
// By signing your name and ID below you are stating that you have agreed
// to the online academic integrity statement posted on edX:
// (Course > Assignments > Assignment Information & Policies > Academic Integrity Policy)
/////////////////////////////////////////////////////////////////////////////////////////
// I received help from and/or collaborated with:

// None
//
// Name: Dana Yuan
// login ID: d32yuan
//////////////////////////////////////////////////////////////////////////////////////////

#include "student.h"

//
// DO NOT MODIFY THESE CONSTANTS
//
// see student.h for documentation
const int GRADE_NOT_SET = -1;
// see student.h for documentation
const int MAX_COURSES_PER_STUDENT = 32;
// see student.h for documentation
const int MAX_STUDENT_NAME_LENGTH = 32;

// see student.h for documentation
void student_init(struct student *s, const int id, const char name[]) {
  //
  // ADD CODE
  //
}

// see student.h for documentation
int student_id(const struct student *s) {
  //
  // ADD CODE
  //
  return 0;
}

// see student.h for documentation
char *student_name(struct student *s) {
  //
  // ADD CODE
  //
  return NULL;
}

// see student.h for documentation
bool student_is_enrolled(const struct student *s, const struct course *c) {
  //
  // ADD CODE
  //
  return false;
}

// see student.h for documentation
void student_enroll(struct student *s, struct course *c) {
  //
  // ADD CODE
  //
}

// see student.h for documentation
void student_drop(struct student *s, struct course *c) {
  //
  // ADD CODE
  //
}

// see student.h for documentation
void student_set_grade(struct student *s, struct course *c, int grade) {
  //
  // ADD CODE
  //
}

// see student.h for documentation
int student_grade(const struct student *s, const struct course *c) {
  //
  // ADD CODE
  //
  return 0;
}

// see student.h for documentation
void student_print(const struct student *s) {
  //
  // ADD CODE
  //
}

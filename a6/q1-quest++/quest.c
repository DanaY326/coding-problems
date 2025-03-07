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

#include "quest.h"

//
// DO NOT MODIFY THESE CONSTANTS
//
// see quest.h for documentation
const int MAX_STUDENTS = 512;   
// see quest.h for documentation
const int MAX_COURSES = 128;
// id of first registered student; compute further ids by increasing by one
//   for each additional registration
static const int BASE_ID = 20000000;

// see quest.h for documentation
void quest_init(struct quest *q) {
  //
  // ADD CODE
  //
}

// see quest.h for documentation
int quest_register_student(struct quest *q, const char *name) {
  //
  // ADD CODE
  //
  return 0;
}

// see quest.h for documentation
bool quest_create_course(struct quest *q, const char subject[], 
			 const int number, const char title[],
			 const int capacity) {
  //
  // ADD CODE
  // Use this error message in case of error:
  //   "CREATE FAILURE: course already exists\n"
  //
  return false;
}

// see quest.h for documentation
bool quest_enroll(struct quest *q, const int student_id,
		  const char course_subject[], const int course_number) {
  //
  // ADD CODE
  // Use matching error message in case of error:
  //   "ENROLLMENT FAILURE: student does not exist\n"
  //   "ENROLLMENT FAILURE: course does not exist\n"
  //   "ENROLLMENT FAILURE: course is full\n"
  //   "ENROLLMENT FAILURE: student is already enrolled in course\n"
  //
  return false;
}

// see quest.h for documentation
bool quest_drop(struct quest *q, const int student_id,
		const char course_subject[], const int course_number) {
  //
  // ADD CODE
  // Use matching error message in case of error:
  //   "DROP FAILURE: student does not exist\n"
  //   "DROP FAILURE: course does not exist\n"
  //   "DROP FAILURE: student is not enrolled in course\n"
  //   "DROP FAILURE: student's grade is already set\n"
  //
  return false;
}

// see quest.h for documentation
bool quest_submit_grades(struct quest *q, const char course_subject[],
			 const int course_number, const int student_ids[],
			 const int grades[], const int len) {
  //
  // ADD CODE
  // Use matching error message in case of error:
  //   "SUBMIT FAILURE: course does not exist\n"
  //   "SUBMIT FAILURE: student does not exist\n"
  //   "SUBMIT FAILURE: student is not enrolled in course\n"
  //   "SUBMIT FAILURE: invalid grade\n"
  //
  return false;
}

bool quest_print_student(struct quest *q, const int id) {
  //
  // ADD CODE
  // Use this error message in case of error:
  //   "PRINT STUDENT FAILURE: student does not exist\n"
  return false;
}

bool quest_print_course(struct quest *q, const char subject[],
			const int number) {
  //
  // ADD CODE
  // Use this error message in case of error:
  //   "PRINT COURSE FAILURE: course does not exist\n"
  //
  return false;
}

#ifndef GRADE_SCHOOL_H
#define GRADE_SCHOOL_H

#include <stddef.h>
#include <stdint.h>

#define MAX_NAME_LENGTH 20
#define MAX_STUDENTS 20
#define MAX_ROSTERS 2

typedef struct {
   uint8_t grade;
   char *name;
} student_t;

typedef struct {
   size_t count;
   student_t students[MAX_STUDENTS];
} roster_t;

int add_student(const char *name, uint8_t grade);
roster_t get_roster(void);
void clear_roster(void);
roster_t get_grade(uint8_t desired_grade);

#endif

#include "grade_school.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/*Should not be accessible from outside.*/
static roster_t rosters_register[MAX_ROSTERS] = {0};

/*
 * compare_students() - Compare 2 students records for sorting.
 * @first: Pointer to the first student's record.
 * @second: Pointer to the second student's record.
 *
 * Intended to be used with qsort function hence the
 * signature and return values.
 *
 * Records are sorted in ascending order e.g. 0->9 end A->Z.
 *
 * Return:
 * * -1 - First student's record should be before second student
 * * 0 - records are equal
 * * 1 - First student's record should be after second student
 */
static int compare_students(const void *first, const void *second) {
    if (!first || !second) {
        return -1;
    }
    char *first_name = ((student_t *)first)->name;
    char *second_name = ((student_t *)second)->name;
    uint8_t grade_first = ((student_t *)first)->grade;
    uint8_t grade_second = ((student_t *)second)->grade;
    int first_grade_position = (grade_second < grade_first) \
                               - (grade_first < grade_second);
    if (first_grade_position) {
        /* No need to compare names, grades are different.*/
        return first_grade_position;
    }
    int first_name_position = strcmp(first_name, second_name);
    return first_name_position;
}


static int add_to_roster(roster_t *roster, const char *name, uint8_t grade,
                         bool to_sort) {
    if (!name) {
        return 0;
    }
    if (roster->count == MAX_STUDENTS) {
        return 0;
    }
    size_t buf_size = MAX_NAME_LENGTH * sizeof(char);
    char *name_buf = (char *)malloc(buf_size);
    int ret = snprintf(name_buf, buf_size, "%s", name);
    if (ret >= (int)buf_size || ret < 0) {
        free(name_buf);
        return 0;
    }
    roster->students[roster->count++] = (student_t){grade, name_buf};
    if (to_sort) {
        qsort(roster->students, roster->count, sizeof(student_t),
              compare_students);
    }
    return 1;
}


int add_student(const char *name, uint8_t grade) {
    return add_to_roster(&rosters_register[0], name, grade, true);
}


roster_t get_roster(void) {
    return rosters_register[0];
}


void clear_roster(void) {
    for (int indx = 0; indx < MAX_ROSTERS; indx++) {
        roster_t *r = &rosters_register[indx];
        while (r->count > 0) {
            free(r->students[--r->count].name);
        }
    }
}


roster_t get_grade(uint8_t desired_grade) {
    roster_t *local_roster = &rosters_register[1];
    roster_t *main_roster = &rosters_register[0];
    if (main_roster->count < 1) {
        return *local_roster;
    }
    for (int indx = 0; indx < (int)main_roster->count; indx++) {
        student_t *s = &main_roster->students[indx];
        if (s->grade == desired_grade) {
            int ret = add_to_roster(local_roster, s->name, s->grade, false);
            if (!ret) {
                return *local_roster;
            }
        }
    }
    return *local_roster;
}

#define _XOPEN_SOURCE
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "meetup.h"

#define NWEEK_DAYS 7

static const char week_days[NWEEK_DAYS][10] = {"Sunday", "Monday",
                                               "Tuesday", "Wednesday",
                                               "Thursday", "Friday",
                                               "Saturday"};


static inline int is_leap(unsigned int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}


static int get_month_days(unsigned int year, unsigned int month) {
    static const int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month > 12 || month < 1)
        return -1;
    month -= 1;
    if (month == 1)
        return days[month] + is_leap(year);
    return days[month];
}


static int calc_dow(unsigned int year, unsigned int month, int day) {
#define TMP_BUF_SZ 64
    char *res = NULL;
    int nbytes, max_days;
    char buf[TMP_BUF_SZ] = {0};
    struct tm tinfo = {0};
    if ((max_days = get_month_days(year, month)) < 0)
        return -1;
    if (day > max_days)
        return -1;
    nbytes = snprintf(buf, TMP_BUF_SZ, "%u-%u-%d", year, month, day);
    if (nbytes >= TMP_BUF_SZ || nbytes < 0)
        return -1;
    res = strptime(buf, "%Y-%m-%d", &tinfo);
    if (res == NULL)
        return -1;
    return tinfo.tm_wday;
}


int meetup_day_of_month(unsigned int year, unsigned int month,
                        const char *week, const char *dow) {
    int cnt, cur_dow, day_cnt = 0, last_dow = 0,
        target_dow = -1, cur_mday = 0;
    for (cnt = 0; cnt < NWEEK_DAYS; cnt++) {
        if (!strcmp(dow, week_days[cnt])) {
            target_dow = cnt;
            break;
        }
    }
    if (target_dow < 0)
        return 0;
    while ((cur_dow = calc_dow(year, month, ++cur_mday)) >= 0) {
        if (cur_dow != target_dow) {
            continue;
        }
        day_cnt++;
        if (!strcmp(week, "first") || !strcmp(week, "1st")) {
            return cur_mday;
        } else if (!strcmp(week, "last")) {
            last_dow = cur_mday;
        } else if (!strcmp(week, "teenth")) {
            if (cur_mday > 12 && cur_mday < 20)
                return cur_mday;
        } else if (!strcmp(week, "second") && day_cnt == 2) {
                return cur_mday;
        } else if (!strcmp(week, "third") && day_cnt == 3) {
                return cur_mday;
        } else if (!strcmp(week, "fourth") && day_cnt == 4) {
                return cur_mday;
        } else if (!strcmp(week, "fifth") && day_cnt == 5) {
                return cur_mday;
        }
    }
    if (!strcmp(week, "last"))
        return last_dow;
    return 0;
}

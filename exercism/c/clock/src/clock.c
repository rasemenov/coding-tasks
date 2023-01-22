#include "clock.h"

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

clock_t clock_create(int hour, int minute) {
    clock_t clock = {0};
    int extra_hours = minute / MINUTES_HOURLY;
    if (minute < 0) {
        // Multiples of 60 minutes are handled correctly, anything
        // else requires manual 1-hour subtraction.
        int biased_hour = minute % MINUTES_HOURLY == 0 ? 0 : -1;
        extra_hours = biased_hour + minute / MINUTES_HOURLY;
        minute = minute % MINUTES_HOURLY + MINUTES_HOURLY;
    }
    hour += extra_hours;
    if (hour < 0) {
        hour = hour % HOURS_DAILY + HOURS_DAILY;
    }
    hour %= HOURS_DAILY;
    minute %= MINUTES_HOURLY;
    int res = snprintf(clock.text, MAX_STR_LEN, CLOCK_FMT, hour, minute);
    if (res < 0 || res >= MAX_STR_LEN) {
        return (clock_t){0};
    }
    return clock;
}

typedef struct {
    int hour;
    int minute;
} nclock_t;

static nclock_t strpclock(clock_t clock) {
    int hour, minute;
    int nparsed = sscanf(clock.text, CLOCK_FMT, &hour, &minute);
    if (nparsed != 2) {
        return (nclock_t){-1, -1};
    }
    return (nclock_t){hour, minute};
}

#define CHANGE_CLOCK(_clock_, _minute_, _ops_) \
    { \
        nclock_t parsed = strpclock((_clock_)); \
        if (parsed.hour == -1) { \
            return (clock_t){0}; \
        } \
        return clock_create(parsed.hour, parsed.minute _ops_ (_minute_)); \
    }

#define ADD_CLOCK(_clock_, _minute_) CHANGE_CLOCK((_clock_), (_minute_), +)
#define SUB_CLOCK(_clock_, _minute_) CHANGE_CLOCK((_clock_), (_minute_), -)


clock_t clock_add(clock_t clock, int minute) {
    ADD_CLOCK(clock, minute);
}

clock_t clock_subtract(clock_t clock, int minute) {
    SUB_CLOCK(clock, minute);
}

bool clock_is_equal(clock_t a, clock_t b) {
    return strncmp(a.text, b.text, (size_t)MAX_STR_LEN) == 0;
}

from calendar import monthrange
from datetime import date, timedelta


ISO_DOW = {'monday': 1, 'tuesday': 2, 'wednesday': 3, 'thursday': 4,
           'friday': 5, 'saturday': 6, 'sunday': 7}
WEEK_LEN = len(ISO_DOW)


class MeetupDayException(Exception):
    pass


def meetup(year: int, month: int, week: str, dow: str) -> date:
    iso_dow = ISO_DOW[dow.lower()]
    month_days = monthrange(year, month)[1]
    month_start_dow = date(year, month, 1).isoweekday()
    month_fin_dow = date(year, month, month_days).isoweekday()
    if month_start_dow > iso_dow:
        first_dow = WEEK_LEN - month_start_dow + iso_dow
    else:
        first_dow = iso_dow - month_start_dow
    if month_fin_dow < iso_dow:
        last_dow = WEEK_LEN + month_fin_dow - iso_dow
    else:
        last_dow = month_fin_dow - iso_dow
    first_date = date(year, month, 1) + timedelta(days=first_dow)
    last_date = date(year, month, month_days) - timedelta(days=last_dow)
    if week == 'first':
        meetup_date = first_date
    elif week == 'last':
        meetup_date = last_date
    elif week == 'teenth':
        for day in range(0, last_date.day, 7):
            meetup_date = first_date + timedelta(days=day)
            if meetup_date.day in range(13, 20):
                break
        else:
            raise MeetupDayException('How can I end up there!')
    elif any([week.endswith(ending) for ending in ('st', 'nd', 'rd', 'th')]):
        meetup_date = first_date + timedelta(days=((int(week[0]) - 1) * 7))
        if meetup_date.month != month:
            raise MeetupDayException(
                'There is no {} {} for {} {}'.format(week, dow, year, month))
    else:
        raise MeetupDayException('Invalid criteria provided: {}'.format(week))
    return meetup_date

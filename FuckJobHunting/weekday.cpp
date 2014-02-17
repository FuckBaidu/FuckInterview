/*
 * given:
 * 2014-2-13      Thusday
 * find:
 * 1970-1-1       ????
 */
#include <assert.h>
enum WeekDay {
    Monday = 0,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday
};

struct Date {
    int year;
    int month;
    int day;
    Date(int y, int m, int d) : year(y), month(m), day(d) { } 
};

const static int MonthDays[] = {
    0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

int CountLeapYears(const Date &date) {
    int num_leap_year = date.year / 4 - date.year / 100 + date.year / 400 + 1;
    return num_leap_year;
}

/* count days between date and 0-1-1 */
int CountDays(const Date &date) {
    int days = 0;
    for (int i = 0; i < date.month; i++)
        days += MonthDays[i];
    days += date.day - 1 + date.year * 365 + CountLeapYears(date);
    if (date.year / 4 == 0 && (date.year / 100 != 0 || date.year / 400 == 0) && date.month <= 2)
        days -= 1;
    return days;
}

class Convertor {
public:
    Convertor (const Date &given_date, WeekDay given_weekday) : _given_weekday(given_weekday) {
        _given_days = CountDays(given_date);
    }

    /*
     * find the weekday of date
     */
    WeekDay Convert(const Date &date) {
        int cur_days = CountDays(date);
        int result = ((int)_given_weekday + cur_days - _given_days) % 7;
        if (result < 0)
            result += 7;
        return (WeekDay)result;
    }
private:
    int     _given_days;
    WeekDay _given_weekday;
};

int main() {
    Date given_date(2014, 2, 10);
    Convertor convertor(given_date, Monday);
    Date a(2014, 2, 24);
    assert(convertor.Convert(a) == Monday);
    Date b(2014, 1, 1);
    assert(convertor.Convert(b) == Wednesday);
    Date e(2012, 3, 1);
    assert(convertor.Convert(e) == Thursday);
    Date c(1999, 3, 1);
    assert(convertor.Convert(c) == Monday);
    Date d(1970, 3, 1);
    assert(convertor.Convert(d) == Sunday);
    Date f(999, 3, 1);
    assert(convertor.Convert(f) == Friday);
    return 0;
}

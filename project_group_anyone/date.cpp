#include "date.h"

Date::Date()
{
    Date(1, 1, 1, 0, 0);
}

Date::Date(int day, int month, int year, int hour, int minute)
{
    day_ = day;
    month_ = month;
    year_ = year;
    hour_ = hour;
    minute_ = minute;
}

/*
 * After creating a Time object based on user input, validate it
 * immediately and inform the user about a failed validation.
 */
bool Date::validate()
{
    if (year_ < 0 || month_ < 1 || month_ > 12 || day_ < 1
            || hour_ > 23 || hour_ < 0 || minute_ > 59 || minute_ < 0)
        return false;

    // Max limit of day
    if (isLeapYear())
    {
        if (day_ > days_[1][month_])
            return false;
    }
    else if (day_ > days_[0][month_])
        return false;

    return true;
}

bool Date::isLeapYear()
{
    if (year_ % 400 == 0)
        return true;
    if (year_ % 100 == 0)
        return false;
    if (year_ % 4 == 0)
        return true;
    return false;
}

Date& Date::operator = (Date& t)
{
    year_ = t.getYear();
    month_ = t.getMonth();
    day_ = t.getDay();
    hour_ = t.getHour();
    minute_ = t.getMinute();
    return *this;
}

bool Date::operator == (Date& t)
{
    return (year_ == t.getYear()
            && month_ == t.getMonth()
            && day_ == t.getDay()
            && hour_ == t.getHour()
            && minute_ == t.getMinute());
}

bool Date::operator != (Date& t)
{
    return !(*this == (t));
}

bool Date::operator > (Date& t)
{
    int ret = year_ - t.getYear();
    if (!ret) ret = month_ - t.getMonth();
    if (!ret) ret = day_ - t.getDay();
    if (!ret) ret = hour_ - t.getHour();
    if (!ret) ret = minute_ - t.getMinute();
    return ret > 0;
}

bool Date::operator < (Date& t)
{
    return t > (*this);
}

bool Date::operator >= (Date& t)
{
    return (*this > (t) || *this == (t));
}

bool Date::operator <= (Date& t)
{
    return (*this < (t) || *this == (t));
}

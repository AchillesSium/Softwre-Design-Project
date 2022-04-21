#include "date.h"

/**
 * @brief Date::Date
 * Constructor with default values.
 */
Date::Date()
{
    Date(1, 1, 1, 0, 0);
}

/**
 * @brief Date::Date
 * Constructor with each value as an integer.
 * @param day day to set.
 * @param month month to set.
 * @param year year to set.
 * @param hour hour to set.
 * @param minute minute to set.
 */
Date::Date(int day, int month, int year, int hour, int minute)
{
    day_ = day;
    month_ = month;
    year_ = year;
    hour_ = hour;
    minute_ = minute;
}

// String needs to be formatted dd/mm/yyyy
/**
 * @brief Date::Date
 * Constructor that forms a Date based on a string
 * that is formatted as dd/mm/yyyy.
 * WARNING: doesn't check the input, crashes easily
 * @param dateStr date to set in dd/mm/yyyy format.
 */
Date::Date(std::string dateStr)
{
    day_ = stoi(dateStr.substr(0,2));
    month_ = stoi(dateStr.substr(3,2));
    year_ = stoi(dateStr.substr(6,4));
    hour_ = 0;
    minute_ = 0;
}

/**
 * @brief Date::validate
 * Checks the validity of the date.
 * @return true if valid, false if not.
 */
bool Date::validate()
{
    if (year_ < 0 || month_ < 1 || month_ > 12 || day_ < 1
            || hour_ > 23 || hour_ < 0 || minute_ > 59 || minute_ < 0)
        return false;

    // Max limit of day
    if (isLeapYear())
    {
        if (day_ > days_[1][month_ - 1])
            return false;
    }
    else if (day_ > days_[0][month_ - 1])
        return false;

    return true;
}

/**
 * @brief Date::isLeapYear
 * Checks if the date takes place in a leap year.
 * @return true if leap year, false if not.
 */
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

/**
 * @brief Date::operator =
 * Custom assignment operator.
 * @param t Date to copy the contents of.
 * @return Date with newly assigned contents.
 */
Date& Date::operator = (Date& t)
{
    year_ = t.getYear();
    month_ = t.getMonth();
    day_ = t.getDay();
    hour_ = t.getHour();
    minute_ = t.getMinute();
    return *this;
}

/**
 * Set of custom comparison operators for Dates.
 */
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

/**
 * @brief Date::toString
 * Returns the Date in yyyy-mm-ddThh:ss.mmm
 * format that is used in SMEAR API queries.
 * @return the Date as a string in yyyy-mm-ddThh:ss.mmm format.
 */
std::string Date::toString()
{
    std::string yearStr = std::to_string(year_);
    std::string monthStr = std::to_string(month_);
    if (month_ < 10) monthStr = "0" + monthStr;
    std::string dayStr = std::to_string(day_);
    if (day_ < 10) dayStr = "0" + dayStr;

    return yearStr + "-" + monthStr + "-" + dayStr + "T00:00:00.000";
}

/**
 * @brief Date::advance
 * Advances the date by one day.
 */
void Date::advance()
{
    day_ ++;
    if (isLeapYear())
    {
        if (day_ > days_[1][month_ - 1])
        {
            day_ = 1;
            month_ ++;
        }
    }
    else if (day_ > days_[0][month_ - 1])
    {
        day_ = 1;
        month_ ++;
    }
    if (month_ > 12)
    {
        month_ = 1;
        year_ ++;
    }
}

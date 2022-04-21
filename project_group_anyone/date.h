#ifndef DATE_H
#define DATE_H

#include "string"

/**
 * @brief The Date class
 * Represents a single point in time.
 */
class Date
{
public:
    Date();
    Date(int day, int month, int year, int hour, int min);
    Date(std::string dateStr);
    int getYear()           { return year_; }
    int getMonth()          { return month_; }
    int getDay()            { return day_; }
    int getHour()           { return hour_; }
    int getMinute()         { return minute_; }
    bool validate();
    Date& operator = (Date& t);
    bool operator == (Date& t);
    bool operator != (Date& t);
    bool operator > (Date& t);
    bool operator < (Date& t);
    bool operator >= (Date& t);
    bool operator <= (Date& t);
    std::string toString();
    void advance();

private:
    bool isLeapYear();

    int year_;
    int month_;
    int day_;
    int hour_;
    int minute_;

    const int days_[12][12] =
    {{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
     {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
};

#endif // DATE_H

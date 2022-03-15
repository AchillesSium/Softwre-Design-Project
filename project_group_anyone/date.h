#ifndef DATE_H
#define DATE_H


class Date
{
public:
    Date();
    Date(int day, int month, int year, int hour, int min);
    int getYear()           { return year_; }
    int getMonth()          { return month_; }
    int getDay()            { return day_; }
    int getHour()           { return hour_; }
    int getMinute()         { return minute_; }
    bool validate();
    bool isLeapYear();
    Date& operator = (Date& t);
    bool operator == (Date& t);
    bool operator != (Date& t);
    bool operator > (Date& t);
    bool operator < (Date& t);
    bool operator >= (Date& t);
    bool operator <= (Date& t);
private:
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

#include <iostream>
#include <cstring>
using namespace std;

class Date {
private:
    bool isOurEra;
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
public:
    bool isLeapYear(int year) {
        return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
    }

    int daysInMonth(int month, int year) {
        int daysOfMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (month == 2 && isLeapYear(year)) {
            return 29;
        }
        return daysOfMonth[month];
    }


    Date() {
        this->isOurEra = true;
        this->year = 1960;
        this->month = 1;
        this->day = 1;
        this->hour = 0;
        this->minute = 0;
        this->second = 0;
    }
    Date(int year1,int month1,int day1,int hour1,int minute1,int second1,bool isOurEra1){
		this->isOurEra=isOurEra1;
	    this->year=year1;
	    this->month=month1;
	    this->day=day1;
	    this->hour=hour1;
	    this->minute=minute1;
	    this->second=second1;
	}
    Date add(int year1, int month1, int day1, int hour1, int minute1, int second1) {
        Date result = *this;
        result.year += year1;
        result.month += month1;
        result.day += day1;
        result.hour += hour1;
        result.minute += minute1;
        result.second += second1;
        result.norm();
        return result;
    }

    Date subtract(int year1, int month1, int day1, int hour1, int minute1, int second1) {
        Date result = *this;
        result.year -= year1;
        if (result.year<=0){
            result.year=1-result.year;
        result.isOurEra=0;
        result.month -= month1;
        result.day -= day1;
        result.hour -= hour1;
        result.minute -= minute1;
        result.second -= second1;
        }else{
        result.month -= month1;
        result.day -= day1;
        result.hour -= hour1;
        result.minute -= minute1;
        result.second -= second1;
        }
        result.norm();
        return result;
    }

    void norm() {
        minute += second / 60;
        second %= 60;
        if (second<0){
        second+=60;
        minute--;

        }

        hour += minute / 60;
        minute %= 60;
        if (second<0){
        minute+=60;
        hour--;

        }
        day+=hour/24;
        hour%=24;
        if(hour < 0) {
            hour += 24;
            day--;
        }

        while (day < 1) {
            month--;
            if (month < 1) {
                month = 12;
                year--;
            }
            day += daysInMonth(month, year);
        }

        while (day > daysInMonth(month, year)) {
            day -= daysInMonth(month, year);
            month++;
            if (month > 12) {
                month = 1;
                year++;
            }
        }

        if(month < 1) {
            month += 12;
            year--;
        }

        if (year <= 0) {
            year = 1 - year;
            isOurEra = false;
        } else {
            isOurEra = true;
        }
    }

    friend ostream& operator<<(ostream& os, const Date& dat) {
        os << dat.year << " " << dat.month << " " << dat.day << " " << dat.hour << " " << dat.minute << " " << dat.second;
        if (dat.isOurEra) os << " нашей эры";
        else os << " до нашей эры";
        return os;
    }

    Date& operator =(const Date& dat) {
        this->isOurEra = dat.isOurEra;
        this->year = dat.year;
        this->month = dat.month;
        this->day = dat.day;
        this->hour = dat.hour;
        this->minute = dat.minute;
        this->second = dat.second;
        return *this;
    }

    Date operator +(const Date& dat) {
        Date result=*this;
        int year1 = dat.year;

        int month1 = dat.month;
        int day1 = dat.day;
        int hour1 = dat.hour;
        int minute1 = dat.minute;
        int second1 = dat.second;
        result=result.add(year1, month1, day1, hour1, minute1, second1);
        return result;
    }

    Date operator -(const Date& dat) {
        Date result=*this;
        int year1 = dat.year;
        int month1 = dat.month;
        int day1 = dat.day;
        int hour1 = dat.hour;
        int minute1 = dat.minute;
        int second1 = dat.second;
        result=result.subtract(year1, month1, day1, hour1, minute1, second1);
        return result;
    }

    bool operator ==(const Date& dat) {
        return ((isOurEra == dat.isOurEra) && (year == dat.year) && (month == dat.month) && (day == dat.day) &&
                (hour == dat.hour) && (minute == dat.minute) && (second == dat.second));
    }

    bool operator <=(const Date& dat) {
        return ((isOurEra <= dat.isOurEra) && (year <= dat.year) && (month <= dat.month) && (day <= dat.day) &&
                (hour <= dat.hour) && (minute <= dat.minute) && (second <= dat.second));
    }

    bool operator <(const Date& dat) {
        if (isOurEra != dat.isOurEra) {
            return isOurEra < dat.isOurEra;
        } else {
            if (year != dat.year) {
                return year < dat.year;
            } else {
                if (month != dat.month) {
                    return month < dat.month;
                } else {
                    if (day != dat.day) {
                        return day < dat.day;
                    } else {
                        if (hour != dat.hour) {
                            return hour < dat.hour;
                        } else {
                            if (minute != dat.minute) {
                                return minute < dat.minute;
                            } else {
                                return second < dat.second;
                            }
                        }
                    }
                }
            }
        }
    }

    bool operator >(const Date& dat) {
        if (isOurEra != dat.isOurEra) {
            return isOurEra > dat.isOurEra;
        } else {
            if (year != dat.year) {
                return year > dat.year;
            } else {
                if (month != dat.month) {
                    return month > dat.month;
                } else {
                    if (day != dat.day) {
                        return day > dat.day;
                    } else {
                        if (hour != dat.hour) {
                            return hour > dat.hour;
                        } else {
                            if (minute != dat.minute) {
                                return minute > dat.minute;
                            } else {
                                return second > dat.second;
                            }
                        }
                    }
                }
            }
        }
    }

    bool operator >=(const Date& dat) {
        return ((isOurEra >= dat.isOurEra) && (year >= dat.year) && (month >= dat.month) && (day >= dat.day) &&
                (hour >= dat.hour) && (minute >= dat.minute) && (second >= dat.second));
    }

    Date& operator +=(const Date& dat) {
        if (isOurEra == dat.isOurEra) {
            year += dat.year;
            month += dat.month;
            day += dat.day;
            hour += dat.hour;
            minute += dat.minute;
            second += dat.second;
            norm();
        } else {
            year += dat.year;
            month += dat.month;
            day += dat.day;
            hour += dat.hour;
            minute += dat.minute;
            second += dat.second;
            norm();
        }
        return *this;
    }

    Date& operator -=(const Date& dat) {
        year -= dat.year;
        month -= dat.month;
        day -= dat.day;
        hour -= dat.hour;
        minute -= dat.minute;
        second -= dat.second;
        norm();
        return *this;
    }
};

int main() {
    Date d1;
    setlocale(0, "");
    cout << d1  << endl;
    Date d2(2060, 1, 1, 0, 0, 0, true);
    cout << (d1 > d2) << endl;
    cout << (d1 < d2) << endl;
    cout << (d1 == d2) << endl;
    Date d3 = d2.subtract(2060, 1, 1, 0, 0, 0);
    Date d4(d3 + d2 - d1);
    Date d5(d4);
    d4 += d5 - d4.add(40, 1, 1, 0, 0, 0);

    cout << d3 << endl;
    cout << d4 << endl;
    cout << d5 << endl;

    return 0;
}

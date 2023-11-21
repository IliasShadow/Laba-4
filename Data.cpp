#include <iostream>
#include <cstring>
using namespace std;

class Data{
	public:
	bool isOurEra;
	int year;
	int month;
	int day;
	int hour;
	int minute;
	int second;
	public:
	Data(){
	this->isOurEra=1;
	this->year=1980;
	this->month=1;
	this->day=1;
	this->hour=0;
	this->minute=0;
	this->second=0;
	}
	 bool visok(int year){
        return (((year%4==0)&&(year%100!=0))||(year%400==0));
		}
	void norm(){
		minute+=second/60;
		second%=60;
		hour+=minute/60;
		minute%=60;
		while (second<0){
            second+=60;
            minute--;
        }
        while (minute<0){
            minute+=60;
            hour--;
        }
        while (hour<0){
            hour+= 24;
            day--;
        }

		int daysofMonth[]={0,31,28,31,30,31,30,31,31,30,31,30,31};

		 while (day<1){
            month--;
            if (month<1){
                month=12;
                year--;
            }
            int days=daysofMonth[month];
            if (month==2 && visok(year)){
                days++;
            }
            day+=days;
        }
        while (month>12){
            month-=12;
            year++;
        }
        if (year<=0){
            year= 1-year;
            isOurEra=0;
        }else{isOurEra=1;}
    }
	Data(const Data& dat){
		this->isOurEra=dat.isOurEra;
	    this->year=dat.year;
	    this->month=dat.month;
	    this->day=dat.day;
	    this->hour=dat.hour;
	    this->minute=dat.minute;
	    this->second=dat.second;
	}
	Data& operator =(const Data& dat){
		this->isOurEra=dat.isOurEra;
	    this->year=dat.year;
	    this->month=dat.month;
	    this->day=dat.day;
	    this->hour=dat.hour;
	    this->minute=dat.minute;
	    this->second=dat.second;
		return *this;
	}
	Data add(int year1,int month1,int day1,int hour1,int minute1,int second1){
		Data r=*this;
	    r.year+=year1;
	    r.month+=month1;
	    r.day+=day1;
	    r.hour+=hour1;
	    r.minute+=minute1;
	    r.second+=second1;
		r.norm();
		return r;
	}
	Data subtract(int year1,int month1,int day1,int hour1,int minute1,int second1){
		Data r=*this;
	    r.year-=year1;
	    r.month-=month1;
	    r.day-=day1;
	    r.hour-=hour1;
	    r.minute-=minute1;
	    r.second-=second1;
		r.norm();
		return r;
	}

	bool operator ==(const Data& dat){
		Data r;
		if ((isOurEra==dat.isOurEra)&& (year==dat.year) && (month==dat.month)&& (day==dat.day)&& (hour==dat.hour)&& (minute==dat.minute)&& (second==dat.second)) return 1;
	}
	bool operator <=(const Data& dat){
		return  ((isOurEra<=dat.isOurEra)&& (year<=dat.year) && (month<=dat.month)&& (day<=dat.day)&& (hour<=dat.hour)&& (minute<=dat.minute)&& (second<=dat.second));
	}
	bool operator <(const Data& dat){
		if (isOurEra!=dat.isOurEra){
	return isOurEra<dat.isOurEra;
	}else{
	if (year!=dat.year){
	return year<dat.year;
	}else{
	if (month!=dat.month){
	return month<dat.month;
	}else{
	if (day!=dat.day){
	return day<dat.day;
	}else{
	if (hour!=dat.hour){
	return hour<dat.hour;
	}else{
	if (minute!=dat.minute){
	return minute<dat.minute;
	}else{
	if (second>dat.second){
	return second<dat.second;
	}else return 0;
	}
	}
	}
	}
	}
	}
		}
	bool operator >(const Data& dat){
		if (isOurEra!=dat.isOurEra){
	return isOurEra>dat.isOurEra;
	}else{
	if (year!=dat.year){
	return year>dat.year;
	}else{
	if (month!=dat.month){
	return month>dat.month;
	}else{
	if (day!=dat.day){
	return day>dat.day;
	}else{
	if (hour!=dat.hour){
	return hour>dat.hour;
	}else{
	if (minute!=dat.minute){
	return minute>dat.minute;
	}else{
	if (second>dat.second){
	return second>dat.second;
	}else return 0;
	}
	}
	}
	}
	}
	}
		}
	bool operator >=(const Data& dat){
		return ((isOurEra>=dat.isOurEra)&& (year>=dat.year) && (month>=dat.month)&& (day>=dat.day)&& (hour>=dat.hour)&& (minute>=dat.minute)&& (second>=dat.second));
	}

	Data& operator +=(const Data& dat){
	    year+=dat.year;
	    month+=dat.month;
	    day+=dat.day;
	    hour+=dat.hour;
	    minute+=dat.minute;
	    second+=dat.second;
		norm();
		return *this;
	}
	Data& operator -=(const Data& dat){
		year-=dat.year;
	    month-=dat.month;
	    day-=dat.day;
	    hour-=dat.hour;
	    minute-=dat.minute;
	    second-=dat.second;
		norm();
		return *this;

	}
	Data operator +(const Data& dat){
		Data r;
		int year1=dat.year;
	    int month1=dat.month;
	    int day1=dat.day;
	    int hour1=dat.hour;
	    int minute1=dat.minute;
	    int second1=dat.second;
		r=r.add(year1,month1,day1,hour1,minute1,second1);
		return r;
	}
	Data operator -(const Data& dat){
		Data r;
		int year1=dat.year;
	    int month1=dat.month;
	    int day1=dat.day;
	    int hour1=dat.hour;
	    int minute1=dat.minute;
	    int second1=dat.second;
		r=r.subtract(year1,month1,day1,hour1,minute1,second1);
		return r;
	}
	friend ostream& operator<<(ostream& os, const Data& dat){
        os << dat.year << " " << dat.month << " " << dat.day << " " << dat.hour << " " << dat.minute << " " << dat.second;
        if (dat.isOurEra) os << " нашей эры";
        else os << " до нашей эры";
        return os;
	}

};
int main(){
	setlocale(0,"");
	Data set1,set2;
	set2=set2.add(10,1,12,15,19,1);
	cout<<set1<<endl;
	cout<<set2<<endl;
	cout<<(set1>=set2)<<endl;
	cout<<(set1<set2)<<endl;
	set2=set2.subtract(10,1,12,15,19,1);
	cout<<set2<<endl;
	return 0;
}

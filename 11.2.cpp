#include<iostream>
using namespace std;
class Date{
	public:
		Date() : year(2020),month(5),day(13){}; 
		Date(const Date& d) : year(d.year),month(d.month),day(d.day){};
		Date(int x,int y,int z) : year(x),month(y),day(z){};
		Date NextDay();
		void Set(int y,int m,int d);
		void Input(const string &s); 
		void print(); 
	private:
		int year,month,day;
};
void Date::Set(int y,int m,int d){
	year = y;
	month = m;
	day = d;
}
void Date::Input(const string &s){
	year = (s[0] - '0') * 1000 + (s[1] - '0') * 100 + (s[2] - '0') * 10 + (s[3] - '0');
	month = (s[5] - '0') * 10 + (s[6] - '0');
	day = (s[8] - '0') * 10 + (s[9] - '0');
} 
void Date::print(){
	cout<<"年： "<<year<<" 月： "<<month<<" 日： "<<day<<endl;
}
Date Date::NextDay(){
	Date p;
	p.year = year;
	p.month = month;
	p.day = day;
	p.day++;
	if(p.day == 30 && p.month == 2){
		p.day = 1;
		p.month = 3;
	}
	else if(p.day > 31){
		if(p.month == 12){
			p.year++;
			p.month = 1;
			p.day = 1;
		}
		else {
			p.day = 1;
			p.month ++;
		}
	}
	else if(p.day == 31){
		if(p.month==4||p.month==6||p.month==9||p.month==11){
			p.day = 1;
			p.month ++;
		}
	}
	return p;
} 

class Time : Date{
	public:
		Time():hour(0),minute(0),second(0){}
		Time(int a,int b,int c):hour(a),minute(b),second(c){}
		Time(const Time& b):hour(b.hour),minute(b.minute),second(b.second){}
		void SetTime(int a,int b,int c){
			hour = a;
			minute = b;
			second = c;
		}
		void print(){
			cout<<"时： "<<hour<<" 分： "<<minute<<" 秒： "<<second<<endl;
		}
	private:
		int hour,minute,second;
};
int main(){
	Date d1;
	d1.print();
	Time t1;
	t1.print();
	t1.SetTime(22,34,03);
	t1.print();
//	Date date[10];
//	Date d1,d2(2077,9,14),d3 = d2.NextDay();
//	date[1] = d1;
//	date[2] = d2;
//	date[3] = d3;
//	date[1].print();
//	date[2].print();
//	date[3].print(); 
	return 0;
} 

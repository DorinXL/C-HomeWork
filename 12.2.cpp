#include<iostream>
#include<cstring>
using namespace std;
class String{
	public:
		String(){}
		String(string n):s(n){};
		void SetString(string n){ s = n; }
		string GetString(){ return s;}
		String operator + (const String& b){
			String ss;
			ss = this->s + b.s;
			return ss;
		}
		friend String operator = (const String& a,const String& b){
			if(a.s == b.s){
				return 1;
			}
			else return 0;
		}
		friend String operator < (const String& a,const String& b){
			if(a.s < b.s) return "true";
			else return "flase"; 
		}
	private:
		string s;
};

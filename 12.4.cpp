#include<iostream>
#include<cstring>
using namespace std;
class Cstring{
	public:
		Cstring(){}
		Cstring(const string& c){a = c;}
		Cstring & operator=(const Cstring& D){ 
         this->a = D.a;
        }
		Cstring operator +(const Cstring & b){
			Cstring c;
			c = this->a + b.a;
			return c;
		}
		bool operator <(const Cstring &b){
			if(this->a < b.a) return 1;
			else return 0;
		}
		void Show(){
			cout<<a<<endl;
		};
	private:
		string a;
};
int main(){
	Cstring a("123456");
	Cstring b("abcdef");
	Cstring c = b + a;
	c.Show();
	cout<<endl<<"a是：";
	a.Show();
	a = b;
	cout<<endl<<"a = b 之后的a: ";
	a.Show();
	if(a<b) a.Show();
	else b.Show();
	return 0;
}

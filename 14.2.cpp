#include<iostream>
using namespace std;
template <class T>
class sumnum{
	public:
		sumnum(){}
		sumnum(T a1,T a2,T a3):a(a1),b(a2),c(a3){}
		T GetSum();
	private:
		T a,b,c;
};
template <class T>
T sumnum <T> :: GetSum(){
			return a+b+c;
		}
int main(){
	sumnum <int> a(1,2.0,3.3);
	sumnum <double> b(1,2.0,3.3);
	cout<<a.GetSum()<<endl;
	cout<<b.GetSum()<<endl;
	return 0;
}

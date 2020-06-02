#include<iostream>
#include<cmath>
#include<stdlib.h>
using namespace std;

int gcd(int a,int b)
{
    return b==0 ? a : gcd(b,a%b);
}

class Fraction{
	public:
		Fraction(){standrdize();};
		Fraction(int a,int b):num(a),den(b){standrdize();};
		Fraction operator + (const Fraction &b);
		Fraction operator - (const Fraction &b);
		Fraction operator * (const Fraction &b);
		Fraction operator / (const Fraction &b);
		void standrdize();
		friend ostream &operator << (ostream &output,const Fraction &b){
			output << b.num << "/" << b.den << endl;
			return output;
		}
		friend istream &operator >> (istream &input,Fraction &b){
			input >> b.num >> b.den;
			return input;
		}
	private:
		int num,den;
};
void Fraction::standrdize(){
	long g = gcd(num,den);
	num /= g;
	den /= g;//最小公约,欧几里得 
	if(num == 0 || den == 0){
		num = 0;
		den = 1;
		return;
	}
	if(den < 0){
		den = -den;
		num = -num;
	}
}
Fraction Fraction::operator + (const Fraction &b){
	Fraction a;
	a.num = (this->num * b.den) + (b.num * this->den);
	a.den = this->den * b.den;
	a.standrdize();
	return a;
}
Fraction Fraction::operator - (const Fraction &b){
	Fraction a;
	a.num = (this->num * b.den) - (b.num * this->den);
	a.den = this->den * b.den;
	a.standrdize();
	return a;
}
Fraction Fraction::operator * (const Fraction &b){
	Fraction a;
	a.num = this->num * b.num;
	a.den = this->den * b.den;
	a.standrdize();
	return a;
}
Fraction Fraction::operator / (const Fraction &b){
	Fraction a;
	a.num = this->num * b.den;
	a.den = this->den * b.num;
	a.standrdize();
	return a;
}
int main(){
	Fraction a(1,2),b(2,3);
	cout<<"a + b :"<<(a + b)<<endl;
	cout<<"a - b :"<<(a - b)<<endl;
	cout<<"a * b :"<<(a * b)<<endl;
	cout<<"a / b :"<<(a / b)<<endl;
	return 0;
} 

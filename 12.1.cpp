#include<iostream>
#include<cstring>
using namespace std;
class CShape{
	public:
		virtual double Area(){};
		virtual double SetData(){};
};
class CRect : public CShape{ //¾ØÐÎ 
	public:
		CRect(int a,int b):length(a),width(b){};
		double Area(){
			return length * width;
		}
	private:
		double length,width;
}; 
class CCircle : public CShape{ //¾ØÐÎ 
	public:
		CCircle(int a):rad(a){};
		double Area(){
			return rad * rad * 3.14;
		}
	private:
		int rad;
}; 
class CArea : public CShape{
	public:
		CArea() : rect(5,6),circle(2){};
		double SumArea(){
			return rect.Area() + circle.Area();
		}
	private:
		CRect rect;
		CCircle circle;
};
int main(){
	CArea area;
	cout<<area.SumArea();
	return 0;
} 

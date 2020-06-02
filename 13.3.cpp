#include<iostream>
#include<fstream>
using namespace std;
class Employee{
	public:
		Employee(){}
		Employee(string a,int b,string c,double d){
			name = a;
			age = b;
			num = c;
			pay = d;
		}
		string GetName(){return name;}
		int GetAge(){return age;}
		string GetNum(){return num;}
		double GetPay(){return pay;}
		
	private:
		int age;
		string num;
		string name;
		double pay;
	
};
int main(){
	ofstream out;
	Employee a("张明丽",29,"111-22-333",425.00);
	Employee b("李楷楷",27,"333-22-1111",350.00);
	Employee c("钟静",41,"11-11-0000",650.00);
	out.open("file.txt");
	out << "名字      年龄      编号         工资"<<endl;
	out <<a.GetName()<<"   "<<a.GetAge()<<"   "<<a.GetNum()<<"      "<<a.GetPay()<<endl;
	out <<b.GetName()<<"   "<<b.GetAge()<<"   "<<b.GetNum()<<"    "<<b.GetPay()<<endl;
	out <<c.GetName()<<"      "<<c.GetAge()<<"   "<<c.GetNum()<<"      "<<c.GetPay()<<endl;
	out.close();
	return 0;
}

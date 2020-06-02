#include<iostream>
#include<cmath>
using namespace std;

enum sex{male = 1,female};

class Dog{
	public:
		void Show();
		Dog (string,int,enum sex,double);
		void ChangeName(string);
		void ChangeSex(enum sex);
		void ChangeAge(int);
		void ChangeWeight(double);
	private:
		string name;
		int age;
		enum sex dog_sex;
		double weight;
};
Dog :: Dog(string pname,int page,enum sex psex,double pweight){
	name = pname;
	age = page;
	dog_sex = psex;
	weight = pweight;
}
void Dog ::ChangeName(string pname){
	name = pname;
}
void Dog ::ChangeSex(enum sex psex){
	dog_sex = psex;
}
void Dog ::ChangeAge(int page){
	age = page;
}
void Dog ::ChangeWeight(double pweight){
	weight = pweight;
}
void Dog ::Show(){
	cout<<name<<" "<<age<<" "<<dog_sex<<" "<<weight<<endl;
} 
int main(){ 
	cout<<"定义的方式:名字，年龄，male/female,体重"<<endl;
	Dog dog("Bill",6,male,20.5);
	dog.Show();
	dog.ChangeName("Amazing");
	dog.ChangeAge(12);
	dog.ChangeSex(female);
	dog.ChangeWeight(12.3);
	dog.Show();
	return 0;
} 



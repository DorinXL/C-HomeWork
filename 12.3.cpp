#include<iostream>
using namespace std;
enum BREED{
	YORKIE,CAIRN,DANDIE,SHETLAND,DORERMAN,LAB
};
class Mammal{
	public:
		Mammal():itsAge(2),itsWeight(5){cout<<"Mammal constructor...\n";}
		Mammal(int a,int b):itsAge(a),itsWeight(b){}
		~Mammal(){cout<<"Mammal destructor...\n";}
		int GetAge() const { return itsAge;}
		void SetAge(int age) {itsAge = age;}
		int GetWeight() const {return itsWeight;} 
		void SetWeight(int weight){itsWeight = weight;}
		void Move() const {cout<<"Mammal move one step.\n";}
		virtual void Speak () const {}
		void sleep () const {cout<<"shhh,I'm sleeping.\n";}
		virtual void print () const {}
	protected:
		int itsAge,itsWeight;
};
class Dog : public Mammal{
	public:
		Dog():Mammal(),name("dog"),breed(LAB){}
		Dog(string a,BREED b,int c,int d):name(a),breed(b),Mammal(c,d){}
		~Dog(){cout<<"Mammal Dog destructor...\n";}
		void SetBreed(BREED a) {breed = a;}
		void GetBreed()const {cout<<"This dog's breed is "<<breed<<endl;}
		void Speak () const {cout<<"Woof!"<<endl;}
		void Tail() const {cout<<"Tail wagging...\n";}
		void Beg() const {cout<<"Begging for food...\n";}
		void print() const{
			cout<<"狗的名字： "<<name<<endl;
			cout<<"狗的年龄： "<<GetAge()<<endl;
			cout<<"狗的重量： "<<GetWeight()<<endl;
			GetBreed();
			Speak();
			Tail();
			Beg();
		}
	private:
		string name;
		BREED breed;
};
class Cat : public Mammal{
	public:
		Cat():Mammal(),name("cat"){}
		Cat(string a,int c,int d):name(a),Mammal(c,d){}
		~Cat(){cout<<"Mammal Cat destructor...\n";}
		void Speak () const {cout<<"Weow!"<<endl;}
		void print(){
			cout<<"猫的名字： "<<name<<endl;
			cout<<"猫的年龄： "<<GetAge()<<endl;
			cout<<"猫的重量： "<<GetWeight()<<endl;
		}
	private:
		string name;	
};
class Horse : public Mammal{
	public:
		Horse():Mammal(),name("horse"){}
		Horse(string a,int c,int d):name(a),Mammal(c,d){}
		~Horse(){cout<<"Mammal Horse destructor...\n";}
		void Speak () const {cout<<"Winnie!"<<endl;}
		void print() const {
			cout<<"马的名字： "<<name<<endl;
			cout<<"马的年龄： "<<GetAge()<<endl;
			cout<<"马的重量： "<<GetWeight()<<endl;
		}
	private:
		string name;	
}
;class Pig : public Mammal{
	public:
		Pig():Mammal(),name("Pig"){}
		Pig(string a,int c,int d):name(a),Mammal(c,d){}
		~Pig(){cout<<"Mammal Pig destructor...\n";}
		void Speak () const {cout<<"Oink!"<<endl;}
		void print() const {
			cout<<"猪的名字： "<<name<<endl;
			cout<<"猪的年龄： "<<GetAge()<<endl;
			cout<<"猪的重量： "<<GetWeight()<<endl;
		} 
	private:
		string name;	
};
int main(){
	Mammal *Cairn = new Dog("doga",CAIRN,5,30);
	Mammal *Dorerman = new Dog("dogb",DORERMAN,4,28);
	Mammal *Lab = new Dog("dogc",LAB,6,40);
	Mammal *Cat1 = new Cat("cata",2,15);
	Mammal *Horse1 = new Horse("horse1",5,60);
	Mammal *Pig1 = new Pig("pig1",2,45);
	
	Cairn->print();
	Dorerman->print();
	Lab->print();
	Cat1->print();
	Horse1->print();
	Pig1->print(); 
	return 0; 
} 

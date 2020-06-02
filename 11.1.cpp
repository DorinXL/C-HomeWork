#include<iostream>
#include<cstring>
using namespace std;
enum sex{man,woman};

class Cperson{
	public:
		Cperson():name("样例姓名"),age(114514),astu(man){};
		Cperson(string a,int b,sex c):name(a),age(b),astu(c){};
		void SetPerson(string a,int b,sex c){
			name = a; age = b; astu = c;
		}
		string GetName(){return name;}
		int GetAge(){return age;}
		sex GetSex(){return astu;}
	private:
		string name;
		int age;
		sex astu;
};
class CCourse{
	public:
		CCourse():course_name("样例科目"),credit(0),score(0){};
		CCourse(string a,double b,double c):course_name(a),credit(b),score(c){};
		void SetCourse(string a,double b,double c){
			course_name = a; credit = b; score = c;
		}
		string GetCoure_Name(){return course_name;}
		double GetCreidt(){return credit;}
		double GetScore(){return score;}
	private:
		string course_name;
		double credit;
		double score;
};
class CStudent : public Cperson{
	public:
		CStudent():Cperson(),rank(0),total_score(0),total_credit(0),ave_score(0){};
		CStudent(string a,int b,sex c,int r):Cperson(a,b,c),rank(r),total_score(0){};
		CCourse* GetCourse(int n){
			return course + n;
		}
		void SetStudent(string a,int b,sex c,int r){
			this->SetPerson(a,b,c);
			this->rank = r;
		}
		int GetRank(){return rank;}
		double GetTotal_Score();
		double GetTotal_Credit();
		double GetAve_Score();
	private:
		int rank;
		CCourse course[8];
		double total_score;
		double total_credit;
		double ave_score;
		
};
double CStudent::GetTotal_Score(){
	for(int i = 1;i <= 7;i++){
		if(course[i].GetScore()){
			total_score += course[i].GetScore();
		}
	}
	return total_score;
}
double CStudent::GetTotal_Credit(){
	for(int i = 1;i <= 8;i ++){
		if(course[i].GetCreidt()){
			this->total_credit += course[i].GetCreidt();
		}
	}
	return total_credit;
}
double CStudent::GetAve_Score(){
	int i,sum = 0,flag = 0;
	for(i = 1;i <= 8;i++){
		if(course[i].GetScore()){
			sum += course[i].GetScore();
			flag++;
		}
	}
	ave_score = sum / flag;
	return ave_score;
}
class CClass{
	public:
		CClass(){pstu = new CStudent [10];}
		CClass(int n){pstu = new CStudent [n];}
		CStudent* GetStudent(int n){
			return (pstu + n);
		}
		void Seek(int);
	private:
		CStudent *pstu;
		int class_num,people_num;
		
};
void CClass::Seek(int num){
	cout<<"学生的姓名： "<< pstu[num].GetName() <<endl;
	cout<<"学生的年龄： "<< pstu[num].GetAge() <<endl;
	cout<<"学生的性别： ";
	if(pstu[num].GetSex() == 0) cout<<"man"<<endl;
	else cout<<"woman"<<endl;
	cout<<"学生的学号： "<< pstu[num].GetRank() <<endl;
	cout<<"学生的平均成绩： "<< pstu[num].GetAve_Score() <<endl;
	cout<<"学生的总成绩： "<< pstu[num].GetTotal_Score() <<endl;
	cout<<"学生的总学分： "<< pstu[num].GetTotal_Credit() <<endl<<endl;
}
int main(){
	CClass cla(20);
	cla.GetStudent(1)->SetStudent("张三",12,woman,2);
	cla.GetStudent(1)->GetCourse(1)->SetCourse("C++程序设计",4,30);
	cla.GetStudent(1)->GetCourse(2)->SetCourse("高数",3,0);
	cla.GetStudent(1)->GetCourse(3)->SetCourse("英语",8,60);
	
	cla.GetStudent(2)->SetStudent("李四",12,woman,2);
	cla.GetStudent(2)->GetCourse(1)->SetCourse("C++程序设计",4,60);
	cla.GetStudent(2)->GetCourse(2)->SetCourse("高数",3,10);
	cla.GetStudent(2)->GetCourse(3)->SetCourse("英语",8,30);
	
	cla.GetStudent(3)->SetStudent("王五",12,woman,2);
	cla.GetStudent(3)->GetCourse(1)->SetCourse("C++程序设计",4,90);
	cla.GetStudent(3)->GetCourse(2)->SetCourse("高数",3,20);
	cla.GetStudent(3)->GetCourse(3)->SetCourse("英语",8,20);
	
	cla.Seek(1);
	cla.Seek(2);
	cla.Seek(3);

	return 0;
}

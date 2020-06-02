#include<iostream>
#include<fstream>
using namespace std;
int main(){
	ofstream outfile;
	outfile.open("stock.txt",ios::out | ios::trunc);
	
	outfile << "abcdefG"<<endl;
	
	ifstream infile;
	infile.open("stock.txt");
	
	char s;
	while(!infile.eof()){
		infile >> s;
		if(s == 'a') s -= 32;
	}
	
	outfile << s;
	
	
	outfile.close();
	
	return 0;
} 

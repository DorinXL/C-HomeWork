#include<iostream>
#include<fstream>
using namespace std;
int main(){
	char *buffer;
	int len = 0;
	fstream in,out;
	in.open("file1.txt");
	in << "abcdefGhijklmn"<<endl;
	in.seekg(0,ios::end);
	len = in.tellg();
	cout << "test.txt 文件大小: " << len << "字节" << endl;
	in.seekg(0);
	out.open("file2.txt");
	for(int i = 0;i < 14;i++){
		char j;
		in >> j;
		if(j >= 'A' && j <= 'Z') j += 32;
		else if (j >= 'a' && j <= 'z') j -= 32;
		out << j;
	} 
	
	in.close();
	out.close();
	return 0;
}

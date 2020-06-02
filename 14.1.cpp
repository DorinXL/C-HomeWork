#include<iostream>
using namespace std;
template <typename T>
//class Arr{
//	public:
//		Arr(int c){arr = new T[c];}
//		T& operator [] (int i) {return arr[i];}
//	private:
//		T *arr;
//};
T maxn(T *a,int length){
	T max_n = -10000;
	for(int i = 0;i < length; i++){
		if(a[i] > max_n) max_n = a[i];
	}
	return max_n;
}

int main(){
	int n;
	int a[10] = {1,2,3,4,5,6,7,8,99,20};
	double b[6] = {1.0,22.5,3.66,4.2,4.95,22.6};
	cout<<maxn(a,10)<<endl;
	cout<<maxn(b,6)<<endl;
	return 0;
	
} 

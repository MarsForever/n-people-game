#include <iostream>

using namespace std;
void func(int list);

int main(){
	int list;
	cout << "関数に渡す値を入力してください。" <<endl;
	cin>> list ;

	func(list);
	return 0;
}


void func(int list){

	cout <<"渡された値は" << list << endl;

}
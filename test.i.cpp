#include <iostream>
#include <stdio.h>
using namespace std;

inline int arith(){
	return rand () % 3 + 1;
}

int main (){
	for(int i = 0 ; i +1 <= 100 ; i = i +2){
		cout <<  i  << endl;
		cout << arith() << endl;
	}	
	return 0;
}
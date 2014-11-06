#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <list>
#include <numeric>
#include <algorithm>
#include <fstream>


using namespace std;

int rock = 1;   //　グー　
int scis = 2;  // チョキ
int fabr = 3;   // パー

typedef list<int> LISTINT;
ofstream myfile("Result.txt");

#define T 1000

int game_num = T;

int game_fig[ T] ;

inline int arith(){

	return rand () % 3 + 1;
}
int algo(){
		LISTINT listOne;
	for(int i = 0 ; i <= game_num ; ++i ){
		game_fig[i] = arith();
	}
	if(game_num % 2  == 0)
		for(int i = 0 ; i + 1 <= game_num ; i = i+2 ){
			cout << "\n"<< endl;
			if( game_fig[i] == rock ){
					  if(game_fig[i+ 1] == rock){
					cout << i << " and " << i+1 <<"あいこ" <<endl;
					listOne.push_back(i);
					listOne.push_back(i+1);
				}else if(game_fig[i+ 1] == scis){
					cout << i << "の勝ち" << endl;
					listOne.push_back(i);
				}else /*if(game_fig[i+ 1] == fabr)*/{
					cout << i+1 << "の勝ち" << endl;
					listOne.push_back(i+1);
				}
			}else if(game_fig [i] == scis){
					  if(game_fig[i + 1] == scis){
					cout << i << " and " << i+1 << "あいこ" <<endl;
					listOne.push_back(i);
					listOne.push_back(i+1);
				}else if(game_fig[i+ 1] == fabr){
					cout << i << "の勝ち" << endl;
					listOne.push_back(i);
				}else /*if(game_fig[i+ 1] == rock)*/{
					cout << i+1 << "の勝ち" << endl;
					listOne.push_back(i+1);
				}
			}else /*if(game_fig [i] == fabr)*/{
					  if(game_fig[i +1] == fabr){
					cout << i << " and "<< i+1 << "あいこ" <<endl;
					listOne.push_back(i);
					listOne.push_back(i+1);
				}else if(game_fig[i+ 1] ==rock){
					cout << i << "の勝ち" << endl;
					listOne.push_back(i);
				}else /*if(game_fig[i+ 1] == scis)*/{
					cout << i+1 << "の勝ち" << endl;
					listOne.push_back(i+1);
				}
			//	cout << "\n"<< endl;
			}
		}else{
			for(int i = 0 ; i + 2 <= game_num ; i = i+2 ){
			cout << "\n"<< endl;
			if( game_fig[i] == rock ){
					  if(game_fig[i+ 1] == rock){
					cout << i << " and " << i+1 <<"あいこ" <<endl;
					listOne.push_back(i);
					listOne.push_back(i+1);
				}else if(game_fig[i+ 1] == scis){
					cout << i << "の勝ち" << endl;
					listOne.push_back(i);
				}else /*if(game_fig[i+ 1] == fabr)*/{
					cout << i+1 << "の勝ち" << endl;
					listOne.push_back(i+1);
				}
			}else if(game_fig [i] == scis){
					  if(game_fig[i + 1] == scis){
					cout << i << " and " << i+1 << "あいこ" <<endl;
					listOne.push_back(i);
					listOne.push_back(i+1);
				}else if(game_fig[i+ 1] == fabr){
					cout << i << "の勝ち" << endl;
					listOne.push_back(i);
				}else /*if(game_fig[i+ 1] == rock)*/{
					cout << i+1 << "の勝ち" << endl;
					listOne.push_back(i+1);
				}
			}else /*if(game_fig [i] == fabr)*/{
					  if(game_fig[i +1] == fabr){
					cout << i << " and "<< i+1 << "あいこ" <<endl;
					listOne.push_back(i);
					listOne.push_back(i+1);
				}else if(game_fig[i+ 1] ==rock){
					cout << i << "の勝ち" << endl;
					listOne.push_back(i);
				}else /*if(game_fig[i+ 1] == scis)*/{
					cout << i+1 << "の勝ち" << endl;
					listOne.push_back(i+1);
				}
			}
		}
		//cout << "\n"<< endl;
		listOne.push_back(game_num);
}
	//cout << "\n"<< endl;
	LISTINT::iterator ix; 
	int num = 0;
	
	cout<<"listOne.begin()--- listOne.end():"<<endl; 
		    for (ix = listOne.begin(); ix != listOne.end(); ++ix){ 
		        cout << *ix << " "; 
		  		num++;
		  	//	myfile << *ix << endl ;
		  	}
			cout << " \n" <<num << "個の数が残っている"<< endl;
			
			myfile << num <</* "個の数が残っている" << */ endl;
			game_num = num;
			listOne.erase(listOne.begin(),listOne.end());

}

int main (){

	srand(1);
	int count = 0;
	do{
		algo();
		count++;
	}while(game_num > 3);

	cout <<"algoは" << count <<"回実行されました。"<< endl;
	cout << T << "人の集団" << endl;
	myfile << "algo " ;
	myfile << count ;
	myfile <<" 回実行されました。"<< endl;

	myfile.close();
	return 0;
	
}
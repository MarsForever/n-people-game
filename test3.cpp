#include <iostream>
#include <stdio.h>
#include <stdlib.h>
//#include <fstream>
#include <time.h>

using namespace std;

int rock = 1;   //　グー　
int scis = 2;  // チョキ
int fabr = 3;   // パー

int count_num = 0 ;
int remain =0;
//fstream myfile2("arith.txt" );

#define T 43

int game_num = T;

int game_fig[ T ] ;

inline int arith(){

	return rand () % 3 + 1;
	
}
void algo(){
		int a_num1 = 0 ;
		int a_num2 = 0 ;
		int a_num3 = 0 ;

	for( int i_a = 0 ; i_a < game_num ; ++i_a ){

		game_fig[i_a] = arith();
		//myfile2 << i_a << "\t" <<game_fig[i_a] << endl;

		if(game_fig[i_a] == 1){
			a_num1++;
		}else if(game_fig[i_a] == 2){
			a_num2++;
		}else if(game_fig[i_a] == 3){
			a_num3++;
		}

		if(a_num1 > 0 && a_num2 > 0 && a_num3 > 0){
			cout << "三種類が出てしまった " << endl;
		/*	cout << "a_num1:" << a_num1 << endl;
			cout << "a_num2:" << a_num2 << endl;
			cout << "a_num3:" << a_num3 << endl;
*/
			 a_num1 = 0 ;
			 a_num2 = 0 ;
			 a_num3 = 0 ;
			 count_num ++;

			break;
		}

	}

	

// guu 1  jyoki 2 paa 3
		/*	cout << "a_num1:" << a_num1 << endl;
			cout << "a_num2:" << a_num2 << endl;
			cout << "a_num3:" << a_num3 << endl;
*/
		if(a_num1 > 0 && a_num2 > 0 && a_num3 == 0){
			for(int i = 0 ; i < game_num ; i++ ){	
			//	cout << "game_num "<<game_num << endl;
				if(game_fig[i] == 1){
					cout << i << "グーの勝ち" << endl;
					remain++;

				}else if(game_fig[i] == 2 ){
					cout << i << "はチョキ " << endl;
				}else if(game_fig[i] == 3){
					cout << i << "はパー　" << endl;
				}
					
			}	
					count_num++;
					game_num = remain;
					remain = 0;


		}else if(a_num1 > 0 && a_num3 >0 && a_num2 == 0){

			for(int i = 0 ; i < game_num ; i++ ){	
				if(game_fig[i] == 3){
					cout << i << "パーの勝ち" << endl;
					remain++;
				}else if(game_fig[i] == 1){
					cout << i << "はグー" <<endl;
				}else if(game_fig[i] == 2){
					cout << i << "はチョキ" << endl;
				}
			}
					count_num++;
					game_num = remain;
					remain = 0;

		}else if(a_num2 > 0 && a_num3 > 0 && a_num1 == 0){
			for( int i = 0; i  < game_num ; i++){	
				if(game_fig[i] == 2){
					cout << i << "チョキの勝ち" << endl;
					remain++;
				}else if (game_fig[i] == 1){
					cout << i << "はグー" << endl;
				}else if (game_fig[i] == 3){
					cout << i << "はパー" << endl;
				}
			}
					count_num++;
					game_num = remain;
					remain = 0;
		}

		if(a_num1 > 0 ||  a_num2 > 0 || a_num3 > 0 ){

			cout << "a_num1:" << a_num1 << endl;
			cout << "a_num2:" << a_num2 << endl;
			cout << "a_num3:" << a_num3 << endl;
			cout << "\n";
			}			
}

int main (){
	time_t t_start, t_end;
	t_start = time(NULL);
	srand(0);
	int count = 0;
	do{
		algo();
		count++;
		//cout <<"remain:" <<remain << endl;
	}while(game_num > 3);

	cout <<"algoは" << count_num <<"回実行されました。"<< endl;
	cout << T << "人の集団" << endl;

	//myfile2.close();
	t_end = time(NULL);
	cout << "time :" <<difftime(t_end,t_start) << "s" << endl ;
	return 0;


}
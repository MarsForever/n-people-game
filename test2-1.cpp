#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <time.h>

using namespace std;

int rock = 1;   //　グー　
int scis = 2;  // チョキ
int fabr = 3;   // パー

int count_num = 0 ;
int remain =0;
int befor= 0;
#define WIN 3
#define T 50
//char num = T;
ofstream myfile2("arith.txt");


int game_num = T;

inline int arith(){

	return rand () % 3 + 1;
	
}
void algo(){
	int *game_fig;
	game_fig = (int * )malloc(sizeof(int )* T);
	if(game_fig == NULL)exit(0);
		int a_num1 = 0 ;
		int a_num2 = 0 ;
		int a_num3 = 0 ;

	for( int i_a = 0 ; i_a < game_num ; ++i_a ){

		game_fig[i_a] = arith();
		if(game_fig[i_a] == 1){
			a_num1++;
		}else if(game_fig[i_a] == 2){
			a_num2++;
		}else if(game_fig[i_a] == 3){
			a_num3++;
		}

		if(a_num1 > 0 && a_num2 > 0 && a_num3 > 0){
		//	cout << "三種類が出てしまった " << endl;
			 free(game_fig) ;
			 a_num1 = 0 ;
			 a_num2 = 0 ;
			 a_num3 = 0 ;
			 count_num ++;
			 break;
		}
	}
		remain = 0;
		if(a_num1 > 0 && a_num2 > 0 && a_num3 == 0)
		{
			for(int i = 0 ; i < game_num ; i++ )
			{	
				if(game_fig[i] == 1)
				{
					remain++;
				}	
			}
					count_num++;
					//game_num = remain;
					myfile2 << count_num << "回目に勝負が決まりました" <<endl;
					myfile2 << remain << "人の勝者が残りました。"<<endl;					
					//remain = 0;
		}
			else if(a_num1 > 0 && a_num3 >0 && a_num2 == 0)
			{
				for(int i = 0 ; i < game_num ; i++ )
				{	
					if(game_fig[i] == 3)
					{
						remain++;
					}
				}	
					count_num++;
				//	game_num = remain;
					myfile2 << count_num << "回目に勝負が決まりました" <<endl;
					myfile2 << remain << "人の勝者が残りました。"<<endl;					
					//remain = 0;
		}
			else if(a_num2 > 0 && a_num3 > 0 && a_num1 == 0)
			{
				for( int i = 0; i  < game_num ; i++)
				{	
					if(game_fig[i] == 2)
					{
						remain++;
					}
				}
					count_num++;
					myfile2 << count_num << "回目に勝負が決まりました。" <<endl;
					myfile2 << remain << "人の勝者が残りました。"<<endl;					
		}
				//	 delete[]game_fig ;
		if(a_num1 > 0 ||  a_num2 > 0 || a_num3 > 0 )
		{

			cout << "グー:" << a_num1 << endl;
			cout << "チョキ:" << a_num2 << endl;
			cout << "パー:" << a_num3 << endl;
			cout << "\n";
			cout << "count_num:"<< count_num <<endl;
			myfile2 << "グー:" << a_num1 << endl;
			myfile2 << "チョキ:" << a_num2 << endl;
			myfile2 << "パー:" << a_num3 << endl;
			myfile2 << "\n";
		}	

}		
int main ()
{
	time_t t_start, t_end;
	t_start = time(NULL);
	srand(0);
	int count = 0;
	do
		{
			if(remain != 0)
			{
				game_num = remain ;
			}
			algo();
			count++;
		}
	while(remain > WIN ||remain == 0);	 
	

	cout <<"algoは" << count_num <<"回実行されました。"<< endl;
	cout << T << "人の集団" << endl;
	cout << "remain "<< remain << endl;
	myfile2.close();
	t_end = time(NULL);
	cout << "time :" <<difftime(t_end,t_start) << "s" << endl ;
	return 0;
}
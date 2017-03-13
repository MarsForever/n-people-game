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
int count = 0;
#define WIN 3
#define T 30
//char num = T;
ofstream out("30test.txt");
int game_num = T;
int *game_fig;
int Count_I =0;

inline int arith(){
	return rand () % 3 + 1;
}
void algo()
{
	
	game_fig = (int * )malloc(sizeof(int )* T);
	if(game_fig == NULL)
	{
		exit(0);
	}
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

		if(a_num1 > 0 && a_num2 > 0 && a_num3 > 0)
		{
		//	cout << "三種類が出てしまった " << endl;
			 free(game_fig) ;
			 a_num1 = 0 ;
			 a_num2 = 0 ;
			 a_num3 = 0 ;
			 count_num ++;
			 break;
		}
	}
		if(remain > WIN)
		{
			befor =remain;
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
					out << count_num  <<"\t" << remain <<endl;					
					count++;
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
					out << count_num <<"\t" <<remain <<endl;	
					count++;
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
					out << count_num << "\t"<< remain << endl;		
					count++;			
		}
				//	 delete[]game_fig ;
/*		if(a_num1 > 0 ||  a_num2 > 0 || a_num3 > 0 )
		{

			cout << "グー:" << a_num1 << endl;
			cout << "チョキ:" << a_num2 << endl;
			cout << "パー:" << a_num3 << endl;
			cout << "\n";
			cout << "count_num:"<< count_num <<endl;
			out << "グー:" << a_num1 << endl;
			out << "チョキ:" << a_num2 << endl;
			out << "パー:" << a_num3 << endl;
			out << "\n";			
		}	
*/
}		
void algofor ()
{
	Count_I++;
	out<< "number:"<< Count_I<<endl;
	clock_t t_start, t_end;
	t_start = clock();

	do
		{
		if(remain != 0)
			{
				game_num = remain ;
			}
			algo();
			while(remain < WIN && remain > 0)
			{
					remain = befor;
			}
		}
	while(remain > WIN ||remain == 0);	 


//	cout <<"algoは" << count_num <<"回実行されました。"<< endl;
//	cout << T << "人の集団" << endl;
//	cout << "remain "<< remain << endl;

	out << count_num <<"/t"<<remain << endl;
	out << count <<endl;
	t_end = clock();
	cout << "time :" <<(t_end-t_start) << "ms" << endl ;
	out <<"time:" <<(t_end-t_start) <<"ms"<<endl;
}

int main()
{
	ofstream out;
	out.open("30test.txt",ios::app);
	srand(0);
	for(int i= 0 ; i < 1000 ; i++)
	{
		algofor();
		free(game_fig) ;
		count_num =0;
		remain = 0;
		count = 0;
		befor = 0;
		game_num = T;
	}
	out.close();
	return 0;
}
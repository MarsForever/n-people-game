#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <list>
#include <numeric>
#include <algorithm>
#include <fstream>
//#include <windows.h>
using namespace std;

int rock = 1;   //　グー　
int scis = 2;  // チョキ
int fabr = 3;   // パー

typedef list<int> LISTINT;
ofstream out("test20.txt");

#define T 20
#define WIN 3

int game_num = T;

int game_fig[ T] ;
int remain;
int num ;
int befor;
int count_rem;
int rem;
int i_count;
inline int arith(){
	return rand () % 3 + 1;
}
void algo(){
		LISTINT listOne;
	for(int i = 0 ; i < game_num ; ++i ){
		game_fig[i] = arith();
	}
	befor = remain ;
	remain = 0;
	rem = 0;
	if(game_num  % 2  == 0)
	{
		for(int i = 0 ; i + 1 <= game_num ; i = i+2 )
		{
			if( game_fig[i] == rock ){
				remain++;
				rem++;
				 if(game_fig[i+ 1] == rock)
				 {
				//	out << i << " and " << i+1 <<"あいこ" <<endl;
					listOne.push_back(i);
					listOne.push_back(i+1);
					remain++ ;
				}
				else if(game_fig[i+ 1] == scis)
				{
				//	out << i << "の勝ち" << endl;
					listOne.push_back(i);
				}else if(game_fig[i+ 1] == fabr)
				{
				//	out << i+1 << "の勝ち" << endl;
					listOne.push_back(i+1);
				}
			}
			else if(game_fig [i] == scis)
			{
				rem++;
				remain++;
				 if(game_fig[i + 1] == scis)
				{
				//	out << i << " and " << i+1 << "あいこ" <<endl;
					listOne.push_back(i);
					listOne.push_back(i+1);
					remain++ ;
				}else if(game_fig[i+ 1] == fabr)
				{
				//	out << i << "の勝ち" << endl;
					listOne.push_back(i);
				}else if(game_fig[i+ 1] == rock)
				{
				//	out << i+1 << "の勝ち" << endl;
					listOne.push_back(i+1);
				}
			}
			else if(game_fig[i] == fabr)
			{
				rem++;
				remain++;
				if(game_fig[i +1] == fabr)
				{
				//	out << i << " and "<< i+1 << "あいこ" <<endl;
					listOne.push_back(i);
					listOne.push_back(i+1);
					remain++ ;
				}else if(game_fig[i+ 1] ==rock)
				{
				//	out << i << "の勝ち" << endl;
					listOne.push_back(i);
				}else if(game_fig[i+ 1] == scis)
				{
				//	out << i+1 << "の勝ち" << endl;
					listOne.push_back(i+1);
				}
			}
		}
	}
	else
	{
			for(int i = 0 ; i + 2 <= game_num ; i = i+2 )
			{
			if( game_fig[i] == rock )
			{
				rem++;
				remain++;
				if(game_fig[i+ 1] == rock)
				{
					//out << i << " and " << i+1 <<"あいこ" <<endl;
					listOne.push_back(i);
					listOne.push_back(i+1);
					remain++ ;
				}else if(game_fig[i+ 1] == scis)
				{
				//	out << i << "の勝ち" << endl;
					listOne.push_back(i);
				}else if(game_fig[i+ 1] == fabr)
				{
				//	out << i+1 << "の勝ち" << endl;
					listOne.push_back(i+1);
				}
			}else if(game_fig [i] == scis){
				rem++;
				remain++;
					  if(game_fig[i + 1] == scis){
				//	out << i << " and " << i+1 << "あいこ" <<endl;
					listOne.push_back(i);
					listOne.push_back(i+1);
					remain++ ;
				}else if(game_fig[i+ 1] == fabr){
				//	out << i << "の勝ち" << endl;
					listOne.push_back(i);
				}else if(game_fig[i+ 1] == rock){
				//	out << i+1 << "の勝ち" << endl;
					listOne.push_back(i+1);
				}
			}else if(game_fig [i] == fabr){
				rem++;
				remain++;
					  if(game_fig[i +1] == fabr){
				//	out << i << " and "<< i+1 << "あいこ" <<endl;
					listOne.push_back(i);
					listOne.push_back(i+1);
					remain++ ;
				}else if(game_fig[i+ 1] ==rock){
				//	out << i << "の勝ち" << endl;
					listOne.push_back(i);
				}else if(game_fig[i+ 1] == scis){
				//	out << i+1 << "の勝ち" << endl;
					listOne.push_back(i+1);
				}
			}
		}
		remain ++;
		listOne.push_back(game_num);
}
	LISTINT::iterator ix; 
	 num = 1;
	 /*
	 out << "remain element: \n" << endl;
		    for (ix = listOne.begin(); ix != listOne.end(); ++ix){ 
		       out << *ix << "\t"; 
		       if( num % 5 == 0 )
		        {
		        	out<< "\n"<< endl;
		        }
		        
		  		num++;
		  	}*/
		  	/*
		  	out << "\n" << endl;
			out <<"remain:" << remain<< endl;
			out <<"rem:" <<rem <<"\n" <<endl;
			*/
			
			listOne.erase(listOne.begin(),listOne.end());
			count_rem += rem;
}

void algofor()
{
	
	clock_t t_start, t_end;
	t_start = clock();
	//out<< "number:" << i_count +1 <<endl;
	i_count++;
	int count = 0;
	do
	{
		//out << count+1 << "回戦:" <<endl;
		algo();
		if( remain != 0 )
		{
			//out << "remain:" << remain <<endl;
			game_num = remain;
		}
	
		while(remain < WIN )
		{	
			remain = befor;
			game_num = remain;
		}
		count++;
	}while(remain > WIN || remain == 0);

	cout << "remain :" << remain << endl;
	//out << "remain:" << remain<< endl;
	//remain = 0;
	cout <<"algoは" << count <<"回実行されました。"<< endl;
	cout << "count_rem:" << count_rem << endl;
	cout << T << "人の集団" << endl;
	//out<< T << "人の集団 " <<endl;
	//out<< "algo " ;
	//out<< count <<endl;;
	//out<<" 回実行されました。"<< endl;
	t_end =clock();
	cout << "time :" <<(t_end-t_start) << "ms" << endl ;
	//out <<"計算時間:" <<(t_end-t_start) << "ms" << endl ;
	out<<  count_rem << endl;
	//out << "remain :残っている数"<<endl;
	//out<< "rem :対戦回数" <<endl;
	//out<< "algo: じゃんけんゲームんの実行回数であり、じゃんけんゲームの実際のアルゴリズムでもあります。" <<endl;
	


}

int main()
{
	ofstream out;
	out.open("test20.txt",ios::app);
		srand(0);
	for(int i =0 ; i <1000 ; i++)
	{	
		algofor();
		count_rem = 0;
		game_num = T;
	}
	out.close();
	return 0;
}
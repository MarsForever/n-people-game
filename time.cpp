#include <iostream>
#include <vector>
#include <windows.h>
int main()
{
    std::cout << "QueryPerformanceCounter():\n";
    LARGE_INTEGER freq;
    if( !QueryPerformanceFrequency(&freq) )      // 単位習得
        return 0;
    LARGE_INTEGER start, end;
    for (int i = 0; i < 10; ++i) {
        std::vector<int> v;         // int 型動的配列
        if( !QueryPerformanceCounter(&start) )
            break;       // 取得失敗
        const int N = 1000*100;    //  10万回
        for (int i = 0; i < N; ++i) {
            v.push_back(i);              // 末尾に i を追加
        }
        if( !QueryPerformanceCounter(&end) )
            break;    // 取得失敗
        std::cout << "duration = " << (double)(end.QuadPart - start.QuadPart) / freq.QuadPart << "sec.\n";
    }
   // getchar();
    return 0;
}
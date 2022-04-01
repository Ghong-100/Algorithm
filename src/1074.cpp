// 분할, 재귀
#include <iostream>
#include <cstdio>
#include <array>
#include <algorithm>
#include <math.h>

using namespace std;

int findQt(int N, int row, int col)
{
    int ret = 0, nr = row, nc = col;
    if( !N )
        return ret;
    
    // pivot 변수 잡고 깔끔하게 기준세워서 다시 쓰자
    int pivot = (1 << (N-1)) - 1;   // 2의 2n승 -1

    if( row > pivot )
    {
        ret += 1 << ((2*N)-1);
        nr -= pivot+1;
    }
    if( col > pivot )
    {
        ret += 1 << ((2*N)-2);
        nc -= pivot+1;
    }

    return ret + findQt(N-1, nr, nc);
};

int main(int argc, char** argv)
{
    int N, row, col;
    cin >> N >> row >> col;

    cout << findQt(N, row, col) << endl;;

    return 0;
}
#include <iostream>
#include <cstdio>
#include <array>
#include <algorithm>

using namespace std;

constexpr int MAX_NUM = 1000001;

array<int, MAX_NUM> arr;

int findMinCnt(int val)
{
    if( arr[val] != MAX_NUM )
        return arr[val];
    else
    {
        int m = MAX_NUM;

        // 나누기 3
        if( val%3 == 0 )
            m = min(m, arr[val%3]==MAX_NUM ? findMinCnt(val/3) : arr[val%3]);
        // 나누기 2
        if( val%2 == 0 )
            m = min(m, arr[val%2]==MAX_NUM ? findMinCnt(val/2) : arr[val%2]);
        // 빼기 1
        m = min(m, arr[val-1]==MAX_NUM? findMinCnt(val-1) : arr[val-1]);

        arr[val] = m+1;
        return arr[val];
    }
}



int main(int argc, char* argv[])
{
    fill(arr.begin(), arr.end(), MAX_NUM);
    int N = 0;
    cin >> N;

    arr[1] = 0;
    arr[2] = 1;
    arr[3] = 1;

    cout << findMinCnt(N) << endl;;


    return 0;
}
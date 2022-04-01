#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

#define MAX_NODE    500000

std::array<int, MAX_NODE> arr = { 0 };

int lowerB(int b, int e, int p)
{
    int mid = (b + e) / 2;
    
    while(true)
    {
        if( e <= b )
            break;
        mid = (b + e) / 2;

        if( arr[mid] >= p )
            e = mid;
        else// if( arr[mid] > p )
            b = mid + 1;
    }

    return e;
}

int upperB(int b, int e, int p)
{
    int mid = (b + e) / 2;

    while(true)
    {
        if( e <= b )
            break;
        mid = (b + e) / 2;
        if( arr[mid] > p )
            e = mid;
        else
            b = mid + 1;
    }

    return e;
}

int main(int argc, char** argv)
{
    int nCnt, mCnt;

    scanf("%d", &nCnt);
    for(int i = 0 ; i < nCnt; ++i)
        scanf("%d", &arr[i]);
    
    sort(&arr[0], &arr[nCnt]);
    
    scanf("%d", &mCnt);

    // 123
    int tg = 0;
    int b, e, m, sCnt;
    while(mCnt--)
    {
        scanf("%d", &tg);
        b = 0;
        e = nCnt-1;
        sCnt = 0;
        while(true)
        {
            if( b > e )
                break;
            
            m = (b+e)/2;

            if( arr[m] == tg )
            {
                // 찾았다 요놈
                // upper bound -lower_bound ㄱ 
                sCnt = upperB(m, nCnt, tg) - lowerB(0, m, tg);
                break;
            }
            else if( arr[m] > tg )
                e = m-1;
            else
                b = m+1;
        }
        printf("%d ", sCnt);
    }

    return 0;
}
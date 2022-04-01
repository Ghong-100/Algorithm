#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char* argv[])
{
    int cnt = 0;
    int start, end, diff, pivot = 0;
    double fsq = 0.0;
    cin >> cnt;

    while(cnt--)
    {
        cin >> start;
        cin >> end;
        diff = end - start;
        
        fsq = sqrtf64(diff);

        pivot = (int)fsq;

        if( pivot*pivot == diff )
            printf("%d\n", pivot*2-1);
        else if( pivot*pivot+pivot >= diff )
            printf("%d\n", pivot*2);
        else
            printf("%d\n", pivot*2+1);
    }

    return 0;
}
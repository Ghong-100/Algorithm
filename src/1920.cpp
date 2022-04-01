#include <iostream>
#include <array>
#include <map>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{
    int cnt, nodecnt = 0;
    int input;
    int idx = 0;

    array<int, 100000> arr = { 0 };

    scanf("%d", &cnt);
    nodecnt = cnt;

    while(cnt--)
    {
        scanf("%d", &input);
        arr[idx++] = input;
    }

    sort(&arr[0], &arr[nodecnt]);

    scanf("%d", &cnt);

    int begin, end;

    while(cnt--)
    {
        scanf("%d", &input);

        begin = 0;
        end = nodecnt-1;
        while(true)
        {
            idx =  (int)(begin+end)*0.5;
            if( arr[idx] == input )
            {
                printf("1\n");
                break;
            }
            else if( begin >= end )
            {
                printf("0\n");
                break;
            }
            else if( arr[idx] > input )
                end = idx - 1;
            else
                begin = idx + 1;
        }
    }

    return 0;
}
#include <iostream>
#include <array>

using namespace std;

// 
// 첫째 줄에 자연수 M과 N이 빈 칸을 사이에 두고 주어진다. (1 ≤ M ≤ N ≤ 1,00 0,000) M이상 N이하의 소수가 하나 이상 있는 입력만 주어진다.
// 한 줄에 하나씩, 증가하는 순서대로 소수를 출력한다.
// Eratos

#define MAX_ARR 1000001
void Eratos(int min, int max)
{
    array<int, MAX_ARR> arr = { 0 };
    int mulIdx, mulVal = 0;
    for(int i = 2; i <= max; ++i)
    {
        if( arr[i] == 0 )
        {
            if( i >= min )
                printf("%d\n", i);
            
            mulIdx = 2;
            while(true)
            {
                mulVal = i*mulIdx;
                if( mulVal > max || mulVal > MAX_ARR )
                    break;
                arr[mulVal] = 1;
                ++mulIdx;
            }
        }
    }

}

int main(int argc, char* argv[])
{
    int min,max;
    cin >> min; 
    cin >> max;
	Eratos(min, max);


	return 0;
}

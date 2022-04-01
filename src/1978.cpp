#include <iostream>
#include <array>

using namespace std;

#define MAX_ARR     1001
#define PRIME       1
#define COMPOSITE   2

array<int, MAX_ARR> arr = { 0 };

void Eratos()
{
    int mulVal = 0;
    int primeNum = 0;

    for(int i=2; i < MAX_ARR; ++i)
    {
        if( arr[i] == 0 )
        {
            primeNum = mulVal = i;
            
            arr[mulVal] = PRIME;
            while(true)
            {
                mulVal += primeNum;
                if( mulVal > MAX_ARR )
                    break;
                arr[mulVal] = COMPOSITE;
            }
        }
    }
}

int main(int argc, char** argv)
{
    Eratos();
    int cnt, input = 0;
    int result = 0;

    cin >> cnt;
    while(cnt--)
    {
        cin >> input;
        if( arr[input] == PRIME )
            ++result;
    }

    cout << result << endl;

    return 0;
}
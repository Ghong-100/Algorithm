#include <iostream>
#include <math.h>
#include <string>

using namespace std;

const int   _R = 31;
const int   _M = 1234567891;

// 39,824,770 * 31 + 21
// 39,824,770 * 31   21
// 1,284,670 * 

int main(int argc,char* argv[])
{
    int len;
    cin >> len;

    string str;
    cin >> str;

    // 잠깐만
    // 31진법??? 그냥 _M을 31진법으로 변환해서 쌩으로 나무지연산 때려도 되려나?는 31진법용 나누기, 나머지연산 필요
    // 패스
    
    // 이산수학 ㄱ. 모듈라 연산 ㄱㄱ
    // 을 정석으로 해줄 필요는 없다.
    // 나머지의 몫을 구하는 연산이 아니니까 그냥 앞에서부터 한단계씩 내려오믄 됨.
    // djb2 ㄱㄱ ㄹㅇ
    // 456 % 3 할때
    // 맨앞 4랑 3이 mod 함 쳐서 1이 남고
    // 그 1의 자릿수를 한개 높이고 그담인 5랑 더함. 그럼 15가되고 다시 3이랑 mod 때리믄 0
    // 0에다가 자릿수를 높여봤자 0이니까 걍 그 담인 6이랑 3이랑 mod 치면 0
    // 샘플 2
    // 4567 % 11
    // 4 mod 11 = 4, 4에다 10곱하고 5더함. 45
    // 45 mod 11 = 1, 1에다 10곱하고 6더함. 16
    // 16 mod 11 = 5, 5에다 10곱하고 7더함 . 57
    // 57 mod 11 = 2

    int idx = str.length() - 1;
    int cur = 0;
    unsigned long long hash = 0;
    
    while(idx >= 0)
    {
        cur = str[idx--] - 'a' + 1;
        hash = (((hash << 5) - hash) + cur) % _M;
    };

    cout << hash << endl;


    return 0;
}
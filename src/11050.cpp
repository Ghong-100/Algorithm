#include <iostream>

int main(int argc, char** argv)
{
    int N, K;
    std::cin >> N >> K;
    if( K > N || K< 0)
        std::cout << '0' << std::endl;

    int res = 1;
    int D = N-K;
    while(N > D)
    {
        res *= N--;
    }
    while(K > 1)
    {
        res /=K--;
    }

    std::cout << res << std::endl;
    return 0;
}
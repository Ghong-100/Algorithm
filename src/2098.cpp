#include <iostream>
#include <array>

#define MAX_CITY    16
std::array<std::array<int, MAX_CITY>, MAX_CITY>    W;


void TSP()
{

};

int main(int argc, char** argv)
{
    std::cin.tie(nullptr);
    int cityCnt;
    std::cin >> cityCnt;
    int cost = 0;
    for(int i=0;i<cityCnt;++i)
    {
        for(int j=0;j<cityCnt;++j)
        {
            std::cin >> cost;
            W[i][j] = cost;
        }
    }

    return 0;
}
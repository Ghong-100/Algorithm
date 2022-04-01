#include <iostream>
#include <array>
#include <cstdio>

using namespace std;

#define MAX_CNT     1000

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int M,N;
    cin >> M >> N;

    std::array<std::array<int, MAX_CNT>, MAX_CNT> arr;
    std::array<std::array<pair<int,int>, MAX_CNT*MAX_CNT>, 2>    ripe;

    int tmt;
    int rCnt[2] = { 0 };
    int rareCnt = M*N;

    for(int i=0; i<N; ++i)
    {
        for(int j=0; j<M; ++j)
        {
            cin >>tmt;
            arr[i][j] = tmt;
            if( tmt == 1 )
                ripe[1][rCnt[1]++] = make_pair(i,j);
            else if( tmt == -1 )
                --rareCnt;
        }
    }
    rareCnt -= rCnt[1];

    // for(int i=0; i<N; ++i)
    // {
    //     for(int j=0; j<M; ++j)
    //     {
    //         cout << arr[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    int day = 0, cur = 0, nxt = 0;
    while(true)
    {
        cur = (day+1) % 2;
        nxt = cur?0:1;
        // if( rCnt[cur] == 0 )
        //     break;
        rCnt[nxt] = 0;
        for(int k=0; k<rCnt[cur]; ++k)
        {
            // 4방향 돌리기
            if( ripe[cur][k].first+1 < N  &&
                arr[ripe[cur][k].first+1][ripe[cur][k].second] == 0 ) {
                    arr[ripe[cur][k].first+1][ripe[cur][k].second] = 1;
                    ripe[nxt][rCnt[nxt]++] = make_pair(ripe[cur][k].first+1,ripe[cur][k].second);
                    --rareCnt;
                }

            if( ripe[cur][k].first-1 >= 0 &&
                arr[ripe[cur][k].first-1][ripe[cur][k].second] == 0 ) {
                    arr[ripe[cur][k].first-1][ripe[cur][k].second] = 1;
                    ripe[nxt][rCnt[nxt]++] = make_pair(ripe[cur][k].first-1,ripe[cur][k].second);
                    --rareCnt;
                }

            if( ripe[cur][k].second-1 >= 0 &&
                arr[ripe[cur][k].first][ripe[cur][k].second-1] == 0 ) {
                    arr[ripe[cur][k].first][ripe[cur][k].second-1] = 1;
                    ripe[nxt][rCnt[nxt]++] = make_pair(ripe[cur][k].first,ripe[cur][k].second-1);
                    --rareCnt;
                }

            if( ripe[cur][k].second+1 < M &&
                arr[ripe[cur][k].first][ripe[cur][k].second+1] == 0 ) {
                    arr[ripe[cur][k].first][ripe[cur][k].second+1] = 1;
                    ripe[nxt][rCnt[nxt]++] = make_pair(ripe[cur][k].first,ripe[cur][k].second+1);
                    --rareCnt;
                }
        }

        if( rCnt[nxt] )
            ++day;
        else
            break;
    }
    if( rareCnt )
        cout << -1 << endl;
    else
        cout << day << endl;

    return 0;
}
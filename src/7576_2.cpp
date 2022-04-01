#include <iostream>
#include <queue>
#include <cstdio>
#include <array>

using namespace std;


#define MAX_CNT 1000
#define px      p.first
#define py      p.second

// DFS ㄱㄱ
int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int M, N, tmt;
    cin >> M >> N;

    std::array<array<int, MAX_CNT>, MAX_CNT> arr;
    queue<pair<int, int>>   Q;

    int chkCnt = M*N;
    

    for(int y=0; y<N; ++y)
    {
        for(int x=0; x<M; ++x)
        {
            cin >> tmt; 
            arr[x][y] = tmt;
            if( tmt == 1 )
                Q.push( make_pair(x, y) );
            else if( tmt == -1 )
                --chkCnt;
        }
    }

    // for(int y=0; y<N; ++y)
    // {
    //     for(int x=0; x<M; ++x)
    //         cout << arr[x][y] << ' ';
    //     cout << endl;
    // }
    chkCnt -= Q.size();
    int dCnt[2];
    dCnt[0] = Q.size();
    dCnt[1] = 0;
    int day = 0;
    int cur = 0, nxt = 1;

    pair<int,int> p;
    while(!Q.empty())
    {
        if( dCnt[cur] == 0 )
        {
            cur = nxt;
            nxt = cur?0:1;
            ++day;
        }
        else
            --dCnt[cur];

        p = Q.front();
        Q.pop();

        if( px+1 < M && arr[px+1][py] == 0 )
        {
            Q.push( make_pair(px+1,py) );
            --chkCnt;
            ++dCnt[nxt];
        }
        if( px-1 >= 0 && arr[px-1][py] == 0 )
        {
            Q.push( make_pair(px-1,py) );
            --chkCnt;
            ++dCnt[nxt];
        }
        if( py-1 >= 0 && arr[px][py-1] == 0 )
        {
            Q.push( make_pair(px,py-1) );
            --chkCnt;
            ++dCnt[nxt];
        }
        if( py+1 < N && arr[px][py+1] == 0 )
        {
            Q.push( make_pair(px,py+1) );
            --chkCnt;
            ++dCnt[nxt];
        }
    }
    
    if( chkCnt )
        cout << -1 << endl;
    else
        cout << day << endl;

    return 0;
}
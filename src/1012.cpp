#include <iostream>
#include <cstdio>
#include <array>
#include <stack>
#include <queue>

using namespace std;

constexpr int MAX_SIZE = 50;

int main(int argc, char* argv[])
{
    int T = 0;
    scanf("%d", &T);

    using node = pair<int,int>;
    
    while(T--)
    {
        // 배추 목록에서 하나 뽑아서 worm flag 없으면
        // DFS로 함 둘러주고, 걔들 worm flag 바꿔주고
        // wormcnt++
        int x, y;
        int wormcnt = 0;
        int width, height, cbgCnt;

        queue<node>    worm;
        array<array<int, MAX_SIZE>, MAX_SIZE> field;
        
        scanf("%d %d %d", &width, &height, &cbgCnt);

        // 지렁지렁
        fill(&field[0][0], &field[width-1][height], 0);
        for(int i = 0; i < cbgCnt; ++i)
        {
            scanf("%d %d", &x, &y);
            field[x][y] = 1;
            worm.push( node(x,y) );
        }

        // // 췤
        // for(x=0;x<width;++x)
        // {
        //     for(y=0;y<height;++y)
        //         cout << field[x][y] << ' ';
        //     cout << '\n';
        // }
        while(!worm.empty())
        {
            node cur = worm.front();
            worm.pop();
            if( field[cur.first][cur.second] != 1 )
                continue;
            ++wormcnt;

            stack<node> dfs;
            dfs.push( node(cur.first, cur.second) );

            while(!dfs.empty())
            {
                cur = dfs.top();
                dfs.pop();

                field[cur.first][cur.second] = 2;

                if( cur.first+1<width && field[cur.first+1][cur.second] == 1 )
                    dfs.push( node(cur.first+1, cur.second) );
                if( cur.second+1<height && field[cur.first][cur.second+1] == 1 )
                    dfs.push( node(cur.first, cur.second+1) );
                if( cur.first>0 && field[cur.first-1][cur.second] == 1 )
                    dfs.push( node(cur.first-1, cur.second) );
                if( cur.second>0 && field[cur.first][cur.second-1] == 1 )
                    dfs.push( node(cur.first, cur.second-1) );
            };
        };

        cout << wormcnt << '\n';
    };

    return 0;
}
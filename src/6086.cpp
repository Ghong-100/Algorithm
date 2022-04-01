#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX_FLOW = 1000;
const int nZ = 4;

int main(int argc, char* argv[])
{
    int cnt, flow = 0;
    char fst, snd;
    cin >> cnt;


    int capacity[nZ][nZ] = { 0 };
    int maxFlow[nZ][nZ] = { 0 };
    vector<int> conn[nZ];
    for(auto v : conn)
        fill(v.begin(), v.end(), 0);
    
    for(int i = 0; i < cnt; ++i )
    {
        cin >> fst >> snd >> flow;
        int f = (int)fst-65;
        int s = (int)snd-65;
        
        // 경로별 최대 유량
        maxFlow[f][s] = flow;
        maxFlow[s][f] = flow;

        // 인접 노드 등록해주고
        conn[f].push_back(s);
        conn[s].push_back(f);
    }

    // for(int i=0;i<nZ;++i)
    // {
    //     for(int j=0;j<nZ;++j)
    //         cout << maxFlow[i][j] << ' ';
    //     cout << '\n';
    // }

    queue<int> BFS;
    int cur = 0;

    // 시작 경로 잡아주고
    BFS.push(0);
    while( BFS.size() )
    {
        // 현재 노드 잡아주고
        cur = BFS.front();
        BFS.pop();

    }



    return 0;
}
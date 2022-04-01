#include <iostream>
#include <array>
#include <string>
#include <cmath>

using namespace std;

int main(int argc, char* argv[])
{
    std::array<std::array<int, 750>, 750> mine;

    int row, col = 0;
    string data = "";
    cin >> row; cin >> col;

    std::fill( &mine[0][0], &mine[row-1][col], 0);

    for(int i = 0; i < row; ++i)
    {
        cin >> data;
        for( int j = 0; j < col; ++j)
        {
            if( data[j] == '1' )
                mine[i][j] = 1;
        }
    }
    
    int s = ceil( min(row, col)/(float)2.f );
    int p = 0, d = 0;

    do
    {
        for(int i=0; i <= row-(s*2-1); ++i)
        {
            for(int j=s-1; j < col-(s-1); ++j)
            {
                if( mine[i][j] == 1 )
                {
                    d = (s-1)*2;
                    if( mine[i+d][j] == 1)
                    {
                        // 탐색 최대 높이 = (s-1)*2;
                        for(p = 1; p < s; ++p)
                        {
                            if( !mine[i+p]  [j+p]  ||
                                !mine[i+d-p][j+p]  ||
                                !mine[i+d-p][j-p]  || 
                                !mine[i+p]  [j-p]  )
                                break;
                        }
                        if( p == s )
                        {
                            cout << p << endl;
                            return 0;
                        }
                    }
                }
            }
        }
    }while(s--);


    // for(int i = 0; i < row; ++i)
    // {
    //     for( int j = 0; j < col; ++j)
    //         cout << mine[i][j] << ' ';
    //     cout << '\n';
    // }

    // delete[] mine;

    cout << 0 << endl;

    return 0;
}
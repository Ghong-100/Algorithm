#include <iostream>
#include <array>
#include <string>

using namespace std;

#define MAX_LENGTH 50
#define CHESS_LENGTH 8

int main(int argc, char* argv[])
{
    array<array<bool, MAX_LENGTH>, MAX_LENGTH> board;
    for(auto arr : board)
        fill(arr.begin(), arr.end(), 0);
    
    array<array<bool, CHESS_LENGTH>, CHESS_LENGTH> chess[2];
    bool cellColor = true;  // true == white, false == black
    for(int i=0; i < 2; ++i)
    {
        cellColor = (bool)i;
        for(auto& chessLine : chess[i])
        {
            cellColor = !cellColor;
            for(auto& chessCell : chessLine )
            {
                chessCell = cellColor;
                cellColor = !cellColor;
                // cout << (int)chessCell << ' ';
            }
            // cout << endl;
        }
        // cout << "-------------------------------" << endl;
    }

    int colCnt, rowCnt;
    string s = "";
    cin >> rowCnt >> colCnt;
    for(int row=0;row<rowCnt;++row)
    {
        cin >> s;
        for(int col=0;col<colCnt;++col)
            board[row][col] = (s.at(col)=='W')?true:false;
    }

    // board에서 8*8사이즈 탐색
    int minDiffCnt;
    int diffCnt[2] = { 0 };
    minDiffCnt = 65;
    for(int sRow=0; sRow<=rowCnt-CHESS_LENGTH;++sRow)
    {
        for(int sCol=0; sCol<=colCnt-CHESS_LENGTH;++sCol)
        {
            // 개수 비교
            diffCnt[0] = diffCnt[1] = 0;
            for(int y=0; y<CHESS_LENGTH;++y)
            {
                for(int x=0; x<CHESS_LENGTH;++x)
                {
                    if( board[sRow+y][sCol+x] != chess[0][x][y] )
                        ++diffCnt[0];
                    if( board[sRow+y][sCol+x] != chess[1][x][y] )
                        ++diffCnt[1];
                }
            }
            minDiffCnt = min(minDiffCnt, min(diffCnt[0], diffCnt[1]));
        }
    }

    cout << minDiffCnt << endl;
    // for(auto row:board)
    // {
    //     for(auto col:row)
    //         cout << (col?'W':'B');
    //     cout << '\n';
    // }


    return 0;
}
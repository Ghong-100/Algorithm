#include <iostream>
// #include <cstdio>
#include <string>
#include <array>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

// upper 와 lower 잡은 다음 두 값을 비교해서 더 갠춘한놈으로 ㄱ?
// ㄱㄱ

int main(int argc, char** argv)
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);

    // 아니지 그냥 string으로 박아버려?
    
    // 999 찾을때
    // 0, 1만 사용가능이면
    // 아래에서 치고 올라올땐
    // 그냥 자리수 맞춰서 가장 큰거
    // 111 로 시작하믄 될거구
    // 위에서 내려갈때는 자리수 올릴려믄...
    // 맨앞자리(9)가 지금 내가 사용가능한거보다 커 그럼 +1 자리 후 가장 작은거로 ㄱㄱ
    // 1000 
    //
    // 1. 같은거
    // 2. 없으면 걔보다 작은거중 가장 큰거
    //      -> lower
    // 3. 그리고 걔보다 큰거중 가장 작은거
    //     -> upper
    // 4. lower 랑 upper랑 비교
    // 5. 가능?ㄱ
    //
    // * 10개 다 고장이면 노가다 ㄱㄱ
    // * 현위치 == 찾는값 => 끗!
    
    int N = 0, cur = 100;
    cin >> N;

    std::vector<int> vecBtn;
    for(int i = 0; i < 10; ++i)
        vecBtn.push_back(i);

    int brokenCnt, tmp;
    cin >> brokenCnt;

    while(brokenCnt--)
    {
        cin  >> tmp;
        vecBtn.erase( find(vecBtn.begin(), vecBtn.end(), tmp) );
    }
    // vecBtn.shrink_to_fit(); 안해

    // 칼종료 조건 2개
    if( N == cur ) {
        cout << "0\n";
        return 0;
    }
    else if( vecBtn.empty() ) {
        cout << abs(N - cur) << endl;
        return 0;
    }

    sort(vecBtn.begin(), vecBtn.end());
    string strN = to_string(N);
    int len = strN.length();

    vector<int> vecN;
    for(int i=0; i<len; ++i)
        vecN.push_back( strN.c_str()[i]-'0' );

    vector<int> vecL;
    vecL.reserve(len);
    
    int btnCnt = vecBtn.size();
    int lowN = 0;
    int curN = 0;

    int i, j;
    for(i=0; i<len; ++i)
    {
        // 같은값이면 
        if( curN == lowN )
        {
            // 작지않은 최대값
            for(j=0; j<btnCnt; ++j)
            {
                // 가장 일반적인 케이스
                // lowN+vecBtn[j] > curN+vecN[i] 를 비교해야하지만 lowN==curN이라 더하기는 스킵
                if( vecBtn[j] > vecN[i] )
                {
                    // 15, {1,4,9} 에서 1을 찾아둔 상태. 9에서 멈추고 한칸뒤의 4를 뽑는다.
                    if( j != 0 )
                    {
                        --j;
                        break;
                    }
                    // 10, {1,4,9} 에서 1을 찾아둔 상태. 0보다 1이 크니까. 앞자리에서 내림연산해줘야함.
                    else
                    {
                        int idx = vecL.size() - 1;
                        while( idx>=0 )
                        {
                            if( vecL[idx] > 0 )
                            {
                                --vecL[idx];
                                break;
                            }
                            else
                            {
                                if( idx >= 0 )
                                {
                                    vecL[idx--] = vecBtn.size() - 1;
                                    continue;
                                }
                                else
                                {
                                    
                                }
                            }
                        }
                    }
                }
                // 같으면 끝까지가야지
                else if( vecBtn[j] == vecN[i] )
                    break;
                // 복잡한 케이스

                else if( j == 0 )
                {
                    continue;
                }


            }
            // 그런거 없어
            if( j == btnCnt )
            {
                // 
                continue;
            }
        }
    }


    // for(int i = 0; i < len; ++i)
    // {
    //     int j;
    //     for(j=0; j<btnCnt; ++j)
    //     {
    //         // 작으면 일단 ㄱ
    //         if( vecBtn[j] < vecN[i] )
    //             continue;
    //         // 큰 경우
    //         else if( ( vecBtn[j] > vecN[i] ) )
    //         {
    //             // 처음부터 답없으면 ㅈㅈ
    //             if( i == 0 && j == 0 )
    //             {
    //                 vecL.push_back(-1);
    //                 break;
    //             }
    //             // 멈춰야하는 경우
    //             if( vecBtn[j-1] < vecN[i] )
    //             {
    //                 --j;
    //                 break;
    //             }
    //             // 작은값이 없는경우
    //             if( j == 0 )
    //             {
    //                 // 앞자리 내림 연산 들어간경우
    //                 if( vecBtn[vecL[i-1]] > vecN[i-1] )
    //                 {
    //                     j = btnCnt-1;
    //                     break;
    //                 }

    //                 // 앞줄에서 1씩 빼주고, 현재값은 max로
    //                 for(int k=vecL.size()-1; k >= 0; --k)
    //                 {
    //                     if( vecL[k] != 0 )
    //                     {
    //                         if( vecBtn[vecL[k]] >= vecN[k] )
    //                             vecL[k] -= 1;
    //                         j = btnCnt-1;
    //                         break;
    //                     }
    //                 }
    //             }

    //         }
    //         // 같으면 일단 스톱
    //         else if( vecBtn[j] == vecN[i] )
    //         {
    //             // 앞자리 내림 연산 들어간경우
    //             if( vecBtn[vecL[i-1]] != vecN[i-1] )
    //                 j = btnCnt-1;
    //             break;
    //         }
    //     }
    //     if( vecL.back() == -1 )
    //         break;
    //     j = j==btnCnt?j-1:j;

    //     vecL.push_back(j);
    // }

    // vector<int> vecH;
    // vecH.reserve(len);


    // for(int i = 0; i < len; ++i)
    // {
    //     int j;
    //     for(j=btnCnt-1; j>-1; --j)
    //     {
    //         if( vecBtn[j] > vecN[i] )
    //             continue;
    //         else if( ( vecBtn[j] < vecN[i] ) )
    //         {
    //             if( i == 0 && j == btnCnt-1 )
    //             {
    //                 vecH.push_back(-1);
    //                 break;
    //             }
    //             if( vecBtn[j+1] > vecN[i] )
    //             {
    //                 ++j;
    //                 break;
    //             }
    //             if( j == btnCnt-1 )
    //             {
    //                 // 앞자리 내림 연산 들어간경우
    //                 if( vecBtn[vecH[i-1]] < vecN[i-1] )
    //                 {
    //                     j = 0;
    //                     break;
    //                 }

    //                 // 앞줄에서 1씩 빼주고, 현재값은 max로
    //                 for(int k=vecH.size()-1; k >= 0; --k)
    //                 {
    //                     if( vecH[k]+1 != vecBtn.size() )
    //                     {
    //                         if( vecBtn[vecH[k]] <= vecN[k] )
    //                             vecH[k] += 1;
    //                         j = 0;
    //                         break;
    //                     }
    //                 }
    //             }

    //         }
    //         // 같으면 일단 스톱
    //         else if( vecBtn[j] == vecN[i] )
    //         {
    //             // // 앞자리 내림 연산 들어간경우
    //             if( i == 0 && j == btnCnt-1 )
    //                 break;
    //             if( vecBtn[vecH[i-1]] != vecN[i-1] )
    //                 j = 0;
    //             else
    //                 break;
    //         }
    //     }
    //     if( vecH.back() == -1 )
    //         break;
    //     // if( j < 0 )
    //     // {
    //     //     if( vecBtn[btnCnt-1] >= vecN[i] )
    //     //         j=btnCnt-1;
    //     //     else
    //     //         j = 0;
    //     // }
    //     j = (j<0)?0:j;

    //     vecH.push_back(j);
    // }


    // // for(int i=0; i <vecL.size(); ++i)
    // //     cout << vecBtn[vecL[i]];
    // // cout << endl;

    // // for(int i=0; i <vecH.size(); ++i)
    // //     cout << vecBtn[vecH[i]];
    // // cout << endl;

    // int low=0, high=0;
    // for(int i=0; i <vecL.size(); ++i)
    //     low += vecBtn[vecL[i]] * pow(10, vecL.size()-1-i);

    // for(int i=0; i <vecH.size(); ++i)
    //     high += vecBtn[vecH[i]] * pow(10, vecH.size()-1-i);

    // cout << low << '\n' << high << endl;
    // low = to_string(low).length() + abs(low-N);
    // high = to_string(high).length() + abs(high-N);

    // cout << min( low, high ) << endl;

    // cout << strN.length() + min( abs( stoi(strLow)-N), abs( stoi(strHigh)-N)) << endl;
    // // 아래서부터 올라가자
    // for(int i = 0; i < len; ++i)
    // {
    //     int num = strN.c_str()[i] - '0';
    //     Itr it = vecBtn.begin();
    //     vector<int> vecLow;

    //     while(true)
    //     {
    //         if( it == vecBtn.end() )
    //             break;

    //         if( 

    //     }



    //     while(true)
    //     {
    //         // 끗
    //         if( it == vecBtn.end() )
    //             break;
            
    //         // 멈춰야할때. 더 크면.
    //         else if( stoi(strLow+to_string(*it)) > stoi(strN.substr(0, i+1)) )
    //         {
                
    //             Itr pre = find(vecBtn.begin(), vecBtn.end(), strLow.c_str()[i-1]-'0');
    //             // 앞자리를 하나 작게
    //             if( pre != vecBtn.begin() )
    //             {
    //                 strLow = strLow.substr(0, strLow.length()-1);
    //                 strLow += to_string( *(pre-1) );
    //             }
    //             else
    //             {
    //                 // 못하면? strN보다 작은 strLow를 만들수가 없음
    //                 it = vecBtn.end();
    //                 strLow = "";
    //                 break;
    //             }
    //         }
    //         // 같음 끗이지
    //         else if( strLow+to_string(*it) == strN.substr(0, i+1) )
    //         {
    //             break;
    //         }
    //         else
    //         {

    //         }





    //         else if( *(it+1) > num )
    //         {
    //             if( !strLow.length() )
    //                 break;
                
    //             // 크기 비교 ㄱ
    //             // strLow가 strN보다 크게 나올 경우, 앞자리에 있는 숫자를 하나 작게해준다.
    //             // strN = 50 일때 { 1, 5 } 면
    //             // 첫사이클에서 strLow 는 "5"가 들어있고 strLow는 "51"이 될거구
    //             // 51 > 50 이니까 strLow의 "5"를 "1"로 바꿔줘
    //             if( stoi(strLow+to_string(*it)) > stoi(strN.substr(0, i+1)) )
    //             {
    //                 Itr pre = find(vecBtn.begin(), vecBtn.end(), strLow.c_str()[i-1]-'0');
    //                 // 앞자리를 하나 작게
    //                 if( pre != vecBtn.begin() )
    //                 {
    //                     strLow = strLow.substr(0, strLow.length()-1);
    //                     strLow += to_string( *(pre-1) );
    //                 }
    //                 else
    //                 {
    //                     // 못하면? strN보다 작은 strLow를 만들수가 없음
    //                     it = vecBtn.end();
    //                     strLow = "";
    //                     break;
    //                 }
    //             }
    //             // 500, { 4, 5, 9 } 면 5 -> 49 -> 499 로 가야하니까
    //             // 5
    //             // 499
    //             // 
    //             else if( stoi(strLow+to_string(*it)) < stoi(strN.substr(0, i+1)) )
    //             {
    //                 ++it;
    //             }
    //             else
    //                 break;

    //             /*
    //             // if( *(it) > num && i != 0 && strLow.c_str()[i-1] >= strN.c_str()[i-1] )
    //             if( *(it) > num && it == vecBtn.begin() )
    //             {
    //                 Itr pre = find(vecBtn.begin(), vecBtn.end(), strLow.c_str()[i-1]-'0');
    //                 if( pre != vecBtn.begin() && pre != vecBtn.end() )
    //                 {
    //                     // 이전 스트링에서 1빼줘야함
    //                     // strLow.substr(0, strLow.length()-1);
    //                     // strLow += to_string( *(it-1) );
    //                     // strLow.at(strLow.length()-1) = to_string( *(it-1) );
    //                     strLow = strLow.substr(0, strLow.length()-1);
    //                     strLow += to_string( *(pre-1) );
    //                 }

    //             }
    //             // else if( *it <= num )
    //             //     break;
    //             // else
    //             // ++it;
    //             break;
    //             */
    //         }
    //         else
    //             ++it;
    //     }
    //     // cout << *(it) << endl;
    //     if( it != vecBtn.end() )
    //         strLow += to_string(*it);
    //     // cout << strLow << endl;
    // }

    // // 위에서 내려오는거
    // for(int i = 0; i < len; ++i)
    // {
    //     int num = strN.c_str()[i] - '0';
    //     RItr it = vecBtn.rbegin();

    //     while(true)
    //     {
    //         if( (it+1) == vecBtn.rend() )
    //             break;
    //         else if( *(it+1) < num )
    //         {
    //             if( *(it) < num && it == vecBtn.rbegin() )
    //             {
    //                 RItr pre = find(vecBtn.rbegin(), vecBtn.rend(), strHigh.c_str()[i-1]-'0');
    //                 if( pre != vecBtn.rbegin() && pre != vecBtn.rend() )
    //                 {
    //                     strHigh = strHigh.substr(0, strHigh.length()-1);
    //                     strHigh += to_string( *(pre-1) );
    //                 }
    //             }
    //             break;
    //             // else
    //             //     ++it;
    //         }
    //         else
    //             ++it;
    //     }
    //     // cout << *(it) << endl;
    //     strHigh += to_string(*it);
    // }

    // cout << strLow << endl;
    // cout << strHigh << endl;

    // cout << strN.length() + min( abs( stoi(strLow)-N), abs( stoi(strHigh)-N)) << endl;


    return 0;
}
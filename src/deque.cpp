/*
push_front X: 정수 X를 덱의 앞에 넣는다.
push_back X: 정수 X를 덱의 뒤에 넣는다.
pop_front: 덱의 가장 앞에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
pop_back: 덱의 가장 뒤에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
size: 덱에 들어있는 정수의 개수를 출력한다.
empty: 덱이 비어있으면 1을, 아니면 0을 출력한다.
front: 덱의 가장 앞에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
back: 덱의 가장 뒤에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.


map에 string,function 객체를 담아서 Input 으로 받은 string에 해당하는 function 을 호출하도록
시간제한 있으니까 신규 할당, 해제는 없게. array에 node max cnt 잡아두고 idx와 cnt로 컨트롤

*/
#include <iostream>
#include <string>
#include <map>
#include <array>
#include <functional>
#include <cstdio>

#define MAX_NODE 10001
using namespace std;

class Deque
{
public:
    array<int, MAX_NODE>    dq = { 0 };
    int                     fIdx = 0;
    int                     bIdx = 0;
    int                     cnt = 0;

    map<string, function<void()>>  dFunc;
public:
    void    Excute(const string& command) {
        dFunc[command]();
    };
    void    InitCommand();
public:
    Deque()
    {
        InitCommand();
    }
};

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Deque dd;

    int cnt = 0;
    string command;
    cin >> cnt;
    while(cnt--)
    {
        cin >> command;
        dd.Excute(command);
    }

    return 0;
}

void Deque::InitCommand()
{
    dFunc["push_front"] = [this]() {
        fIdx = --fIdx<0?MAX_NODE-1:fIdx;
        cin >> dq[fIdx];
        bIdx = cnt?bIdx:fIdx;
        ++cnt;
    };
    dFunc["push_back"] = [this]() {
        bIdx = ++bIdx==MAX_NODE?0:bIdx;
        fIdx = cnt?fIdx:bIdx;
        cin >> dq[bIdx];
        ++cnt;
    };
    dFunc["pop_front"] = [this]() {
        if( cnt )
        {
            printf("%d\n", dq[fIdx++]);
            --cnt;
            fIdx = (fIdx==MAX_NODE)?0:fIdx;
            bIdx = cnt?bIdx:fIdx;
        }
        else
            printf("%d\n", -1);
    };
    dFunc["pop_back"] = [this]() {
        if( cnt )
        {
            printf("%d\n", dq[bIdx--]);
            --cnt;
            bIdx = bIdx<0?MAX_NODE-1:bIdx;
            fIdx = cnt?fIdx:bIdx;
        }
        else
            printf("%d\n", -1);
    };
    dFunc["size"] = [this]() {
        printf("%d\n", cnt);
    };
    dFunc["empty"] = [this]() {
        printf("%d\n", cnt?0:1);
    };
    dFunc["front"] = [this]() {
        printf("%d\n", cnt?dq[fIdx]:-1);
    };
    dFunc["back"] = [this]() {
        printf("%d\n", cnt?dq[bIdx]:-1);
    };
};
#include <iostream>
#include <string>
#include <array>
#include <cstdio>
#include <map>
#include <functional>

using namespace std;

class Queue
{
    class Node  {
        public:
            int     value = 0;
            Node*   next = nullptr;
        Node(int v) : value(v) {}
    };
private:
    Node*   front = nullptr;
    Node*   back  = nullptr;
    int     cnt = 0;
public:
    void   Push(int& val);
    int    Pop();
    int    Size();
    int    Empty();
    int    Front();
    int    Back();

    ~Queue() {
        Node* p = front;
        while(p);
        {
            p = front;
            front = p->next;
            delete p;
        }
    }
};

void Queue::Push(int& val)
{
    if( front == nullptr )
    {
        front = new Node(val);
        back = front;
        ++cnt;
    }
    else
    {
        back->next = new Node(val);
        back = back->next;
        ++cnt;
    }    
};

int Queue::Pop()
{
    int res = 0;
    if( front )
    {
        res = front->value;
        front = front->next;
        --cnt;
        if( front == nullptr ) back = nullptr;
    }
    else
        res = -1;
    return res;
};

int Queue::Size()
{
    return cnt;
};

int Queue::Empty()
{
    return cnt?0:1;
};

int Queue::Front()
{
    return cnt?front->value:-1;
};

int Queue::Back()
{
    return cnt?back->value:-1;
};

int main(int argc, char* argv[])
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(nullptr);
    int cmd = 0;
    cin >> cmd;
    
    string command = "";
    int    val = 0;
    Queue   Q;

    while(cmd--)
    {
        cin >> command;
        if( command == "push" )
        {
            cin >> val;
            Q.Push(val);
        }
        else if( command == "pop" )
            printf("%d\n", Q.Pop());
        else if( command == "size" )
            printf("%d\n", Q.Size());
        else if( command == "empty" )
            printf("%d\n", Q.Empty());
        else if( command == "front" )
            printf("%d\n", Q.Front());
        else if( command == "back" )
            printf("%d\n", Q.Back());
    }


    return 0;
}
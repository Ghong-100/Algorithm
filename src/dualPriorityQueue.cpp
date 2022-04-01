#include <iostream>
#include <cstdio>
#include <set>
#include <execinfo.h>

using namespace std;

void func2()
{
    int size;
    void*   arr[10];
    char**  str;

    size = backtrace(arr, 10);

    cout << "size : " << size << endl;

    str = backtrace_symbols(arr, size);
    for(int i = 0; i < size; ++i)
    {
        cout << str[i] << endl;
    }

    delete str;

}

void func1()
{
    func2();
}

int main()
{
    func1();

    return 0;
 
    int tCnt;   // 테스트 횟수
    scanf("%d", &tCnt);

    int cCnt = 0;
    char cmd;
    int val;
    while(tCnt--)
    {
        scanf("%d", &cCnt);
        multiset<int> map;
        while(cCnt--)
        {
            scanf(" %c %d", &cmd, &val);
            //cin >> cmd >> val;
            if( cmd == 'I' )
                map.insert(val);
            else
            {
                if( !map.empty() )
                {
                    if( val > 0 )
                        map.erase( map.lower_bound(*map.rbegin()) );
                    else
                        map.erase( map.lower_bound(*map.begin()) );
                }
            }
        }
        if( map.empty() )
            printf("EMPTY\n");
        else
            printf("%d %d\n", *map.rbegin(), *map.begin() );
    }

    return 0;
}

// #include <iostream>
// #include <array>
// #include <cstdio>

// using namespace std;

// #define MAX_CMD     1000000

// typedef class DualPriorityQueue
// {
// public:
//     class Node
//     {
//     public:
//         int     val = 0;
//         Node*   left = nullptr;
//         Node*   right = nullptr;
//         void    Init() { val=0;left=right=nullptr; };
//     };

// public:
//     Node*       front = nullptr;
//     Node*       end = nullptr;
//     int         cnt = 0;

// public:
//     void        Insert(int& val);
//     void        Delete(int& val);
//     void        reset() { cnt = 0; front = end = nullptr; };
// } DPQ;

// class Pool
// {
// private:
//     DPQ::Node   node[MAX_CMD];
//     int         cnt = 0;
// public:
//     DPQ::Node*  getNode() { return &node[cnt++]; };
//     void        reset() {
//         for(int idx=0;idx<cnt;++idx)
//             node[idx].Init();
//         cnt = 0;
//     };
// };

// Pool pool;

// int main(int argc, char** argv)
// {
//     cin.tie(nullptr);
//     ios_base::sync_with_stdio(false);
//     int tCnt;   // 테스트 횟수
//     cin >> tCnt;

//     int cCnt;   // 테스트당 입력할 커맨드 개수
//     char    cmd;
//     int     val;
//     DPQ     dpq;

//     while(tCnt--)
//     {
//         cin >> cCnt;
//         while(cCnt--)
//         {
//             cin >> cmd >> val;
//             if( cmd == 'I' )
//                 dpq.Insert(val);
//             else if (cmd == 'D')
//                 dpq.Delete(val);
//         }
        
//         if( dpq.cnt )
//             printf("%d %d\n", dpq.end->val, dpq.front->val);
//         else
//             printf("EMPTY\n");
        
//         pool.reset();
//         dpq.reset();
//     }
//     return 0;
// }

// void DualPriorityQueue::Insert(int& val)
// {
//     Node*   tmp = pool.getNode();
//     tmp->val = val;
//     if( cnt )
//     {
//         Node*   cur = front;
//         // 맨 앞
//         if( cur->val > tmp->val )
//         {
//             cur->left = tmp;
//             tmp->right = cur;
//             front = tmp;
//         }
//         else
//         {
//             // 제일 뒤거나 위치를 찾은 경우
//             while(cur->right && cur->right->val <= val)
//             {
//                 cur = cur->right;
//             }
//             if( cur->right )
//             {   // 중간
//                 tmp->left = cur;
//                 tmp->right = cur->right;
//                 cur->right->left = tmp;
//                 cur->right = tmp;
//             }
//             else
//             {   // 맨 뒤
//                 cur->right = tmp;
//                 tmp->left = cur;
//                 end = tmp;
//             }
//         }
//         ++cnt;
//     }
//     else
//     {
//         front = end = tmp;
//         ++cnt;
//     }
// }

// void DualPriorityQueue::Delete(int& val)
// {
//     if( val > 0 )
//     {
//         if( end )
//         {
//             if( end->left )
//             {
//                 end->left->right = nullptr;
//                 end = end->left;
//             }
//             else
//                 end = nullptr;
//             front = --cnt?front:nullptr;
//         }
//     }
//     else
//     {
//         if( front )
//         {
//             if( front->right )
//             {
//                 front->right->left = nullptr;
//                 front = front->right;
//             }
//             else
//                 front = nullptr;
//             end = --cnt?end:nullptr;
//         }
//     }
// }
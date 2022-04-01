#include <iostream>
#include <string>
#include <array>
#include <algorithm>

using namespace std;

int main(int argc, char** argv)
{
    int cnt;
    cin >> cnt;

    array<pair<int, char*>, 100001> arr;
    int age = 0;
    char name[100001][101];
    for(int i = 0; i < cnt; ++i)
    {
        scanf("%d %s", &age, name[i]);
        arr[i] = make_pair(age, name[i]);
    }

    stable_sort(&arr[0], &arr[cnt], [](const pair<int, char*>& fst, const pair<int, char*>& snd)->bool {
        return fst.first < snd.first;
    });

    for(int i = 0; i < cnt; ++i)
    {
        printf("%d %s\n", arr[i].first, arr[i].second);
    }

    return 0;
}
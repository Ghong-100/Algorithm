#include <iostream>
#include <array>
#include <algorithm>

using namespace std;



int main(int argc, char** argv)
{
    array<pair<int, int>, 100001> arr;

    using P = pair<int, int>;
    P input = { 0, 0 };
    int cnt;
    cin >> cnt;

    for(int i = 0; i < cnt; ++i)
    {
        cin >> input.first >> input.second;
        arr[i] = input;
    }


    sort(&arr[0], &arr[cnt], [](const P& fst, const P& snd)->bool{
        return (fst.first == snd.first) ? (fst.second<snd.second) : (fst.first<snd.first);
    });

    for(int i = 0; i < cnt; ++i)
    {
        cout << arr[i].first << ' ' << arr[i].second << endl;
    }

    return 0;
}
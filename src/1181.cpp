#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(int argg, char** argv)
{
    int cnt = 0;
    cin >> cnt;

    map<string, string> dict[50];
    
    string input;
    
    while(cnt--)
    {
        cin >> input;
        dict[input.length()-1].insert( make_pair(input, input) );
    }

    for(auto d : dict )
        for(auto o: d)
            cout << o.first << '\n';

    return 0;
}
#include <iostream>
#include <string>

int main()
{
    std::string input;
    int len = 0;
    bool isP = true;

    while(true)
    {
        std::cin >> input;

        if( input == "0" )
            break;

        len = input.length();
        isP = true;
        for(int i = 0; i < len*0.5; ++i)
        {
            if( input[i] != input[len-i-1] )
            {
                isP = false;
                break;
            }
        }
        if( isP )
            printf("yes\n");
        else
            printf("no\n");
    }


    return 0;
}
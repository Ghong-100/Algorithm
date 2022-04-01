#include <iostream>
#include <math.h>

int main()
{
    int num[3];
    int m, p;
    while(true)
    {
        scanf("%d %d %d", &num[0], &num[1], &num[2]);
        if( !num[0] && !num[1] && !num[2] )
            break;
    
        m = (num[0]>num[((num[1]>num[2]) ? 1 : 2)])?0:((num[1]>num[2]) ? 1 : 2);
        p = num[m] * num[m];
        for(int i = 0; i < 3; ++i)
            if( m != i )
                p -= (num[i]*num[i]);
        
        if( p )
            printf("wrong\n");
        else
            printf("right\n");

    }

    return 0;
}
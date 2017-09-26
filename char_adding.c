#include <iostream>
#include <string.h>

int addop(char a, char b, int j, char *r)
{
    char tmp = a+b+j - '0';
    if(tmp > '9')
    {
        *r = tmp - 10;
        return 1;
    }
    else
    {
        *r = tmp;
        return 0;
    }
}

int main(int argc, char * argv[])
{
    if(argc != 3)
        return 1;
    char *s = argv[1];
    char *t = argv[2];
    int ss = strlen(s)-1;
    int st = strlen(t)-1;
    char j = 0;
    while(1)
    {
        j = addop(s[ss],t[st],j,t+st);
        ss -= 1;
        st -= 1;
        if(ss <0 || st<0)
        {
            while(j)
            {
                j = addop('0',t[st],j,t+st);
                st--;
            }
            break;
        }
    }
    std::cout << t << std::endl;
}

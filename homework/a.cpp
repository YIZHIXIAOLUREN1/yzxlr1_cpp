#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 7;
#define gc() getchar()
#define pc(x) putchar(x)
#define endl pc(10)
inline int read()
{
    int w = 1, q = 0;
    char ch = ' ';
    while (ch != '-' && (ch < '0' || ch > '9'))
        ch = gc();
    if (ch == '-')
        w = -1, ch = gc();
    while (ch >= '0' && ch <= '9')
        q = q * 10 + ch - '0', ch = gc();
    return w * q;
}
inline void pr(ll x)
{
    if (x < 0)
        pc('-'), x = -x;
    if (x > 9)
        pr(x / 10);
    pc(x % 10 + '0');
}
int main()
{
    int a, b;
    float x;

    scanf("%d,%d",&a,&b);

    x = (float)2*a*b / (a + b)/(a + b);

    printf("x=%f\n", x);

    return 0;
}

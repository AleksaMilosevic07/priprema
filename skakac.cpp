#include <bits/stdc++.h>
using namespace std;

long long M[1005][1005];
long long X, Y;

int main()
{
    cin>>X>>Y;
    M[0][1] = 1;
    for(int i = 2; i<=X+1; i++)
    {
        for(int j = 2; j <= Y+1; j++)
        {
            M[i][j] += M[i-2][j+1];
            M[i][j] += M[i-2][j-1];
            M[i][j] += M[i-1][j+2];
            M[i][j] += M[i-1][j-2];

        }
    }
    cout<<M[X+1][Y+1]<<endl;
    return 0;
}

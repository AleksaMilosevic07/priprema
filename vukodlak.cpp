#include <bits/stdc++.h>
using namespace std;

char matrica[1005][1005];
int N, M, brojOvaca;

void DFS(int i, int j)
{
    matrica[i][j] = '#';
    if(matrica[i][j + 1] == '.' or matrica[i][j + 1] == 'K')
    {
        if(matrica[i][j + 1] == 'K')
        {
            brojOvaca--;
        }
        DFS(i, j + 1);
    }
    if(matrica[i + 1][j] == '.' or matrica[i+1][j] == 'K')
    {
        if(matrica[i+1][j] == 'K')
        {
            brojOvaca--;
        }
        DFS(i+1, j);    }
    if(matrica[i][j - 1] == '.' or matrica[i][j-1] == 'K')
    {
        if(matrica[i][j-1] == 'K')
        {
            brojOvaca--;
        }
        DFS(i, j - 1);
    }
    if(matrica[i - 1][j] == '.' or matrica[i-1][j] == 'K')
    {
        if(matrica[i-1][j] == 'K')
        {
            brojOvaca--;
        }
        DFS(i - 1, j);
    }
}


int main()
{
    memset(matrica, '#', sizeof(matrica));
    scanf("%d %d", &N, &M);
    for(int i = 1; i<=N; i++)
    {
        for(int j = 1; j<=M; j++)
        {
            cin>>matrica[i][j];
            if(matrica[i][j] == 'K')
            {
                brojOvaca++;
            }
        }
    }

    for(int i = 1; i<=N; i++)
    {
        for(int j = 1; j<=M; j++)
        {
            if(matrica[i][j] == 'V')
            {
               DFS(i, j);
            }
        }
    }

    cout<<brojOvaca<<endl;
    return 0;
}

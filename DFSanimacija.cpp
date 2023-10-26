#include <bits/stdc++.h>
using namespace std;

char matrica[1005][1005];
int N, M;

void ispis()
{
    for(int i = 1; i<=N; i++)
    {
        for(int j = 1; j<=M; j++)
        {
            cout<<matrica[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<endl;
    cout<<endl;
}


void DFS(int i, int j)
{
    matrica[i][j] = '#';
    if (matrica[i][j + 1] == '.')
    {
        ispis();
        DFS(i, j + 1);
    }
    if (matrica[i + 1][j] == '.')
    {
        ispis();
        DFS(i + 1, j);
    }
    if (matrica[i][j - 1] == '.')
    {
        ispis();
        DFS(i, j - 1);
    }
    if (matrica[i - 1][j] == '.')
    {
        ispis();
        DFS(i - 1, j);
    }
}





int main()
{
    memset(matrica, '#', sizeof(matrica));

    scanf("%d %d", &N, &M);
    for(int i = 1; i<= N; i++)
    {
        for(int j = 1; j<=M; j++)
        {
            matrica[i][j] = '.';
        }
    }

    DFS(1, 1);


    return 0;
}

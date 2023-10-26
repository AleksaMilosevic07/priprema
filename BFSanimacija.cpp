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
    system("pause");
}

void BFS(int R, int C)
{
    queue <int> QR, QC;
    QR.push(R);
    QC.push(C);
    matrica[R][C] = '#';

    while(QR.size())
    {
        R = QR.front();
        C = QC.front();
        if (matrica[R][C + 1] == '.')
        {
            QR.push(R);
            QC.push(C+1);
            matrica[R][C + 1] = '#';
        }
        if (matrica[R + 1][C] == '.')
        {
            QR.push(R+1);
            QC.push(C);
            matrica[R + 1][C] = '#';
        }
        if (matrica[R][C - 1] == '.')
        {
            QR.push(R);
            QC.push(C-1);
            matrica[R][C - 1];

        }
        if (matrica[R - 1][C] == '.')
        {
            QR.push(R-1);
            QC.push(C);
            matrica[R - 1][C] = '#';
        }
        ispis();
        QR.pop();
        QC.pop();
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
            matrica[i][j] = '.';
        }
    }
    BFS(1, 1);

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

char livadu[1005][1005];

void BFS(int R, int C)
{
    queue <int> QR, QC;
    QR.push(R);
    QC.push(C);
    livada[R][C] = '#';

    while(QR.size())
    {
        R = QR.front();
        C = QC.front();
        if(livada[R+1][C+2] == '.' or livada[R+1][C+2] == 'B')
        {
            if(livada[R+1][C+2] == 'B')
            {
                return;
            }
            QR.push(R+1);
            QC.push(C+2);
            livada[R+1][C+2] = '#';

        }
    }


}




int main()
{
    memset(livada, '#', sizeof(livada));
    scanf("%d %d", &N, &M);

    for(int i = 1; i<=N; i++)
    {
        for(int j = 1; j<=M; j++)
        {
            livada[i][j] = '.';
        }
    }
    livada[N][M] = 'B';
    BFS(1, 1);



    return 0;
}

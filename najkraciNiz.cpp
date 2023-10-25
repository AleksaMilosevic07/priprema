#include <bits/stdc++.h>
using namespace std;

int N, M, brojac;
int resenje = 100000;
bool ImaB;
char lavirint[1005][1005];

void DFS(int i, int j)
{
    if (lavirint[i][j] == 'B')
    {
        ImaB = true;
        resenje = min(resenje, brojac) - 1;
        return;
    }

    lavirint[i][j] = '#';

    if (brojac == N * M)
    {
        return;
    }

    if (lavirint[i][j + 1] == '.' or lavirint[i][j+1] == 'B')
    {
        brojac++;
        DFS(i, j + 1);
    }
    if (lavirint[i + 1][j] == '.' or lavirint[i+1][j] == 'B')
    {
        brojac++;
        DFS(i + 1, j);
    }
    if (lavirint[i][j - 1] == '.' or lavirint[i][j-1] == 'B')
    {
        brojac++;
        DFS(i, j - 1);
    }
    if (lavirint[i - 1][j] == '.' or lavirint[i-1][j] == 'B')
    {
        brojac++;
        DFS(i - 1, j);
    }

}

int main()
{
    memset(lavirint, '#', sizeof(lavirint));
    scanf("%d %d", &N, &M);

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            cin >> lavirint[i][j];
        }
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            if (lavirint[i][j] == 'A')
            {
                DFS(i, j);
            }
        }
    }

    if (ImaB == false)
        cout << "ne" << endl;
    else
        cout << resenje << endl;

    return 0;
}

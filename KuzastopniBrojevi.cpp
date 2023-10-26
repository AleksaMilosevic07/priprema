#include <bits/stdc++.h>
using namespace std;
int niz[1005], k, N, resenje, sum;

void provera()
{
    for(int i = 1; i<=N; i++)
    {
        for(int j = 0; j<k-1; j++)
        {
            sum+=niz[i+j];
            resenje = max(resenje, sum);
        }

    }
}


int main()
{
    scanf("%d", &N);
    for(int i = 1; i<=N; i++)
    {
        scanf("%d", &niz[i]);
    }
    scanf("%d", &k);

    provera();
    cout<<resenje<<endl;


    return 0;
}

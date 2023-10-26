#include <bits/stdc++.h>
using namespace std;
int broj, stepen;

int stepenovanje(int brojcina)
{
    if(stepen == 1)
    {
        return brojcina;
    }
    else
    {
        brojcina *= broj;
        stepen--;
        stepenovanje(brojcina);
    }
}


int main()
{
    scanf("%d %d", &broj, &stepen);
    cout<<stepenovanje(broj)<<endl;


    return 0;
}

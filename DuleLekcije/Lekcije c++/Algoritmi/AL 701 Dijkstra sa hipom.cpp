#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ld long double
using namespace std;
int N,M,cvor,D[100005];
bool idx[100005];

struct slog{
   int sused,cena;
   bool operator < (const slog &a) const{
      return cena > a.cena;  /// Hip u C++ je "maxhip" to znaci da nama kada je potreban minimum na vrhu, predefinisemo operator manje na suprotno
   }
}pom;
vector <slog> V[100005];
priority_queue <slog> H;
int main(){
  memset(D,-1,sizeof(D));

  cin>>N>>M;
  /// formiranje grafa
  for(int i=1;i<=M;i++){
     cin>>cvor>>pom.sused>>pom.cena;
     V[cvor].push_back(pom);
     swap(cvor,pom.sused);
     V[cvor].push_back(pom);
  }

  /// DIJKSTRA sa HIP-om
  /// 1. inicijalizacija, pocetna daljina od cvora za koga se trazi udaljenost ostalih, cvor ide u hip i jedini je tamo trenutno
  pom.cena=0;
  pom.sused=1;
  PQ.push(pom);
  /// 2. dogod ima grana na hipu Dijkstra ih obradjuje
  while(H.size()){
     /// 2.a.1. uzimamo najbolju granu sa hipa, pamtimo je,
     pom=H.top();
     ///   a.2. uklanjamo jesa vrha,
     H.pop();
     ///   a.3. pamtimo je ya potrebe kasnije obrade,
     int x=pom.sused;
     int bestcena=pom.cena;
     ///   a.4. Ako najbolja grana vodi do ;vora koji je ve' odradjen, prelazimo odmah na sledecu
     if(idx[x]) continue;
     ///   b.1. Obelezavamo cvor x da je odradjen, i upisujemo najbolju daljinu od pocetnog do cvora x
     idx[x]=1;
     D[x]=bestcena;
     ///   b.2 Sve izlazne grane iz cvora x prema cvorovima koji do sada nisu obradjeni, sa preracunatim cenama stavljamo na hip
     for(int i=0;i<V[x].size();i++){
        if (idx[V[x][i].sused])continue;
        pom.sused=V[x][i].sused;
        pom.cena=V[x][i].cena+bestcena;
        H.push(pom);
     }
  }

  /// u nizu D su udaljenosti svih cvorova od pocetnog. Ako je u nizu "-1", do cvora se ne moze doci iz pocetnog
  for(int i=1;i<=N;i++)
    cout<< i << " " << D[i] << "\n";
   return 0;
}

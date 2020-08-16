#include <bits/stdc++.h>

#define MP make_pair
#define PB push_back
#define INF INT_MAX
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define lim 100000

using namespace std;

typedef pair <int, int> pi;
typedef long long ll;
typedef unsigned long long ull;

stack <int> p;
vector <int> G[lim];
bool Free[lim];
int Low[lim], Num[lim], cnt = 0, SCC = 0,m,n;

void DFS(int u)
{
    cnt++;
    Low[u] = Num[u] = cnt;
    p.push(u);


    for(int v = 0;v < G[u].size();v++)
    {
        if(Num[ G[u][v] ] > 0) // Neu v da tham
        {
            Low[u] = min(Low[u], Num[ G[u][v] ]);
        }
        else // Neu v chua tham thi tham v
        {
            DFS( G[u][v] );
            Low[u] = min(Low[u], Low[ G[u][v] ]);
        }
    }

    if(Low[u] == Num[u])
    {
        int v;
        SCC++;

        #ifdef hello
        cout<<u<<endl;
        #endif // hello

        cout<<"TPLT manh thu "<<SCC<<" : ";
        do
        {
            v = p.top(); p.pop();
            Low[v] = Num[v] = lim; ///Bo toan bo cac canh tu v
            cout<<v<<" , ";
            Free[v] = 0; /// Xoa v ra khoi V
        }
        while(v != u);
        cout<<endl;
    }

}

void Tarjan()
{
    for(int i=1;i<=n;i++)
    {
        if(Free[i])
               DFS(i);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifdef djxone123456
    freopen("debug.inp","r",stdin);
    freopen("debug.out","w",stdout);
    #endif

    cin>>n>>m;

    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;

        G[x].PB(y);
    }

    for(int i = 1;i <= n;i++)
        {
            Free[i] = true;
            Num[i] = 0;
        }

    Tarjan();

    return 0;
}


















#include <bits/stdc++.h>

#define MP make_pair
#define PB push_back
#define INF INT_MAX
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007

using namespace std;

typedef pair <int, int> pi;
typedef long long ll;
typedef unsigned long long ull;
const int lim  = 1e5;

int Free[lim],trace[lim];
vector <int> G[lim];

void DFS(int u)
{
    Free[u] = 0;
    for(int v = 0; v < G[u].size(); v++)
    {
        if(Free[G[u][v]])
        {
            trace[G[u][v]] = u;
            DFS(G[u][v]);
        }
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

    int m,n,a,b;

    cin>>m>>n>>a>>b;

    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;

        G[x].PB(y);
        //G[y].PB(x);
    }

    for(int i=1;i<=n;i++)
        Free[i] = 1;

    DFS(a);

    if(Free[b])
        cout<<"No path from "<< a<< " to "<<b;
    else
    {
        string s;
        while(b!=a)
        {
            s += to_string(b) + " >= ";
            b = trace[b];
        }
        reverse(s.begin(),s.end());
        cout<<a<<s;
    }
    return 0;
}


















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
const int lim = 1e5;

queue <pi> p;
vector <int> G[lim];
bool Free[lim];
int trace[lim];

void BFS(int st)
{
    p.push({0,st});

    while(!p.empty())
    {
        pi ct = p.front(); p.pop();
        int u = ct.second;
        if(!Free[u])
        {
            continue;
        }
        Free[u] = 0;
        for(int v = 0;v < G[u].size();v++)
            if(Free[G[u][v]])
            {
                p.push(MP(u,G[u][v]));
            }
            trace[u] = ct.first;
        cout<<u<<' ';
    }
    cout<<endl;
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
        Free[i] = true;

    BFS(a);

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


















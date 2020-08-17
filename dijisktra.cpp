#include <bits/stdc++.h>

#define MP make_pair
#define PB push_back
#define INF INT_MAX
#define PI 3.1415926535897932384626433832795
#define MOD 10000000000000007
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair <int, int> pi;
typedef pair <ll, ll> pl;
typedef unsigned long long ull;
typedef pair <pair<int, int>, int> pii;

vector<pi> G[3000];
int m,n,dd[3000];

void dijsktra()
{
    priority_queue<pi, vector<pi>, greater<pi>> pq;

    for(int i = 1;i<=n;i++)
    {
        dd[i] = INF;
    }
    dd[1] = 0;

    pq.push(pi(0, 1)); //weight - u

    while(!pq.empty())
    {
        int u = pq.top().second;
        int du = pq.top().first;
        pq.pop();

        if(du != dd[u]) continue;

        for(pi lay : G[u])
        {
            int v = lay.second;
            int uv = lay.first;

            if(dd[v] > du + uv)
                {
                    dd[v] = du + uv;
                    pq.push(pi(dd[v], v));
                }
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

    cin>>m>>n;

    while(m--)
    {
        int x,y,w;
        cin>>x>>y>>w;

        G[x].push_back(pi(w, y));
        G[y].push_back(pi(w, x));
    }

    dijsktra();

    for(int i = 1;i<=n;i++)
    {
        cout<<"1 -> "<<i<<" : "<<dd[i]<<endl;
    }
    return 0;
}

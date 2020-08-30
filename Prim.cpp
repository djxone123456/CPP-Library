#include <bits/stdc++.h>

#define fi first
#define se second
#define MP make_pair
#define PB push_back
#define INF INT_MAX
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define endl '\n'
#define getBit(A, bit) ((A & 1 << bit) != 0)
#define turnOn(A, bit) (A |= 1 << bit)
#define turnOff(A, bit) (A &= ~(1 << bit))

using namespace std;

typedef long long ll;
typedef pair <int, int> pi;
typedef unsigned long long ull;

const int oo = 1e9+7;

int n,m;
vector <pi> a[100100];
bool dd[100100]={0};

ll prim(int st)
{
    priority_queue< pi, vector<pi>, greater<pi> >pq;

    pq.push(pi(0,st));

    ll res = 0;

    while(!pq.empty())
    {
        int u = pq.top().se;
        int du = pq.top().fi;
        pq.pop();

        if(dd[u]==0)
            {
                dd[u] = 1;
                res += du;

                for(pi Pop : a[u])
                    {
                        int v = Pop.se;
                        int uv = Pop.fi;
                        pq.push(pi(uv,v));
                    }
            }
    }
    return res;
}

void init()
{
    cin>>n>>m;

    for(int i=1;i<=m;++i)
    {
        int a1,b1,c1;
        cin>>a1>>b1>>c1;
        a[a1].push_back(pi(c1,b1));
        a[b1].push_back(pi(c1,a1));
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

    init();

    cout<<prim(1);

    return 0;
}

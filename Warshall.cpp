#include <bits/stdc++.h>

#define MP make_pair
#define PB push_back
#define INF INT_MAX
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define lim 200

using namespace std;

typedef pair <int, int> pi;
typedef long long ll;
typedef unsigned long long ull;

int a[lim][lim],cnt = 0,n,avail[lim];

void Warshall() // Chi nen su dung cho BAO DONG do thi (Connected component)
{
    for(int k = 1;k<=n;k++)
        for(int i = 1;i<=n;i++)
           for(int j = 1;j<=n;j++)
              a[i][j] = a[i][j] || a[i][k] && a[k][j];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifdef djxone123456
    freopen("debug.inp","r",stdin);
    freopen("debug.out","w",stdout);
    #endif

    int m;

    cin>>n>>m;

    memset(a,0,sizeof(a));
    memset(avail, 1, sizeof(avail));

    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;

        a[x][y] = 1;
        a[x][y] = 1;
        a[i][i] = 1;
    }

    Warshall();

    //In ket qua
    for(int u=1;u<=n;u++)
    {
        if(avail[u])
        {
            cnt++;
            cout<<"TPLT thu "<<cnt<<" : ";
            for(int v = 1;v<=n;v++)
                if(a[u][v])
                {
                    avail[v] = 0;
                    cout<<v<<", ";
                }
            cout<<endl;
        }
    }
    return 0;
}


















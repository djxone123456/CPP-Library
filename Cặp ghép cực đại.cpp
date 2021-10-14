#include <bits/stdc++.h>

#define pb push_back
#define maxn 300005

using namespace std;

int n, m, res = 0, current;
vector <int> a[maxn];
int mx[maxn], Used[maxn];

bool find_bride(int groom)
{
    if(Used[groom] == current)
        return 0; /// if this couple is available

    Used[groom] = current;

    for(int bride : a[groom]) /// find other bride
    {
        if(!mx[bride]) /// if bride is alone
        {
            mx[bride] = groom; /// this make them be a couple
            return 1;
        }

        if(find_bride(mx[bride])) /// if groom of this bride can find another bride, this groom can get her
        {
            mx[bride] = groom; /// <3
            return 1;
        }
    }

    return 0;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

    cin >> m >> n;
    int u, v;

    while (cin >> u >> v)
        a[u].pb(v + m);

    for(current = m; current >= 1; current--)
        res += find_bride(current);

    cout << res << endl;

    for(int bride = m + 1; bride <= m + n; bride++)
        cout << mx[bride] <<' ';
    return 0;
}

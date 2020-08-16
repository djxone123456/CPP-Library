ll nhan(ll a,ll b, ll m)
{
    if (b == 0)
        return 0;
    ll t = nhan(a, b / 2, m);
    t = (t + t) % m;
    if (b % 2 == 1)
        t = (t + a) % m;

    return t;
}

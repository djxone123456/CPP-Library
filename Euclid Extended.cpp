ll extEuclid(ll a, ll b, ll &x, ll &y) // Extended Euclid
{
    ll xx, yy;

    xx = y = 0;
    yy = x = 1;

    while(b)
    {
        ll q = a / b;
        ll t = b; b = a % b; a = t;
        t = xx; xx = x - q * xx; x = t;
        t = yy; yy = y - q * yy; y = t;
    }

    return a;
}

ll nhan(ll a,ll b, ll m) //Nhân ấn độ
{
    if (b == 0)
        return 0;
    ll t = nhan(a, b / 2, m);
    t = (t + t) % m;
    if (b % 2 == 1)
        t = (t + a) % m;

    return t;
}

ll POWW(ll a, ll pos, ll m) //Power
{
    if(pos == 0) return 1;

    ll pw = POWW(a, pos / 2, m) % m;
    if(pos % 2) return (nhan(nhan(pw, pw, m), a, m)) % m;
    return nhan(pw, pw, m) % m;
}

ll inserve_modulo(ll b, ll m) //Nghịch đảo modulo
{
    ll x,y;

    if(extEuclid(b, m, x, y) != 1) return -1;

    return (x % m + m) % m;

}

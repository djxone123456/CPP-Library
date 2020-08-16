ll inserve_modulo(ll b, ll m)
{
    ll x,y;

    if(extEuclid(b, m, x, y) != 1) return -1;

    return (x % m + m) % m;

}

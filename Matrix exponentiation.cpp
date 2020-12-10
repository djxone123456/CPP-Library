struct matrix{
    int val[maxn][maxn];
    int height , width;

    matrix (){
        memset(val, 0, sizeof(val));
    }

    matrix operator * (const matrix &B)
    {
        ll MOD2 = MOD * MOD;
        matrix C;
        for (int i = 1; i <= height; i++)
            for (int j = 1; j <= B.width; j++)
            {
                ll tmp = 0;
                for (int k = 1; k <= B.height; k++)
                {
                    tmp += (ll)val[i][k] * B.val[k][j];
                    while(tmp > MOD2) tmp -= MOD2;
                }
                C.val[i][j] = tmp % MOD;
            }
        C.height = height;
        C.width = B.width;
        return C;
    }

    matrix POWW(ull x)
    {
        if(x == 1) return (*this);
        if(x == 2) return (*this) * (*this);

        matrix tmp = POWW(x / 2);

        if(x & 1) return tmp * tmp * (*this);

        return tmp * tmp;
    }
};

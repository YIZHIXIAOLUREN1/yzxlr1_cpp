const int MAXN= 1e6 + 3;
typedef unsigned int       u32;
typedef unsigned long long u64;
const u32 BAS1 = 13331, MOD1 = 1e9 + 7;
const u32 BAS2 =   131, MOD2 = 1e9 + 9;
int H1[MAXN], P1[MAXN];
int H2[MAXN], P2[MAXN];
u64 get(int l, int r){
    int h1 = (H1[r] - 1ull * H1[l - 1] * P1[r - l + 1] % MOD1 + MOD1) % MOD1;
    int h2 = (H2[r] - 1ull * H2[l - 1] * P2[r - l + 1] % MOD2 + MOD2) % MOD2;
    return 1ull * h1 << 32 | h2;
}
void init(int n, char S[]){
    P1[0] = P2[0] = 1;
    for(int i = 1;i <= n;++ i)
        H1[i] = (1ull * H1[i - 1] * BAS1 + S[i]) % MOD1,
        H2[i] = (1ull * H2[i - 1] * BAS2 + S[i]) % MOD2,
        P1[i] = 1ull * P1[i - 1] * BAS1 % MOD1,
        P2[i] = 1ull * P2[i - 1] * BAS2 % MOD2;
}
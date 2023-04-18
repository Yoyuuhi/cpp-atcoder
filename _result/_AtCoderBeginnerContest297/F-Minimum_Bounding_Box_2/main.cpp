#include <bits/stdc++.h>

#include <atcoder/all>
#define out(X) cout << (X) << endl;
#ifdef __LOCAL
#define DBG(X) cout << #X << " = " << (X) << endl;
#else
#define DBG(X)
#endif
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = atcoder::modint998244353;
const int INF = numeric_limits<int>::max() / 2;

const int MOD = 998244353;
vector<long long> fact, fact_inv, inv;

void init_nCk(int SIZE) {
  fact.resize(SIZE + 5);
  fact_inv.resize(SIZE + 5);
  inv.resize(SIZE + 5);
  fact[0] = fact[1] = 1;
  fact_inv[0] = fact_inv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i < SIZE + 5; i++) {
    fact[i] = fact[i - 1] * i % MOD;
    inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
    fact_inv[i] = fact_inv[i - 1] * inv[i] % MOD;
  }
}
mint nCk(int h, int w, int k) {
  if (h <= 0 || w <= 0 || k < 0 || h * w < k) {
    return 0;
  }
  int n = h * w;
  return fact[n] * (fact_inv[k] * fact_inv[n - k] % MOD) % MOD;
}
mint f(int h, int w, int k) {
  mint a = nCk(h, w, k);
  mint b = 2 * nCk(h - 1, w, k) + 2 * nCk(h, w - 1, k);
  mint c = nCk(h - 2, w, k) + 4 * nCk(h - 1, w - 1, k) + nCk(h, w - 2, k);
  mint d = 2 * nCk(h - 2, w - 1, k) + 2 * nCk(h - 1, w - 2, k);
  mint e = nCk(h - 2, w - 2, k);

  return a - b + c - d + e;
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  int h, w, k;
  cin >> h >> w >> k;

  init_nCk(h * w + 1);

  mint ans = 0;
  rep2(i, 1, h + 1) {
    rep2(j, 1, w + 1) {
      if (i * j < k) {
        continue;
      }
      ans += f(i, j, k) * i * j * (h - i + 1) * (w - j + 1);
    }
  }
  ans /= nCk(h, w, k);
  out(ans.val());
}

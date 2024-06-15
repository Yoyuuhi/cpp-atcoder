#include <bits/stdc++.h>

#include <atcoder/all>
#define out(X) cout << (X) << endl;
#define outs(XS)                      \
  for (auto X : XS) cout << X << " "; \
  cout << endl;
#define outl cout << endl;
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
const ll INFLL = numeric_limits<ll>::max() / 2;
template <typename T>
vector<T> nis(T n) {
  vector<T> ret(n);
  rep(i, n) cin >> ret[i];
  return ret;
}
template <typename T>
T tpow(T x, int n) {
  T ret = 1;
  while (n > 0) {
    if (n & 1) ret *= x;
    x *= x;
    n >>= 1;
  }
  return ret;
}

const ll MOD = 998244353;
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

long long nCk(int n, int k) {
  assert(!(n < k));
  assert(!(n < 0 || k < 0));
  return fact[n] * (fact_inv[k] * fact_inv[n - k] % MOD) % MOD;
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  ll k;
  cin >> k;
  vector<ll> cs = nis(ll(26));

  init_nCk(1001);
  vector<vector<mint>> dp(26, vector<mint>(k + 1, 0));
  rep(i, min(k + 1, cs[25] + 1)) dp[25][i] = nCk(k, i);
  for (int i = 24; i >= 0; i--) {
    rep2(x, 0, k + 1) {
      if (dp[i + 1][x].val() == 0) break;

      rep2(y, 0, cs[i] + 1) {
        if (x + y > k) break;
        dp[i][x + y] += nCk(k - x, y) * dp[i + 1][x];
      }
    }
  }

  mint ans = 0;
  rep2(i, 1, k + 1) ans += dp[0][i] / nCk(k, i);
  out(ans.val());
}

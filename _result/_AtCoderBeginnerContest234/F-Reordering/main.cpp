#include <bits/stdc++.h>

#include <atcoder/all>
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
typename enable_if<is_same_v<T, ll> || is_same_v<T, int> ||
                       is_same_v<T, unsigned int>,
                   void>::type
out(T value) {
  cout << value << endl;
}
template <typename T>
typename enable_if<is_same_v<T, mint>, void>::type out(T value) {
  cout << value.val() << endl;
}
template <typename T>
typename enable_if<is_same_v<T, vector<ll>> || is_same_v<T, vector<int>>,
                   void>::type
out(T value) {
  for (auto v : value) cout << " ";
  cout << endl;
}

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

long long nCk(int n, int k) {
  assert(!(n < k));
  assert(!(n < 0 || k < 0));
  return fact[n] * (fact_inv[k] * fact_inv[n - k] % MOD) % MOD;
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  string s;
  cin >> s;
  vector<int> mem(26, 0);
  for (auto c : s) mem[c - 'a']++;

  int n = s.size();
  init_nCk(n + 1);
  vector<vector<mint>> dp(27, vector<mint>(n + 1, 0));
  dp[0][0] = 1;

  rep(i, 26) {
    rep(j, n + 1) {
      if (!dp[i][j].val()) continue;
      dp[i + 1][j] += dp[i][j];
      rep2(t, 1, mem[i] + 1) { dp[i + 1][j + t] += dp[i][j] * nCk(j + t, t); }
    }
  }
  mint ans = 0;
  rep2(j, 1, n + 1) ans += dp[26][j];
  out(ans);
}

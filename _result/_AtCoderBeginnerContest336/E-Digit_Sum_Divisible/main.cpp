#include <bits/stdc++.h>

#include <atcoder/all>
#define out(X) cout << (X) << endl;
#define outs(XS) \
  for (auto X : XS) cout << X << " ";
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
using mint = atcoder::modint1000000007;
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

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  ll n;
  cin >> n;

  ll nn = n;
  int level = 0;
  while (nn > 0) {
    level++;
    nn /= 10;
  }

  vector<ll> ns(level, 0);
  nn = n;
  rep(i, level) {
    ll res = nn % 10;
    ns[level - 1 - i] = res;
    nn /= ll(10);
  }

  vector<ll> sns(level, 0);
  rep(i, level) {
    sns[i] = ns[i];
    if (i > 0) sns[i] += sns[i - 1];
  }

  ll m = 9 * level;
  ll ans = 0;
  rep2(i, 1, m + 1) {
    vector<vector<vector<ll>>> dp(level,
                                  vector<vector<ll>>(i + 2, vector<ll>(i, 0)));
    rep(ii, ns[0]) {
      if (ii > i) continue;
      dp[0][ii][ii % i] = 1;
    }
    if (ns[0] <= i) {
      dp[0][i + 1][ns[0] % i] = 1;
    }
    rep(l, level - 1) {
      rep(sum, i + 1) {
        rep(res, i) {
          if (dp[l][sum][res] == 0) continue;
          rep(num, 10) {
            if (num + sum > i) continue;
            dp[l + 1][num + sum][(res * 10 + num) % i] += dp[l][sum][res];
          }
        }
      }
      int sum = sns[l];
      rep(res, i) {
        if (dp[l][i + 1][res] == 0) continue;
        rep(num, ns[l + 1]) {
          if (num + sum > i) continue;
          dp[l + 1][num + sum][(res * 10 + num) % i] += dp[l][i + 1][res];
        }
        ll num = ns[l + 1];
        if (num + sum > i) continue;
        dp[l + 1][i + 1][(res * 10 + num) % i] += dp[l][i + 1][res];
      }
    }
    ans += dp[level - 1][i][0];
    if (sns[level - 1] == i) ans += dp[level - 1][i + 1][0];
  }
  out(ans);
}

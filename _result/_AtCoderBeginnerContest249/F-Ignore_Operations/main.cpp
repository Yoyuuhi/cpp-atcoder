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

  ll n, k;
  cin >> n >> k;
  vector<vector<ll>> tys;
  rep(i, n) {
    ll t, y;
    cin >> t >> y;
    tys.push_back({t, y});
  }

  ll sum = 0;
  priority_queue<ll, vector<ll>, less<ll>> pq;
  ll ans = -INFLL;
  for (auto i = n - 1; i >= 0; i--) {
    if (k < 0) break;
    ll t = tys[i][0], y = tys[i][1];
    if (t == 1) {
      ans = max(ans, y + sum);
      k--;
    }
    if (t == 2) {
      if (y >= 0) {
        sum += y;
      } else {
        pq.push(y);
      }
    }
    while (ll(pq.size()) > k) {
      ll yy = pq.top();
      pq.pop();
      sum += yy;
    }
  }
  if (k >= 0) ans = max(ans, sum);
  out(ans);
}

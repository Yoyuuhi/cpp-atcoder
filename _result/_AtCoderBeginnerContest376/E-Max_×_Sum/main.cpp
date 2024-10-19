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

void solve() {
  ll n, k;
  cin >> n >> k;
  auto as = nis(n), bs = nis(n);
  vector<pair<ll, ll>> pa;
  rep(i, n) {
    auto a = as[i], b = bs[i];
    pa.push_back({a, b});
  }

  sort(all(pa));
  ll ans = INFLL;
  priority_queue<ll, vector<ll>, less<ll>> pq;
  ll sum = 0;
  rep(i, n) {
    auto a = pa[i].first, b = pa[i].second;
    if (pq.size() < k - 1) {
      sum += b;
      pq.push(b);
      continue;
    }
    ans = min(ans, a * (sum + b));

    if (!pq.empty()) {
      auto p = pq.top();
      if (p > b) {
        sum -= p;
        sum += b;
        pq.pop();
        pq.push(b);
      }
    }
  }

  out(ans);
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  int t;
  cin >> t;
  rep(i, t) solve();
}

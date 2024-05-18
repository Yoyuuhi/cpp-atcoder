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

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  int n;
  cin >> n;
  vector<string> ss(n);
  rep(i, n) cin >> ss[i];

  sort(all(ss));
  vector<ll> as(n, 0);
  rep(i, n - 1) {
    string s1 = ss[i], s2 = ss[i + 1];
    ll a = 0;
    rep(idx, min(s1.size(), s2.size())) {
      if (s1[idx] == s2[idx])
        a++;
      else
        break;
    }
    as[i] = a;
  }

  ll ans = 0, pa = 0;
  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>> pq;
  pq.emplace(0, 0);
  rep(i, n - 1) {
    ll a = as[i], num = 1, ta = pa + a;
    while (pq.top().first > a) {
      auto p = pq.top();
      pq.pop();
      ta -= (p.first - a) * p.second;
      num += p.second;
    }
    if (pq.top().first == a) {
      auto p = pq.top();
      pq.pop();
      num += p.second;
    }
    pq.emplace(a, num);
    ans += ta;
    pa = ta;
  }
  out(ans);
}

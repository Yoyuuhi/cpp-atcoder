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

ll n, t;
void updateMem(map<ll, bool> &mem, ll a) {
  map<ll, bool> tm;
  for (auto m : mem) {
    tm[m.first] = true;
    if (m.first + a <= t) tm[m.first + a] = true;
  }
  swap(tm, mem);
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  cin >> n >> t;
  auto as = nis(n);

  map<ll, bool> mem1;
  mem1[0] = true;
  rep(i, n / 2) updateMem(mem1, as[i]);
  map<ll, bool> mem2;
  mem2[0] = true;
  for (int i = n - 1; i >= n / 2; i--) updateMem(mem2, as[i]);
  vector<ll> v1, v2;
  for (auto m : mem1) v1.push_back(m.first);
  for (auto m : mem2) v2.push_back(m.first);
  sort(all(v1));
  sort(all(v2));

  ll ans = 0;
  for (auto v : v1) {
    ans = max(ans, v);
    int i2 = lower_bound(all(v2), t - v + 1) - v2.begin();
    if (!i2) continue;
    ans = max(ans, v + v2[i2 - 1]);
  }
  out(ans);
}

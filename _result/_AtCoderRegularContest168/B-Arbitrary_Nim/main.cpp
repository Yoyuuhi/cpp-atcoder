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
ll ni() {
  ll ret;
  cin >> ret;
  return ret;
}
template <typename T>
vector<T> nis(T n) {
  vector<T> ret(n);
  rep(i, n) cin >> ret[i];
  return ret;
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  int n = ni();
  auto as = nis(n);
  int x = 0;
  for (auto a : as) x ^= a;
  if (x) {
    out(-1);
    return 0;
  }

  map<int, int> mem;
  for (auto a : as) mem[a]++;
  vector<int> ks;
  for (auto m : mem) ks.push_back(m.first);
  sort(all(ks), greater<int>());
  for (auto k : ks) {
    if (mem[k] % 2) {
      out(k - 1);
      return 0;
    }
  }
  out(0);
}

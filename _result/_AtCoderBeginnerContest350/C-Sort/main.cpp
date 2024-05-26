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
  vector<int> as(n);
  vector<int> mem(n, -1);
  rep(i, n) {
    cin >> as[i];
    as[i]--;
    mem[as[i]] = i;
  }

  vector<vector<int>> qs;
  rep(i, n) {
    if (as[i] == i) continue;
    int a = i, b = as[i];
    int x = mem[a], y = mem[b];
    if (x > y) swap(x, y);
    qs.push_back({x + 1, y + 1});
    swap(as[x], as[y]);
    swap(mem[a], mem[b]);
  }
  out(qs.size());
  for (auto q : qs) cout << q[0] << ' ' << q[1] << endl;
}

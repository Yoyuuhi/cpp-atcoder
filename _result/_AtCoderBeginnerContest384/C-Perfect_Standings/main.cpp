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

bool comp(pair<int, string> &a1, pair<int, string> &a2) {
  if (a1.first != a2.first) return a1.first > a2.first;
  return a1.second < a2.second;
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  auto as = nis(5);
  vector<char> vs = {'A', 'B', 'C', 'D', 'E'};
  vector<pair<int, string>> mem;
  rep2(i, 1, 1 << 5) {
    string str = "";
    int score = 0;
    rep(ii, 5) {
      if (i & (1 << ii)) {
        str += vs[ii];
        score += as[ii];
      }
    }
    mem.push_back({score, str});
  }

  sort(all(mem), comp);
  for (auto m : mem) out(m.second);
}

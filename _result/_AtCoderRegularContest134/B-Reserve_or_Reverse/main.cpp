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

using S = array<int, 2>;
auto compare = [](S &a1, S &a2) -> bool {
  if (a1[0] != a2[0]) {
    return a1[0] > a2[0];
  } else {
    return a1[1] < a2[1];
  }
};

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  int n;
  cin >> n;
  string s;
  cin >> s;

  priority_queue<S, vector<S>, decltype(compare)> pq(compare);
  rep(i, n) {
    char c = s[i];
    pq.push({c - 'a', i});
  }

  int ir = n - 1;
  rep(i, n) {
    char c = s[i];

    while (!pq.empty()) {
      auto pp = pq.top();
      if (pp[0] >= c - 'a') break;
      int ii = pp[1];
      pq.pop();
      if (ii <= i || ii > ir) continue;

      ir = min(ir, ii);
      swap(s[i], s[ii]);
      break;
    }
  }
  out(s);
}

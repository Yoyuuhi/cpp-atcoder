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

  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;

  vector<string> mem;
  string ts = "";
  ts += s[0];
  rep2(i, 1, s.size()) {
    if (s[i] != s[i - 1]) {
      mem.push_back(ts);
      ts = "";
    }
    ts += s[i];
  }
  if (ts.size() > 0) mem.push_back(ts);

  int count = 0, idx = -1;
  rep(i, mem.size()) {
    if (mem[i][0] == '1') count++;
    if (count == k) {
      idx = i;
      break;
    }
  }
  swap(mem[idx], mem[idx - 1]);
  for (auto m : mem) cout << m;
  outl;
}

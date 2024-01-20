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

  int n;
  cin >> n;

  int bit = 0;
  int nn = n - 1;
  while (nn > 0) {
    bit++;
    nn = nn >> 1;
  }

  vector<vector<int>> mem(bit);
  rep(i, n) {
    int nn = i;
    int b = 0;
    while (nn > 0) {
      if ((nn & 1) != 0) {
        mem[b].push_back(i + 1);
      }
      b++;
      nn = nn >> 1;
    }
  }

  out(bit);
  for (auto bs : mem) {
    cout << bs.size() << ' ';
    for (auto b : bs) cout << b << ' ';
    outl;
  }

  string s;
  cin >> s;
  int ans = 0;
  for (int i = bit - 1; i >= 0; i--) {
    char c = s[i];
    ans = ans << 1;
    if (c == '1') ans += 1;
  }
  out(ans + 1);
}

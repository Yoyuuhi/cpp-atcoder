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
  vector<string> ss;
  rep(i, n) {
    string s;
    cin >> s;
    ss.push_back(s);
  }

  vector<vector<char>> tx(100, vector<char>(n, '*'));
  rep(i, n) {
    string s = ss[i];
    int jj = n - 1 - i;
    rep(ii, s.size()) tx[ii][jj] = s[ii];
  }

  rep(i, 100) {
    string str0 = "", str1 = "";
    rep(j, n) {
      str1 += tx[i][j];
      if (tx[i][j] != '*') {
        str0 += str1;
        str1 = "";
      }
    }
    if (str0.size() > 0) out(str0);
  }
}

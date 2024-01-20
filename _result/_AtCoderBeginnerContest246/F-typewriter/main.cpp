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
using mint = atcoder::modint998244353;
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

ll n, l;

mint calc(mint num) { return tpow(num, l); }
string commonStr(string a, string b) {
  vector<bool> mem(26, false);
  for (auto c : a) mem[c - 'a'] = true;

  string str;
  for (auto c : b)
    if (mem[c - 'a']) str += c;
  return str;
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  cin >> n >> l;
  vector<string> ss(n);
  rep(i, n) cin >> ss[i];

  mint ans = 0;
  rep2(i, 1, n + 1) {
    mint symbol = i % 2 ? 1 : -1;
    vector<int> vs;
    rep(ii, n) {
      if (ii < n - i) {
        vs.push_back(0);
      } else {
        vs.push_back(1);
      }
    }
    do {
      string s = "abcdefghijklmnopqrstuvwxyz";
      rep(ii, n) {
        if (vs[ii] == 1) s = commonStr(s, ss[ii]);
      }
      ans += symbol * calc(s.size());
    } while (next_permutation(all(vs)));
  }
  out(ans.val());
}

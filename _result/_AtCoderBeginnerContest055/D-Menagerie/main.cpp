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

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  int n;
  cin >> n;
  string s;
  cin >> s;

  rep(bit, 4) {
    vector<int> ans;
    ans.push_back(bit & 2 ? 1 : 0);
    ans.push_back(bit & 1 ? 1 : 0);
    rep2(i, 1, n - 1) {
      char symbol = s[i];
      int c = ans[i];
      if (c) {
        ans.push_back(symbol == 'o' ? ans[i - 1] : (ans[i - 1] + 1) % 2);
      } else {
        ans.push_back(symbol == 'o' ? (ans[i - 1] + 1) % 2 : ans[i - 1]);
      }
    }
    int a0, a1;
    if (ans[n - 1]) {
      a0 = s[n - 1] == 'o' ? ans[n - 2] : (ans[n - 2] + 1) % 2;
    } else {
      a0 = s[n - 1] == 'o' ? (ans[n - 2] + 1) % 2 : ans[n - 2];
    }
    if (ans[0]) {
      a1 = s[0] == 'o' ? ans[n - 1] : (ans[n - 1] + 1) % 2;
    } else {
      a1 = s[0] == 'o' ? (ans[n - 1] + 1) % 2 : ans[n - 1];
    }
    if (a0 == ans[0] && a1 == ans[1]) {
      for (auto a : ans) {
        cout << (a ? 'S' : 'W');
      }
      outl;
      return 0;
    }
  }
  out(-1);
}

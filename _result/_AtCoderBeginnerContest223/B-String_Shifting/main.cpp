#include <bits/stdc++.h>

#include <atcoder/all>
#define out(X) cout << (X) << endl;
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

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  string s;
  cin >> s;

  vector<string> ss;
  rep(i, s.size()) {
    string ts = "";

    rep2(ii, i, s.size()) ts += s[ii];
    rep(ii, i) ts += s[ii];
    ss.push_back(ts);
  }
  sort(all(ss));
  out(ss[0]);
  out(ss[ss.size() - 1]);
}

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
using Modint = atcoder::modint998244353;
const int INF = numeric_limits<int>::max() / 2;

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif
  static char buf[500'001];
  scanf("%s", buf);
  string s = buf;

  std::vector<int> sa = suffix_array(s);
  ll ans = s.size() * (s.size() + 1) / 2;
  for (auto a : lcp_array(s, sa)) {
    ans -= a;
  }
  out(ans);
}

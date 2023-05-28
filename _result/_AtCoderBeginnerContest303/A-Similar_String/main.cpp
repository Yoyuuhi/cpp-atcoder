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

  int n;
  cin >> n;
  string s, t;
  cin >> s >> t;
  rep(i, n) {
    char c1 = s[i];
    char c2 = t[i];
    if (c1 > c2) {
      swap(c1, c2);
    }
    if (c1 == c2) {
      continue;
    }
    if (c1 == '1' && c2 == 'l' || c1 == '0' && c2 == 'o') continue;
    out("No");
    return 0;
  }
  out("Yes");
}

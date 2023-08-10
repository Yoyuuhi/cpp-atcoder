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
  if (!n) {
    out("Yes");
    return 0;
  }
  while (!(n % 10)) n /= 10;
  string s = to_string(n);
  for (int i = 0; i < s.size() / 2; i++) {
    if (s[i] != s[s.size() - 1 - i]) {
      out("No");
      return 0;
    }
  }
  out("Yes");
}

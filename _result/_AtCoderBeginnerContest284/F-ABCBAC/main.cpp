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
  string t;
  cin >> t;

  string a = t.substr(0, n);
  string b = t.substr(n);
  reverse(all(b));
  string x = a + b;
  string y = b + a;

  vector<int> zx = z_algorithm(x);
  zx.push_back(0);
  vector<int> zy = z_algorithm(y);
  zy.push_back(0);
  rep2(i, n, 2 * n) {
    if (!(zy[i] == 2 * n - i && zx[3 * n - i] == i - n)) continue;
    string s1 = x.substr(0, i - n);
    string s2 = y.substr(0, 2 * n - i);
    reverse(all(s2));
    out(s1 + s2);
    out(s1.size());
    return 0;
  }
  out(-1);
}

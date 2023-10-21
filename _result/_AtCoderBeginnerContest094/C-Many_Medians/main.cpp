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
  vector<int> xs(n), cxs(n);
  rep(i, n) {
    cin >> xs[i];
    cxs[i] = xs[i];
  }

  sort(all(cxs));
  map<int, int> m;
  rep(i, n) {
    if (m.find(cxs[i]) == m.end()) {
      m[cxs[i]] = i;
    }
  }
  int r = cxs[n / 2];
  int l = cxs[n / 2 - 1];
  rep(i, n) {
    int idx = m[xs[i]];
    cout << (idx >= n / 2 ? l : r) << endl;
  }
}

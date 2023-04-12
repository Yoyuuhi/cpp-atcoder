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

  int n, m;
  cin >> n >> m;
  vector<Modint> as, bs;
  rep(i, n) {
    int a;
    cin >> a;
    as.push_back(a);
  }
  rep(i, m) {
    int b;
    cin >> b;
    bs.push_back(b);
  }

  std::vector<Modint> cv = convolution(as, bs);
  rep(i, cv.size()) {
    if (!i) {
      cout << cv[i].val();
      continue;
    }
    cout << " " << cv[i].val();
  }
  out("")
}

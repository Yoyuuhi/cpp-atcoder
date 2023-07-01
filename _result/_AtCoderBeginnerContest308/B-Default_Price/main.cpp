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

  int n, m;
  cin >> n >> m;
  vector<string> cs(n);
  rep(i, n) cin >> cs[i];

  vector<string> ds(m);
  vector<int> ps(m + 1);
  rep(i, m) cin >> ds[i];
  int p0;
  cin >> p0;

  map<string, int> mem;
  rep(i, m) {
    int p;
    cin >> p;
    mem[ds[i]] = p;
  }
  int ans = 0;
  rep(i, n) {
    if (mem.find(cs[i]) != mem.end()) {
      ans += mem[cs[i]];
    } else {
      ans += p0;
    }
  }
  out(ans);
}

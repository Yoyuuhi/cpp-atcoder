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

  int n, d;
  cin >> n >> d;
  vector<bool> mem(d, true);
  rep(i, n) {
    string s;
    cin >> s;
    rep(j, d) {
      if (s[j] == 'x') mem[j] = false;
    }
  }
  int l = -1;
  int ans = 0;
  rep(i, d) {
    if (!mem[i]) l = i;
    ans = max(ans, i - l);
  }
  out(ans);
}

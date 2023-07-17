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
  vector<map<int, bool>> fx(n);
  vector<int> ps(n);
  rep(i, n) {
    int p, c;
    cin >> p >> c;
    ps[i] = p;
    rep(j, c) {
      int f;
      cin >> f;
      fx[i][f] = true;
    }
  }
  rep(i, n) {
    rep(j, n) {
      if (i == j || ps[i] < ps[j]) continue;
      bool s1 = true;
      bool s2 = false;
      rep(k, m + 1) {
        if (fx[i][k] && !fx[j][k]) s1 = false;
        if (!fx[i][k] && fx[j][k]) s2 = true;
      }
      if (ps[i] > ps[j] && s1) {
        out("Yes");
        return 0;
      }
      if (s1 && s2) {
        out("Yes");
        return 0;
      }
    }
  }
  out("No");
}

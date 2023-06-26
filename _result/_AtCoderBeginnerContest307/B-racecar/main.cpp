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

bool judge(string s) {
  int n = s.size();
  rep(i, n) {
    int j = n - 1 - i;
    if (j <= i) break;
    if (s[i] != s[j]) return false;
  }
  return true;
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  int n;
  cin >> n;
  vector<string> ss(n);
  rep(i, n) cin >> ss[i];
  rep(i, n) {
    rep2(j, i + 1, n) {
      if (judge(ss[i] + ss[j]) || judge(ss[j] + ss[i])) {
        out("Yes");
        return 0;
      }
    }
  }
  out("No");
}

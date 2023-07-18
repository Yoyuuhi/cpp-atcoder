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
  set<string> mem;
  rep(i, n) {
    string s1, s2;
    cin >> s1;
    s2 = s1;
    rep(j, s2.size() / 2) swap(s2[j], s2[s2.size() - 1 - j]);
    if (s1 > s2) swap(s1, s2);
    mem.insert(s1);
  }
  out(mem.size());
}

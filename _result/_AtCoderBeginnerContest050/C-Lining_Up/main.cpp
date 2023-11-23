#include <bits/stdc++.h>

#include <atcoder/all>
#define out(X) cout << (X) << endl;
#define outs(XS)                      \
  for (auto X : XS) cout << X << " "; \
  cout << endl;
#define outl cout << endl;
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
using mint = atcoder::modint1000000007;
const int INF = numeric_limits<int>::max() / 2;
const ll INFLL = numeric_limits<ll>::max() / 2;
ll ni() {
  ll ret;
  cin >> ret;
  return ret;
}
template <typename T>
vector<T> nis(T n) {
  vector<T> ret(n);
  rep(i, n) cin >> ret[i];
  return ret;
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  int n;
  cin >> n;
  map<int, int> mem;
  rep(i, n) {
    int a;
    cin >> a;
    mem[a]++;
  }
  if ((n % 2) && mem[0] != 1) {
    out(0);
    return 0;
  }
  int s = (n % 2 == 1) ? 2 : 1;
  rep2(i, s, n / 2) {
    if (mem[i] != 2) {
      out(0);
      return 0;
    }
    i++;
  }
  mint ans = 1;
  rep(i, n / 2) ans *= 2;
  out(ans.val());
}

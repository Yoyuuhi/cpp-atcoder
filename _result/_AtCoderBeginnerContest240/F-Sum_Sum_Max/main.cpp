#include <bits/stdc++.h>

#include <atcoder/all>
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
template <typename T>
vector<T> nis(T n) {
  vector<T> ret(n);
  rep(i, n) cin >> ret[i];
  return ret;
}
template <typename T>
typename enable_if<is_same_v<T, ll> || is_same_v<T, int> ||
                       is_same_v<T, unsigned int>,
                   void>::type
out(T value) {
  cout << value << endl;
}
template <typename T>
typename enable_if<is_same_v<T, mint>, void>::type out(T value) {
  cout << value.val() << endl;
}
template <typename T>
typename enable_if<is_same_v<T, vector<ll>> || is_same_v<T, vector<int>>,
                   void>::type
out(T value) {
  for (auto v : value) cout << v << " ";
  cout << endl;
}

void solve() {
  ll n, m;
  cin >> n >> m;
  ll ans;
  ll ta = 0;
  ll sum = 0;
  rep(i, n) {
    ll x, y;
    cin >> x >> y;
    if (i == 0) ans = x;
    if (x < 0 && sum + x > 0) {
      int t = min(y, sum / (-x));
      ans = max(ans, ta + sum * t + x * t * (t + 1) / 2);
    }
    ta += sum * y;
    ta += x * y * (y + 1) / 2;
    sum += x * y;
    ans = max(ans, ta);
  }
  out(ans);
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  int t;
  cin >> t;
  rep(i, t) solve();
}

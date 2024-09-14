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
outs(T value) {
  for (auto v : value) cout << v << " ";
  cout << endl;
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  ll n;
  cin >> n;
  auto xs = nis(n);
  auto ps = nis(n);

  vector<ll> sumps(n + 1, 0);
  rep(i, n) {
    sumps[i + 1] += ps[i];
    sumps[i + 1] += sumps[i];
  }

  ll q;
  cin >> q;
  rep(i, q) {
    ll l, r;
    cin >> l >> r;
    int li = lower_bound(all(xs), l) - xs.begin();
    int ri = lower_bound(all(xs), r) - xs.begin();
    if (ri < n && xs[ri] > r) ri--;
    if (ri == n) ri--;
    out(sumps[ri + 1] - sumps[li]);
  }
}

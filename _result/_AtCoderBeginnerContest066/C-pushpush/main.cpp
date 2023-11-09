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
#define outv(vs) \
  for (auto v : vs) out(v)
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = atcoder::modint998244353;
const int INF = numeric_limits<int>::max() / 2;
const ll INFLL = numeric_limits<ll>::max() / 2;
template <typename T>
vector<T> nis(T n) {
  vector<T> ret(n);
  rep(i, n) cin >> ret[i];
  return ret;
}
template <typename T>
typename enable_if<is_same_v<T, ll> || is_same_v<T, int>, void>::type out(
    T value) {
  cout << value << endl;
}
template <typename T>
typename enable_if<is_same_v<T, vector<ll>> || is_same_v<T, vector<int>>,
                   void>::type
out(T value) {
  for (auto v : value) cout << v << " ";
  cout << endl;
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  int n;
  cin >> n;
  auto as = nis(n);

  vector<int> lr = {n / 2, n / 2};
  vector<int> bs(n);
  bs[n / 2] = as[0];
  rep2(i, 1, n) {
    int idx;
    if (i % 2) {
      idx = lr[0] - 1;
      lr[0]--;
    } else {
      idx = lr[1] + 1;
      lr[1]++;
    }
    bs[idx] = as[i];
  }
  if (n % 2) {
    for (int i = n - 1; i >= 0; i--) {
      cout << bs[i] << " ";
    }
    outl
  } else {
    out(bs);
  }
}

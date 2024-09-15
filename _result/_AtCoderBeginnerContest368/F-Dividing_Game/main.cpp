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

template <typename T>
vector<pair<T, T>> prime_factor(T n) {
  vector<pair<T, T>> ret;
  for (T i = 2; i * i <= n; i++) {
    if (n % i != 0) continue;
    T tmp = 0;
    while (n % i == 0) {
      tmp++;
      n /= i;
    }
    ret.push_back(make_pair(i, tmp));
  }
  if (n != 1) ret.push_back(make_pair(n, 1));
  return ret;
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  int n;
  cin >> n;
  auto as = nis(n);

  int xo = 0;
  rep(i, n) {
    int a = as[i];
    auto pf = prime_factor(a);
    int count = 0;
    for (auto p : pf) count += p.second;
    xo ^= count;
  }

  if (xo) {
    cout << "Anna" << endl;
  } else {
    cout << "Bruno" << endl;
  }
}

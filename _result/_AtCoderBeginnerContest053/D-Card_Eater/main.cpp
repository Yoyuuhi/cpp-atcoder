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

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  int n;
  cin >> n;
  auto as = nis(n);

  map<int, int> mem;
  for (auto a : as) mem[a]++;

  vector<int> mv;
  for (auto m : mem) {
    if (m.second > 1) mv.push_back(m.second - 1);
  }
  sort(all(mv));
  rep2(i, 1, mv.size()) mv[i] -= mv[i - 1];
  int ans = mem.size();
  if (mv.size() == 0) {
    out(ans);
    return 0;
  }
  out(mv[mv.size() - 1] % 2 ? ans - 1 : ans);
}

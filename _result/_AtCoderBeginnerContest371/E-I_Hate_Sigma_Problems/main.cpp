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
  auto as = nis(n);

  vector<int> cs(n + 1, 0);
  vector<ll> mem(n + 1, 0);
  rep(i, n) {
    ll a = as[i];
    if (!cs[a]) mem[i + 1]++;
    cs[a]++;
    mem[i + 1] += mem[i];
  }

  ll summ = 0;
  rep(i, n + 1) summ += mem[i];

  map<int, int> nextAppear;
  vector<int> memNext(n, n);
  for (int i = n - 1; i >= 0; i--) {
    auto a = as[i];
    if (nextAppear.find(a) == nextAppear.end()) {
      nextAppear[a] = i;
    } else {
      memNext[i] = nextAppear[a];
      nextAppear[a] = i;
    }
  }

  ll ta = summ - 1;
  ll ans = summ;
  rep2(i, 1, n) {
    ll a = as[i - 1];

    ll d = 1;
    if (a != as[i]) d = 2;
    ta -= d;

    int ni = memNext[i - 1];
    if (ni > i + 1) ta -= ni - i - 1;

    ans += ta + 1;
  }
  out(ans);
}

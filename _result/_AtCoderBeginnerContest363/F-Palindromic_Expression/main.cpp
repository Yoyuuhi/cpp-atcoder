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
template <typename T>
vector<T> nis(T n) {
  vector<T> ret(n);
  rep(i, n) cin >> ret[i];
  return ret;
}
template <typename T>
T tpow(T x, int n) {
  T ret = 1;
  while (n > 0) {
    if (n & 1) ret *= x;
    x *= x;
    n >>= 1;
  }
  return ret;
}

bool isPalin(ll num) {
  string str = to_string(num);
  rep(i, str.size() / 2) {
    int j = str.size() - 1 - i;
    if (str[i] != str[j]) return false;
  }
  return true;
}

bool valid(ll num) {
  string str = to_string(num);
  for (auto c : str)
    if (c == '0') return false;
  return true;
}

ll palin(ll num) {
  string str = to_string(num);
  rep(i, str.size() / 2) {
    int j = str.size() - 1 - i;
    swap(str[i], str[j]);
  }
  return stoll(str);
}

map<ll, bool> failed;
vector<ll> stk;

bool calc(ll num) {
  if (failed[num]) return false;

  if (valid(num) && isPalin(num)) return true;
  for (ll i = 2; i * i <= num; i++) {
    if (num % i != 0) continue;
    if (!valid(i)) continue;
    auto pi = palin(i);
    if ((num / i) % pi != 0) continue;

    stk.push_back(i);
    if (calc(num / i / pi)) return true;
    failed[num / i / pi] = true;
    stk.pop_back();
  }
  return false;
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  ll n;
  cin >> n;

  if (!calc(n)) {
    out(-1);
    return 0;
  }

  string ans = "";
  rep(i, stk.size()) {
    ans += to_string(stk[i]) + "*";
    n /= stk[i];
    n /= palin(stk[i]);
  }
  ans += to_string(n);
  for (int i = stk.size() - 1; i >= 0; i--) {
    ans += "*" + to_string(palin(stk[i]));
  }
  out(ans);
}

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

int bs(int ok, int ng, bool f(int)) {
  if (!f(ok)) return -1;
  if (f(ng)) return ng;
  while (abs(ok - ng) > 1) {
    ll mid = (ok + ng) / 2;
    if (f(mid)) {
      ok = mid;
    } else {
      ng = mid;
    }
  }
  return ok;
}

int n, q;
string s;

vector<int> mems1, mems2, memr1, memr2, memd;
int l, r;

bool f(int length) {
  if (length == 0) return true;
  if (length % 2 == 0) return f(length + 1);

  auto side = (length - 1) / 2;
  if (side == 0) return memd[r + 1] - memd[l] > 0;

  auto idx = lower_bound(all(mems1), memr1[l] + side) - mems1.begin();
  if (idx == n + 2) return false;

  return mems2[idx] - memr2[r + 2] >= side;
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  cin >> n >> q;
  cin >> s;

  mems1.assign(n + 2, 0);
  mems2.assign(n + 2, 0);
  memr1.assign(n + 2, 0);
  memr2.assign(n + 2, 0);
  memd.assign(n + 2, 0);
  int res1 = 0, res2 = 0;
  rep(i, n) {
    char c = s[i];
    if (c == '1') {
      res1++;
      memr1[i + 1]++;
    }
    if (c == '/') {
      mems1[i + 1] += res1;
      res1 = 0;
      memd[i + 1]++;
    }
    mems1[i + 1] += mems1[i];
    memr1[i + 1] += memr1[i];
    memd[i + 1] += memd[i];
  }
  mems1[n + 1] = mems1[n];
  for (int i = n - 1; i >= 0; i--) {
    char c = s[i];
    if (c == '2') {
      res2++;
      memr2[i + 1]++;
    }
    if (c == '/') {
      mems2[i + 1] += res2;
      res2 = 0;
    }
    mems2[i + 1] += mems2[i + 2];
    memr2[i + 1] += memr2[i + 2];
  }

  rep(i, q) {
    cin >> l >> r;
    l--;
    r--;
    auto ans = bs(0, r - l + 1, f);
    out(ans);
  }
}

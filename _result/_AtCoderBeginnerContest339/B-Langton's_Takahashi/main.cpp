#include <bits/stdc++.h>

#include <atcoder/all>
#define out(X) cout << (X) << endl;
#define outs(XS) \
  for (auto X : XS) cout << X << " ";
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

vector<int> t1(vector<int> v) {
  int i = v[0], j = v[1];
  int ii = j, jj = i;
  if (i != 0) {
    ii *= -1;
    jj *= -1;
  }
  return {ii, jj};
}
vector<int> t2(vector<int> v) {
  int i = v[0], j = v[1];
  int ii = j, jj = i;
  if (j != 0) {
    ii *= -1;
    jj *= -1;
  }
  return {ii, jj};
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  int h, w, n;
  cin >> h >> w >> n;
  vector<vector<char>> mem(h, vector<char>(w, '.'));
  int x = 0, y = 0;
  vector<int> v = {-1, 0};
  rep(i, n) {
    if (mem[x][y] == '.') {
      mem[x][y] = '#';
      v = t1(v);
    } else {
      mem[x][y] = '.';
      v = t2(v);
    }
    x = (x + v[0] + h) % h;
    y = (y + v[1] + w) % w;
  }
  for (auto m : mem) {
    for (auto c : m) cout << c;
    outl;
  }
}

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

struct rvdsu {
 public:
  rvdsu() : _n(0) {}
  explicit rvdsu(int n) : _n(n), parent_or_size(n, -1), largestTen(n) {
    for (int i = 0; i < _n; i++) largestTen[i].push_back(i);
  }

  int merge(int a, int b) {
    assert(0 <= a && a < _n);
    assert(0 <= b && b < _n);
    int x = leader(a), y = leader(b);
    if (x == y) return x;
    if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
    parent_or_size[x] += parent_or_size[y];
    parent_or_size[y] = x;

    vector<int> lt;
    int i1 = 0, i2 = 0;
    while (lt.size() < 10) {
      int t1 = -1, t2 = -1;
      if (i1 < largestTen[x].size()) t1 = largestTen[x][i1];
      if (i2 < largestTen[y].size()) t2 = largestTen[y][i2];

      if (t1 == -1 && t2 == -1) break;
      if (t1 >= t2) {
        lt.push_back(t1);
        i1++;
      } else {
        lt.push_back(t2);
        i2++;
      }
    }
    largestTen[x] = lt;

    return x;
  }

  int calc(int v, int k) {
    int x = leader(v);
    if (size(x) < k) return -1;
    return largestTen[x][k - 1] + 1;
  }

  bool same(int a, int b) {
    assert(0 <= a && a < _n);
    assert(0 <= b && b < _n);
    return leader(a) == leader(b);
  }

  int leader(int a) {
    assert(0 <= a && a < _n);
    if (parent_or_size[a] < 0) return a;
    return parent_or_size[a] = leader(parent_or_size[a]);
  }

  int size(int a) {
    assert(0 <= a && a < _n);
    return -parent_or_size[leader(a)];
  }

 private:
  int _n;
  // root node: -1 * component size
  // otherwise: parent
  std::vector<int> parent_or_size;

  std::vector<vector<int>> largestTen;
};

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  int n, q;
  cin >> n >> q;

  rvdsu d(n);

  rep(i, q) {
    int que;
    cin >> que;
    if (que == 1) {
      int u, v;
      cin >> u >> v;
      u--;
      v--;
      d.merge(u, v);
    }
    if (que == 2) {
      int v, k;
      cin >> v >> k;
      v--;
      out(d.calc(v, k));
    }
  }
}

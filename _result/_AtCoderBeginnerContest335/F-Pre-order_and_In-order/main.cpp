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

struct node {
  int left;
  int right;
};

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  int n;
  cin >> n;
  auto ps = nis(n), is = nis(n);
  if (ps[0] != 1) {
    out(-1);
    return 0;
  }
  vector<node> nodes(n + 1, {0, 0});

  int v = 1;
  vector<int> roots;
  queue<int> que;

  int flag = 0;
  if (ps[0] == is[0]) {
    flag = 1;
  } else {
    roots.push_back(ps[0]);
    que.push(is[0]);
  }
  rep2(i, 1, n) {
    if (flag == 0) {
      nodes[v].left = ps[i];
    } else {
      nodes[v].right = ps[i];
    }
    v = ps[i];
    roots.push_back(ps[i]);
    que.push(is[i]);
    flag = 0;
    while (roots.size() != 0 && !que.empty() &&
           roots[roots.size() - 1] == que.front()) {
      v = que.front();
      roots.pop_back();
      que.pop();
      flag = 1;
    }
  }

  if (roots.size() != 0 || !que.empty()) {
    out(-1);
  } else {
    rep2(i, 1, n + 1) {
      cout << nodes[i].left << ' ' << nodes[i].right << endl;
    }
  }
}

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

struct RandomNumberGenerator {
  mt19937 mt;

  RandomNumberGenerator()
      : mt(chrono::steady_clock::now().time_since_epoch().count()) {}

  int operator()(int a, int b) {  // [a, b)
    uniform_int_distribution<int> dist(a, b - 1);
    return dist(mt);
  }

  int operator()(int b) {  // [0, b)
    return (*this)(0, b);
  }
};

vector<string> split(const string &s, char delim) {
  vector<string> elems;
  stringstream ss(s);
  string item;
  while (getline(ss, item, delim)) {
    if (!item.empty()) {
      elems.push_back(item);
    }
  }
  return elems;
}

int op0(int a, int b) { return max(a, b); }
int op1(int a, int b) { return min(a, b); }
int e0() { return -1; }
int e1() { return INF; }

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  int h, w, q;
  cin >> h >> w >> q;
  vector<vector<int>> mem(h, vector<int>(w, 1));
  vector<int> ra(w);
  rep(i, w) ra[i] = i;
  vector<segtree<int, op0, e0>> memr0(h, segtree<int, op0, e0>(ra));
  vector<segtree<int, op1, e1>> memr1(h, segtree<int, op1, e1>(ra));

  vector<int> ca(h);
  rep(i, h) ca[i] = i;
  vector<segtree<int, op0, e0>> memc0(w, segtree<int, op0, e0>(ca));
  vector<segtree<int, op1, e1>> memc1(w, segtree<int, op1, e1>(ca));

  int ans = h * w;
  rep(i, q) {
    int r, c;
    cin >> r >> c;
    r--;
    c--;
    if (mem[r][c]) {
      ans--;
      mem[r][c] = 0;

      memr0[r].set(c, -1);
      memr1[r].set(c, INF);
      memc0[c].set(r, -1);
      memc1[c].set(r, INF);

      continue;
    }

    int left = memr0[r].prod(0, c);
    if (left != -1) {
      ans--;
      int cc = left;
      memr0[r].set(cc, -1);
      memr1[r].set(cc, INF);
      memc0[cc].set(r, -1);
      memc1[cc].set(r, INF);
      mem[r][left] = 0;
    }
    int right = memr1[r].prod(c, w);
    if (right != INF) {
      ans--;
      int cc = right;
      memr0[r].set(cc, -1);
      memr1[r].set(cc, INF);
      memc0[cc].set(r, -1);
      memc1[cc].set(r, INF);
      mem[r][right] = 0;
    }
    int top = memc0[c].prod(0, r);
    if (top != -1) {
      ans--;
      int rr = top;
      memr0[rr].set(c, -1);
      memr1[rr].set(c, INF);
      memc0[c].set(rr, -1);
      memc1[c].set(rr, INF);
      mem[top][c] = 0;
    }
    int down = memc1[c].prod(r, h);
    if (down != INF) {
      ans--;
      int rr = down;
      memr0[rr].set(c, -1);
      memr1[rr].set(c, INF);
      memc0[c].set(rr, -1);
      memc1[c].set(rr, INF);
      mem[down][c] = 0;
    }
  }
  out(ans);
}

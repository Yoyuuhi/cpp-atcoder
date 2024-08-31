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

vector<string> split(const string& s, char delim) {
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

int op(int a, int b) { return max(a, b); }
int e() { return 0; }
using P = vector<int>;

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  int h, w, n;
  cin >> h >> w >> n;
  vector<vector<int>> rcs;
  map<int, int> memr;
  rep(i, n) {
    int r, c;
    cin >> r >> c;
    r--;
    c--;
    rcs.push_back({r, c});
  }
  segtree<int, op, e> st(200001);
  sort(all(rcs), greater<vector<int>>());

  priority_queue<P, vector<P>, less<P>> pq;
  for (auto rc : rcs) {
    int r = rc[0], c = rc[1];
    int val = st.prod(c, 200001) + 1;
    pq.push({val, r, c});
    st.set(c, val);
  }
  pq.push({0, h - 1, w - 1});

  int count = 0;
  string ans = "";
  int r = 0, c = 0;
  while (!pq.empty()) {
    P p = pq.top();
    pq.pop();
    int rr = p[1], cc = p[2];
    if (rr < r || cc < c) continue;
    rep(i, rr - r) ans += 'D';
    rep(i, cc - c) ans += 'R';
    r = rr;
    c = cc;
    count++;
  }
  out(count - 1);
  out(ans);
}
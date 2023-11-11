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

struct Edge {
  long long from;
  long long to;
  char c;
};
using Graph = vector<Edge>;

vector<int> cc;
int n;
string s;
Graph g;
int h = 0;

void solve(int now) {
  char c = s[now];
  int from = g[now].from;
  cc[now + 1] = cc[from + 1];
  if (c - 'A' == cc[now + 1]) {
    cc[now + 1]++;
  } else {
    cc[now + 1] = c == 'A' ? 1 : 0;
  }

  int to = g[now].to;
  if (cc[now + 1] == 3) {
    int ff = g[from].from;
    int fff = g[ff].from;
    if (fff != -1) g[fff].to = to;
    if (to != n) g[to].from = fff;
    if (fff == -1) {
      h = to;
    }
  }

  if (to != n) solve(to);
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif
  cin >> s;

  n = s.size();
  g.resize(n);
  cc.assign(n + 1, 0);

  rep(i, n) { g[i] = {i - 1, i + 1, s[i]}; }
  solve(0);
  int now = h;
  while (now < n && now >= 0) {
    cout << s[now];
    now = g[now].to;
  }
  outl;
}

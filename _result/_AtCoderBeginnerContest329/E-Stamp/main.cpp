#include <bits/stdc++.h>

#include <atcoder/all>
#define outx(X) cout << (X) << endl;
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

int n, m;
string s, t, st;
vector<char> mem;
queue<int> que;

void calcl(int idx) {
  if (idx >= 0 && s.substr(idx, m) != st) {
    bool poss = true;
    rep2(i, idx, idx + m) {
      if (s[i] != '#' && s[i] != t[i - idx]) {
        poss = false;
        break;
      }
    }
    if (poss) {
      rep2(i, idx, idx + m) {
        s[i] = '#';
        que.push(i);
      }
    }
  }
}

void calc(int idx) {
  int li = idx - m + 1;
  calcl(idx);
  calcl(li);
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  cin >> n >> m;
  cin >> s >> t;
  st = "";
  rep(i, m) st += '#';

  rep(i, n) {
    if (i + m - 1 >= n) break;
    if (s.substr(i, m) == t) {
      rep2(idx, i, i + m) {
        s[idx] = '#';
        que.push(idx);
      }
    }
  }

  while (!que.empty()) {
    int idx = que.front();
    que.pop();
    calc(idx);
  }

  for (auto c : s) {
    if (c != '#') {
      outx("No");
      return 0;
    }
  }
  outx("Yes");
}

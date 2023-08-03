#include <bits/stdc++.h>

#include <atcoder/all>
#define out(X) cout << (X) << endl;
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
using mint = atcoder::modint998244353;
const int INF = numeric_limits<int>::max() / 2;

struct str {
  int idx;
  ll val;
  bool add;
};

str op1(str a, str b) {
  if (a.add && b.add) {
    if (a.val > b.val) swap(a, b);
    return a;
  } else if (a.add || b.add) {
    if (!a.add) swap(a, b);
    return a;
  }
  return {-1, 0, false};
}
str op2(str a, str b) {
  if (!(a.add || b.add)) {
    if (a.val < b.val) swap(a, b);
    return a;
  } else if (!(a.add && b.add)) {
    if (a.add) swap(a, b);
    return a;
  }
  return {-1, 0, false};
}
str e() { return {-1, 0, false}; }

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  int n, k, q;
  cin >> n >> k >> q;
  vector<str> as(n);
  rep(i, n) as[i] = {i, 0, false};
  segtree<str, op1, e> st1(as);
  segtree<str, op2, e> st2(as);

  int count = 0;
  ll sum = 0;
  rep(i, q) {
    int x, y;
    cin >> x >> y;
    x--;
    if (count < k) {
      if (as[x].add) {
        sum = sum - as[x].val + y;
        as[x].val = y;
        st1.set(x, {x, y, true});
        st2.set(x, {x, y, true});
      } else {
        count++;
        sum += y;
        as[x] = {x, y, true};
        st1.set(x, {x, y, true});
        st2.set(x, {x, y, true});
      }
      out(sum);
      continue;
    }

    str s1 = st1.all_prod();
    str s2 = st2.all_prod();
    if (as[x].add) {
      if (y >= s2.val) {
        sum = sum - as[x].val + y;
        as[x].val = y;
        st1.set(x, {x, y, true});
        st2.set(x, {x, y, true});
      } else {
        sum = sum - as[x].val + s2.val;
        as[x] = {x, y, false};
        as[s2.idx].add = true;
        st1.set(x, {x, y, false});
        st1.set(s2.idx, {s2.idx, s2.val, true});
        st2.set(x, {x, y, false});
        st2.set(s2.idx, {s2.idx, s2.val, true});
      }
      out(sum);
      continue;
    }

    if (y <= s1.val) {
      as[x].val = y;
      st1.set(x, {x, y, false});
      st2.set(x, {x, y, false});
    } else {
      sum = sum - s1.val + y;
      as[x] = {x, y, true};
      as[s1.idx].add = false;
      st1.set(x, {x, y, true});
      st1.set(s1.idx, {s1.idx, s1.val, false});
      st2.set(x, {x, y, true});
      st2.set(s1.idx, {s1.idx, s1.val, false});
    }
    out(sum);
  }
}

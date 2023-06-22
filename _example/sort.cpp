vector<vector<int>> ax;

bool comp(vector<int> &a1, vector<int> &a2) {
  if (a1.size() != a2.size()) return a1.size() < a2.size();
  rep(i, a1.size()) {
    if (a1[i] != a2[i]) {
      return a1[i] < a2[i];
    }
  }
  return false;
}

sort(all(ax), comp);
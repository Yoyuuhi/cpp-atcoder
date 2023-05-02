int bs(int ok, int ng, bool f(int)) {
  if (!f(ok)) return -1;
  if (f(ng)) return ng;
  while (abs(ok - ng) > 1) {
    int mid = (ok + ng) / 2;
    if (f(mid)) {
      ok = mid;
    } else {
      ng = mid;
    }
  }
  return ok;
}
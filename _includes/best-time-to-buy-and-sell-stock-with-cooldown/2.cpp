int maxProfit(const vector<int> &prices) {
  array<int, 3> d1{};
  array<int, 3> d2{};
  for (int i = prices.size() - 1; i >= 0; i--) {
    d2 = d1;
    d1[0] = max(d2[0], d2[1] - prices[i]);
    d1[1] = max(d2[1], d2[2] + prices[i]);
    d1[2] = max(d2[2], d2[0]);
  }
  return d1[0];
}

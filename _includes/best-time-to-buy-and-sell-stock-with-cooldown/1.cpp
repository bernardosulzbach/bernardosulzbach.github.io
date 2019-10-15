int maxProfit(const vector<int> &prices) {
  vector<array<int, 3>> m(prices.size() + 1);
  for (int i = prices.size() - 1; i >= 0; i--) {
    m[i][0] = max(m[i + 1][0], m[i + 1][1] - prices[i]);
    m[i][1] = max(m[i + 1][1], m[i + 1][2] + prices[i]);
    m[i][2] = max(m[i + 1][2], m[i + 1][0]);
  }
  return m[0][0];
}

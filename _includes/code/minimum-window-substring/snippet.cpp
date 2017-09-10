string minimum_window_substring(string s, string t) {
  if (t.empty()) {
    return "";
  }
  // Frequency in the token.
  unordered_map<char, size_t> tf;
  for (char c : t) {
    tf[c]++;
  }
  // Frequency in the string.
  unordered_map<char, size_t> sf;
  // How many characters we have to match.
  const auto target = t.size();
  const auto n = s.size();
  size_t best_i = 0;
  const auto no_size = numeric_limits<size_t>::max();
  size_t best_size = no_size;
  size_t slow = 0;
  size_t fast = 0;
  size_t matched = 0;
  // Advance fast until we met the target.
  // Then shrink with slow until we no longer meet the conditions.
  // As this advances each pointer at most N times, this is O(n).
  while (slow < n && fast < n) {
    sf[s[fast]]++;
    if (sf[s[fast]] <= tf[s[fast]]) {
      matched++;
    }
    fast++;
    // Here, the range is [slow, fast).
    while (matched == target && slow < fast) {
      const size_t match_size = fast - slow;
      if (match_size < best_size) {
        best_i = slow;
        best_size = match_size;
      }
      sf[s[slow]]--;
      if (sf[s[slow]] < tf[s[slow]]) {
        matched--;
      }
      slow++;
    }
  }
  if (best_size == no_size) {
    return "";
  }
  return s.substr(best_i, best_size);
}

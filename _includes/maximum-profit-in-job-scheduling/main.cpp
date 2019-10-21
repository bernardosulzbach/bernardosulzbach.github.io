struct Job {
  int startTime;
  int endTime;
  int profit;

  Job(int startTime, int endTime, int profit) : startTime(startTime), endTime(endTime), profit(profit) {}

  bool operator<(const Job& rhs) const {
    if (startTime < rhs.startTime) return true;
    if (rhs.startTime < startTime) return false;
    if (endTime < rhs.endTime) return true;
    if (rhs.endTime < endTime) return false;
    return profit < rhs.profit;
  }
};

int firstEqualOrGreater(const map<int, int>& bestStartingFrom, int key) {
  return bestStartingFrom.upper_bound(key - 1)->second;
}

int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
  vector<Job> jobs;
  for (size_t i = 0; i < startTime.size(); i++) {
    jobs.emplace_back(startTime[i], endTime[i], profit[i]);
  }
  // Sorting this vector is O(n lg n).
  sort(begin(jobs), end(jobs));
  map<int, int> bestStartingFrom;
  bestStartingFrom[numeric_limits<int>::max()] = 0;
  // Querying and inserting n times here is O(n lg n).
  for (auto it = rbegin(jobs); it != rend(jobs); it++) {
    const auto a = firstEqualOrGreater(bestStartingFrom, it->startTime);
    const auto b = it->profit + firstEqualOrGreater(bestStartingFrom, it->endTime);
    bestStartingFrom[it->startTime] = max(a, b);
  }
  return firstEqualOrGreater(bestStartingFrom, 0);
}

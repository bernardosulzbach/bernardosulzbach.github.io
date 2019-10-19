#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

using U8 = uint8_t;
using U16 = uint16_t;
using U32 = uint32_t;
using U64 = uint64_t;

using I8 = int8_t;
using I16 = int16_t;
using I32 = int32_t;
using I64 = int64_t;

template <typename T>
T populationCount(T t) {
  T count = 0;
  while (t) {
    count++;
    t &= (t - 1u);
  }
  return count;
}

template <typename T>
void writeBits(T t) {
  for (U64 i = 0; i < sizeof(T) * 8; i++) {
    cout << ((t >> (sizeof(T) * 8u - 1u - i)) & 1u);
  }
}

struct Person {
  U16 index;
  U16 skills;

  Person(U16 index, U16 skills) : index(index), skills(skills) {}
};

void writePeopleSet(const vector<Person> &peopleSet, const string &name) {
  cout << name << ":" << '\n';
  for (U64 personIndex = 0; personIndex < peopleSet.size(); personIndex++) {
    writeBits(peopleSet[personIndex].skills);
    cout << "\n";
  }
}

class Solution {
  static void removeRedundantPeople(vector<Person> &peopleSet) {
    sort(rbegin(peopleSet), rend(peopleSet), [](const Person &a, const Person &b) {
      if (populationCount(a.skills) < populationCount(b.skills)) {
        return true;
      }
      if (populationCount(a.skills) == populationCount(b.skills)) {
        if (a.index > b.index) {
          return true;
        }
        if (a.index == b.index) {
          return a.skills < b.skills;
        }
      }
      return false;
    });
    vector<bool> redundant(peopleSet.size());
    for (U64 i = 0; i < peopleSet.size(); i++) {
      if (redundant[i]) {
        continue;
      }
      for (U64 j = i + 1; j < peopleSet.size(); j++) {
        if (redundant[j]) {
          continue;
        }
        if ((peopleSet[i].skills | peopleSet[j].skills) == peopleSet[i].skills) {
          redundant[j] = true;
        }
      }
    }
    U64 w = 0;
    for (U64 i = 0; i < peopleSet.size(); i++) {
      if (redundant[i]) {
        continue;
      }
      peopleSet[w++] = peopleSet[i];
    }
    peopleSet.erase(begin(peopleSet) + w, end(peopleSet));
  }

  static void setCover(vector<Person> &peopleSet, U16 goal, U16 current, U64 index, vector<U64> &used,
                       vector<U64> &best) {
    if (!best.empty() && used.size() >= best.size()) {
      return;
    }
    if (current == goal) {
      if (best.empty() || used.size() < best.size()) {
        best = used;
      }
      return;
    }
    if (index == peopleSet.size()) {
      return;
    }
    const auto oldCurrent = current;
    current = current | peopleSet[index].skills;
    used.push_back(index);
    setCover(peopleSet, goal, current, index + 1, used, best);
    used.pop_back();
    current = oldCurrent;
    setCover(peopleSet, goal, current, index + 1, used, best);
  }

 public:
  static vector<int> smallestSufficientTeam(const vector<string> &requiredSkills,
                                            const vector<vector<string>> &people) {
    U16 target = 0u;
    for (U64 i = 0; i < requiredSkills.size(); i++) {
      target = (target << 1u) | 1u;
    }
    cout << "Target:\n";
    writeBits(target);
    cout << "\n\n";
    vector<Person> peopleSet;
    for (U64 personIndex = 0; personIndex < people.size(); personIndex++) {
      const auto skillsAsWords = people[personIndex];
      U16 skills = 0;
      for (const auto &personSkill : skillsAsWords) {
        for (U64 i = 0; i < requiredSkills.size(); i++) {
          if (personSkill == requiredSkills[i]) {
            skills = skills | (1u << i);
          }
        }
      }
      peopleSet.emplace_back(personIndex, skills);
    }
    writePeopleSet(peopleSet, "All");
    cout << '\n';
    removeRedundantPeople(peopleSet);
    writePeopleSet(peopleSet, "Non-redundant");
    // Search on the remaining people.
    vector<U64> best;
    {
      vector<U64> used;
      setCover(peopleSet, target, 0, 0, used, best);
    }
    vector<int> originalIndexes;
    for (const auto bestIndex : best) {
      originalIndexes.push_back(peopleSet[bestIndex].index);
    }
    return originalIndexes;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<string> requiredSkills(n);
  for (int i = 0; i < n; i++) {
    cin >> requiredSkills[i];
  }
  vector<vector<string>> people;
  int m;
  while (cin >> m) {
    vector<string> personSkills(m);
    for (int i = 0; i < m; i++) {
      cin >> personSkills[i];
    }
    people.push_back(personSkills);
  }
  auto first = true;
  for (const auto &value : Solution::smallestSufficientTeam(requiredSkills, people)) {
    if (!first) {
      cout << ' ';
    }
    cout << value;
    first = false;
  }
  cout << '\n';
  return 0;
}

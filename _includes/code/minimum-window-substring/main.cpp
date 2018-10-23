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

// Generic code

#define debug(x) cout << #x " is " << x << '\n'
#define debugbinary(x) cout << #x " is " << binary(x) << '\n'

const double PI = 4 * atan(1);

typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef vector<vector<bool>> bMat;
typedef vector<vector<i64>> i64Mat;

// Prints the values separated by the specified separator.
template <typename It, typename T = typename iterator_traits<It>::value_type>
void print(It a, It b, string separator) {
  copy(a, b, ostream_iterator<T>(cout, separator.c_str()));
  if (separator.find("\n") == string::npos) {
    cout << "\n";
  }
}

// Prints the values separated by spaces.
template <typename It, typename T = typename iterator_traits<It>::value_type>
void print(It a, It b) {
  print(a, b, " ");
}

// Prints the values separated by spaces.
template <typename T>
void print(T t) {
  print(t.begin(), t.end());
}

// Prints the values separated by newlines.
template <typename It, typename T = typename iterator_traits<It>::value_type>
void print_lines(It a, It b) {
  print(a, b, "\n");
}

// Prints the values separated by newlines.
template <typename T>
void print_lines(T t) {
  print_lines(t.begin(), t.end());
}

// Ignores everything on std::cin until the next '\n'.
void cin_ignore_until_newline(void) {
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

template <typename T>
string binary(const T t) {
  const int bits = 8 * sizeof(T);
  stringstream ss;
  for (int i = bits - 1; i >= 0; i--) {
    ss << (int)((t >> i) & 1);
  }
  return ss.str();
}

template <typename K, typename V>
struct PairHash {
  size_t operator()(const pair<K, V> &p) const {
    auto h1 = hash<K>{}(p.first);
    auto h2 = hash<V>{}(p.second);
    return h1 ^ (h2 << 1);
  }
};

/**
 * Information Retrieval code.
 */
vector<string> tokenize(string &input) {
  vector<string> tokens;
  string token;
  for (char c : input) {
    if (isalpha(c)) {
      token += tolower(c);
    } else {
      if (!token.empty()) {
        tokens.push_back(token);
        token.erase();
      }
    }
  }
  if (!token.empty()) {
    tokens.push_back(token);
  }
  return tokens;
}

/**
 * Computes TF-IDF by using
 *
 *     f(t, d) * log(N / nt)
 */
vector<vector<double>> tf_idf(vector<vector<string>> &input) {
  const double N = input.size();
  // Make the table of how many documents have a term (nt).
  map<string, int> documents_with_term;
  for (vector<string> &document : input) {
    unordered_set<string> seen;
    for (string &term : document) {
      if (seen.count(term) == 0) {
        documents_with_term[term]++;
        seen.insert(term);
      }
    }
  }
  const size_t term_count = documents_with_term.size();
  unordered_map<string, size_t> term_index;
  size_t index = 0;
  for (auto p : documents_with_term) {
    string term = p.first;
    term_index.insert({term, index});
    index++;
  }
  vector<vector<int>> count(N, vector<int>(term_count));
  for (size_t i = 0; i < N; i++) {
    for (string &term : input[i]) {
      count[i][term_index[term]]++;
    }
  }
  vector<vector<double>> results(N, vector<double>(term_count));
  for (size_t i = 0; i < N; i++) {
    for (auto p : documents_with_term) {
      string term = p.first;
      auto j = term_index[term];
      int documents_with_it = p.second;
      results[i][j] = count[i][j] * log(N / documents_with_it);
    }
  }
  return results;
}

double dot(const vector<double> &a, const vector<double> &b) {
  double x = 0;
  for (size_t i = 0; i < a.size(); i++) {
    x += a[i] * b[i];
  }
  return x;
}

double norm(const vector<double> &v) {
  double x = 0;
  for (size_t i = 0; i < v.size(); i++) {
    x += v[i] * v[i];
  }
  return sqrt(x);
}

double cosine_similarity(const vector<double> &a, const vector<double> &b) {
  return dot(a, b) / (norm(a) * norm(b));
}

/**
 * Unbalanced Binary Search Tree implementation.
 */
template <typename T>
class BinaryTree {
  T x;
  bool used = false;
  BinaryTree *l = NULL;
  BinaryTree *r = NULL;

 public:
  BinaryTree(void) {}

  ~BinaryTree(void) {
    if (l != NULL) {
      delete l;
    }
    if (r != NULL) {
      delete r;
    }
  }

  void insert(const T v) {
    if (!used) {
      x = v;
      used = true;
      return;
    }
    BinaryTree *t = v < x ? l : r;
    if (t == NULL) {
      BinaryTree *b = new BinaryTree();
      if (v < x) {
        l = b;
        t = b;
      } else {
        r = b;
        t = b;
      }
    }
    t->insert(v);
  }

  template <typename It>
  void breadth_search(It it) {
    queue<BinaryTree *> trees;
    trees.push(this);
    while (!trees.empty()) {
      const BinaryTree *t = trees.front();
      trees.pop();
      *it++ = t->x;
      if (t->l != NULL) {
        trees.push(t->l);
      }
      if (t->r != NULL) {
        trees.push(t->r);
      }
    }
  }
};

template <typename T, typename Edge = int>
class SparseGraph {
  static const Edge no_edge = -1;

  vector<T> nodes;
  vector<unordered_map<size_t, Edge>> edges;

 public:
  template <typename It>
  SparseGraph(It it, It end) {
    nodes = vector<T>(it, end);
    edges.resize(nodes.size(), unordered_map<size_t, Edge>());
  }

  ~SparseGraph() {}

  T get(const size_t i) { return nodes[i]; }

  void replace(const size_t i, const size_t j) { swap(nodes[i], nodes[j]); }

  void insert_edge(const size_t i, const size_t j, const Edge value) {
    edges[i][j] = value;
  }

  unordered_set<size_t> minimum_spanning_tree(const size_t start) const {
    unordered_set<size_t> t;
    set<pair<Edge, size_t>> q;
    q.insert({0, start});
    while (!q.empty()) {
      auto p = q.begin();
      q.erase(q.begin());
      if (t.count(p.second)) {
        continue;
      }
      t.insert(p.second);
      // Add to the queue all new nodes.
      for (size_t neighbor : edges[p.second]) {
        if (!t.count(neighbor)) {
          q.insert({p.first + edges[p.second][neighbor], neighbor});
        }
      }
    }
    return t;
  }
};

/**
 * The specialized node type used in Tarjan's algorithm.
 */
typedef struct TarjanNode {
  i64 id;
  i64 index;
  i64 link;
  bool stack;
  vector<i64> outgoing;

  TarjanNode(i64 node_id, const vector<bool> &relations) {
    id = node_id;
    index = undefined_index;
    link = 0;
    stack = false;
    for (u64 i = 0; i < relations.size(); i++) {
      if (relations[i]) {
        outgoing.push_back(i);
      }
    }
  }

  static const i64 undefined_index = numeric_limits<i64>::min();

} TarjanNode;

vector<TarjanNode> derive_nodes(const vector<vector<bool>> &matrix) {
  vector<TarjanNode> nodes;
  for (u64 i = 0; i < matrix.size(); i++) {
    nodes.push_back(TarjanNode(i, matrix[i]));
  }
  return nodes;
}

void tarjan_start(vector<vector<i64>> &components, vector<TarjanNode> &nodes,
                  vector<size_t> &node_stack, TarjanNode &node, i64 &index) {
  node.index = index;
  node.link = index;
  index++;
  node_stack.push_back(node.id);
  node.stack = true;
  for (i64 out : node.outgoing) {
    TarjanNode &next = nodes[out];
    if (next.index == TarjanNode::undefined_index) {
      tarjan_start(components, nodes, node_stack, next, index);
      node.link = min(node.link, next.link);
    } else if (next.stack) {
      // As the next node is on the stack too, it is in this component.
      node.link = min(node.link, next.index);
    }
  }
  // If we have a new component, add it to the vector.
  if (node.link == node.index) {
    vector<i64> component;
    while (true) {
      TarjanNode &removed = nodes[node_stack.back()];
      node_stack.pop_back();
      removed.stack = false;
      component.push_back(removed.id);
      if (removed.id == node.id) {
        break;
      }
    }
    components.push_back(component);
  }
}

/**
 * An implementation of Tarjan's algorithm.
 */
vector<vector<i64>> derive_components(vector<vector<bool>> &matrix) {
  vector<vector<i64>> components;
  vector<TarjanNode> nodes = derive_nodes(matrix);
  vector<size_t> node_stack;
  i64 index = 0;
  // Prevent value copies from the base vector.
  for (TarjanNode &node : nodes) {
    // If we have not yet connected this node, try to do it.
    if (node.index == TarjanNode::undefined_index) {
      tarjan_start(components, nodes, node_stack, node, index);
    }
  }
  for (vector<i64> &component : components) {
    sort(component.begin(), component.end());
  }
  sort(components.begin(), components.end());
  return components;
}

template <typename T, typename Edge = int>
class DirectedGraph {
  static const Edge no_edge = -1;

  vector<T> nodes;
  vector<vector<Edge>> m;

 public:
  template <typename It>
  DirectedGraph(It it, It end) {
    nodes = vector<T>(it, end);
    m.resize(nodes.size(), vector<Edge>(nodes.size(), no_edge));
  }

  ~DirectedGraph() {}

  T get(const size_t i) { return nodes[i]; }

  void replace(const size_t i, const size_t j) { swap(nodes[i], nodes[j]); }

  void insert_edge(const size_t i, const size_t j) { m[i][j] = 1; }

  /**
   * Returns the index of the minimum parent of the i-th node.
   */
  size_t minimum_parent(const size_t i) {
    unordered_set<size_t> visited;
    bool found = false;
    T minimum_so_far = 0;
    vector<size_t> s;
    s.push_back(i);
    while (!s.empty()) {
      const size_t x = s.back();
      s.pop_back();
      // Skip if already visited.
      if (visited.count(x) != 0) {
        continue;
      }
      if (x != i && (!found || get(x) < get(minimum_so_far))) {
        // Found a better node.
        minimum_so_far = x;
        found = true;
      }
      visited.insert(x);
      // Add all parents to the stack.
      for (size_t j = 0; j != nodes.size(); j++) {
        if (m[x][j] != 0) {
          if (visited.count(j) == 0) {
            s.push_back(j);
          }
        }
      }
    }
    if (found) {
      return minimum_so_far;
    } else {
      return i;
    }
  }

  /**
   * Uses Dijkstra's to find the minimum distance between A and B.
   */
  size_t minimum_distance(const size_t a, const size_t b) {
    unordered_set<size_t> v;
    set<pair<T, size_t>> q;
    q.push({0, a});
    while (!q.empty()) {
      auto node = q.front().second;
      auto dist = q.front().first;
      q.pop();
      if (node == b) {
        return dist;
      }
      if (v.count(node)) {
        continue;
      }
      v.insert(node);
      for (size_t i = 0; i < m.size(); i++) {
        if (m[node][i] != no_edge && !v.count(i)) {
          q.push({dist + m[node][i], i});
        }
      }
    }
    return no_edge;
  }
};

i64 longest_common_subsequence(const string &a, const string &b) {
  vector<i64> row(a.size() + 1, 0);
  vector<vector<i64>> matrix(b.size() + 1, row);
  for (size_t i = 1; i != b.size(); i++) {
    for (size_t j = 1; j != a.size(); j++) {
      if (b[i - 1] == a[j - 1]) {
        matrix[i][j] = matrix[i - 1][j - 1];
      } else {
        matrix[i][j] = max(matrix[i - 1][j], matrix[i][j - 1]);
      }
    }
  }
  return matrix[b.size() - 1][a.size() - 1];
}

/**
 * Reads an integer from S, using the provided base.
 */
i64 read_base(const string s, const i64 base) {
  i64 x = 0;
  for (auto c : s) {
    x *= base;
    if ('a' <= c && c <= 'z') {
      x += c - 'a' + 10;
    } else {
      x += c - '0';
    }
  }
  return x;
}

/**
 * Reverses an integer X. Transforming 123 in 321.
 */
i64 reverse(i64 x) {
  i64 r = 0;
  while (x) {
    r *= 10;
    r += x % 10;
    x /= 10;
  }
  return r;
}

bool starts_with(string s, string prefix, bool ignore_case = false) {
  if (s.size() < prefix.size()) {
    return false;
  }
  for (size_t i = 0; i != prefix.size(); i++) {
    auto s_c = s[i];
    auto p_c = prefix[i];
    if (ignore_case) {
      s_c = tolower(s_c);
      p_c = tolower(p_c);
    }
    if (s_c != p_c) {
      return false;
    }
  }
  return true;
}

vector<vector<int>> subsets_with_duplicates(vector<int> &nums) {
  sort(nums.begin(), nums.end());
  vector<int> values;
  vector<int> counts;
  for (int num : nums) {
    if (!counts.empty() && num == values[counts.size() - 1]) {
      counts[counts.size() - 1]++;
    } else {
      values.push_back(num);
      counts.push_back(1);
    }
  }
  vector<vector<int>> subsets;
  vector<int> selection(counts.size(), 0);
  while (true) {
    // Add the subset.
    vector<int> subset;
    for (u64 i = 0; i < selection.size(); i++) {
      for (int j = 0; j < selection[i]; j++) {
        subset.push_back(values[i]);
      }
    }
    subsets.push_back(subset);
    if (selection == counts) {
      break;
    }
    // Increment the selection.
    bool incremented = false;
    for (u64 index = 0; index < selection.size() && !incremented; index++) {
      if (selection[index] < counts[index]) {
        selection[index]++;
        incremented = true;
      } else {
        selection[index] = 0;
      }
    }
  }
  return subsets;
}

u64 combinations(u64 m, u64 n) {
  // (m + n - 2) choose (n - 1)
  // (m + n - 2)! / ((n - 1)! * (m - 1)!)
  u64 numeratorEnd = m + n - 2;
  u64 denominatorMax = max(m - 1, n - 1);
  u64 denominatorMin = min(m - 1, n - 1);
  u64 total = 1;
  for (u64 i = denominatorMax + 1; i <= numeratorEnd; i++) {
    total *= i;
  }
  for (u64 i = 2; i <= denominatorMin; i++) {
    total /= i;
  }
  return total;
}

u64 levenshtein(const string &a, const string &b) {
  vector<u64> row(a.size() + 1, 0);
  vector<vector<u64>> d(b.size() + 1, row);
  for (u64 j = 0; j < b.size() + 1; j++) {
    d[j][0] = j;
  }
  for (u64 i = 0; i < a.size() + 1; i++) {
    d[0][i] = i;
  }
  for (u64 j = 1; j < b.size() + 1; j++) {
    for (u64 i = 1; i < a.size() + 1; i++) {
      const u64 cost = b[j - 1] != a[i - 1];
      d[j][i] =
          min(d[j - 1][i - 1] + cost, min(d[j - 1][i] + 1, d[j][i - 1] + 1));
    }
  }
  return d[b.size()][a.size()];
}

vector<pair<i64, i64>> merge_intervals(vector<pair<i64, i64>> &intervals) {
  sort(intervals.begin(), intervals.end());
  vector<pair<i64, i64>> s;
  for (auto p : intervals) {
    if (s.empty() || s.back().second < p.first) {
      s.push_back(p);
    } else {
      s.back().second = max(s.back().second, p.second);
    }
  }
  return s;
}

// Quick "cross product" of 2D vectors for convex hulls.
int cross(pair<int, int> a, pair<int, int> b, pair<int, int> o) {
  int x = (a.first - o.first) * (b.second - o.second);
  int y = (a.second - o.second) * (b.first - o.first);
  return x - y;
}

// Andrew's monotone chain for convex hulls.
vector<size_t> convex_hull(vector<pair<int, int>> ps) {
  vector<size_t> lower;
  for (int i = 0; i < (int)ps.size(); i++) {
    const auto p = ps[i];
    auto s = lower.size();
    while (s >= 2 && cross(ps[lower[s - 2]], ps[lower[s - 1]], p) < 0) {
      lower.pop_back();
      s = lower.size();
    }
    lower.push_back(i);
  }
  vector<size_t> upper;
  for (int i = ps.size() - 1; i >= 0; i--) {
    const auto p = ps[i];
    auto s = upper.size();
    while (s >= 2 && cross(ps[upper[s - 2]], ps[upper[s - 1]], p) < 0) {
      upper.pop_back();
      s = upper.size();
    }
    upper.push_back(i);
  }
  vector<size_t> hull = lower;
  hull.pop_back();
  hull.insert(hull.end(), upper.begin(), upper.end());
  hull.pop_back();
  return hull;
}

// How many layers (hulls) a set of points has.
int layers(vector<pair<int, int>> ps) {
  int count = 0;
  while (ps.size() >= 2) {
    sort(ps.begin(), ps.end());
    vector<size_t> indexes = convex_hull(ps);
    count++;
    unordered_set<size_t> index_set(indexes.begin(), indexes.end());
    vector<pair<int, int>> next;
    for (size_t i = 0; i < ps.size(); i++) {
      if (!index_set.count(i)) {
        next.push_back(ps[i]);
      }
    }
    ps = next;
  }
  return count;
}

struct CostValue {
  i64 cost;
  i64 value;
};

// Step that allows you to spend K into the remaining I choices.
i64 knapsack_step(vector<CostValue> &v, i64Mat &m, bMat &c, u64 i, i64 k) {
  // End of recursion.
  if (i == v.size()) {
    return 0;
  }
  if (k == 0) {
    return 0;
  }
  if (m[i][k] >= 0) {
    return m[i][k];
  }
  i64 value = knapsack_step(v, m, c, i + 1, k);
  // Consider taking the next object if we can afford it.
  if (v[i].cost <= k) {
    i64 alternative = v[i].value + knapsack_step(v, m, c, i + 1, k - v[i].cost);
    if (alternative > value) {
      c[i][k] = true;
      value = alternative;
    }
  }
  m[i][k] = value;
  return value;
}

// 0-1 Knapsack with Cost-Value pairs and K limit.
// O(V.size() * K)
vector<size_t> knapsack(vector<CostValue> &v, i64 k) {
  i64Mat m(v.size(), vector<i64>(k + 1, -1));
  bMat c(v.size(), vector<bool>(k + 1, false));
  knapsack_step(v, m, c, 0, k);
  vector<size_t> chosen;
  for (u64 i = 0; i < v.size(); i++) {
    if (c[i][k]) {
      chosen.push_back(i);
      k -= v[i].cost;
    }
  }
  return chosen;
}

double euclidean_distance(pair<double, double> a, pair<double, double> b) {
  return sqrt(pow(b.first - a.first, 2) + pow(b.second - a.second, 2));
}

template <typename It>
double minimum_distance(It a, It b) {
  auto size = distance(a, b);
  if (size < 2) {
    return numeric_limits<double>::max();
  }
  auto m = a + size / 2;
  auto dl = minimum_distance(a, m);
  auto dr = minimum_distance(m, b);
  auto d = min(dl, dr);
  // Find a possible smaller distance in the crossing.
  auto it = m;
  while (it != a && m->first - it->first < d) {
    it--;
  }
  while (it != m) {
    for (auto r = m; r != b && r->first - it->first < d; r++) {
      d = min(d, euclidean_distance(*it, *r));
    }
    it++;
  }
  return d;
}

// Using a very naive sieve.
vector<i64> derive_primes(u64 m, u64 n) {
  vector<bool> sieve(n + 1, true);
  sieve[0] = sieve[1] = false;
  for (u64 i = 2; i <= n; i++) {
    if (sieve[i]) {
      for (u64 m = 2 * i; m <= n; m += i) {
        sieve[m] = false;
      }
    }
  }
  // Transform in a vector of primes.
  vector<i64> primes;
  for (u64 i = m; i <= n; i++) {
    if (sieve[i]) {
      primes.push_back(i);
    }
  }
  return primes;
}

// How many times D divides N factorial.
i64 factorial_factor_count(const i64 n, const i64 d) {
  i64 x = 0;
  i64 f = d;  // Current factor being counted.
  while (n / f) {
    x += (n / f);
    f *= d;
  }
  return x;
}

u64 gcd(u64 a, u64 b) {
  while (b != 0) {
    tie(a, b) = make_tuple(b, a % b);
  }
  return a;
}

i64 gcd(i64 a, i64 b) {
  a = abs(a);
  b = abs(b);
  return gcd((u64)a, (u64)b);
}

i64 lcm(i64 a, i64 b) {
  i64 c = gcd(a, b);
  return c == 0 ? 0 : a / c * b;
}

// A simple Trie for lowercase ASCII.
struct Trie {
  // These are freed when the Trie is destroyed.
  vector<unique_ptr<Trie>> children = vector<unique_ptr<Trie>>(26);
  bool word = false;

  template <typename It>
  void insert(It begin, It end) {
    if (begin == end) {
      word = true;
      return;
    }
    const size_t index = (*begin) - 'a';
    if (!children[index]) {
      // This is better, but only C++14.
      // children[index] = make_unique<Trie>();
      children[index].reset(new Trie());
    }
    children[index]->insert(begin + 1, end);
  }

  template <typename It>
  bool contains(It begin, It end) const {
    if (begin == end) {
      return word;
    }
    const size_t index = (*begin) - 'a';
    if (!children[index]) {
      return false;
    }
    return children[index]->contains(begin + 1, end);
  }

  // 0 - Does not.
  // 1 - This is the prefix of something.
  // 2 - Full match.
  template <typename It>
  int contains_as_prefix(It begin, It end) const {
    if (begin == end) {
      if (word) {
        return 2;
      } else {
        return 1;
      }
    }
    const size_t index = (*begin) - 'a';
    if (!children[index]) {
      return 0;
    }
    return children[index]->contains_as_prefix(begin + 1, end);
  }

  i64 words() const {
    i64 words = 0;
    if (word) {
      words++;
    }
    for (const unique_ptr<Trie> &child : children) {
      if (child) {
        words += child->words();
      }
    }
    return words;
  }

  int children_count() const {
    int count = 0;
    for (const unique_ptr<Trie> &child : children) {
      if (child) {
        count++;
      }
    }
    return count;
  }

  void branch_count(unordered_map<i64, i64> &m, i64 branches = 0) const {
    if (word) {
      m[branches]++;
    }
    if (branches == 0 || word || children_count() > 1) {
      branches++;
    }
    for (const unique_ptr<Trie> &child : children) {
      if (child) {
        child->branch_count(m, branches);
      }
    }
  }
};

template <typename T, typename Comparator>
class SlidingWindow {
  struct Block {
    Block(T v, size_t w) : value(v), width(w) {}
    T value;
    size_t width;
  };
  Comparator comp;
  deque<Block> data;

 public:
  void push(const T t) {
    size_t width = 1;
    while (!data.empty() && comp(data.back().value, t)) {
      data.pop_back();
      width++;
    }
    data.emplace_back(t, width);
  }
  T get() const { return data.front().value; }
  void pop() {
    // Either reduce the width of the best block (front), or drop it.
    if (data.empty()) {
      return;
    }
    if (data.front().width > 1) {
      data.front().width--;
    } else {
      data.pop_front();
    }
  }
};

template <typename T>
static T lsb(const T t) {
  return t & -t;
}

template <typename T>
class BIT {
 public:
  vector<T> data;
  BIT(const vector<T> &source) {
    data.resize(source.size() + 1, 0);
    for (size_t i = 0; i < source.size(); i++) {
      update(i + 1, source[i]);
    }
  }
  void update(size_t index, T delta) {
    while (index < data.size()) {
      data[index] += delta;
      index += lsb(index);
    }
  }
  T query(size_t index) const {
    T sum = 0;
    while (index) {
      sum += data[index];
      index -= lsb(index);
    }
    return sum;
  }
};

/*
 * w[i][j] = the amount the bidder J is willing to pay for item I.
 *
 * The run time is O(nm^2) where n = |items| and m = |bidders|.
 *
 * Resets negative bids in w to 0.
 *
 * Returns a, where a[i] = J means I-th item got assigned to bidder J.
 *
 * A[i] = -1 means item I did not get assigned.
 *
 * To minimize, set w[i][j] = max(w) - w[i][j].
 *
 * To assign all, w[i][j] = min(w) + w[i][j].
 */
vector<int> hungarian_method(vector<vector<int>> &w) {
  const int n = w.size();
  const int m = w[0].size();
  const int PHI = -1;
  const int NOL = -2;
  const int INF = numeric_limits<int>::max();
  vector<vector<bool>> x(n, vector<bool>(m));
  vector<bool> ss(n);
  vector<bool> st(m);
  vector<int> u(n);
  vector<int> v(m);
  vector<int> p(m);
  vector<int> ls(n);
  vector<int> lt(m);
  vector<int> a(n);
  int f = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      f = max(f, w[i][j]);
    }
  }
  fill(u.begin(), u.end(), f);
  fill(p.begin(), p.end(), INF);
  fill(lt.begin(), lt.end(), NOL);
  fill(ls.begin(), ls.end(), PHI);
  fill(a.begin(), a.end(), -1);
  while (true) {
    f = -1;
    for (int i = 0; i < n && f == -1; i++) {
      if (ls[i] != NOL && !ss[i]) {
        f = i;
      }
    }
    if (f != -1) {
      ss[f] = true;
      for (int j = 0; j < m; j++) {
        if (!x[f][j] && u[f] + v[j] - w[f][j] < p[j]) {
          lt[j] = f;
          p[j] = u[f] + v[j] - w[f][j];
        }
      }
    } else {
      for (int i = 0; i < m && f == -1; i++) {
        if (lt[i] != NOL && !st[i] && p[i] == 0) {
          f = i;
        }
      }
      if (f == -1) {
        int d1 = INF, d2 = INF, d;
        for (int i : u) {
          d1 = min(d1, i);
        }
        for (int i : p) {
          if (i > 0) {
            d2 = min(d2, i);
          }
        }
        d = min(d1, d2);
        for (int i = 0; i < n; i++) {
          if (ls[i] != NOL) {
            u[i] -= d;
          }
        }
        for (int i = 0; i < m; i++) {
          if (p[i] == 0) {
            v[i] += d;
          }
          if (p[i] > 0 && lt[i] != NOL) {
            p[i] -= d;
          }
        }
        if (d2 >= d1) {
          break;
        }
      } else {
        st[f] = true;
        int s = -1;

        for (int i = 0; i < n && s == -1; i++) {
          if (x[i][f]) {
            s = i;
          }
        }
        if (s == -1) {
          for (int l, r;; f = r) {
            r = f;
            l = lt[r];

            if (r >= 0 && l >= 0) {
              x[l][r] = !x[l][r];
            } else {
              break;
            }
            r = ls[l];
            if (r >= 0 && l >= 0) {
              x[l][r] = !x[l][r];
            } else {
              break;
            }
          }
          fill(p.begin(), p.end(), INF);
          fill(lt.begin(), lt.end(), NOL);
          fill(ls.begin(), ls.end(), NOL);
          fill(st.begin(), st.end(), false);
          fill(ss.begin(), ss.end(), false);
          for (int i = 0; i < n; i++) {
            bool ex = true;
            for (int j = 0; j < m && ex; j++) {
              ex = !x[i][j];
            }
            if (ex) {
              ls[i] = PHI;
            }
          }
        } else {
          ls[s] = f;
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (x[i][j]) {
        a[j] = i;
      }
    }
  }
  return a;
}

int largest_rectangle_in_histogram(vector<int> &v) {
  const int length = v.size();
  int best = 0;
  // {Index, Height}
  vector<array<int, 2>> s;
  auto pop = [&best, &s](int i) {
    best = max(best, s.back()[1] * (i - s.back()[0] + 1));
    s.pop_back();
  };
  for (int i = 0; i < length; i++) {
    s.push_back({{i, v[i]}});
    while (s.size() > 1) {
      const auto a = s[s.size() - 2];
      const auto b = s[s.size() - 1];
      if (a[1] < b[1]) {
        break;
      } else if (a[1] == b[1]) {
        pop(i);
      } else {
        int index = s[s.size() - 2][0];
        int height = b[1];
        pop(i);
        pop(i - 1);
        s.push_back({{index, height}});
      }
    }
    const auto e = s[s.size() - 1];
    best = max(best, e[1] * (i - e[0] + 1));
  }
  while (!s.empty()) {
    pop(length - 1);
  }
  return best;
}

class Manacher {
 private:
  // P[i] = length of longest palindromic substring of t, centered at i.
  vector<int> p;
  // The transformed string.
  vector<char> t;
  // The original string.
  string s;

  // Transform s into t.
  // For example, if s = "abba", then t = "$#a#b#b#a#@" the # are interleaved
  // to avoid even/odd-length palindromes uniformly $ and @ are prepended and
  // appended to each end to avoid bounds checking.
  void preprocess() {
    t = vector<char>(s.size() * 2 + 3);
    t[0] = '$';
    t[s.length() * 2 + 2] = '@';
    for (int i = 0; i < (int)s.length(); i++) {
      t[2 * i + 1] = '#';
      t[2 * i + 2] = s[i];
    }
    t[s.length() * 2 + 1] = '#';
  }

 public:
  Manacher(string str) {
    s = str;
    preprocess();
    p = vector<int>(t.size());
    int center = 0;
    int right = 0;
    for (int i = 1; i < (int)t.size() - 1; i++) {
      int mirror = 2 * center - i;
      if (right > i) {
        p[i] = min(right - i, p[mirror]);
      }
      // Attempt to expand palindrome centered at I.
      while (t[i + (1 + p[i])] == t[i - (1 + p[i])]) p[i]++;

      // If palindrome centered at I expands past right,
      // adjust center based on expanded palindrome.
      if (i + p[i] > right) {
        center = i;
        right = i + p[i];
      }
    }
  }

  // The longest palindromic substring.
  string longest_palindromic_substring() {
    int length = 0;  // Length of longest palindromic substring.
    int center = 0;  // Center of longest palindromic substring.
    for (int i = 1; i < (int)p.size() - 1; i++) {
      if (p[i] > length) {
        length = p[i];
        center = i;
      }
    }
    return s.substr((center - 1 - length) / 2, length);
  }

  // The longest palindromic substring centered at index I / 2.
  string longest_palindromic_substring(int i) {
    int length = p[i + 2];
    int center = i + 2;
    return s.substr((center - 1 - length) / 2, length);
  }
};

// Given ABCBA, how many stripes of continuous letters can cover it?
// Answer: 3
// AAAAA
//  BBB
//   C
// Runs in O(N^2)
int minimum_stripes_to_cover(string s) {
  const int n = s.size();
  if (n < 2) {
    return n;
  }
  vector<vector<int>> stripes(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    stripes[i][i] = 1;
  }
  for (int i = n - 2; i >= 0; i--) {
    for (int j = i + 1; j < n; j++) {
      stripes[i][j] = stripes[i + 1][j] + 1;
      for (int k = i; k < j; k++) {
        if (s[i] == s[k + 1]) {
          // We can paint from I into K + 1 with the same stripe.
          const auto merging = stripes[i][k] + stripes[k + 1][j] - 1;
          stripes[i][j] = min(stripes[i][j], merging);
        }
      }
    }
  }
  return stripes[0][n - 1];
}

template <typename Collection>
vector<int> knuth_morris_pratt_initialize(Collection pattern) {
  const int m = pattern.size();
  vector<int> f(m);
  f[0] = -1;
  int k = 0;
  for (int i = 1; i < m; i++) {
    k = f[i - 1];
    while (k >= 0) {
      if (pattern[k] == pattern[i - 1]) {
        break;
      }
      k = f[k];
    }
    f[i] = k + 1;
  }
  return f;
}

template <typename Collection>
bool knuth_morris_pratt(Collection pattern, Collection target) {
  const int m = pattern.size();
  const int n = target.size();
  vector<int> f = knuth_morris_pratt_initialize(pattern);
  int i = 0;
  int k = 0;
  while (i < n) {
    if (k == -1) {
      i++;
      k = 0;
    } else if (target[i] == pattern[k]) {
      i++;
      k++;
      if (k == m) {
        return true;
      }
    } else {
      k = f[k];
    }
  }
  return false;
}

// Timing functions (to profile just part of the code)

static chrono::high_resolution_clock::time_point time_point;

void tic() { time_point = chrono::high_resolution_clock::now(); }

void toc() {
  const auto now = chrono::high_resolution_clock::now();
  chrono::duration<double, std::milli> ms = now - time_point;
  cout << ms.count() << " ms" << '\n';
}

struct TreeNode {
  int value;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : value(x), left(nullptr), right(nullptr) {}
};

// Non-recursive in-order tree traversal.
void traverse(TreeNode *root) {
  stack<TreeNode *> s;
  s.push(root);
  while (root->left != nullptr) {
    s.push(root->left);
    root = root->left;
  }
  auto next = [&s]() {
    if (s.empty()) {
      return;
    }
    if (s.top()->right) {
      auto top = s.top();
      s.pop();
      s.push(top->right);
      while (s.top()->left) {
        s.push(s.top()->left);
      }
    } else {
      s.pop();
    }
  };
  // The top of the stack is the current node.
  while (!s.empty()) {
    next();
  }
}

// Use MAX / 2 for infinity to prevent overflow.
template <typename T>
void floyd_warshall(vector<vector<T>> &d) {
  const auto n = d.size();
  // Just in case the input is bad, set vertices to 0.
  for (size_t i = 0; i < n; i++) {
    d[i][i] = 0;
  }
  for (size_t k = 0; k < n; k++) {
    for (size_t i = 0; i < n; i++) {
      for (size_t j = 0; j < n; j++) {
        const auto alternative = d[i][k] + d[k][j];
        d[i][j] = min(d[i][j], alternative);
      }
    }
  }
}

struct Point {
  double x = 0.0;
  double y = 0.0;
  double dist(const Point &o) { return hypot(x - o.x, y - o.y); }
};

double dist_to_line(const Point &p, const Point &a, const Point &b, Point &r) {
  auto d = (b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y);
  auto scale = ((p.x - a.x) * (b.x - a.x) + (p.y - a.y) * (b.y - a.y)) / d;
  r.x = a.x + scale * (b.x - a.x);
  r.y = a.y + scale * (b.y - a.y);
  return r.dist(p);
}

struct Edge {
  // Outgoing vertex.
  int v;
  int flow;
  // Capacity.
  int c;
  // The index of the reverse edge in the adjacency list.
  int rev;
  Edge(int v, int flow, int C, int rev) : v(v), flow(flow), c(C), rev(rev) {}
};

class Graph {
  int size;
  vector<int> level;
  vector<vector<Edge>> adj;

 public:
  Graph(int size) : size(size) {
    adj.resize(size);
    level.resize(size);
  }

  void add_edge(int u, int v, int c, bool bidirectional) {
    const auto u_size = adj[u].size();
    const auto v_size = adj[v].size();
    adj[u].emplace_back(v, 0, c, v_size);
    adj[v].emplace_back(u, 0, bidirectional ? c : 0, u_size);
  }

  bool bfs(int s, int t);
  int send_flow(int s, int t, int flow, vector<int> &start);
  // Using Dinic's Algorithm.
  int max_flow(int s, int t);
};

// Finds if more flow can be sent from s to t. Also assigns levels to nodes.
bool Graph::bfs(int s, int t) {
  for (int i = 0; i < size; i++) {
    level[i] = -1;
  }
  level[s] = 0;
  // Create a queue, enqueue source vertex and mark source vertex as visited.
  list<int> q;
  q.push_back(s);
  while (!q.empty()) {
    const auto u = q.front();
    q.pop_front();
    for (auto i = adj[u].begin(); i != adj[u].end(); i++) {
      Edge &e = *i;
      if (level[e.v] < 0 && e.flow < e.c) {
        level[e.v] = level[u] + 1;
        q.push_back(e.v);
      }
    }
  }
  // If we cannot reach the sink we return false.
  return level[t] < 0 ? false : true;
}

// A DFS based function to send flow after BFS has figured out that there is a
// possible flow.
//
// This function called multiple times for a single call of BFS.
int Graph::send_flow(const int u, int t, int flow, vector<int> &start) {
  if (u == t) return flow;
  // Traverse all adjacent edges.
  const int n = adj[u].size();
  for (; start[u] < n; start[u]++) {
    // Pick next edge from the adjacency list.
    Edge &e = adj[u][start[u]];
    if (level[e.v] == level[u] + 1 && e.flow < e.c) {
      // Find the minimum flow from u to t.
      int curr_flow = min(flow, e.c - e.flow);
      int temp_flow = send_flow(e.v, t, curr_flow, start);
      if (temp_flow > 0) {
        e.flow += temp_flow;
        // Subtract flow from the reverse edge of current edge.
        adj[e.v][e.rev].flow -= temp_flow;
        return temp_flow;
      }
    }
  }
  return 0;
}

int Graph::max_flow(int s, int t) {
  if (s == t) {
    return -1;
  }
  int total = 0;
  // Augment the flow while there is path from source to sink.
  while (bfs(s, t)) {
    // Store how many edges are visited from V { 0 to V }.
    vector<int> start(size);
    while (int flow = send_flow(s, t, numeric_limits<int>::max(), start)) {
      total += flow;
    }
  }
  return total;
}

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

// Problem-specific code

int main() {
  ios_base::sync_with_stdio(false);
  assert(minimum_window_substring("", "A") == string(""));
  assert(minimum_window_substring("A", "") == string(""));
  assert(minimum_window_substring("A", "A") == string("A"));
  assert(minimum_window_substring("A", "AB") == string(""));
  assert(minimum_window_substring("ADOBECODEBANC", "ABC") == "BANC");
  assert(minimum_window_substring("ADOBECODECABANC", "ABC") == "CAB");
  return 0;
}

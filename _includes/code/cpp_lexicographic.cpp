std::string text = "abbc";
do {
  cout << text << '\n';
} while (std::next_permutation(text.begin(), text.end()));
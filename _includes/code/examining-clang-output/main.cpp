#include <chrono>
#include <iostream>
#include <sstream>

using namespace std;

int sumTwiceUpTo(int n) {
  asm("test edi, edi\n"
      "jle .ASMLB1_1\n"
      "lea eax, [rdi - 1]\n"
      "lea ecx, [rdi - 2]\n"
      "imul ecx, eax\n"
      "and ecx, -2\n"
      "lea eax, [rcx + 4*rdi - 2]\n"
      "ret\n"
      ".ASMLB1_1:\n"
      "xor eax, eax\n");
}

int mySumTwiceUpTo(int n) {
  asm("test edi, edi\n"
      "jle .ASMLB2_1\n"
      "lea eax, [rdi - 1]\n"
      "lea ecx, [rdi - 2]\n"
      "imul ecx, eax\n"
      "lea eax, [rcx + 4*rdi - 2]\n"
      "ret\n"
      ".ASMLB2_1:\n"
      "xor eax, eax\n");
}

int main() {
  auto start = std::chrono::steady_clock::now();
  for (int j = 0; j < 1000; j++) {
    for (int i = 0; i < 65536; i++) {
      sumTwiceUpTo(i);
    }
  }
  auto now = std::chrono::steady_clock::now();
  std::chrono::duration<double, std::nano> ns = now - start;
  cout << ns.count() << " ns" << '\n';

  start = std::chrono::steady_clock::now();
  for (int j = 0; j < 1000; j++) {
    for (int i = 0; i < 65536; i++) {
      mySumTwiceUpTo(i);
    }
  }
  now = std::chrono::steady_clock::now();
  ns = now - start;
  cout << ns.count() << " ns" << '\n';
}

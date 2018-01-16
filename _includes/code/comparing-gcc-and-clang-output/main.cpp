#include <chrono>
#include <iostream>
#include <sstream>

using namespace std;

asm(".LC3:\n"
    "  .long 1065353216");
asm(".LC4:\n"
    "  .long 3212836864");

float evaluateClang(float a, float b) {
  asm("subss xmm0, xmm1\n"
      "movss xmm1, dword ptr [rip + .LC3]\n"
      "addss xmm1, xmm0\n"
      "mulss xmm1, xmm0\n"
      "addss xmm0, dword ptr [rip + .LC4]\n"
      "mulss xmm0, xmm1");
}

float evaluateGCC(float a, float b) {
  asm("subss xmm0, xmm1\n"
      "movss xmm2, dword ptr [rip + .LC3]\n"
      "movaps xmm1, xmm0\n"
      "addss xmm1, xmm2\n"
      "mulss xmm1, xmm0\n"
      "subss xmm0, xmm2\n"
      "mulss xmm0, xmm1");
}

int main() {
  auto start = std::chrono::steady_clock::now();
  for (int j = 0; j < 1000; j++) {
    for (int i = 0; i < 65536; i++) {
      evaluateClang(4.0f, 9.0f);
    }
  }
  auto now = std::chrono::steady_clock::now();
  std::chrono::duration<double, std::nano> ns = now - start;
  cout << ns.count() << " ns" << '\n';

  start = std::chrono::steady_clock::now();
  for (int j = 0; j < 1000; j++) {
    for (int i = 0; i < 65536; i++) {
      evaluateGCC(4.0f, 9.0f);
    }
  }
  now = std::chrono::steady_clock::now();
  ns = now - start;
  cout << ns.count() << " ns" << '\n';
}

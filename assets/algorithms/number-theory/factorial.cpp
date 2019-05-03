#include <cstdint>
#include <iostream>

#include "boost/multiprecision/gmp.hpp"

#include "pari/pari.h"

using U64 = uint64_t;

// The two required codewords + 512 bits in precision.
// This should be plenty.
constexpr long PariPrecision = 2 + 512 / BITS_IN_LONG;

U64 actualDigitsInFactorial(U64 n) {
  boost::multiprecision::mpz_int product = 1;
  for (U64 i = 1; i <= n; i++) {
    product *= i;
  }
  return product.str().size();
}

U64 approximateDigitsInFactorialUsingLogGamma(U64 n) {
  const auto oldStackPointer = avma;
  // floor(logGamma(n + 1) / log(10)) + 1
  const auto logGamma = glngamma(stoi(n + 1), PariPrecision);
  const auto logTen = mplog(dbltor(10.0));
  const auto value = addii(floorr(divrr(logGamma, logTen)), stoi(1));
  const auto result = gtolong(value);
  avma = oldStackPointer;
  return result;
}

U64 approximateDigitsInFactorial(U64 n) {
  if (n < 2) {
    return 1;
  }
  double sum = 0.0;
  for (U64 i = 1; i <= n; i++) {
    sum += std::log10(i);
  }
  return std::ceil(sum);
}

void findDivergence() {
  double sum = 0.0;
  for (U64 i = 2;; i++) {
    const auto usingLogGamma = approximateDigitsInFactorialUsingLogGamma(i);
    sum += std::log10(i);
    if (usingLogGamma != std::ceil(sum)) {
      std::cerr << "Diverged in n = " << i << "." << '\n';
      return;
    }
    if (i % 10000 == 0) {
      std::cerr << "No divergence up to " << i << "." << '\n';
    }
  }
}

int main(void) {
  // Initialize the PARI library with 1 MiB of memory.
  pari_init(1UL << 20UL, 0);
  findDivergence();
  pari_close();
  return 0;
}

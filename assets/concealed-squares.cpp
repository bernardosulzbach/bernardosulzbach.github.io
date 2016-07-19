#include <iostream>

const unsigned long RANGE_START = 101010101UL;
const unsigned long RANGE_END = 138902662UL;
const unsigned long RANGE_LENGTH = RANGE_END - RANGE_START + 1;

bool is_the_answer(unsigned long value) {
    long expected = 9;
    while (expected > 0) {
        if (value % 10 == expected) {
            value /= 100;
            expected--;
        } else {
            return false;
        }
    }
    return true;
}

int main() {
    for (unsigned long i = RANGE_START; i <= RANGE_END; i++) {
        if (i % 10 == 3 || i % 10 == 7) {
            if (is_the_answer(i * i)) {
                // Note that we must multiply the found answer by 10.
                unsigned long normalized_answer = i * 10;
                std::cout << normalized_answer << '\n';
                break;
            }
        }
    }
    return 0;
}

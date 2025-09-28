#include <print>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdlib>

std::vector<int> decimalRepresentation(int n) {
    std::vector<int> res{};

    for (long long i = 1; n > 0; i *= 10) {
        auto [q, r] = std::div(n, 10);

        n = q;
        if (r != 0) res.push_back(r * i);
    }

    std::ranges::reverse(res);
    return res;
}

int main() {
    int n = 6;

    std::print("Output: {}", decimalRepresentation(n));
}
#include <vector>
#include <print>
#include <ranges>
#include <algorithm>

std::vector<std::vector<int>> reverseSubmatrix(const std::vector<std::vector<int>>& grid, int x, int y, int k) {
    auto grid_ret = grid;

    for (const unsigned i : std::views::iota(x, x + k/2)) {
        const unsigned j = 2*x + k - 1 - i;

        auto irange = grid_ret[i] | std::views::drop(y) | std::views::take(k);
        auto jrange = grid_ret[j] | std::views::drop(y) | std::views::take(k);

        std::ranges::swap_ranges(irange, jrange);
    }

    return grid_ret;
}

int main() {
    std::vector<std::vector<int>> v{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    std::vector<std::vector<int>> w{{3, 4, 2, 3}, {2, 3, 4, 2}};

    std::print("{}\n", reverseSubmatrix(v, 1, 0, 3));
    std::print("{}",   reverseSubmatrix(w, 0, 2, 2));
}
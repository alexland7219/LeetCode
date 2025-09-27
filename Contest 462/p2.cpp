#include <vector>
#include <print>
#include <ranges>
#include <algorithm>

int sortPermutation(const std::vector<int>& nums) {
    auto x = std::views::enumerate(nums)
           | std::views::filter([](auto k){ auto [i, v] = k; return i != v; })
           | std::views::transform([](auto k){ return std::get<1>(k); });
           
    return std::ranges::fold_left_first(x, std::bit_and{}).value_or(0);
}

int main() {
    std::vector v{0, 3, 2, 1};

    std::print("{}", sortPermutation(v));
}
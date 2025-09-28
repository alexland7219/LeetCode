#include <array>
#include <algorithm>
#include <span>
#include <print>

long long maxTotalValue(std::span<int> nums, int k) {
    auto [mm, xx] = std::ranges::minmax(nums);
    
    return k * static_cast<long long>(xx - mm);
}

int main() {
    std::array nums{4, 2, 5, 1};

    std::print("Result: {}", maxTotalValue(nums, 3));
}
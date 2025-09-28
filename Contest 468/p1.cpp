#include <array>
#include <print>
#include <span>
#include <numeric>
#include <functional>
#include <execution>

int evenNumberBitwiseORs(std::span<int> nums) {
    return std::transform_reduce(
        std::execution::par,
        nums.begin(),
        nums.end(),
        0,
        std::bit_or{},
     );
}

int main() {
    std::array nums{1, 8, 16};

    std::print("Output: {}", evenNumberBitwiseORs(nums));
}
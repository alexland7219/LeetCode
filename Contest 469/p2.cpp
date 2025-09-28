#include <print>
#include <array>
#include <span>
#include <cstdlib>
#include <algorithm>

using LL = long long;

LL splitArray(std::span<int> nums) {

    size_t l  = 0;
    size_t ll = 1;
    size_t r  = nums.size() - 1;
    size_t rr = nums.size() - 2;
    
    LL left_sum  = nums[l];
    LL right_sum = nums[r];

    for (; ll < nums.size() - 1 and nums[ll] > nums[l]; l = ll++)
        left_sum += nums[ll];

    for (; rr != 0 and nums[rr] > nums[r]; r = rr--)
        right_sum += nums[rr];
    
    // Case where peak is 1 element
    if (l == r)
        return std::min(
            std::abs(left_sum - right_sum + nums[l]),
            std::abs(left_sum - right_sum - nums[l])
        );

    // Case where peak is 2 elements or always inc/dec
    if (ll == r)
        return std::abs(left_sum - right_sum);

    return -1;
}

int main() {
    std::array nums{3, 1, 2};

    std::print("Output: {}", splitArray(nums));
}
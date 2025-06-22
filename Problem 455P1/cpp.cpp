#include <vector>
#include <numeric>
#include <algorithm>
#include <functional>

auto isPrime(int n) -> bool {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    for (int i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}


auto checkPrimeFrequency(vector<int>& nums) -> bool {
    return std::transform_reduce(
        nums.begin(), 
        nums.end(),
        false,
        std::logical_or{},
        [&](auto x) {
            return isPrime(std::ranges::count(nums, x));
        }
    );
}
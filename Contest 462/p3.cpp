#include <vector>
#include <ranges>
#include <print>
#include <numeric>
#include <algorithm>

long long maxTotal(std::vector<int>& value, std::vector<int>& limit) {
    auto zipped = std::views::zip(limit, value);
    std::ranges::sort(zipped, std::ranges::greater{});

    auto diff_limits = [](auto x, auto y){ return std::get<0>(x) == std::get<0>(y); };
    auto chunks = zipped | std::views::chunk_by(diff_limits);
    
    return std::transform_reduce(
        chunks.begin(),
        chunks.end(),
        0LL,
        std::plus{},
        [](auto rng){
            int limit = std::get<0>(*rng.begin());
            auto list = rng | std::views::values | std::views::take(limit);
            
            return std::ranges::fold_left(list, 0, std::plus{});
        }
    );
}

int main() {
    std::vector val{4, 1, 5, 2};
    std::vector lim{3, 3, 2, 3};
    
    std::print("{}", maxTotal(val, lim));
}
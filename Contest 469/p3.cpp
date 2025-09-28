#include <vector>
#include <print>
#include <algorithm>
#include <numeric>

#define MOD 1000000007

auto add_with_mod = [](int x, int y) {
    return (x+y) % MOD;
};

int zigZagArrays(int n, int l, int r) {
    int s = r - l + 1;

    std::vector<std::vector<int>> inc(n+1, std::vector<int>(s, 0));
    std::ranges::fill(inc[0], 1);

    auto dec = inc;

    std::vector<int> prefInc(s, 0), prefDec(s, 0);

    for (int i = 1; i <= n; ++i) {
        std::exclusive_scan(inc[i-1].begin(),  inc[i-1].end(),  prefInc.begin(), 0, add_with_mod);
        std::exclusive_scan(dec[i-1].rbegin(), dec[i-1].rend(), prefDec.rbegin(), 0, add_with_mod);

        inc[i] = prefDec;
        dec[i] = prefInc;
    }

    return add_with_mod(inc[n][0], dec[n][s-1]);
}

int main() {
    std::println("Output = {}", zigZagArrays(3, 4, 5));
}

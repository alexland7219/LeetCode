#include <ranges>
#include <vector>
#include <print>
#include <iostream>
using std::vector;

auto findCoins(vector<int>& numWays) -> vector<int> {
    size_t N = numWays.size();
    vector<int> aux(N, 0);
    vector<int> res(0);

    for (auto [i, totalWays] : numWays | std::views::enumerate) {
        if (totalWays - aux[i] == 0) continue;
        else if (totalWays - aux[i] != 1) return vector<int>{}; 

        for (int x : aux) std::cout << x << ' ';
        std::cout << '\n';

        res.push_back(i + 1);
        aux[i]++;

        for (auto [j, currentWays] : aux | std::views::enumerate) {
            const int k = j + i + 2;
            if (k > N) break;
            std::cout << "k = " << k - 1 << "\npair = " << currentWays << ' ' << j << std::endl;

            aux[k-1] += currentWays;
           for (int x : aux) std::cout << x << ' ';
           std::cout << '\n'; 
        }
    }

    return res;
}

int main() {
    vector v{1, 2, 2, 3, 4};
    for (int x : findCoins(v)) std::cout << x << ' ';
    std::cout << '\n';
}
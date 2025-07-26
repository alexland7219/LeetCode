#include <print>
#include <string>
#include <algorithm>

auto processStr(std::string_view s) -> std::string {
    std::string res;

    for (char c : s) {
        switch (c) {
            case '%':
            std::ranges::reverse(res);
            break;

            case '#':
            res += res;
            break;

            case '*':
            if (not res.empty())
                res.pop_back();
            break;

            default:
            res.push_back(c);
        }
    }

    return res;
}

int main() {
    std::string inp("a#b%*");
    std::println("{}", processStr(inp));
}
#include <iostream>
#include <vector>
#include <string>

std::vector<short> naiveStringMatcher (std::string const& text, std::string const& pattern)
{
    int n = text.length(), m = pattern.length();

    char buf[10000] = " ";

    std::vector<short> answer;

    for (int i = 0; i <= n - m; ++i)
    {
        text.copy(buf, m, i);
        buf[m] = '\0';
        if (buf == pattern)
            answer.push_back(i + 1);
    }

    return answer;
}

int main() {
    freopen("search1.in", "r", stdin);
    freopen("search1.out", "w", stdout);

    std::string text, pattern;

    std::cin >> pattern >> text;

    std::vector<short> matches = naiveStringMatcher(text, pattern);

    std::cout << matches.size() << "\n";

    for (auto const& sym: matches)
        std::cout << sym << " ";

    return 0;
}

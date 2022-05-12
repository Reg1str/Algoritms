#include <iostream>
#include <vector>
#include <algorithm>

void prefix_function(std::string const& string)
{
    int n = string.length();
    std::vector<int> pi(n);

    for (int i = 1; i < n; ++i)
    {
        int j = pi[i - 1];

        while (j > 0 && string[i] != string[j])
            j = pi[j - 1];

        if (string[i] == string[j])
            ++j;

        pi[i] = j;
    }

    for (auto const& res: pi)
    {
        std::cout << res << " ";
    }
}

int main()
{
    freopen("prefix.in", "r", stdin);
    freopen("prefix.out", "w", stdout);

    std::string text;

    std::cin >> text;

    prefix_function(text);

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> z_function(const std::string& string)
{
    std::vector<int> z(string.length(), 0);

    for (int i = 1, l = 0, r = 0; i < string.length(); i++)
    {
        if (i <= r)
            z[i] = std::min(z[i - l], r - i + 1);

        while (i + z[i] < string.length())
        {
            if (string[i + z[i]] == string[z[i]])
                z[i]++;
            else
                break;
        }

        if (z[i] > 0 && i + z[i] - 1 > r)
        {
            l = i;
            r = i + z[i] - 1;
        }
    }

    return z;
}

int main()
{
    std::string text, pattern;

    std::cin >> pattern >> text;

    std::vector<int> z = z_function(pattern + '#' + text);

    std::vector<unsigned> ans;

    int p_len = pattern.length();

    for (int i = 0; i < text.length(); i++)
        if (z[p_len + 1 + i] == p_len)
            ans.push_back(i + 1);

    std::cout << ans.size() << "\n";

    for (unsigned const& pos: ans)
    {
        std::cout << pos << " ";
    }

    return 0;
}
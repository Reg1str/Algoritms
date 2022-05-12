#include <iostream>
#include <vector>
 
std::vector<int> prefix_function(std::string const& string)
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
 
    return pi;
}
 
void kmp(int alphabet, std::string const& string)
{
    std::vector<int> pi = prefix_function(string);
    int n = string.length();
    std::vector<std::vector<int> > ans(n + 1, std::vector<int>(alphabet));
 
    for (int i = 0; i < n + 1; ++i)
    {
        for (int j = 0; j < alphabet; ++j)
        {
            if (i > 0 && j + 'a' != string[i])
                ans[i][j] = ans[pi[i - 1]][j];
            else
                ans[i][j] = i + (j + 'a' == string[i]);
        }
    }
 
    for (int i = 0; i < ans.size(); ++i)
    {
        for (int j = 0; j < ans[i].size(); ++j)
            std::cout << ans[i][j] << ' ';
 
        std::cout << '\n';
    }
}
 
int main()
{
    int n;
    std::string text;
 
    std::cin >> n >> text;
 
    kmp(n, text);
 
 
    return 0;
}
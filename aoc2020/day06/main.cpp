#include <iostream>
#include <numeric>
#include <string>
#include <sstream>
#include <utility>
#include <vector>

std::vector<std::string> parse_input()
{
    std::stringstream ss;
    for (std::string line; getline(std::cin, line); )
        if (line.empty())
            ss << '\n';
        // For this problem is better not to do this
        // else
        //     ss << ' ' << line;
        else
            ss << line;

    std::vector<std::string> lines;
    for (std::string line; getline(ss, line); )
        lines.push_back(std::move(line));

    return lines;
}

int count_unique_chars(std::string str)
{
    std::sort(str.begin(), str.end());
    auto last = std::unique(str.begin(), str.end());
    str.erase(last, str.end());
    return str.length();
}

int main()
{
    const std::vector<std::string> input = parse_input();

    const int result = std::accumulate(
        input.cbegin(),
        input.cend(),
        0,
        [] (auto accum, auto str)
        {
            return accum + count_unique_chars(str);
        }
    );

    std::cout << result << std::endl;
}

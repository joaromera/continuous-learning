#include <algorithm>
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
        else
            ss << ' ' << line;

    std::vector<std::string> lines;
    for (std::string line; getline(ss, line); )
        lines.push_back(std::move(line));

    return lines;
}

int count_unique_chars(std::string str)
{
    std::string::iterator end_pos = std::remove(str.begin(), str.end(), ' ');
    std::sort(str.begin(), end_pos);
    auto last = std::unique(str.begin(), end_pos);
    return std::distance(str.begin(), last);
}

void part_one(const std::vector<std::string> input)
{
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

int main()
{
    const std::vector<std::string> input = parse_input();

    part_one(input);

}

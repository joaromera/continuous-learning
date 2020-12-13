#include <algorithm>
#include <iostream>
#include <iterator>
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

int count_intersection_chars(std::string sv)
{
    // Count and remove spaces
    std::string str(sv);
    auto spaces = std::count(str.begin(), str.end(), ' ');
    std::string::iterator end_pos = std::remove(str.begin(), str.end(), ' ');

    // Eliminate duplicates
    std::sort(str.begin(), end_pos);
    auto last_unique = std::unique(str.begin(), end_pos);
    str.erase(last_unique, str.end());

    // Count appearences of unique chars in original string against spaces
    return std::accumulate(str.begin(), str.end(), 0, [&](auto accum, auto chr) {
        return accum + (std::count(sv.cbegin(), sv.cend(), chr) / (spaces));
    });
}

using countingFunc = int(*)(std::string);

void solve_problem(const std::vector<std::string> input, countingFunc fun)
{
    const int result = std::accumulate(
        input.cbegin(),
        input.cend(),
        0,
        [&fun] (auto accum, auto str)
        {
            return accum + fun(str);
        }
    );

    std::cout << result << std::endl;
}

int main()
{
    const std::vector<std::string> input = parse_input();
    solve_problem(input, count_unique_chars);
    solve_problem(input, count_intersection_chars);
}

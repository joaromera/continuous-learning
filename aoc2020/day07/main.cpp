#include <iostream>
#include <string>
#include <sstream>
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

int main()
{
    const std::vector<std::string> input = parse_input();
}

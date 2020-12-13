#include <fstream>
#include <iostream>
#include <numeric>
#include <string>
#include <string_view>
#include <vector>

std::vector<std::string> loadInput()
{
    std::vector<std::string> strs;
    std::ifstream file ("input.txt");
    for (std::string str; std::getline(file, str); )
    {
        strs.push_back(str);
    }
    return strs;
}

constexpr int row(const std::string_view str)
{
    int low = 0;
    int top = 128;
    int mid = (low + top) / 2;
    for (const char c : str)
    {
        if (c == 'F')
            top = mid;
        if (c == 'B')
            low = mid;
        mid = (low + top) / 2;
    }
    return mid;
}

constexpr int col(const std::string_view str)
{
    int low = 0;
    int top = 8;
    int mid = (low + top) / 2;
    for (const char c : str)
    {
        if (c == 'L')
            top = mid;
        if (c == 'R')
            low = mid;
        mid = (low + top) / 2;
    }
    return mid;
}

constexpr int seat_id(const std::string_view str)
{
    return (row(str) * 8) + col(str);
}

int main()
{
    std::vector<std::string> input = loadInput(); input.push_back("");

    // Part 1
    std::vector<int> seatIds;
    std::generate_n(std::back_inserter(seatIds), input.size(), [&input, i = 0] () mutable {
        return seat_id(input[i++]);
    });

    std::cout << *std::max_element(seatIds.begin(), seatIds.end()) << std::endl;

    // Part 2
    std::sort(seatIds.begin(), seatIds.end());

    for (int i = 0; i < seatIds.size(); ++i)
    {
        auto fptr = std::find(seatIds.begin(), seatIds.end(), i);
        if (fptr == std::end(seatIds)) std::cout << i << std::endl;
    }
}

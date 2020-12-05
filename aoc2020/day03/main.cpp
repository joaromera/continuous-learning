#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
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

int main()
{
    const std::vector<std::string> input = loadInput();

    const int pattern_length = input.front().length();

    const int column_increment = 3;
    const int row_increment = 1;

    unsigned count = 0;
    unsigned column = 0;
    unsigned row = 0;

    while (row < input.size())
    {
        if (input[row][column % pattern_length] == '#')
        {
            ++count;
        }
        column += column_increment;
        row += row_increment;
    }
    std::cout << count << std::endl;
}
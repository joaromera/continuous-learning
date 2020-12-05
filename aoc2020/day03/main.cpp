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

    unsigned count = 0;

    for (int i = 0, j = 0; i < input.size(); i += 1, j += 3)
    {
        if (input[i][j % pattern_length] == '#')
        {
            ++count;
        }
    }
    std::cout << count << std::endl;
}

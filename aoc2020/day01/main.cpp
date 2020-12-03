#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::vector<int> loadInput()
{
    std::vector<int> ints;
    std::ifstream file ("input.txt");
    for (std::string str; std::getline(file, str); )
    {
        ints.push_back(std::stoi(str));
    }
    return ints;
}

int main()
{
    auto input = loadInput();

    for (int i = 0; i < input.size(); ++i)
        for (int j = i + 1; j < input.size(); ++j)
            if (input[i] + input[j] == 2020)
                std::cout << input[i] * input[j] << std::endl;

    for (int i = 0; i < input.size(); ++i)
        for (int j = i + 1; j < input.size(); ++j)
            for (int k = j + 1; k < input.size(); ++k)
                if (input[i] + input[j] + input[k] == 2020)
                    std::cout << input[i] * input[j] * input[k] << std::endl;
}
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
    const auto input = loadInput();

    unsigned first_policy_valid_passwords = 0;
    unsigned sec_policy_valid_passwords = 0;

    for (auto &s : input)
    {
        const int minimum = std::stoi(s.substr(0, s.find('-')));
        const int maximum = std::stoi(s.substr(s.find('-') + 1, s.find(' ')));
        const char letter = s.substr(s.find(' ') + 1, s.find(':')).front();
        const std::string password = s.substr(s.find(": ") + 2);
        const int count = std::count(password.begin(), password.end(), letter);

        if (count >= minimum && count <= maximum)
            ++first_policy_valid_passwords;

        if (password[minimum - 1] == letter ^ password[maximum - 1] == letter)
            ++sec_policy_valid_passwords;
    }

    std::cout << first_policy_valid_passwords << std::endl;
    std::cout << sec_policy_valid_passwords << std::endl;
}
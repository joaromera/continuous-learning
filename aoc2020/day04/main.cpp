#include <algorithm>
#include <array>
#include <fstream>
#include <iostream>
#include <map>
#include <regex>
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

constexpr std::string_view get_value(const std::string_view str, const std::string_view key)
{
    const auto pos = str.find(key);

    if (pos == std::string::npos) return "";

    const auto begin_value_pos = pos + key.length() + 1;
    const auto end_value_pos = str.substr(begin_value_pos).find(" ");

    return str.substr(begin_value_pos, end_value_pos);
}

auto valid_byr = [] (const std::string& str) {
    return str.length() == 4 && std::stoi(str) >= 1920 && std::stoi(str) <= 2002;
};

auto valid_iyr = [] (const std::string& str) {
    return str.length() == 4 && std::stoi(str) >= 2010 && std::stoi(str) <= 2020;
};

auto valid_eyr = [] (const std::string& str) {
    return str.length() == 4 && std::stoi(str) >= 2020 && std::stoi(str) <= 2030;
};

auto valid_hgt = [] (const std::string& str) {
    if (std::smatch base_match;
        std::regex_match(str, base_match, std::regex("(\\d+)(in|cm)")))
    {
        if (base_match[2] == "in")
        {
            return std::stoi(base_match[1]) >= 59 && std::stoi(base_match[1]) <= 76;
        }
        else if (base_match[2] == "cm")
        {
            return std::stoi(base_match[1]) >= 150 && std::stoi(base_match[1]) <= 193;
        }
    }
    return false;
};

auto valid_hcl = [] (const std::string& str) {
    return std::regex_match(str, std::regex("#[0-9a-f]{6}"));
};

auto valid_ecl = [] (const std::string& str) {
    return std::regex_match(str, std::regex("amb|blu|brn|gry|grn|hzl|oth"));
};

auto valid_pid = [] (const std::string& str) {
    return std::regex_match(str, std::regex("\\d{9}"));
};

using validatorFunc = bool(*)(const std::string&);

std::map<std::string, validatorFunc> keys_and_validators = {
    {"byr", valid_byr },
    {"iyr", valid_iyr },
    {"eyr", valid_eyr },
    {"hgt", valid_hgt },
    {"hcl", valid_hcl },
    {"ecl", valid_ecl },
    {"pid", valid_pid }
};

bool all_keys_present(std::vector<std::string>::const_iterator begin, std::vector<std::string>::const_iterator end)
{
    return std::all_of(
        keys_and_validators.cbegin(),
        keys_and_validators.cend(),
        [&begin, &end] (const auto &kp)
        {
            return std::any_of(
                begin,
                end,
                [&kp] (const std::string &passport_data)
                {
                    return !get_value(passport_data, kp.first).empty();
                }
            );
        }
    );
}

bool all_values_valid(std::vector<std::string>::const_iterator begin, std::vector<std::string>::const_iterator end)
{
    return std::all_of(
        keys_and_validators.cbegin(),
        keys_and_validators.cend(),
        [&begin, &end] (const auto &kp)
        {
            return std::any_of(
                begin,
                end,
                [&kp] (const std::string &passport_data)
                {
                    return kp.second(std::string(get_value(passport_data, kp.first)));
                }
            );
        }
    );
}

bool is_valid_passport(std::vector<std::string>::const_iterator begin, std::vector<std::string>::const_iterator end)
{
    // 1st problem
    // return all_keys_present(begin, end);

    // 2nd problem
    return all_values_valid(begin, end);
}

int main()
{
    std::vector<std::string> input = loadInput(); input.push_back("");

    std::vector<std::string>::const_iterator passport_beg = input.cbegin();

    int count = 0;

    for (auto it = input.cbegin(); it != input.cend(); ++it)
    {
        if (it->empty())
        {
            if (is_valid_passport(passport_beg, it)) ++count;

            passport_beg = it;
        }
    }

    std::cout << count << std::endl;
}

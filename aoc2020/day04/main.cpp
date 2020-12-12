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

using validatorFunc = bool(*)(const std::string&);

std::map<std::string, validatorFunc> keys_and_validators = {
    {"byr", [] (const std::string& str) {
        return str.length() == 4 && std::stoi(str) >= 1920 && std::stoi(str) <= 2002;
    }},
    {"iyr", [] (const std::string& str) {
        return str.length() == 4 && std::stoi(str) >= 2010 && std::stoi(str) <= 2020;
    }},
    {"eyr", [] (const std::string& str) {
        return str.length() == 4 && std::stoi(str) >= 2020 && std::stoi(str) <= 2030;
    }},
    {"hgt", [] (const std::string& str) {
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
    }},
    {"hcl", [] (const std::string& str) {
        return std::regex_match(str, std::regex("#[0-9a-f]{6}"));
    }},
    {"ecl", [] (const std::string& str) {
        return std::regex_match(str, std::regex("amb|blu|brn|gry|grn|hzl|oth"));
    }},
    {"pid", [] (const std::string& str) {
        return std::regex_match(str, std::regex("\\d{9}"));
    }}
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
                    std::string val (get_value(passport_data, kp.first));
                    return kp.second(val);
                }
            );
        }
    );
}

bool is_valid_passport(std::vector<std::string>::const_iterator begin, std::vector<std::string>::const_iterator end)
{
    return all_keys_present(begin, end) && all_values_valid(begin, end);
}

std::vector<std::string> test_input = {
    "pid:087499704 hgt:74in ecl:grn iyr:2012 eyr:2030 byr:1980",
    "hcl:#623a2f",
    "",
    "eyr:2029 ecl:blu cid:129 byr:1989",
    "iyr:2014 pid:896056539 hcl:#a97842 hgt:165cm",
    "",
    "hcl:#888785",
    "hgt:164cm byr:2001 iyr:2015 cid:88",
    "pid:545766238 ecl:hzl",
    "eyr:2022",
    "",
    "iyr:2010 hgt:158cm hcl:#b6652a ecl:blu byr:1944 eyr:2021 pid:093154719",
    ""
};

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

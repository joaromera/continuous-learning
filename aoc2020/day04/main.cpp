#include <algorithm>
#include <array>
#include <fstream>
#include <iostream>
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

    const auto begin_value_pos = pos + key.length();
    const auto end_value_pos = str.substr(begin_value_pos).find(" ");

    return str.substr(begin_value_pos, end_value_pos);
}

constexpr std::array valid_passport_keys = {
    "byr",
    "iyr",
    "eyr",
    "hgt",
    "hcl",
    "ecl",
    "pid"
};

bool all_keys_present(std::vector<std::string>::const_iterator begin, std::vector<std::string>::const_iterator end)
{
    return std::all_of(
        valid_passport_keys.cbegin(),
        valid_passport_keys.cend(),
        [&begin, &end] (const std::string &key)
        {
            return std::any_of(
                begin,
                end,
                [&key] (const std::string &passport_data)
                {
                    return !get_value(passport_data, key).empty();
                }
            );
        }
    );
}

bool all_values_valid(std::vector<std::string>::const_iterator begin, std::vector<std::string>::const_iterator end)
{
    return true;
}

bool is_valid_passport(std::vector<std::string>::const_iterator begin, std::vector<std::string>::const_iterator end)
{
    return all_keys_present(begin, end) && all_values_valid(begin, end);
}

constexpr std::array test_input = {
    "ecl:gry pid:860033327 eyr:2020 hcl:#fffffd",
    "byr:1937 iyr:2017 cid:147 hgt:183cm",
    "",
    "iyr:2013 ecl:amb cid:350 eyr:2023 pid:028048884",
    "hcl:#cfa07d byr:1929",
    "",
    "hcl:#ae17e1 iyr:2013",
    "eyr:2024",
    "ecl:brn pid:760753108 byr:1931",
    "hgt:179cm",
    "",
    "hcl:#cfa07d eyr:2025 pid:166559648",
    "iyr:2011 ecl:brn hgt:59in",
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

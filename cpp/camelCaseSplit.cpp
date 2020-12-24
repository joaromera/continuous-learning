#include <iostream>
#include <string>

std::string camelCaseSplit(std::string str)
{
    for (auto it = str.begin(); it != str.end(); ++it)
    {
        if (std::isupper(*it))
        {
            it = str.insert(it, ' ');
            ++it;
        }
    }
    return str;
}

std::string parseTestName(const std::string& str)
{
    const std::string namePrefix = "test";

    const std::string::size_type namePrefixPos = str.find(namePrefix);
    const std::string::size_type nameEndPos = str.find('(');

    if (namePrefixPos == std::string::npos ||
        nameEndPos == std::string::npos ||
        namePrefixPos > nameEndPos)
    {
        throw std::invalid_argument(
            "Function names must start with 'test' and include a parameter list in ()"
        );
    }

    const std::string::size_type nameStartPos = namePrefixPos + namePrefix.length();
    const std::string::size_type nameLength = nameEndPos - nameStartPos;
    const std::string name = str.substr(nameStartPos, nameLength);
    return camelCaseSplit(name);
}

int main()
{
    std::cout << parseTestName("public void testCowsCanBeMilked()") << std::endl;
    std::cout << parseTestName("public void testSheepAreNotTheOnlyFruit()") << std::endl;
}

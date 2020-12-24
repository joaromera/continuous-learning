#include <iostream>
#include <string>

std::string functionName(const std::string& sv)
{
    const std::string namePrefix = "test";
    const std::string::size_type nameStartPos = sv.find(namePrefix) + namePrefix.length();
    const std::string::size_type nameLength = sv.find("(") - nameStartPos;
    std::string name = sv.substr(nameStartPos, nameLength);

    for (auto it = name.begin(); it != name.end(); ++it)
    {
        if (std::isupper(*it))
        {
            it = name.insert(it, ' ');
            ++it;
        }
    }
    return name;
}

int main()
{
    std::cout << functionName("public void testCowsCanBeMilked()") << std::endl;
    std::cout << functionName("public void testSheepAreNotTheOnlyFruit()") << std::endl;
}

#include <iostream>

template <typename T, typename ...TS>
constexpr auto sum(T t, TS... ts)
{
    if constexpr (sizeof...(ts) > 0)
    {
        return t + sum(ts...);
    }

    return t;
}

template <typename ...TS>
constexpr auto mean(TS... ts)
{
    return sum(ts...) / static_cast<float>(sizeof...(ts));
}

int main()
{
    std::cout << mean(1,2,3,4,5,6) << std::endl;
}

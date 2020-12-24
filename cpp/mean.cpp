#include <iostream>

template <typename T, typename ...TS>
constexpr long double sum(T t, TS... ts)
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
    return sum(ts...) / sizeof...(ts);
}

int main()
{
    std::cout << mean(1,2,3,4,5,6) << std::endl;
}

/*
An alternative to detect overflow could be:

template <typename T, typename ...TS>
constexpr long double sum(T t, TS... ts)
{
    if constexpr (sizeof...(ts) > 0)
    {
        auto ts_sum = sum(ts...);
        auto result = t + ts_sum;
        if (result > std::numeric_limits<long double>::max())
            throw std::overflow_error(
                "Sum of input arguments to mean(TS... ts) has overflowed"
            );
        return result;
    }

    return t;
}
*/

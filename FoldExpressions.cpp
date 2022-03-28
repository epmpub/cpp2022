#include <iostream>
template<typename ... T>
auto sum(T ... t)
{
    typename std::common_type<T...>::type result{};
    (void)std::initializer_list<int>{(result += t,0)...};
    return result;
}

template<typename ... T>
auto sum2(T ... t)
{
    return (... /t);
}

int main()
{
    std::cout << sum2(8,4,2) << std::endl;
    return 0; 
}
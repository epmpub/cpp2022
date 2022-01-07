#include <type_traits>
#include <iostream>
#include <limits>

using namespace std;

template <typename T>
constexpr bool is_both()
{
    if constexpr(std::is_integral<T>::value && !std::is_same<bool,T>::value){
        if constexpr(std::numeric_limits<T>::max() < 1000){
            return true;
        }
    }
        return false;
}

template <typename T>
auto print_type_info(const T& t)
{
    if constexpr(is_both<T>()){
            return t+1;
    }else if constexpr(std::is_floating_point<T>::value){
        return t+0.1;
    }else{
        return t;
    }
}
int main(int argc, char** argv)
{
    std::cout << print_type_info(1) << "\n";
    std::cout << print_type_info(511) << "\n";
    std::cout << print_type_info(3.14) << "\n";
    std::cout << std::boolalpha << (true) << "\n";
    std::cout << print_type_info("Hello world") << "\n";

    return 0;
}
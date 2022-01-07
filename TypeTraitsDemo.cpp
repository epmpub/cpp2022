#include <iostream>
#include <type_traits>
template<class T>
void func(T&& param) {
    if (std::is_same<typename std::decay<T>::type, int>::value)
        std::cout << "param is an int\n";
    else
        std::cout << "param is not an int\n";
}

int main()
{
    std::cout << __cplusplus << "\n";
    
    int three = 3;
    func(three);  //prints "param is not an int"!!!!
}

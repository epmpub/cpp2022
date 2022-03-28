#include <iostream>

template<typename T>
void print_impl(const T& t)
{
    std::cout << t << "\n";
}

template<typename ...T>
void print(const T& ... t)
{
    // (void)std::initializer_list<int>{(print_impl(t),0)...};
    (void)std::initializer_list<int>{(std::cout<<t<<"\n",0)...};
}


int fa()
{
    std::cout << "fa\n";
    return 1;
}
int fb()
{
    std::cout << "fb\n";
    return 2;
}

int main(int argc, char *argv[])
{
    print("Hello","World",1,3,5,7,9,3.14f,fa(),fb());
    // print(fa(),fb());
    return 0;
}
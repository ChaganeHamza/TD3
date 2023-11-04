//creation de template
template <typename T>
auto square(T x) {
    return x * x;
}
//le programme : 
#include <iostream>
#include <vector>

template <typename T>
auto square(T x) {
    return x * x;
}

int main() {
    std::cout << "Le carré de 3 est " << square(3) << std::endl;
    std::cout << "Le carré de 2.5 est " << square(2.5) << std::endl;

    struct Point {
        int x, y;
    };
    Point p = {3, 4};
    Point squared_p = {square(p.x), square(p.y)};
    std::cout << "Le carré du point (" << p.x << ", " << p.y << ") est (" << squared_p.x << ", " << squared_p.y << ")" << std::endl;

    return 0;
}
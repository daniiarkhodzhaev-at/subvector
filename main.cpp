#include <iostream>

#include <subvector.hpp>

int main(void) {
    int i;
    Subvector a(5, 0);
    for (i = 0; i < 5; ++i) {
        a.push_back(i);
    }

    for (i = 0; i < a.size(); ++i) {
        std::cout << a.get_element(i) << ' ';
    }
    std::cout << '\n';

    return 0;
}

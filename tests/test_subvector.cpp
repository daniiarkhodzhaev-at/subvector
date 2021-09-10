#include <iostream>

#include <subvector.hpp>

const unsigned LENGTH = 5;

const int VALUE = 7;

int main(void) {
    /* This should check all subvector functions */

    unsigned i;
    int data;

    /* Subvector costructors tests */
    Subvector a;
    Subvector b(LENGTH);
    Subvector c(LENGTH, VALUE);

    if (a.size() != 0) {
        std::cerr << "0-argument constructor error: wrong size " << a.size() << "!\n";
        return 1;
    }
    if (b.size() != LENGTH) {
        std::cerr << "1-argument constructor error: wrong size " << b.size() << "!\n";
        return 1;
    }
    for (i = 0; i < b.size(); ++i) {
        if (b.get_element(i) != 0) {
            std::cerr << "1-argument constructor error: data is not 0 at position " << i << "!\n";
            return 1;
        }
    }
    if (c.size() != LENGTH) {
        std::cerr << "2-argument constructor failed: wrong size!\n";
        return 1;
    }
    for (i = 0; i < c.size(); ++i) {
        if (c.get_element(i) != VALUE) {
            std::cerr << "2-argument constructor error: data is not " << VALUE << " at position " << i << "!\n";
            return 1;
        }
    }

    /* Subvector push_back tests */
    for (i = 0; i < LENGTH; ++i) {
        a.push_back(i);
    }
    if (a.size() != LENGTH) {
        std::cerr << "push_back error: wrong size " << a.size() << "!\n";
        return 1;
    }
    for (i = 0; i < a.size(); ++i) {
        if (a.get_element(i) != i) {
            std::cerr << "push_get error: wrong data " << a.get_element(i) << " at position " << i << "!\n";
            return 1;
        }
    }

    /* Subvector pop_back tests */
    i = 0;
    do {
        data = a.pop_back();
        if (data != LENGTH - i - 1) {
            std::cerr << "push_get error: wrong data " << data << " at position " << LENGTH - i - 1 << "!\n";
            return 1;
        }
        ++i;
    } while (a.size() != 0);
    if (a.size() != 0) {
        std::cerr << "pop_back error: wrong size " << a.size() << "!\n";
        return 1;
    }

    /* Subvector resize tests */
    a.resize(LENGTH);
    b.resize(0);
    c.resize(2 * LENGTH);
    if (b.size() != 0) {
        std::cerr << "resize error: wrong size " << b.size() << "!\n";
        return 1;
    }
    if (c.size() != 2 * LENGTH) {
        std::cerr << "resize error: wrong size " << c.size() << "!\n";
        return 1;
    }

    for (i = 0; i < LENGTH; ++i) {
        c.set_element(LENGTH + i, LENGTH + i);
        a.set_element(i, i);
        if (c.get_element(i) != VALUE) {
            std::cerr << "resize/set_element error: wrong data " << c.get_element(i) << " at position " << i << ", must be " << VALUE <<"!\n";
            return 1;
        }
    }

    for (i = LENGTH; i < 2 * LENGTH; ++i) {
        if (c.get_element(i) != i) {
            std::cerr << "resize/set_element error: wrong data " << c.get_element(i) << " at position " << i << "!\n";
            return 1;
        }
    }

    /* Subvector clear tests */
    a.clear();
    if (a.size() != 0) {
        std::cerr << "clear error: wrong size " << c.size() << "!\n";
        return 1;
    }

    std::cerr << "All tests passed successfully!\n";

    return 0;
}

#include "subvector.hpp"
#include <climits>

Subvector::Subvector(void) : Subvector::Subvector(0, 0) {}

Subvector::Subvector(unsigned _size) : Subvector::Subvector(_size, 0) {}

Subvector::Subvector(unsigned _size, int d) {
    unsigned i;

    top = _size;
    capacity = _size;
    mas = new int[capacity];
    for (i = 0; i < _size; ++i) {
        mas[i] = d;
    }
}

Subvector::~Subvector() {
    delete[] mas;
}

int Subvector::push_back(int d) {
    if (top == capacity) {
        if (reserve(__get_new_capacity())) {
            return 1;
        }
    }
    mas[top++] = d;
    return 0;
}

int Subvector::pop_back(void) {
    if (top == 0) {
        return INT_MAX;
    }
    return mas[--top];
}

int Subvector::get_element(unsigned pos) {
    if (pos >= top) {
        return INT_MAX;
    }
    return mas[pos];
}

int Subvector::set_element(unsigned pos, int data) {
    if (pos >= top) {
        return 1;
    }
    mas[pos] = data;
    return 0;
}

int Subvector::resize(unsigned _size) {
    return resize(_size, 0);
}

int Subvector::resize(unsigned _size, int data) {
    unsigned i;
    if (reserve(_size)) {
        return 1;
    }
    for (i = top; i < _size; ++i) {
        mas[i] = data;
    }
    top = _size;
    return 0;
}

int Subvector::reserve(unsigned _size) {
    int *mas_new;
    unsigned i, cpcnt;

    mas_new = new int[_size];
    capacity = _size;

    cpcnt = (_size < top) ? _size : top;
    
    for (i = 0; i < cpcnt; ++i) {
        mas_new[i] = mas[i];
    }

    top = cpcnt;
    delete[] mas;
    mas = mas_new;

    return 0;
}

unsigned Subvector::size() {
    return top;
}

void Subvector::clear(void) {
    delete[] mas;
    mas = nullptr;
    top = 0;
    capacity = 0;
}

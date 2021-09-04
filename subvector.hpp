#ifndef __SUBVECTOR_HPP
#define __SUBVECTOR_HPP

class Subvector {
    int *mas;
    unsigned top;
    unsigned capacity;

public:
    Subvector(void);

    Subvector(unsigned);

    Subvector(unsigned, int);

    ~Subvector();

    int push_back(int);

    int pop_back(void);

    int get_element(unsigned);

    int resize(unsigned);

    unsigned size();

    void clear(void);

private:
    unsigned __get_new_capacity() {
        return capacity * 2 + 1;
    }
};

#endif

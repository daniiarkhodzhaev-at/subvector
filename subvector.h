#ifndef SUBVECTOR_H
#define SUBVECTOR_H

struct subvector {
    int *mas;
    unsigned top;
    unsigned capacity;
};

int __init(struct subvector *);

int __push_back(struct subvector *, int);

int __pop_back(struct subvector *);

int __push_forward(struct subvector *, int);

int __pop_forward(struct subvector *);

int __get_element(struct subvector *, unsigned);

int __resize(struct subvector *, unsigned);

void __shrink_to_fit(struct subvector *);

void __clear(struct subvector *);

void __destructor(struct subvector *);

#endif

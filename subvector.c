#include "subvector.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MALLOC_RULE(a)      ((a) * 2 + 1)
#define MIN(a, b)           (((a) < (b)) ? (a) : (b))

int __init(struct subvector *qv) {
    qv->mas = NULL;
    qv->top = 0;
    qv->capacity = 0;
    return 0;
}

int __push_back(struct subvector *qv, int d) {
    if (!qv) {
        return 1;
    }
    if (qv->top == qv->capacity) {
        if (__resize(qv, MALLOC_RULE(qv->capacity))) {
            return 1;
        }
    }
    *(qv->mas + (qv->top)++) = d;
    return 0;
}

int __pop_back(struct subvector *qv) {
    if (!qv) {
#ifndef NDEBUG
        fprintf(stderr, "null subvector, aborting\n");
#endif
        abort();
    }
    if (qv->top == 0) {
#ifndef NDEBUG
        fprintf(stderr, "empty subvector, aborting (not really, but...)\n");
#endif
#ifdef SV_STRICT_POP_BACK
        abort();
#else
        return 0;
#endif
    }
    return *(qv->mas + (--(qv->top)));
}

int __push_forward(struct subvector *qv, int d) {
    if (!qv) {
#ifndef NDEBUG
        fprintf(stderr, "null subvector, aborting\n");
#endif
        abort();
    }
    if (qv->top == qv->capacity) {
        if (__resize(qv, MALLOC_RULE(qv->capacity))) {
            return 1;
        }
    }
    memmove(qv->mas + 1, qv->mas, (qv->top++)*sizeof(int));
    *(qv->mas) = d;
    return 0;
}

int __pop_forward(struct subvector *qv) {
    int ans;
    if (!qv) {
#ifndef NDEBUG
        fprintf(stderr, "null subvector, aborting\n");
#endif
        abort();
    }
    if (qv->top == 0) {
#ifndef NDEBUG
        fprintf(stderr, "empty subvector, aborting (not really, but...)\n");
#endif
#ifdef SV_STRICT_POP_BACK
        abort();
#else
        return 0;
#endif
    }
    ans = *qv->mas;
    memmove(qv->mas, qv->mas + 1, (--(qv->top))*sizeof(int));
    return ans;
}

int __get_element(struct subvector *qv, unsigned pos) {
        if (!qv) {
#ifndef NDEBUG
        fprintf(stderr, "null subvector, aborting\n");
#endif
        abort();
    }
    if (pos <= qv->top) {
#ifndef NDEBUG
        fprintf(stderr, "no such pos, aborting\n");
#endif
    }
    return *(qv->mas + pos);
}

int __resize(struct subvector *qv, unsigned new_capacity) {
    if (!qv) {
        return 1;
    }
    qv->mas = (int *)realloc(qv->mas, new_capacity*sizeof(int));
    if (!qv->mas && qv->top) {
#ifndef NDEBUG
        fprintf(stderr, "OOM: dropping\n");
#endif
        return 1;
    }
    qv->capacity = new_capacity;
    qv->top = MIN(qv->top, new_capacity);
    return 0;
}

void __shrink_to_fit(struct subvector *qv) {
    if (!qv) {
#ifndef NDEBUG
        fprintf(stderr, "null subvector, aborting\n");
#endif
        abort();
    }
    if (__resize(qv, qv->top)) {
        abort();
    }
}

void __clear(struct subvector *qv) {
    if (!qv) {
#ifndef NDEBUG
        fprintf(stderr, "null subvector, aborting\n");
#endif
        abort();
    }
    qv->top = 0;
}

void __destructor(struct subvector *qv) {
    if (!qv) {
#ifndef NDEBUG
        fprintf(stderr, "null subvector, aborting\n");
#endif
        abort();
    }
    if (qv->mas) {
        free(qv->mas);
    }
    __init(qv);
}

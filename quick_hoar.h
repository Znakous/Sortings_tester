#pragma once

#include "include_me.h"

void QuickSortHoar(std::vector<Int>& v, Int l, Int r) {
    if (l >= r) {
        return;
    }
    Int i = l;
    Int j = r;
    Int mid = v[(l + r) / 2];
    while (i <= j) {
        while(v[i] < mid) {
            ++i;
        }
        while(v[j] > mid) {
            --j;
        }
        if (i <= j) {
            std::swap(v[i], v[j]);
            ++i;
            --j;
        }
    }
    QuickSortHoar(v, l, j);
    QuickSortHoar(v, i, r);
}
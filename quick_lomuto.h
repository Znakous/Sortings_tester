#pragma once
#include "include_me.h"

int PartitionLomuto(std::vector<Int>& v, Int l, Int r) {
    Int pivot_ind = (l + r) / 2;
    std::swap(v[pivot_ind], v[r]);
    Int pivot = v[r];

    Int i = l - 1;

    for (Int j = l; j < r; ++j) {
        if (v[j] < pivot){
            ++i;
            std::swap(v[i], v[j]);
        }
    }
    std::swap(v[i + 1], v[r]);
    return i + 1;
}



void QuickSortLomuto(std::vector<Int>& v, Int l, Int r) {
    if (l < r) {
        Int sep = PartitionLomuto(v, l, r);
        QuickSortLomuto(v, l, sep);
        QuickSortLomuto(v, sep + 1, r);
    }
}

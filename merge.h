#pragma once


#include "include_me.h"


void Merge_(std::vector<Int> &v, Int l, Int r) {
    Int mid = ((l + r) / 2);

    std::vector<Int> tmp(r - l + 1);
    Int i = l, j = mid+1, cur_tmp = 0;

    while (i <= mid && j <= r) {
        if (v[i] <= v[j]) {
            tmp[cur_tmp] = v[i];
            ++i;
        } else {
            tmp[cur_tmp] = v[j];
            ++j;
        }
        cur_tmp++;
    }
    while (i <= mid) {
        tmp[cur_tmp] = v[i];
        ++i;
        ++cur_tmp;
    }
    while (j <= r) {
        tmp[cur_tmp] = v[j];
        ++j;
        ++cur_tmp;
    }
    for (Int k = 0; k < (r - l + 1); k++) {
        v[l+k] = tmp[k];
    }
}

void MergeSort(std::vector<Int> &v, Int l, Int r) {
    if (l >= r) {
        return;
    }
    Int mid = ((l + r) / 2);
    MergeSort(v, l, mid);
    MergeSort(v, mid + 1, r);
    Merge_(v, l, r);
}
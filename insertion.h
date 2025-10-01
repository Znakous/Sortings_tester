#pragma once

#include "include_me.h"


void InsertionSort(std::vector<Int>& v, Int l, Int r) {
    for(Int i=l;i <= r; ++i)     
		for(Int j=i;j>l && v[j-1] > v[j]; --j) {
			std::swap(v[j-1],v[j]);
		}			
}
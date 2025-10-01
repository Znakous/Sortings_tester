#pragma once


#include "_dont_open/data_type.h"


// включите сюда свои сортировки
#include "quick_hoar.h"
#include "quick_lomuto.h"
#include "merge.h"
#include "insertion.h"

enum SortType {
    Hoar, 
    Lomuto, 
    Merge, 
    Insert,
}; // сюда имена

#include "_dont_open/mapping.h" // не убирать


void Prep() {
    // имена функций
    functions[Hoar] = &QuickSortHoar;
    functions[Lomuto] = &QuickSortLomuto;
    functions[Merge] = &MergeSort;
    functions[Insert] = &InsertionSort;

    // названия сортировок

    names[Hoar] = "Hoar";
    names[Lomuto] = "Lomuto";
    names[Merge] = "Merge";
    names[Insert] = "Insert";
}

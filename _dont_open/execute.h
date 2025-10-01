#pragma once

#include "../add_new_sorts.h"
#include "zips.h"




std::vector<std::string> head = {"Type", "duration", "= oper", "<=> opers", "+- opers", "++ -- opers", 
    // "* opers", 
    "/ opers"};
void CoutHead() {
    for (auto el : head){
        std::cout << lzip(el);
    }
    std::cout << "\n\n";
}
void CoutCounters(SortType st, int duration) {
    std::cout << lzip(st) << lzip(duration) << lzip(Counter().assigns) << 
        lzip(Counter().comparisons) 
        << lzip(Counter().plus_minus) << lzip(Counter().incrs_decrs) 
        // << lzip(Counter().multiply) 
        << lzip(Counter().divide) 
        << "\n\n";
}


void Sort(std::vector<Int>& v, SortType sort_type) {
    ResetCounters();
    auto start = std::chrono::high_resolution_clock::now();

    functions[sort_type](v, 0, num_of_elements - 1);
     
    

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    CoutCounters(sort_type, duration.count());
}






void Execute(std::vector<SortType>& calls, std::vector<Int>& example) {
    CoutHead();
    num_of_elements = example.size();
    std::vector<std::vector<Int>> v(calls.size(), example);

    for (int i=0; i<calls.size(); ++i) {
        Sort(v[i], calls[i]);
    }
}
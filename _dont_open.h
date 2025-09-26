#pragma once

#include <random>
#include <iostream>

#include "add_new_sorts.h"


constexpr int zip_const = 15;

template<typename T>
std::string lzip(T a) {
    std::string cur = std::string(a);
    return std::string(" ", zip_const - cur.size()) + cur;
}

template<>
std::string lzip(int a) {
    std::string cur = std::to_string(a);
    return std::string(zip_const - cur.size(), ' ') + cur;
}

template<>
std::string lzip(std::string cur) {
    return std::string(zip_const - cur.size(), ' ') + cur;
}

template<>
std::string lzip(SortType a) {
    std::string cur = names[a];
    return std::string(zip_const - cur.size(), ' ') + cur;
}




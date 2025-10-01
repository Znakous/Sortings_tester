#pragma once


#include "../add_new_sorts.h"


// настраивается под консоль
constexpr signed zip_const = 15; 

template<typename T>
std::string lzip(T a) {
    std::string cur = std::string(a);
    return std::string(zip_const - cur.size(), ' ') + cur;
}

template<>
std::string lzip(signed a) {
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




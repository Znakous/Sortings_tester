#pragma once

#include <map>

std::map<SortType, void(*)(std::vector<Int>&, Int, Int)> functions;
std::map<SortType, std::string> names;
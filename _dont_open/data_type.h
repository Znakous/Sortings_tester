#pragma once

#include "../include_me.h"

struct Counter {
    static int assigns;
    static int comparisons;
    static int incrs_decrs;
    static int plus_minus;
    static int multiply;
    static int divide;
    int val;
    Counter(int a) : val(a) {}
    Counter() : val(0) {}

    Counter& operator=(Counter other) {
        ++assigns;
        val = other.val;
        return *this;
    }
    bool operator<(Counter other) {
        ++comparisons;
        return val < other.val;
    }
    bool operator<=(Counter other) {
        ++comparisons;
        return val <= other.val;
    }
    bool operator>(Counter other) {
        ++comparisons;
        return val > other.val;
    }
    bool operator>=(Counter other) {
        ++comparisons;
        return val >= other.val;
    }

    template<typename T>
    bool operator<(T other) {
        ++comparisons;
        return val < other;
    }
    template<typename T>
    bool operator>(T other) {
        ++comparisons;
        return val > other;
    }
    template<typename T>
    bool operator<=(T other) {
        ++comparisons;
        return val <= other;
    }
    template<typename T>
    bool operator>=(T other) {
        ++comparisons;
        return val >= other;
    }

    Counter operator++(signed) {
        auto cur = *this;
        ++(*this);
        return cur;
    }
    Counter& operator++() {
        ++incrs_decrs;
        ++val;
        return *this;
    }
    Counter& operator--() {
        ++incrs_decrs;
        --val;
        return *this;
    }
    Counter operator--(signed) {
        auto cur = *this;
        --(*this);
        return cur;
    }

    template<typename T>
    Counter operator+(T other) {
        ++plus_minus;
        return Counter(val + other);
    }

    template<>
    Counter operator+(Counter other) {
        ++plus_minus;
        return Counter(val + other.val);
    }

    template<typename T>
    Counter operator/(T other) {
        ++divide;
        return Counter(val / other);
    }

    template<>
    Counter operator/(Counter other) {
        ++divide;
        return Counter(val / other.val);
    }
    
    template<typename T>
    Counter operator-(T other) {
        ++plus_minus;
        return Counter(val - Counter(other));
    }

    template<>
    Counter operator-(Counter other) {
        ++plus_minus;
        return Counter(val - other.val);
    }

    operator int() {
        return val;
    }

    operator std::string() {
        return std::to_string(val);
    }
};

int Counter::assigns = 0;
int Counter::comparisons = 0;
int Counter::incrs_decrs = 0;
int Counter::plus_minus = 0;
int Counter::multiply = 0;
int Counter::divide = 0;

#define Int Counter
#define int Counter






void ResetCounters() {
    Counter().assigns = 0;
    Counter().comparisons = 0;
    Counter().incrs_decrs = 0;
    Counter().plus_minus = 0;
    Counter().multiply = 0;
    Counter().divide = 0;
}

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<> distrib(1, INT_MAX);

int num_of_elements;



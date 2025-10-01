#include "_dont_open/execute.h"


signed main() {
    Prep();
    

    std::vector<SortType> calls {
        Merge, 
        Hoar, 
        Lomuto, 
        Insert,
    }; // какие сортировки хотим вызвать в их порядке

    std::vector<Int> v; // вектор, который будем сортировать
    



    // Пример задания вектора
    v.resize(8000);
    for (int i=0; i<v.size(); ++i) {
        v[i] = distrib(gen);
    }

    Execute(calls, v); // делает магию
}
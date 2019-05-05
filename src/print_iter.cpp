#include <experimental/iterator>
#include <iostream>
#include <utility>
#include <valarray>
#include <vector>
#include <deque>
#include "print_iter.h"

template<>
void printIterable(const std::vector<int>& ctn, const char *name) {
    std::cout << " /// " << name << ": [";
    std::copy(ctn.cbegin(), ctn.cend(), std::experimental::make_ostream_joiner(std::cout, "; "));
    std::cout << "]" << std::endl;
}

template<>
void printIterable(const std::deque<int>& ctn, const char *name) {
    std::cout << " /// " << name << ": [";
    std::copy(ctn.cbegin(), ctn.cend(), std::experimental::make_ostream_joiner(std::cout, "; "));
    std::cout << "]" << std::endl;
}
 
std::ostream& operator <<(std::ostream &out, const std::pair<int, bool> c)
{
    return out << c.first;
}
 
template<>
void printIterable(const std::deque<std::pair<int, bool>>& ctn, const char *name) {
    std::cout << " /// " << name << ": [";
    if (!ctn.empty()) {
        std::cout << ctn.front();
        if (ctn.size() > 1) {
            for (int i = 1; i < ctn.size(); ++i) {
                std::cout << "; " << ctn[i];
            }
        }
    }
    std::cout << "]" << std::endl;
}


#include <iostream>
#include <vector>
#include <algorithm>

#include "tri.hpp"
#include "ScopedTimer.hpp"

int main()
{
    std::vector<int> array_int {1,4,6,5,7,9,2};
    std::vector<int> array_int_trie {1, 2, 2, 3, 4, 8, 12};
    std::vector<float> array_float {1.f,4.f,6.f,5.f,7.f,9.f,2.f};

    // if (is_sorted(array)) {
    //     std::cout << "Le tableau est trie" << std::endl;
    // } else {
    //     std::cout << "Le tableau n'est pas trie" << std::endl;
    // }

    // selection_sort(array_int);
    // merge_sort(array_float);
    // display(array_float);

    // {
    //     ScopedTimer timer("nom du chronometre");
    //         std::sort(array_int.begin(), array_int.end());
    // }

    //pour tester la dichotomie
    int res {search(array_int_trie,12)};
    std::cout << res << std::endl;
}
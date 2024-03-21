#pragma once

bool is_sorted(std::vector<int> const& vec) ;
void display(std::vector<int> const& vec);
void display(std::vector<float> const& vec);

//tri pas selection
void selection_sort(std::vector<int> & vec);

//tri fusion
void merge_sort_merge(std::vector<float> & vec, size_t const left, size_t const middle, size_t const right);
void merge_sort(std::vector<float> & vec, size_t const left, size_t const right);
void merge_sort(std::vector<float> & vec);
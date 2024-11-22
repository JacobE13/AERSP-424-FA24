#include <iostream>
#include <thread>



void matrix_multiply_thread(square_matrix& c, square_matrix& a, square_matrix& b,
                            size_t i) {
    
}

void matrix_multiply_p(square_matrix& c, square_matrix& a, square_matrix& b) {
    assert(a.sz == b.sz && b.sz == c.sz);
    for (size_t x = 0; x != c.sz * c.sz; ++x) {
        c.v[x] = 0.0;
    }
    std::vector<std::thread> ts;
    for (size_t i = 0; i != c.sz; ++i) {
        ts.push_back(std::thread(matrix_multiply_thread, std::ref(c), std::ref(a), std::ref(b), i));
    }
    for (size_t i = 0; i != c.sz; ++i) {
        ts[i].join();
    }
}
#include <iostream>
#include <array>

enum class Ineq : bool {
    left_bigger = false, //    >
    right_bigger = true  //    <
};

constexpr size_t max_length = 10;
using Comps = std::array<Ineq, max_length>;

auto order_rank(const Comps& comps, int N) {
    auto ranks = std::array<int, max_length>{};
    ranks.fill(0);

    // TODO: 최적화(알고리즘)
    // std::valarray로 2차원이 아닌 1차원으로 만들기
    auto rank_mat = std::array<decltype(ranks), max_length> {};
    rank_mat.fill(ranks);

    // TODO: 최적화(알고리즘)
    // pivot 으로 정하고, 위에 부분에서 1씩 더하거나 뺴고 아래거에서 더하면 됨
    // std::valarray 에서 row 마다의 연산(step) 기능 구현?
    for (auto row_idx = 0; row_idx < N; ++row_idx) {
        for (auto left = row_idx; left < N-1; ++left) {
            rank_mat[row_idx][left+1] = rank_mat[row_idx][left];
            rank_mat[row_idx][left+1] += comps[left] == Ineq::left_bigger ? -1 : 1;
        }
    }

    std::cout << "-------------------------" << std::endl;
    for (const auto& row : rank_mat) {
        for (const auto& val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "-------------------------" << std::endl;

    // TODO: 최적화(알고리즘)
    // std::valarray로 column 마다의 연산(step) 기능 구현?
    for (auto c = 0; c < N; ++c) {
        auto c_cum = 0;
        for (auto r = 0; r < N; ++r) {
            c_cum += rank_mat[r][c];
        }
        ranks[c] = c_cum;
    } 

    for (auto i = 0; i < N; ++i) {
        std::cout << ranks[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "-------------------------" << std::endl;

    return ranks;
}

auto rank_orders(const std::array<int, 10>& ranks, int N) {
    // TODO: min elements한 다음에 더해줘서 양수로 만듬
    // 하여간에 하면 됨 ㅇㅇ
}

int main(void) {
    int N;
    std::cin >> N;

    Comps comparators;
    char comp;
    for (auto i = 0; i < N; ++i) {
        std::cin >> comp;
        comparators[i] = comp == '>' ? Ineq::left_bigger : Ineq::right_bigger;
    }

    auto ranks = order_rank(comparators, N+1);


    return 0;
} 
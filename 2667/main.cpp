#include <iostream>
#include <array>
#include <vector>
#include <tuple>
#include <string>
#include <queue>
#include <algorithm>

using Pos = std::tuple<int, int>;
using Map = std::vector<std::string>;
using Indicator = std::vector<std::vector<bool>>;

inline auto make_indicator(int N) {
    Indicator indicator(N);
    std::generate(std::begin(indicator), std::end(indicator), [&N = std::as_const(N)](){
        return std::vector<bool>(N, false);
    });

    return indicator;
}

inline auto visit(const Map& map, Indicator& indicator, int i, int j) -> bool {
    if (i < 0 or j < 0 or i >= map.size() or j >= map.size())
        return false;

    return map[i][j] == '1' and indicator[i][j] == false ? indicator[i][j] = true : false;
}

auto bfs(const Map& map, Indicator& indicator, int i, int j) -> int {
    constexpr std::array<int, 4> di = {-1, 0, 1, 0};
    constexpr std::array<int, 4> dj = {0, 1, 0, -1};

    if (visit(map, indicator, i, j) == false)
        return 0;

    auto visit_counts = 1;
    std::queue<Pos> next_visits;
    next_visits.emplace(i, j);
    
    while (next_visits.empty() == false) {
        const auto& [cur_i, cur_j] = next_visits.front();
        next_visits.pop();
        
        for (auto k = 0; k < 4; ++k) {
            auto next_i = cur_i + di[k];
            auto next_j = cur_j + dj[k];
            if (visit(map, indicator, next_i, next_j) == true) {
                next_visits.emplace(next_i, next_j);
                ++visit_counts;
            }
        }
    }

    return visit_counts;
}

auto dfs(const Map& map, Indicator& indicator, int i, int j) -> int {
    constexpr std::array<int, 4> di = {-1, 0, 1, 0};
    constexpr std::array<int, 4> dj = {0, 1, 0, -1};

    if (visit(map, indicator, i, j) == false)
        return 0;
    
    auto visit_counts = 1;

    for (auto k = 0; k < 4; ++k) {
        visit_counts += dfs(map, indicator, i + di[k], j +dj[k]);
        
    }

    return visit_counts;

}

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N;
    std::cin >> N;
    std::string in_str;
    auto indicator = make_indicator(N);
    Map input_map(N);
    for (auto i = 0; i < N; ++i) {
        
        std::cin >> in_str;
        input_map[i] = in_str;
    }

    std::vector<int> total_blocks;
    for (auto i = 0; i < N; ++i) {
        for (auto j = 0; j < N; ++j) {
            auto num_blocks = dfs(input_map, indicator, i, j);
            if (num_blocks != 0) {
                total_blocks.push_back(num_blocks);
            }
        }
    }

    std::sort(std::begin(total_blocks), std::end(total_blocks));

    std::cout << total_blocks.size() << std::endl;

    for (const auto& num_blocks : total_blocks) {
        std::cout << num_blocks << std::endl;
    }

    return 0;
} 
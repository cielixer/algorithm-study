#include <iostream>
#include <tuple>
#include <vector>
#include <queue>
#include <algorithm>
#include <iterator>

using Edge = std::tuple<int, int>;
using Adjacency = std::vector<std::vector<bool>>;
using Indicator = std::vector<bool>;

auto make_adjacency(const std::vector<Edge>& edges, int N) -> Adjacency {
    Adjacency adj(N);
    std::generate(std::begin(adj), std::end(adj), [&N = std::as_const(N)](){
        return std::vector<bool>(N, false);
    });

    for (const auto& edge : edges) {
        const auto& [A, B] = edge;
        adj[A-1][B-1] = true;
        adj[B-1][A-1] = true;
    }

    return adj;
}

inline auto visit(Indicator& indicator, int v) -> bool {
    return indicator[v-1] == false ? indicator[v-1] = true : false;
}

inline auto check_link(const Adjacency& adj, int a, int b) {
    return adj[a-1][b-1];
}

auto dfs(const Adjacency& adj, Indicator& indicator, int v) {
    if (visit(indicator, v) == false)
        return;
    std::cout << v << " ";

    for (auto i = 1; i <= indicator.size(); ++i) {
        if (check_link(adj, v, i) == true) {
            dfs(adj, indicator, i);
        }
    }
}

auto bfs(const Adjacency& adj, Indicator& indicator, int v) {
    std::queue<int> next_visits;

    visit(indicator, v);
    next_visits.push(v);

    while (next_visits.empty() == false) {
        auto target = next_visits.front();
        next_visits.pop();

        std::cout << target;

        for (auto i = 1; i <= indicator.size(); ++i) {
            if (check_link(adj, target, i) and visit(indicator, i))
                next_visits.push(i);
        }

        if (next_visits.empty() == false)
            std::cout << " ";
    }
}

int main(void) {
    int N, M, V;
    std::cin >> N >> M >> V;

    std::vector<Edge> edges(M);

    for (auto i = 0; i < M; ++i) {
        int A, B;
        std::cin >> A >> B;
        edges[i] = std::make_tuple(A, B);
    }

    auto adj = make_adjacency(edges, N);

    auto dfs_indicator = Indicator(N, false);
    dfs(adj, dfs_indicator, V);

    std::cout << std::endl;

    auto bfs_indicator = Indicator(N, false);
    bfs(adj, bfs_indicator, V);

    std::cout << std::endl;

    return 0;
} 
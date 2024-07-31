#include <iostream>
#include <tuple>
#include <vector>

// prints a vector of tuples
void printPoints(const std::vector<std::tuple<long, long>>& pts) {
    for (const auto& point : pts) {
        std::cout << "(" << std::get<0>(point) << ", " << std::get<1>(point) << ")" << std::endl;
    }
}

int main() {

    std::vector<std::tuple<long, long>> pts;
    pts.push_back(std::make_tuple(1, 2));
    pts.push_back(std::make_tuple(3, 4));

   
    printPoints(pts);

    return 0;
}

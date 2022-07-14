#include <bits/stdc++.h>

int INF = 1e9 + 7;

int solve(std::vector<int> &v) {

    std::cout << "Input Numbers: " << std::endl;

    for (int i: v) {  // printing all stones values
        std::cout << i << std::endl;
    }

    std::vector<int> br(v.size(), INF); // initalizing a vector where to set the current best value
    br[0] = 0;

    for (int i = 0; i < v.size() - 1; i++) { // iterate each vector's entry
        for (int k = 1; k <= 2; k++) { // every other values
            if (i + k < v.size()) { // checking if the skip is less than the vector size (stones)

                br[i + k] = std::min(br[i + k], std::abs(v[i] - v[i + k]) + v[i]); //we're updating the best result (in i + j)
                                                                                      // to the minimum between itself and the difference between the
                                                                                      // abs value of the vector size (stones) less
                                                                                      //itself (i + k)
                                                                                      //then we subtract the result (of the abs value) to the actual price
            }
        }
    }

    std::cout << "Output Number: " << std::endl;


    std::cout << br[v.size() - 1] << std::endl;  //we retrived the result

    return 0;
}

int main() {
    int n; // N of stones

    std::cin >> n; // input of n value


    std::vector<int> vs(n); // vector of stones

    for (int i = 0; i < n; i++) {  // iterate for pushing all stones (price) values onto the vector
        std::cin >> vs[i];
    }


    return solve(vs); // calling solve method
}

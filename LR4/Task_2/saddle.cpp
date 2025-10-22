#include "saddle.h"
#include <iostream>
#include <vector>

std::vector<std::pair<int,int>> findSaddle(int n, int m, int** arr) {
    std::vector<std::pair<int,int>> res;

    for (int i = 0; i < n; i++) {
        int minVal = arr[i][0];
        int colIndex = 0;
        for (int j = 0; j < m; j++) {
            if (arr[i][j] < minVal) {
                minVal = arr[i][j];
                colIndex = j;
            }
        }

        bool isSaddle = true;
        for (int t = 0; t < n; t++) {
            if (arr[t][colIndex] > minVal) {
                isSaddle = false;
                break;
            }
        }

        if (isSaddle) {
            res.push_back({i, colIndex});
        }
    }

    if (res.empty()) {
        std::cout << "Седловые точки не найдены" << std::endl;
    }

    return res;
}

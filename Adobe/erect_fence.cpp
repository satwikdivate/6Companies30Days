 #include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int cross(std::vector<int>& a, std::vector<int>& b, std::vector<int>& c) {
        return (b[0] - a[0]) * (c[1] - a[1]) - (c[0] - a[0]) * (b[1] - a[1]);
    }

    std::vector<std::vector<int>> outerTrees(std::vector<std::vector<int>>& points) {
        int i = 0, n = points.size();

        // Find the lowest, leftmost point
        for (int j = 1; j < n; j++)
            if (points[i][0] > points[j][0] || (points[i][0] == points[j][0] && points[i][1] > points[j][1]))
                std::swap(points[i], points[j]);

        auto z = points[0]; // Remember the point
        for (auto& x : points) {
            x[0] -= z[0]; // Center everything into 0,0 for sorting
            x[1] -= z[1];
        }

        // Sort by fixed point pseudo angles and distance
        std::sort(points.begin() + 1, points.end(), [z](const auto& x, const auto& y) {
            int xx = x[0] == 0 ? INT_MAX : (x[1] * 1000000) / x[0];
            int yy = y[0] == 0 ? INT_MAX : (y[1] * 1000000) / y[0];
            int dx = std::abs(x[1]) + std::abs(x[0]);
            int dy = std::abs(y[1]) + std::abs(y[0]);
            return xx < yy || (xx == yy && dx > dy);
        });

        // Reverse the first ones **
        int k = 1;
        while (k + 1 < n && cross(points[i], points[k], points[k + 1]) == 0)
            k++;
        std::reverse(points.begin() + 1, points.begin() + k + 1);

        // Build the convex hull using a stack
        for (int j = 1; j < n; j++) {
            std::swap(points[++i], points[j]); // Push all into a stack
            while (cross(points[i - 1], points[i], points[(j + 1) % n]) < 0)
                i--; // Pop bad points from the stack
        }

        points.resize(i + 1); // Remove extra points
        for (auto& x : points) {
            x[0] += z[0]; // Recover original points
            x[1] += z[1];
        }

        return points;
    }
};
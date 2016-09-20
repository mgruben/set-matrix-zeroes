#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                cout << matrix[i][j];
            }
            cout << endl;
        }
    }
};

int main() {
    vector<vector<int>> m = {{1,2,3},{4,5,6},{7,8,9}};
    Solution sol;
    sol.setZeroes(m);
    return 0;
}

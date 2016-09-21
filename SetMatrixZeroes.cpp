#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> rowsToZero;
        set<int> colsToZero;
        
        // Scan the array for zeros
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0) {
                    rowsToZero.insert(i);
                    colsToZero.insert(j);
                }
            }
        }
        
        // Zero the rows
        for (int i: rowsToZero) {
            for (int j = 0; j < matrix[0].size(); j++) {
                matrix[i][j] = 0;
            }
        }
        
        // Zero the columns
        for (int j : colsToZero) {
            for (int i = 0; i < matrix.size(); i++) {
                matrix[i][j] = 0;
            }
        }
    }
};

string toString(vector<int> v) {
    string ans = "[";
    for (int i = 0; i < v.size(); i++) {
        ans += " " + to_string(v[i]) + " ";
    }
    ans += "]";
    return ans;
}

string toString(vector<vector<int>> v) {
    string ans = "[";
    for (int i = 0; i < v.size(); i++) {
        ans += toString(v[i]);
        ans += "\n";
    }
    ans = ans.substr(0, ans.length() - 1);
    ans += "]";
    return ans;
}

int main() {
    vector<vector<int>> m = {{1,2},{6,8},{0,1},{6,8},{6,8},};
    cout << toString(m) << endl;
    Solution sol;
    sol.setZeroes(m);
    cout << toString(m) << endl;
    return 0;
}

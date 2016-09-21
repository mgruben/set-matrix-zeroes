#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool zeroFirstRow = false;
        bool zeroFirstCol = false;
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        if (matrix[0][0] == 0) {
            zeroFirstRow = true;
            zeroFirstCol = true;
        }
        else {
            for (int i = 0; i < m; i++) {
                if (matrix[i][0] == 0) {
                    zeroFirstCol = true;
                    break;
                }
            }
            
            for (int j = 0; j < n; j++) {
                if (matrix[0][j] == 0) {
                    zeroFirstRow = true;
                    break;
                }
            }
        }
        
        /**
         * Scan the array for rows and columns
         * to be zeroed.
         */
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        for (int i = 1; i < m; i++) {
            if (matrix[i][0] == 0) {
                for (int j = 1; j < n; j++) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        for (int j = 1; j < n; j++) {
            if (matrix[0][j] == 0) {
                for (int i = 1; i < m; i++) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        // Zero the first row
        if (zeroFirstRow) {
            for (int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }
        
        // Zero the first column
        if (zeroFirstCol) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
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

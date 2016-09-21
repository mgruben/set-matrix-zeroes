#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        /**
         * The approach to this solution follows from the
         * problem statement:
         * 
         * If one entry in a row must be zero, then all
         * entries in that row must be zero.
         * Similarly, if one entry in a column must be zero,
         * then all entries in that column must be zero.
         * 
         * The obverse of this is also true:
         * If we know that a row must be zeroed, then we
         * can represent this by setting a single entry
         * in that row to zero.
         * Similarly, if we know that a column must be zeroed,
         * then we can represent this by setting a single
         * entry in that column to zero.
         * 
         * Since every non-empty matrix has a first row
         * and a first column:
         * (1) let's zero the first column of the first row
         * when we find a zero in that row, and
         * (2) let's zero the first row of the first column
         * when we find a zero in that column.
         * 
         * However, since we're using the first row and
         * the first column to keep track of which things
         * need to be zeroed, we can't zero them out until
         * the very end.
         * 
         * Hence, we initialize two booleans to false, since
         * we don't know yet if the first row or first column
         * need to be zeroed.
         * Of course, if the incoming matrix has any zeros in
         * the first row, that row needs to be zeroed, and
         * the same goes for columns.
         * At that point, we'll set these booleans to true,
         * and handle it just before return.
         */
        bool zeroFirstRow = false;
        bool zeroFirstCol = false;
        
        // Store frequent calls to meaningful variables
        int m = matrix.size();
        int n = matrix[0].size();
        
        // Check for needing to zero initial row or column
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
        
        // Zero the marked rows
        for (int i = 1; i < m; i++) {
            if (matrix[i][0] == 0) {
                for (int j = 1; j < n; j++) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        // Zero the marked columns
        for (int j = 1; j < n; j++) {
            if (matrix[0][j] == 0) {
                for (int i = 1; i < m; i++) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        // Zero the first row, if needed
        if (zeroFirstRow) {
            for (int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }
        
        // Zero the first column, if needed
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
    vector<vector<int>> m = {{1,2},{6,8},{0,1},{6,8},{6,8}};
    cout << toString(m) << endl;
    Solution sol;
    sol.setZeroes(m);
    cout << toString(m) << endl;
    return 0;
}

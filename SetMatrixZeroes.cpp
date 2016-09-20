#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0) {
                    for (int k = 0; k < matrix.size(); k++) {
                        matrix[k][j] = 0;
                    }
                }
            }
            cout << endl;
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
    vector<vector<int>> m = {{1,2},{6,8},{9,1},{6,8},{6,8},};
    cout << toString(m) << endl;
    Solution sol;
    sol.setZeroes(m);
    return 0;
}

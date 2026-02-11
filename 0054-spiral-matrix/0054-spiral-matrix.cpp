class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();
        int srow = 0, erow = m - 1;
        
        int scol = 0, ecol = n - 1;

        vector<int> ans;

        while (srow <= erow && scol <= ecol) {

            // for top

            for (int i = scol; i <= ecol; i++) {
                ans.push_back(matrix[srow][i]);
            }
            srow++;

            // for end col  ,, top to buttom;

            for (int i = srow; i <= erow; i++) {
                ans.push_back(matrix[i][ecol]);
            }
            ecol--;

            // for buttom
        if (srow <= erow) {
    for (int i = ecol; i >= scol; i--)
        ans.push_back(matrix[erow][i]);
    erow--;
}

if (scol <= ecol) {
    for (int i = erow; i >= srow; i--)
        ans.push_back(matrix[i][scol]);
    scol++;
}


           
        }

        return ans;
    }
};
class Solution {
public:
   void dfs(vector<vector<int>>& image, int i, int j, int color, int org) {
    if (i < 0 || j < 0 || i >= image.size() || j >= image[i].size() || image[i][j] != org) {
        return;
    }
    image[i][j] = color;
    dfs(image, i + 1, j, color, org);
    dfs(image, i - 1, j, color, org);
    dfs(image, i, j + 1, color, org);
    dfs(image, i, j - 1, color, org);
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int org=image[sr][sc];
        if (org != color) {
            dfs(image, sr, sc, color, org);
        }
        return image;
    }
};
// https://leetcode.com/problems/flood-fill/description/

class Solution {
public:

    void dfs(vector<vector<int>>& image, int sr, int sc, int color,int initialColor){
        int n = image.size() ; int m = image[0].size() ;
        if(sr<0 || sc < 0 || sr >= n || sc >= m ) return ;
        if(image[sr][sc] != initialColor) return ;
        image[sr][sc] = color ;
        dfs(image,sr+1,sc,color,initialColor) ;
        dfs(image,sr,sc+1,color,initialColor) ;
        dfs(image,sr-1,sc,color,initialColor) ;
        dfs(image,sr,sc-1,color,initialColor) ;
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initialColor = image[sr][sc] ;
        if(initialColor==color) return image ;
        dfs(image,sr,sc,color,initialColor) ;
        return image ;
    }
};

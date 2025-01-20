class Solution {
    vector<vector<int>> ans;
    void help(vector<vector<int>>& graph,int curr,vector<int>& path){
        if(curr==graph.size()-1){
            ans.push_back(path);
            return ;
        }
        for(int i:graph[curr]){
            path.push_back(i);
            help(graph,i,path);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> temp={0};
        help(graph,0,temp);
        return ans;
    }
};
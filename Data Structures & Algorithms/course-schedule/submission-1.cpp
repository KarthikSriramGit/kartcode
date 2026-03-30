class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses);
        for(auto& pre: prerequisites){
            adj[pre[0]].push_back(pre[1]);
            indegree[pre[1]]++;
        }
        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0){                
                q.push(i);
            }
        }
        int finish = 0;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            finish++;
            for(int nei : adj[curr]){
                indegree[nei]--;
                if(indegree[nei] == 0){
                    q.push(nei);
                }
            }
        }
        return finish == numCourses;
    }
};

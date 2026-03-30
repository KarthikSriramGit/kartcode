class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0); // how many dependencies does each course have
        vector<vector<int>> adj(numCourses); // vector of vector of dependencies
        for(vector<int>& pre : prerequisites){
            indegree[pre[1]]++;
            adj[pre[0]].push_back(pre[1]);
        }
        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0){
                q.push(i); // for courses that have no dependencies, add it to the q
            }
        }
        int finish = 0;
        while(!q.empty()){
            int node = q.front(); q.pop();
            finish++;
            for(int nei : adj[node]){
                indegree[nei]--;
                if(indegree[nei] == 0){
                    q.push(nei);
                }
            }
        }
        return finish == numCourses;
    }
};

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        for(vector<int> pre : prerequisites){
            indegree[pre[1]]++;
            adj[pre[0]].push_back(pre[1]);
        }
        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        int finish = 0;
        while(!q.empty()){
            int curr = q.front(); q.pop();
            finish++;
            for(int course : adj[curr]){
                indegree[course]--;
                if(indegree[course] == 0){
                    q.push(course);
                }
            }
        }
        return finish == numCourses;
    }
};

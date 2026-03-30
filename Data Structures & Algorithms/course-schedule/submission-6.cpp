class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites){
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> dependencies(numCourses);
        for(vector<int>& pre : prerequisites){
            indegree[pre[0]]++;
            dependencies[pre[1]].push_back(pre[0]);
        }
        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        int finish = 0;
        while(!q.empty()){
            int course = q.front(); q.pop();
            finish++;
            for(int dependent : dependencies[course]){
                indegree[dependent]--;
                if(indegree[dependent] == 0){
                    q.push(dependent);
                }
            }
        }
    return finish == numCourses;
    }
};

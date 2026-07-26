class Solution {
  public:
    vector<vector<int>> levelSort(vector<int>& arr) {
        vector<vector<int>> result;
        int n = arr.size();
        int index = 0;
        int levelSize = 1; // Number of nodes at the current level
        
        while (index < n) {
            vector<int> currentLevel;
            // Collect nodes for the current level
            for (int i = 0; i < levelSize && index < n; i++) {
                currentLevel.push_back(arr[index++]);
            }
            // Sort the nodes of the current level independently
            sort(currentLevel.begin(), currentLevel.end());
            result.push_back(currentLevel);
            
            // The next level will have twice as many nodes
            levelSize *= 2;
        }
        
        return result;
    }
};
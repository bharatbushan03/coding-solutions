class Solution {
	public:
	vector<int> find(vector<int>& arr, int x) {
		
		int n = arr.size();
		
		int st = 0, end = n - 1;
		
		while (st <= end) {
			int mid = st + (end - st)/2;
			if (arr[mid] >= x)
				end = mid - 1;
			else
				st = mid + 1;
		}
		if (st >= n || arr[st] != x)
			return {-1, -1};
		vector<int> ans;
		ans.push_back(st);
		
		st = 0, end = n - 1;
		
		while (st <= end) {
			int mid = st + (end - st)/2;
			
			if (arr[mid] <= x)
				st = mid + 1;
			else
				end = mid - 1;
		}
		
		ans.push_back(st-1);
		
		return ans;
	}
};

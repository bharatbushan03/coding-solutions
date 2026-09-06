class Solution {
	public:
	int single(vector<int>& arr) {
		int n = arr.size();
		int st = 0, end = n - 1;
		
		if (n == 1)
			return arr[0];
		
		while (st <= end) {
			int mid = st + (end - st)/2;
			if (mid == 0) {
			    if (arr[mid] != arr[mid+1]) return arr[mid];
			    else st++;
			}
			else if (mid == n-1) {
			    if (arr[mid] != arr[mid-1]) return arr[mid];
			    else end--;
			}
			else if (arr[mid] != arr[mid+1] && arr[mid] != arr[mid-1]) return arr[mid];
			else if ((arr[mid] == arr[mid + 1] && mid%2 == 0) || (arr[mid] == arr[mid - 1] && mid%2 == 1))
				// end = mid - 1;
				st = mid + 1;
			else
				// st = mid + 1;
				end = mid - 1;
		}
		
		return - 1;
	}
};

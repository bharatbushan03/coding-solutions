class Solution:
    def upperBound(self, arr, target):
        # n = len(arr)
        # st, end=0, n-1
        
        # while st <= end:
        #     mid = st + (end-st)//2
        #     if arr[mid] <= target:
        #         st = mid + 1
        #     else:
        #         end = mid - 1
                
        # return st
        
        index = bisect.bisect_right(arr, target)
        return index
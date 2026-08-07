class Solution {
  public:
    int countFriendsPairings(int n)
    {
        if (n <= 2)
            return n;
    
        // recursive calls
        return countFriendsPairings(n - 1) + (n - 1) * 
        countFriendsPairings(n - 2);
    }
};

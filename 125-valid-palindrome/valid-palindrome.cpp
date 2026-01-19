class Solution {
public:
    // TC: O(n)
    bool isPalindrome(string s) {
        int left = 0, right = s.length() - 1;
        while(left < right)
        {
            if(!isalnum(s[left])) left++; // left is not alphanumeric skip
            else if(!isalnum(s[right])) right--; // right is not alphanumeric skip
            else if(tolower(s[left]) == tolower(s[right])){ // compar chars
                left++;
                right--;
            }
            else return false;
        }
        return true;
    }
};
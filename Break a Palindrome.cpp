class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n=palindrome.size();
        if(n==1) return "";
        int i=0;
        while(i<n && ((n%2 && i==n/2) || palindrome[i]=='a')) ++i;
        if(i<n) palindrome[i]='a';
        else ++palindrome[i-1];
        return palindrome;
    }
};

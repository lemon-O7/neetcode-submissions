class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        for(int i=0;i<n;i++) {
            int j=i;
            while (j < n && s[j] != ' ') j++;
            int temp = j--;
            while(i<j) {
                int t = s[i];
                s[i] = s[j];
                s[j] = t;
                i++;
                j--;
            }
            j=temp;
            i=j;

        }
        return s;
    }
};
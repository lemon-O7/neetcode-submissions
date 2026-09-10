class Solution {
public:
    string addBinary(string a, string b) {
        int n,m;
        n= a.size();
        m= b.size();
        int carry=0;
        string ans;
        int len = n>m ? n : m;
        n--;
        m--;
        for(int i=0;i<len;i++) {
            int x = 0;
            int y = 0;

            if(n >= 0)
                x = a[n--] - '0';

            if(m >= 0)
                y = b[m--] - '0';

            int sum = x + y + carry;

            carry = sum / 2;
            ans.push_back((sum % 2) + '0');
        }
        if(carry) ans.push_back('1');
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
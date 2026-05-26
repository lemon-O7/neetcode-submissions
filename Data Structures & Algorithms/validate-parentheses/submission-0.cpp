struct Stack {
    int top;
    int size;
    int *S;
};

class Solution {
public:
    bool isValid(string s) {
        struct Stack parentheses;
        parentheses.top = -1;
        parentheses.size = s.size();

        parentheses.S = new int[parentheses.size];
        int i=0;
        while(i<s.size()) {
            if(s[i]==40 || s[i]==91 || s[i]==123) {
                
                parentheses.top++;
                parentheses.S[parentheses.top]= s[i];
            }
            else {
                if(parentheses.top == -1)
                    return false;

                if(s[i]==41) {
                    if(parentheses.S[parentheses.top]==40) {
                        parentheses.top--;
                    }
                    else {
                        return false;
                    }
                }
                if(s[i]==93) {
                    if(parentheses.S[parentheses.top]==91) {
                        parentheses.top--;
                    }
                    else {
                        return false;
                    }
                }
                if(s[i]==125) {
                    if(parentheses.S[parentheses.top]==123) {
                        parentheses.top--;
                    }
                    else {
                        return false;
                    }
                }
            }
            i++;
        }
        return parentheses.top == -1;
    }
};
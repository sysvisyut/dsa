#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isSame(string &word, string &str2, int i, int m){
        for(int j=0;j<m;j++){
            if(word[i] != str2[j]){
                return false;
            }
            i++;
        }

        return true;
    }
    string generateString(string str1, string str2){
        int n = str1.size();
        int m = str2.size();
        int N = n+m-1;

        string word(N,'$');

        vector<bool> change(N,false);

        for(int i=0;i<n;i++){
            if(str1[i] == 'T'){
                int i1 = i;
                for(int j=0;j<m;j++){
                    if(word[i1]!='$' && word[i1]!=str2[j]){
                        return "";
                    }
                    word[i1] = str2[j];     //mark all the T cases 
                    i1++;
                }
            }
        }
        for(int i=0;i<N;i++){
            if(word[i] == '$') {
                word[i] = 'a'; //fill the rem spaces with a and mark canChange as true as they may be changed after
                change[i] = true;
            }
        }

        for(int i=0;i<n;i++){
            if(str1[i] == 'F'){

                if(isSame(word,str2,i,m)){ //if same then we need to make them unequal
                    bool changed = false;
                    for(int k=i+m-1; k>=i;k--){
                        if(change[k]){
                            word[k] = 'b';
                            changed = true;
                            break;
                        }
                    }
                    if(!changed){ //not able to change any char to break equality
                        return "";
                    }
                }
            }
        }
        return word;

        
    }
};
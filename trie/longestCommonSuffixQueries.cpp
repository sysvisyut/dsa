class Solution {
public:

    struct trieNode{
        int idx;
        trieNode* children[26];
    };

    void deleteTrie(trieNode* root){

    if(root == NULL) return;

        for(int i=0;i<26;i++){
            deleteTrie(root->children[i]);
        }

        delete root;
    }

    trieNode* getNode(int i){
        trieNode* temp = new trieNode();
        temp->idx = i;

        for(int j=0;j<26;j++){
            temp->children[j] = NULL;
        }

        return temp;
    }

    void insertTrie(trieNode* root, int i, vector<string>& wordsContainer){

        string word = wordsContainer[i];
        int n = word.size();

        for(int j=n-1;j>=0;j--){

            int ch_idx = word[j]-'a';

            if(root->children[ch_idx] == NULL){
                root->children[ch_idx] = getNode(i);
            }

            root = root->children[ch_idx];

            if(wordsContainer[root->idx].size() > n){
                root->idx = i;
            }
        }
    }

    int searchTrie(trieNode* root, string &word){

        int res_idx = root->idx;
        int n = word.size();

        for(int i=n-1;i>=0;i--){

            int ch_idx = word[i]-'a';

            if(root->children[ch_idx] == NULL){
                return res_idx;
            }

            root = root->children[ch_idx];
            res_idx = root->idx;
        }

        return res_idx;
    }

    vector<int> stringIndices(vector<string>& wordsContainer,
                              vector<string>& wordsQuery) {

        int m = wordsContainer.size();
        int n = wordsQuery.size();

        vector<int> res(n);

        trieNode* root = getNode(0);

        for(int i=0;i<m;i++){

            if(wordsContainer[root->idx].size() >
               wordsContainer[i].size()){

                root->idx = i;
            }

            insertTrie(root, i, wordsContainer);
        }

        for(int i=0;i<n;i++){
            res[i] = searchTrie(root, wordsQuery[i]);
        }


        deleteTrie(root);

        return res;
    }
};
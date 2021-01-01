class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        // map the first element of pieces
        map<int,vector<int>> mymap;
        
        for(auto p:pieces){
            mymap[p[0]]=p;
        }
        // construct array from map
        vector<int> res;
        for(auto i:arr){
            if(mymap.find(i)!=mymap.end())
            {
                res.insert(res.end(),mymap[i].begin(),mymap[i].end());
            }
        }
        // check if constructed array is same as arr 
        return res==arr;
    }
};

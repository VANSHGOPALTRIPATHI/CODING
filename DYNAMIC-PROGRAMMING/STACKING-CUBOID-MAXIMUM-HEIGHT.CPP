class Solution {
public:
bool check(vector<int>base,vector<int>newbox){
    if ( newbox[0]<=base[0]&&newbox[1]<=base[1]&&newbox[2]<=base[2] ){
        return true;
    }
    else{
        return false;
    }
}

int space(int n ,vector<vector<int>>&a){
        vector<int>currRow(n+1,0);
        vector<int>nextRow(n+1,0);
         
        for ( int curr=n-1 ;curr>=0 ;curr--){
             for ( int prev =curr-1;prev>=-1;prev--){
        int include =0;
        if ( prev == -1 || check(a[curr],a[prev])){
            include= a[curr][2]+ nextRow[curr+1];
        }
        int exclude= 0 + nextRow[prev+1];
        
         currRow[prev+1]= max(include,exclude);
             }
             nextRow=currRow;
         }
         return nextRow[0];
    }
    int maxHeight(vector<vector<int>>& cuboids) {
        // sort all dimensions ->

        for (auto &a:cuboids){
            sort(a.begin(), a.end());
        }

        // sort all cubid basis on width or length->
        sort(cuboids.begin(),cuboids.end());
        
        // use longest subsequence array->

        return space( cuboids.size(),cuboids);
        

            }
};
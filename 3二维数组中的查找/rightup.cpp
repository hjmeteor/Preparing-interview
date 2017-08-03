#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool Find(vector<vector<int> > array,int target)
    {
        if(array.empty()){
            return false;
        }
        int row = array.size();
        int column = array[0].size();
        for(int i = 0, j = column - 1; (i < row && j >= 0);){
            if(target == array[i][j]){
                return true;
            }
            else if(target < array[i][j]){
                j--;
            }
            else if(target > array[i][j]){
                i++;
            }
        }
        return false;
    }
};
#include <iostream>
#include <vector>

using namespace std;



#define __main main

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




int __main()
{
    int a1[] = { 1, 2, 8, 9, };
    int a2[] = { 2, 4, 9, 12, };
    int a3[] = { 4, 7, 10, 13, };
    int a4[] = { 6, 8, 11, 15, };
    vector<vector<int>> array;
    array.push_back(vector<int>(a1, a1 + 4));
    array.push_back(vector<int>(a2, a2 + 4));
    array.push_back(vector<int>(a3, a3 + 4));
    array.push_back(vector<int>(a4, a4 + 4));

    Solution solu;
    cout <<solu.Find(array, 7) <<endl;
    return 0;
}
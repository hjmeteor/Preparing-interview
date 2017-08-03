#include <iostream>
using namespace std;

class Solution
{
public:
	void replaceSpace(char *str,int length){
        if(length <= 0 || str == NULL){
            return;
        }
        int indexOfOriginal = length - 1;
        int count = 0;
        for(int i = 0; i < length(); i++){
            if(str[i] == ' '){
                count++;
            }
        }
        if(count == 0){
            return;
        }
        int indexOfnew = length - 1 + count * 2;
        for(int i = indexOfOriginal, j = indexOfnew; (i >= 0 && j > i);){
            if(str[i] == ' '){
                str[j--] = '0';
                str[j--] = '2';
                str[j--] = '%';
            }
            else{
                str[j--] = str[i];
            }
            i--;
        }
    }
}
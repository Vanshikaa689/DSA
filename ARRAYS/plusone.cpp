#include<iostream>
using namespace std;
#include<vector>
    vector<int> plusOne(vector<int>& digits) {
        auto it = digits.end()-1;
        int i;
        int count=0; 
        if(*(it)==9)
        {
            while(it!=digits.begin()&&*(it) == 9)
            {
                digits.erase(digits.end()-1);
                count++;
                it--;
            }
            if(it==digits.begin()&&*(it) == 9)
            {
                digits.clear();
                digits.push_back(1);
                for(i=0; i<count; i++)
            {
                digits.push_back(0);
            }
            digits.push_back(0);
            }
            else{
            int a = *it;
            digits.erase(it);
            digits.push_back(a+1);
            for(i=0; i<count; i++)
            {
                digits.push_back(0);
            }
            }
        }
        else
        {
            int a = *it;
            digits.erase(digits.end()-1);
            digits.push_back(a+1);
        }
    return digits;
    }

int main()
{
    vector<int> a = {9, 9, 0};
    vector<int> b = plusOne(a);
    for(auto i:b)
    {
        cout<<i;
    }
    return 0;
}

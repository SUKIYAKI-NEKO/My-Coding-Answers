// https://leetcode.com/problems/integer-to-roman/description/

// Medium

// Topics:
// Math 、 String

// Description:
// Given an integer, convert it to a Roman numeral.

// Submission1(line 24):
// Original solution - written by me
// Approach: digit-by-digit branching
// Accepted
// Runtime: 2 ms Memory: 9.33 MB

// Submission2 (line 123):
// Co-developed with Claude AI assistance
// improvement : greedy algorithm with a lookup table
// Accepted
// Runtime: 0 ms Memory: 12.74 MB


//Submission1:

class Solution {
public:
    string intToRoman(int num) {
        string rm;
        int in;
        int a=0;
        while(1){
            if(!num)break;
            in=num%10;
            num/=10;
            a++;
            if(in==0)continue;
            if(a==1){
                if(in==4){
                    rm='V'+rm;
                    rm='I'+rm;
                }
                else if(in==9){
                    rm='X'+rm;
                    rm='I'+rm;
                }
                else if(in<4){
                    while(in){
                        rm='I'+rm;
                        in--;
                    }
                }
                else {
                    in-=5;
                    while(in){
                        rm='I'+rm;
                        in--;
                    }
                    rm='V'+rm;
                }
            }
            else if(a==2){
                if(in==4){
                    rm='L'+rm;
                    rm='X'+rm;
                }
                else if(in==9){
                    rm='C'+rm;
                    rm='X'+rm;
                }
                else if(in<4){
                    while(in){
                        rm='X'+rm;
                        in--;
                    }
                }
                else {
                    in-=5;
                    while(in){
                        rm='X'+rm;
                        in--;
                    }
                    rm='L'+rm;
                }
            }
            else if(a==3){
                if(in==4){
                    rm='D'+rm;
                    rm='C'+rm;
                }
                else if(in==9){
                    rm='M'+rm;
                    rm='C'+rm;
                }
                else if(in<4){
                    while(in){
                        rm='C'+rm;
                        in--;
                    }
                }
                else {
                    in-=5;
                    while(in){
                        rm='C'+rm;
                        in--;
                    }
                    rm='D'+rm;
                }
            }
            else {
                while(in){
                    rm='M'+rm;
                    in--;
                }
            }
        }
        return rm;
    }
};



//Submission 2:
// Co-developed with Claude AI assistance

class Solution {
public:
    string intToRoman(int num) {
        vector <pair<int,string>> table={
            {1000,"M"},{900,"CM"},{500,"D"},{400,"CD"},{100,"C"},{90,"XC"},{50,"L"},{40,"XL"},{10,"X"},
            {9,"IX"},{5,"V"},{4,"IV"},{1,"I"}
        };
        string rm;
        for(auto a : table){
            while(num>=a.first){
                rm+=a.second;
                num-=a.first;
            }
        }
        return rm;
    }
};

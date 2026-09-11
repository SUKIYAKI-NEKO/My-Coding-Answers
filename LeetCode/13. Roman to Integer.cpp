// https://leetcode.com/problems/roman-to-integer/description/

// Easy

// Topics : 
// Hash Table 、 Math 、 String

// Description :
// Given a roman numeral, convert it to an integer.

// Submission1(line 24) :
// Original solution - written by me
// Approach: digit-by-digit branching
// Accepted
// Runtime: 0 ms  Memory: 9.90 MB

// Submission 2 (line 79) :
// Original solution - written by me (idea from 12.Integer to Roman)
// Approach: lookup table
// Accepted
// Runtime: 0-2 ms  Memory: 12.22 MB



// Submission 1 :

class Solution {
public:
    int romanToInt(string s) {
        int ans=0;
        int a=s.length();
        for(int i=0;i<a;i++){
            if(s[i]=='M')ans+=1000;
            if(s[i]=='D')ans+=500;
            if(s[i]=='L')ans+=50;
            if(s[i]=='V')ans+=5;
            if(s[i]=='C'){
                if(s[i+1]=='D' && i<a-1){
                    ans+=400;
                    i++;
                }
                else if(s[i+1]=='M' && i<a-1){
                    ans+=900;
                    i++;
                }
                else ans+=100;
            }
            if(s[i]=='X'){
                if(s[i+1]=='L' && i<a-1){
                    ans+=40;
                    i++;
                }
                else if(s[i+1]=='C' && i<a-1){
                    ans+=90;
                    i++;
                }
                else ans+=10;
            }
            if(s[i]=='I'){
                if(s[i+1]=='V' && i<a-1){
                    ans+=4;
                    i++;
                }
                else if(s[i+1]=='X' && i<a-1){
                    ans+=9;
                    i++;
                }
                else ans+=1;
            }
        }

        return ans;
    }
};





//Submission 2 :

class Solution {
public:
    int romanToInt(string s) {
        vector <pair<int,char>> table={
             {1000,'M'}, {100,'C'},{1000,'M'} ,{500,'D'}, {100,'C'},{500,'D'}  //1000 900 500 400 
             ,{100,'C'} ,{10,'X'},{100,'C'},  {50,'L'},  {10,'X'},{50,'L'}    //100 90 50 40
             ,{10,'X'}, {1,'I'},{10,'X'}, {5,'V'}, {1,'I'},{5,'V'}, {1,'I'}   // 10 9 5 4 1
        };
      
        int ans=0;
        int a=s.length();
        int si=0;
        int pre=1000;
        for(auto t:table){
            while(s[si]==t.second){
                if(t.first>pre){
                    ans=ans-pre*2;
                    ans+=t.first;
                }
                else ans+=t.first;
                pre=t.first;
                si++;
                if(si>=a)return ans;
            }
        }
        return ans;
    }
};

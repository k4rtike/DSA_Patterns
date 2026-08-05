/*
#include<bits/stdc++.h>
using namespace std;
// Take 2-d array-> vector of vectors
int main(){
    //a 2-d vector containing vectors of 2 elements inside which represents range like arr[[1,3],[4,6]...]

    vector<vector<int>> res;
    int n=10;// let n is the size of 'a' the given range, n mtlb jitni categories hain.

    //ab pehle 1st range ki start aur end le lo
    //it will represent ki abhi tk ka range itna hai 
    int start1=a[0][0]; //assume 'a' as given 2d array of ranges
    int end1=a[0][1]; //first category ka ending price suppose [1,3]

    //ab aage ki categories dekhenge jahan merge ki need hogi merge kar denge, jo range sahi hongi unhe answer
    // me store karke aage move kar jayenge

    for(int i=1;i<n;i++){
        int start2=a[i][0]; //a[i][0] me i denote kar rha hai category number, aur 0 bta rha hai ki first vala element
        int end2 = a[i][1]; //yahan 1 bta rha hai ki dusra element lena hai mtln ending range.
        if(end1>=start2){
        //merge hoga
            start1= start1;
            end1 =max(end1,end2); //jo bada hoga wo aa jayega
            continue;
        }
        
        //jab merge nahi ho rha hai , answer me store kar do 
        res.push_back({start1, end1}); //result 2d vector me chala gya ab ye
        start1=start2; //current range update kar do mtlb ab is cuurent range se dekho , iske pehle vali ho gyi hain sab
        end1 = end2;   
    }
    
    res.push_back({start1, end1});// last vale start1, end1 ko store karne ke liye;
    return res;
}

//Leetcode : Insert Intervals
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        //first insert the newInterval
        if(intervals.empty()){
            return {newInterval};
        }

        bool insert=false;
        vector<vector<int>> temp;

        for(int i=0; i<intervals.size(); i++){
            if(insert==false && intervals[i][0]>=newInterval[0]){
                temp.push_back(newInterval);
                insert=true;
            }
            temp.push_back(intervals[i]);
        }

        if(insert==false){
            temp.push_back(newInterval);
        }

        vector<vector<int>> res;

        int start1 = temp[0][0];
        int end1 = temp[0][1];

        for(int i=1; i<temp.size(); i++){
            int start2 = temp[i][0];
            int end2 = temp[i][1];

            if(end1>=start2){
                //merge
                start1=start1;
                end1=max(end1,end2);
                continue;
            }
            
            res.push_back({start1,end1});
            start1=start2;
            end1=end2;
        }
        res.push_back({start1, end1});
        
        return res;
    }
};
*/
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<limits.h>
using namespace std;

    void findPrevSmallestElement(vector<int>&heights,vector<int>&prevAns){

        stack<int> st;
        st.push(-1);
        int n = heights.size();

        for(int i=0;i<n;i++){

            int element = heights[i];

            while(st.top()!=-1 && heights[st.top()]>=element) st.pop();

            prevAns.push_back(st.top());
            st.push(i);

        }

    }

    void findNextSmallestElement(vector<int>&heights,vector<int>&nextAns){

        stack<int> st;
        st.push(-1);
        int n = heights.size();

        for(int i=n-1;i>=0;i--){

            int element = heights[i];

            while(st.top()!=-1 && heights[st.top()]>=element) st.pop();
            
            nextAns.push_back(st.top() == -1 ? n : st.top());
            st.push(i);

        }
    }

    int largestRectangleArea(vector<int>& heights) {

        if(heights.size()==1) return heights[0];

        vector<int> prevAns;
        vector<int> nextAns; 
        
        findPrevSmallestElement(heights,prevAns);
        findNextSmallestElement(heights,nextAns);

        reverse(nextAns.begin(),nextAns.end());

        int maxWidth = INT_MIN;

        for(int i=0;i<heights.size();i++){
            int width = heights[i] * ((nextAns[i]-prevAns[i])-1);
            maxWidth = max(width,maxWidth);
        }

        return maxWidth;
    }

    // from this function 
    // starts the main code of this questions 
    // as the previous three functions are taken from 
    // largest area in a histogram question
    int maximalRectangle(vector<vector<char>>& matrix) {

        // Approach
        // we are treating each row in this 2d matrix as a histogram
        

        // converting the char type 2d matrix into a int type 2d matrix
        vector<vector<int>> int_matrix(matrix.size(),vector<int>(matrix[0].size(),0));

        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                int_matrix[i][j]=matrix[i][j] - '0';
            }
        }

        int maxArea = 0;

        // each row will be acting like histogram
        vector<int> histogram;

        // treavering over the first row and storing that into histogram vector
        for(int i=0;i<int_matrix[0].size();i++) {
            histogram.push_back(int_matrix[0][i]);
        }
        
        // calculating maxArea for that 1 row histogram
        maxArea = max(maxArea,largestRectangleArea(histogram));


        // now traversing from 1st row to the end row
        for(int i=1;i<int_matrix.size();i++){

            for(int j=0;j<int_matrix[0].size();j++){


                // if any column of row is 0 then we will make the histogram columns also 0
                if(int_matrix[i][j]==0) histogram[j]=0;

                // if not, then we will extend the height of the histogram jth column with the current value
                // so i.e histogram[j]+=1;
                else histogram[j]+=1;
            }

            // calculating maxArea for ith row
            maxArea = max(maxArea,largestRectangleArea(histogram));
        }   

        // returning maxArea
        return maxArea;
        
    }

int main(){

    vector<vector<char>> matrix = {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'},
    };

    cout<<maximalRectangle(matrix);
    
    return 0;
}
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };

class Solution {
public:

    void calculateNextGreaterIndex(vector<int>&arr,vector<int>&nextSmallerIndexArray){

        stack<int> st;
        st.push(0);
        int n = arr.size();

        for(int i=n-1;i>=0;i--){

            int element = arr[i];

            while(st.top()!=0 && st.top()<=element) st.pop();

            nextSmallerIndexArray.push_back(st.top());
            st.push(element);

        }
    }
    vector<int> nextLargerNodes(ListNode* head) {

        vector<int> arr;

        while(head){
            arr.push_back(head->val);
            head=head->next;
        }

        // for(auto i:arr) cout<<i<<" ";

        vector<int> nextGreaterElementArray;
        calculateNextGreaterIndex(arr,nextGreaterElementArray);

        reverse(nextGreaterElementArray.begin(),nextGreaterElementArray.end());
        return nextGreaterElementArray;
    }
};

*/
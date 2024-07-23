#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

bool isAllocationPossible(vector<int>&arr, int pageLimit, int m){

    int studentNumber = 1;
    
    int n=arr.size();
    int pageSum=0;

    for(int i=0;i<n;i++){

        // if i add the current book pages into the current student page sum
        // will it cross the page limit for each student or not?
        if(pageSum+arr[i]>pageLimit){

            // if it crosses the page limit
            // the checking that if have more students or not
            if(studentNumber<m){
                studentNumber++;  // now next student has come forward into the line
                pageSum=arr[i]; // starting the pageSum for the new student with arr[i]; current book
            }
            else{
                // it means that there are no more students left but books are left
                // so allocation will not be possible with this pageLimit
                // so returning false
                return false;
            }
        }
        else{
            pageSum+=arr[i];
        }

    }

    return true;

} 

void findMinPages(vector<int>&arr,int m,int &ans){

    // search space

    // if only one student is there
    // and books are these [12,34,67,90]
    // so i have give all the books to that student right?
    // that means that student will get all books i.e 12+34+67+90 and that equal's to 203 pages
    
    // so in that scenario (edge case) where the student is only 1 then maximum limit shoudl be upto
    // sum of all pages i.e 203 in this case
    // and if the students increase's let's say m=2 then pages will be further divided into children
    // so the end limit of pages per children that we can get is 203 i.e sum of books pages;
    int e = accumulate(arr.begin(),arr.end(),0);

    // ano ther edge case would be if the children are equal to the number of books
    // i.e [12,34,67,90] , n=4 and m=4;
    // so in this situation every student will get 1 book
    // to deal with these type of edge cases we need ensure that our page limit is 
    // the maximum number of pages 
    // if we keep it as 90
    // student 1 will be getting 12 pages  # 12<=90 ✅
    // student 2 will be getting 34 pages  # 34<=90 ✅
    // student 3 will be getting 67 pages  # 67<=90 ✅
    // student 4 will be getting 90 pages  # 90<=90 ✅

    // but if we have kept the minimum page limit for each student as any other number of pages 
    // that is not maximum then n=4 and m=4 or n==m scenario will fail
    // example -> let's take limit as 67
    // student 1 will be getting 12 pages  # 12<=67 ✅
    // student 2 will be getting 34 pages  # 34<=67 ✅
    // student 3 will be getting 67 pages  # 67<=67 ✅
    // student 4 will be getting 90 pages  # 90<=67 ❌  // here the condition will fail
                                                        // hence one student will be left without the book
                                                        // which we don't want

    // so start range should always be max(pages)
    int s = *max_element(arr.begin(),arr.end());

    while(s<=e){

        int mid = s+(e-s)/2;

        // here mid is playing the role of giving pageLimit per student
        // so that we can check if the allocation are possible with that page limit
        // if not then we will increase the page limit
        // if yes , we will store the pageLimit i.e mid and will further try to minimize it
        // by lowering the page limit to see that which is the most minimized page limit which is working

        // because by doing that we will reach to a point where we will find the most optimal and 
        // minimized pageLimit through which the allocations of books to each student is also possible 
        // and due to the most minimized pageLimit to each student if we sum of the pages that each student is 
        // getting will also be minimized 

        // and that is the ultimate goal i.e to find a combination of pageLimit where each student gets a book
        // and maximum number of pages that students get can be minimized

        if(isAllocationPossible(arr,mid,m)){
            ans=mid;  // storing the answer
            e=mid-1;  // futher trying to minimize the page limit
        }
        else{
            // the allocation was not possible with the current mid value i.e pageLimit
            // so we will increase the pageLimit
            s=mid+1;
        }


    }

}

int main(){

    // array representing n number of books
    // each arr[i] has number of pages in each book
    // we have to find the minimum number of pages that we can allocate
    // so that the maximum sum of pages should on a children should be minimized
    // while considering that no book gets left and each children atleast has one book
    vector<int> arr = {12, 34, 67, 90};
    int m=2;
    int n=arr.size();
    int ans=0;

    // handling the edge case 
    // where there are less number of books to distribute and the students are more
    if(m>n){
        ans = -1;
    }
    else{
        findMinPages(arr,m,ans);
    }

    cout<<"The answer is "<<ans<<endl;
    
    return 0;
}
/******************************************************************************
a)Implement “Sum of Subsets” using Backtracking. “Sum of Subsets” problem: 
Find a subset of a given set S = {s1,s2,……,sn} of n positive integers whose sum is equal
to a given positive integer d. For example, if S = {1,2,5,6,8} and d = 9 
there are two solutions {1,2,6} and {1,8}. 
A suitable message is to be displayed if the given problem instance doesn’t have a solution.
*******************************************************************************/

#include <iostream>
using namespace std;

void displaySubset(int subSet[], int size) {
    cout<<"{";
   for(int i = 0; i < size-1; i++) {
      cout << subSet[i] << ", ";
   }
   cout << subSet[size-1] <<"}" <<endl;
}

void subsetSum(int set[], int subSet[], int n, int subSize, int total, int nodeCount ,int sum) {
   if( total == sum) {
      displaySubset(subSet, subSize);     //print the subset
      subsetSum(set,subSet,n,subSize-1,total-set[nodeCount],nodeCount+1,sum);     //for other subsets
      return;
   }else {
      for( int i = nodeCount; i < n; i++ ) {     //find node along breadth
         subSet[subSize] = set[i];
         subsetSum(set,subSet,n,subSize+1,total+set[i],i+1,sum);     //do for next node in depth
      }
   }
}

void findSubset(int set[], int size, int sum) {
   int *subSet = new int[size];     //create subset array to pass parameter of subsetSum
   subsetSum(set, subSet, size, 0, 0, 0, sum);
   delete[] subSet;
}

int main() {
   int weights[] = {1,2,5,6,8};
   int size = 5;
   findSubset(weights, size, 9);
}

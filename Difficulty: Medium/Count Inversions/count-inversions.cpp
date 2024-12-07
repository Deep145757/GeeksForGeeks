//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to count inversions in the array.
    int merge(vector<int> &arr, int l, int mid, int r) {
        int count = 0;  // Stores the inversion count
        int i = l, j = mid + 1, k = 0;
        vector<int> temp(r - l + 1);  // Temporary array to store sorted elements
        
        // Merge the two halves
        while (i <= mid && j <= r) {
            if (arr[i] <= arr[j]) {
                // If left half element is smaller, no inversion
                temp[k++] = arr[i++];
            } else {
                // If right half element is smaller, count inversions
                count += (mid - i + 1); // All remaining elements in left half are inversions
                temp[k++] = arr[j++];
            }
        }
        
        // Copy remaining elements from the left half
        while (i <= mid) {
            temp[k++] = arr[i++];
        }

        // Copy remaining elements from the right half
        while (j <= r) {
            temp[k++] = arr[j++];
        }

        // Copy sorted elements back to original array
        for (int p = l; p <= r; p++) {
            arr[p] = temp[p - l];
        }

        return count;  // Return inversion count for this merge step
    }

    // Function to apply merge sort and count inversions recursively
    int mergeSort(vector<int> &arr, int l, int r) {
        if (l >= r) return 0;  // Base case: single element or invalid range
        
        int mid = (l + r) / 2;
        int count = 0;

        // Count inversions in the left half
        count += mergeSort(arr, l, mid);

        // Count inversions in the right half
        count += mergeSort(arr, mid + 1, r);

        // Count inversions during merging of two halves
        count += merge(arr, l, mid, r);

        return count;
    }

    // Main function to count inversions in the array
    int inversionCount(vector<int> &arr) {
        int n = arr.size();
        return mergeSort(arr, 0, n - 1);  // Call mergeSort on the full array
    }
    
};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n;
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);
        Solution obj;
        cout << obj.inversionCount(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends
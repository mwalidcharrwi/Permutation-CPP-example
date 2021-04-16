#include <iostream>
#include <vector>
using namespace std;

/**************************************************************/
/*    Generate all permutations                                    */
/**************************************************************/

// swaps two numbers
void swap (int &x, int &y)
{
    int t=x;
    x = y;
    y = t;
}

void backtrack (vector<int> A, int k, int n)
{
   if (k == n)  // if it is a solution
   {
      // process the solution (print the permutation)
      cout << "{";
      for(int i=0; i<n; i++)
            cout << A[i] << " ";
      cout << "}";
      cout << endl;
   }
   else // construct a solution
      {
         for(int i=k; i<n; i++)
         {
             swap(A[i], A[k]);
             backtrack(A, k+1, n); // generate solution
             swap(A[i], A[k]);
         }
      }
}

int main()
{
   int n;
   cout << "Enter number of elements: ";
   cin >> n;
   vector<int> A(n);
   cout << "Enter " << n << " elements: ";
   for(int i=0; i<n; i++)
      cin >> A[i];
   backtrack(A, 0, n);  // generate all solutions
   return 0;
}



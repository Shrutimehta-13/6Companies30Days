// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// #define ull unsigned long long// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// #define ull unsigned long long
	/* Function to get the nth ugly number*/
	
	ull getNthUglyNo(int n) {
	    // code here
	    int c2=0, c3=0, c5=0;
	    vector <ull> dp(n+1);
	    dp[0]=1;
	    for(int i=1; i<=n; i++)
	    {
	        dp[i] = min({2*dp[c2], 3*dp[c3], 5*dp[c5]});
	        if(2*dp[c2]==dp[i])
	            c2++;
	        if(3*dp[c3]==dp[i])
	            c3++;
	        if(5*dp[c5]==dp[i])
	            c5++;
	    }
	    return dp[n-1];
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.getNthUglyNo(n);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends
	/* Function to get the nth ugly number*/
	int maxDivide(int a, int b)
	{
	    while(a%b==0)
	    {
	        a = a/b;
	    }
	    return a;
	}
	
	int isUgly(int no)
	{
	    no = maxDivide(no,2);
	    no = maxDivide(no,3);
	    no = maxDivide(no,5);
	    
	    return (no==1)?1:0;
	}
	
	
	ull getNthUglyNo(int n) {
	    // code here
	    
	    ull num=1;
	    int count=1;
	    while(n>count)
	    {
	        num++;
	        if(isUgly(num))
	            count++;
	    }
	    return num;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.getNthUglyNo(n);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends

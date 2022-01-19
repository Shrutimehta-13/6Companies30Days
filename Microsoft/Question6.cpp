// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to find list of all words possible by pressing given numbers.
    
    void words(unordered_map<int, vector<char>>&mp, int a[], int n, int idx, string s, vector<string>&ans)
    {
        if(idx==n)
        {
            ans.push_back(s);
            return;
        }
        auto v = mp[a[idx]];
        
        for(int i=0; i<v.size(); i++)
        {
            words(mp, a, n, idx+1, (s+v[i]), ans);
        }
    }
    
    
    vector<string> possibleWords(int a[], int N)
    {
        //Your code here
        unordered_map<int, vector<char>> mp;
        mp[2]={'a','b','c'};
        mp[3]={'d','e','f'};
        mp[4]={'g','h','i'};
        mp[5]={'j','k','l'};
        mp[6]={'m','n','o'};
        mp[7]={'p','q','r','s'};
        mp[8]={'t','u','v'};
        mp[9]={'w','x','y','z'};
        
        vector<string> v;
        words(mp, a, N, "", v);
        return v;
    }
};


// { Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}  // } Driver Code Ends

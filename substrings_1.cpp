#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*

s = aab
n = 3
indexes = 0, ..., n - 1

s[0,0] = a
s[0, 1] = aa
s[1,1] = a
s[1,2] = ab

0 <= left <= right <= n - 1

string s consists of lowercase English alphabetic letters (a to z) only

Input:
n q
s
(two space-separated integers describing the respective values of left and right for a query)

*/

int how_many_substrings(int n, int q, string s) {
    
    int left = 0;
    int right = 0;
    vector<string> substrings(0);
    vector<string> substrings_of_substrings(0);
    vector<int> num_substrings(0);
    
    /* SUBSTRINGS */
    
    for(int i = 0; i <= q - 1; ++i) {
        cin >> left >> right;
        cout << left << " " << right << endl;
        substrings.push_back(s.substr(left, right - left + 1));
    }
    
    cout << endl;
    
    cout << "SUBSTRINGS:" << endl;
    
    for(int n = 0; n <= substrings.size() - 1; ++n) { cout << substrings.at(n) << endl; }
    
    cout << endl;
    
    /* SUBSTRINGS OF SUBSTRINGS */
    
    for(int j = 0; j <= substrings.size() - 1; ++j) {
        for(int k = 0; k <= (substrings.at(j)).length() - 1; ++k) {
            for(int q = 0; q <= (substrings.at(j)).length() - 1; ++q) {
                if(find(substrings_of_substrings.begin(), substrings_of_substrings.end(), (substrings.at(j)).substr(k, q)) != substrings_of_substrings.end()) { }
                else { substrings_of_substrings.push_back( (substrings.at(j)).substr(k, q) ); }
            }
        }
        
        cout << "SUBSTRINGS OF SUBSTRINGS (" << substrings.at(j) << "):" << endl;
        for(int m = 0; m <= substrings_of_substrings.size() - 1; ++m) { cout << substrings_of_substrings.at(m) << endl; }
        cout << endl;
        
        num_substrings.push_back(substrings_of_substrings.size());
        substrings_of_substrings.clear();
    }
    
    /* NUMBER OF SUBSTRINGS */
    
    cout << "NUMBER OF SUBSTRINGS:" << endl;
    
    for(int p = 0; p < num_substrings.size(); ++p) { cout << num_substrings.at(p) << endl; }
    
    cout << endl;
    
    return 0;
}

int main() {
    
    string s = "aabaa";
    int q = 5;
    int n = 5;
    
    how_many_substrings(n, q, s);
    
    cout << n << " " << q << endl;
    cout << s << endl;
    
	return 0;
}

// input data
// s - the input string
// len - the length of the two substrings to be compared
// i1 - the start index of the first substring
// i2 - the start index of the second substring
#include<bits/stdc++.h>
#define ULL unsigned long long
using namespace std;
/* the following code calculates the hashes of all prefixes and then compares any two substrings in O(1): */
int main()
{
    int T; cin>>T;
    for(int tt=1;tt<=T;tt++){
    string s,t;
    int i1, i2, len;
    cin>>s>>t;
    len = t.size();
    // calculate all powers of p
    const int p = 31;
    vector <ULL> p_pow (s.length ());
    p_pow [0] = 1;
    for (size_t i = 1; i <p_pow.size (); ++ i)
        p_pow [i] = p_pow [i-1] * p;

    // Calculate the hashes of all prefixes
    vector <ULL> h (s.length ());
    for (size_t i = 0; i <s.length (); ++ i){
        h [i] = (s [i] - 'a' + 1) * p_pow [i];
        if (i) h [i] += h [i-1];
    }
    ULL h_t = 0;
    for(int i=0;i<t.size();i++){
        h_t += (t[i] - 'a' + 1) * p_pow [i];
    }
    ULL H_t = h_t;
    int cnt = 0;
    for(int i=0;i+len-1<s.size();i++){
        i1  = i;
        ULL h1 = h [i1 + len-1];
        if (i1) h1 -= h [i1-1];
        if(i1) h_t*=(p_pow[i1]);
        if(h1==h_t) cnt++;
        h_t = H_t;
    }
    printf("Case %d: %d\n",tt,cnt);
    }
}

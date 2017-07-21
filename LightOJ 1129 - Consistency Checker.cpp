#include<bits/stdc++.h>
#define ULL unsigned long long
using namespace std;
int main()
{
    int n,t;
    cin>>t;
    for(int tt=1;tt<=t;tt++){
    cin>>n;

    vector <string> s(n);
    for(int i=0;i<n;i++) cin>>s[i];

    // Calculate all powers of p up to 10,000 - the maximum length of a string
    const int p = 31;
    vector <ULL> p_pow (10000);
    p_pow [0] = 1;
    for (size_t i = 1; i <p_pow.size (); i++)
        p_pow [i] = p_pow [i-1] * p;

    // Calculate the hash of each string

    // hashes[] stores the hash value and the index of the string in the array s
//    vector <pair <ULL, int>> hashes (n);

    map<ULL,int>mp;
    vector<ULL>v(10000);
    for (int i = 0; i <n; ++ i){
        ULL hash = 0;
        for (size_t j = 0; j <s [i] .length (); ++ j)
            hash += (s [i] [j] - 'a' + 1) * p_pow [j];

        mp[hash]++;
        v[i] = hash;
    }
    int ck=1;
    for (int i = 0; i <n; ++ i){
        ULL hash = 0;
        for (size_t j = 0; j <s [i] .length (); ++ j){
            hash += (s [i] [j] - 'a' + 1) * p_pow [j];
            if(hash!=v[i] && mp[hash]>=1){
                ck=0;
            }
        }

    }
    printf("Case %d: ",tt);
    if(ck==1)
    cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    }

}


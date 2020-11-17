//t

#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long 
#define For(i,a,b) for(i=a;i<b;i++)
#define eb emplace_back
static long long int mod=(long long)(1e9)+7;
ll fast() {
    ll n=0;
    ll ch=getchar_unlocked();
    while(ch<'0'||ch>'9')
        ch=getchar_unlocked();
    while(ch>='0'&&ch<='9')
    {
        n=(n<<3)+(n<<1)+ch-'0';
        ch=getchar_unlocked();
    }
    return n;
}
ll power(ll x,ll y,ll p){
    ll res = 1;     
    x = x % p;
    if (x == 0) return 0;
    while (y > 0) {  
     if (y & 1)  res = (res*x) % p; 
      y = y>>1;
      x = (x*x) % p;  
    }  
  return res;  
}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
ll t,n,i,j,d;
string str;
t=fast();
while(t--)
{ 
  n=fast();
  vector<ll>main(n+1); 
  vector<ll>prefix(n+1,0);
  ll q,r,ans=0,k=0; 
  For(i,1,n+1) main[i]=fast();
  q=fast();
    ans=0;
    if(n==1){ 
      For(i,0,q){
      r=fast();
      if(main[1]&1) cout<<((main[1])*r)%mod<<"\n";
      else cout<<(((main[1]-1)*r)+1)%mod<<"\n"; 
     }
   }
    else if(main[1]==1){
      For(i,0,q){
      r=fast();
      ans=r/n;  
      if(r==1) ans=1; 
      else{
      if(r%n>1) ans++; 
      }
      cout<<ans%mod<<"\n";
    }
  } 
  else{
    for(i=1;i<=n;i++){
      if(i==n){
        if(main[i]&1) prefix[i]=(prefix[i-1]+main[i])%mod; 
        else prefix[i]=(prefix[i-1]+main[i]-1)%mod;
      }
     else if(i<n-1&&main[i+1]==1){
        if(main[i]&1) prefix[i]=(prefix[i-1]+main[i])%mod; 
        else prefix[i]=(prefix[i-1]+main[i]-1)%mod;
        prefix[i+1]=prefix[i]; 
        i++; 
     }
     else{
       if(main[i]&1) prefix[i]=(prefix[i-1]+main[i]-1)%mod; 
       else prefix[i]=(prefix[i-1]+main[i])%mod;
     }
   }
   For(i,0,q){
     r=fast(); 
     ans=0; ll v=r%n; 
     ll v1=(r/n);
     ans=(v1%mod*(prefix[n])%mod)%mod;
     if(v==0) {
       if(!(main[n]&1)) ans++;
      }
     else if(main[v]==1){
       if(!(main[v-1]&1)) ans+=2; 
       ans=(ans+prefix[v])%mod;
     }
     else if((main[v]&1)){ 
     ans++; 
     if(v+1<n&&main[v+1]==1) ans--;
     ans=(ans+prefix[v])%mod; 
     } 
     else{ 
       if(v+1<n&&main[v+1]==1) ans++;
       ans=(ans+prefix[v])%mod; 
     }
     ans=ans%mod; 
     cout<<ans<<"\n";
   }
  }
}
return 0;
}
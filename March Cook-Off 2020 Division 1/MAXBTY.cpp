#include <bits/stdc++.h>
#define int long long
using namespace std;
void pv(vector<int> v){  for (int i = 0; i < v.size(); ++i){cout<<v[i]<<" ";}cout<<""<<endl;}
void pa(int a[],int n,int p){for (int i = p; i < n+p; ++i){cout<<a[i]<<" ";}cout<<""<<endl;}
#define mem(a) memset(a,0,sizeof(a))
const double pi=3.141592653589793238;
#define IOS ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define d(x) cout<<x<<endl;
#define fni(x,y,z) for(int i=(int)x;i>=(int)y;i-=(int)z)
#define fnj(x,y,z) for(int j=(int)x;j>=(int)y;j-=(int)z)
#define fpi(x,y,z) for(int i=(int)x;i<=(int)y;i+=(int)z)  
#define fpj(x,y,z) for(int j=(int)x;j<=(int)y;j+=(int)z)
#define fpk(x,y,z) for(int k=(int)x;k<=(int)y;k+=(int)z)  
#define fnk(x,y,z) for(int k=(int)x;k>=(int)y;k-=(int)z)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define rev(a) reverse(a.begin(),a.end())
const int inf = 100000000000000000;
#define maxn 100005
#define mod 998244353
std::vector<int> v[maxn];
int modexp(int x,int y) 
{ 
    int res = 1;
    x = x % mod; 
    while (y > 0) 
    {
        if (y & 1LL) 
            res = (res*x) % mod; 
        y = y>>1;
        x = (x*x) % mod;   
    } 
    return res; 
} 
void add_edge(int u1,int v1)
{
    v[u1].pb(v1);
    v[v1].pb(u1);
}
int ask(int u,int v)
{
    d("? "<<u<<" "<<v)
    int t;
    cin>>t;
    return t;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////

int seg[4*maxn],p[maxn],q[maxn],seg1[4*maxn],lazy[4*maxn],lazy1[4*maxn];
int build(int id,int l,int r)
{
    if(r<l) return inf;
    if(l==r) {return seg[id] = p[l];}
    int mid = (l+r)/2;
    return seg[id] = min(build(2*id+1,l,mid),build(2*id+2,mid+1,r));
}
int update(int id,int l,int r,int ql,int qr,int val)
{
    if(lazy[id])
    {
        seg[id]+=lazy[id];
        if(l!=r)
        {
            lazy[id*2+1] += lazy[id];            
            lazy[id*2+2] += lazy[id];
        }
        lazy[id] = 0;
    }
    if(r<l) return inf;
    if(l>qr || r<ql) return seg[id];
    if(l>=ql && r<=qr)
    {
        seg[id]+=val;
        if(l!=r)
        {
            lazy[id*2+1] += val;            
            lazy[id*2+2] += val;
        }
        return seg[id];
    }
    int mid = (l+r)/2;
    return seg[id] = min(update(2*id+1,l,mid,ql,qr,val),update(2*id+2,mid+1,r,ql,qr,val));
}
int get(int id,int l,int r,int ql,int qr)
{
    if(lazy[id])
    {
        seg[id]+=lazy[id];
        if(l!=r)
        {
            lazy[id*2+1] += lazy[id];            
            lazy[id*2+2] += lazy[id];
        }
        lazy[id] = 0;
    }
    if(r<l) return inf;
    if(l>qr || r<ql) return inf;
    if(l>=ql && r<=qr) return seg[id];
    int mid = (l+r)/2;
    return min(get(2*id+1,l,mid,ql,qr),get(2*id+2,mid+1,r,ql,qr));
}
int build1(int id,int l,int r)
{
    if(r<l) return inf;
    if(l==r) {return seg1[id] = q[l];}
    int mid = (l+r)/2;
    return seg1[id] = min(build1(2*id+1,l,mid),build1(2*id+2,mid+1,r));
}
int update1(int id,int l,int r,int ql,int qr,int val)
{
    if(lazy1[id])
    {
        seg1[id]+=lazy1[id];
        if(l!=r)
        {
            lazy1[id*2+1] += lazy1[id];            
            lazy1[id*2+2] += lazy1[id];
        }
        lazy1[id] = 0;
    }
    if(r<l) return inf;
    if(l>qr || r<ql) return seg1[id];
    if(l>=ql && r<=qr)
    {
        seg1[id]+=val;
        if(l!=r)
        {
            lazy1[id*2+1] += val;            
            lazy1[id*2+2] += val;
        }
        return seg1[id];
    }
    int mid = (l+r)/2;
    return seg1[id] = min(update1(2*id+1,l,mid,ql,qr,val),update1(2*id+2,mid+1,r,ql,qr,val));
}
int get1(int id,int l,int r,int ql,int qr)
{
    if(lazy1[id])
    {
        seg1[id]+=lazy1[id];
        if(l!=r)
        {
            lazy1[id*2+1] += lazy1[id];            
            lazy1[id*2+2] += lazy1[id];
        }
        lazy1[id] = 0;
    }
    if(r<l) return inf;
    if(l>qr || r<ql) return inf;
    if(l>=ql && r<=qr) return seg1[id];
    int mid = (l+r)/2;
    return min(get1(2*id+1,l,mid,ql,qr),get1(2*id+2,mid+1,r,ql,qr));
}
void solve()
{
    fpi(0,4*maxn-1,1) seg[i] = seg1[i] = lazy[i] = lazy1[i] = 0;
    fpi(0,maxn-1,1) p[i] = q[i] = 0;
    int n,q1;
    cin>>n>>q1;
    int b[n+1],tot = 0;
    fpi(1,n,1) cin>>b[i];
    p[0] = 0;
    fpi(1,n,1) {p[i] = p[i-1] + b[i];tot+=b[i];}
    q[n+1] = 0;
    fni(n,1,1) q[i] = q[i+1] + b[i];
    build(0,0,n);
    build1(0,1,n+1);
    //pa(q,n+1,1);
    fpi(1,q1,1)
    {
        char c;int l,r;
        cin>>c>>l>>r;
        if(c=='Q')
        {
            //d(get(0,0,n,0,l-1))
            //d(get1(0,1,n+1,r+1,n+1))
            d(tot-get(0,0,n,0,l-1)-get1(0,1,n+1,r+1,n+1))
        }
        else
        {
            update(0,0,n,l,n,r-b[l]);
            update1(0,1,n+1,1,l,r-b[l]);
            //fpj(0,n,1) cout<<get(0,0,n,j,j)<<" ";
            //cout<<endl;
            tot-=b[l];
            tot+=r;
            b[l]=r;
        }
    }
}
int32_t main()
{
    IOS;
    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    #endif
    int t=1;
    cin>>t;
    while(t--) solve();
    // p[0] = 0;p[1] = 1;p[2] = 2;
    // q[0] = 0;q[1] = 1;q[2] = 2;
    // build1(0,0,2);
    // update1(0,0,2,1,2,-1);
    // d(get1(0,0,2,1,2))
    #ifndef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
}
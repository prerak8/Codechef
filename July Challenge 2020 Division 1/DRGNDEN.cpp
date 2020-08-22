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
#define rev(a) reverse(a.begin(),a.en())
const int inf = (int)10e12;
#define maxn 200005
const int mod = 1000000007;
int segf[4*maxn],segb[4*maxn],segh[4*maxn],dpf[maxn],dpb[maxn],nextf[maxn],nextb[maxn],a[maxn],h[maxn];
int n,q;
int lazyf[4*maxn],lazyb[4*maxn];

void updateRange(int node, int start, int end, int l, int r, int val,int* tree,int* lazy)
{
    if(lazy[node] != 0)
    {
        tree[node] += (end - start + 1) * lazy[node];
        if(start != end)
        {
            lazy[node*2] += lazy[node];                  
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;                             
    }
    if(start > end or start > r or end < l)              
        return;
    if(start >= l and end <= r)
    {
        // Segment is fully within range
        tree[node] += (end - start + 1) * val;
        if(start != end)
        {
            // Not leaf node
            lazy[node*2] += val;
            lazy[node*2+1] += val;
        }
        return;
    }
    int mid = (start + end) / 2;
    updateRange(node*2, start, mid, l, r, val,tree,lazy);        // Updating left child
    updateRange(node*2 + 1, mid + 1, end, l, r, val,tree,lazy);   // Updating right child
    tree[node] = tree[node*2] + tree[node*2+1];        // Updating root with max value 
}
int queryRange(int node, int start, int end, int l, int r,int* tree,int* lazy)
{
    if(start > end or start > r or end < l)
        return 0;         // Out of range
    if(lazy[node] != 0)
    {
        // This node needs to be updated
        tree[node] += (end - start + 1) * lazy[node];            // Update it
        if(start != end)
        {
            lazy[node*2] += lazy[node];         // Mark child as lazy
            lazy[node*2+1] += lazy[node];    // Mark child as lazy
        }
        lazy[node] = 0;                 // Reset it
    }
    if(start >= l and end <= r)             // Current segment is totally within range [l, r]
        return tree[node];
    int mid = (start + end) / 2;
    int p1 = queryRange(node*2, start, mid, l, r,tree,lazy);         // Query left child
    int p2 = queryRange(node*2 + 1, mid + 1, end, l, r,tree,lazy); // Query right child
    return (p1 + p2);
}

void buildheight(int node, int start, int end,int* tree)
{
    if(start == end)
    {
        tree[node] = h[start];
    }
    else
    {
        int mid = (start + end) / 2;
        // Recurse on the left child
        buildheight(2*node, start, mid,tree);
        // Recurse on the right child
        buildheight(2*node+1, mid+1, end,tree);
        // Internal node will have the sum of both of its children
        tree[node] = max(tree[2*node],tree[2*node+1]);
    }
}
int queryRangeheight(int node, int start, int end, int l, int r,int* tree)
{
    if(start > end or start > r or end < l)
        return 0;         // Out of range
    if(start >= l and end <= r)             // Current segment is totally within range [l, r]
        return tree[node];
    int mid = (start + end) / 2;
    int p1 = queryRangeheight(node*2, start, mid, l, r,tree);         // Query left child
    int p2 = queryRangeheight(node*2 + 1, mid + 1, end, l, r,tree); // Query right child
    return max(p1,p2);
}

int getdpf(int n1)
{
    return queryRange(1,1,n,n1,n1,segf,lazyf) + dpf[n1];
}

int getdpb(int n1)
{
    return queryRange(1,1,n,n1,n1,segb,lazyb) + dpb[n1];
}

int geth(int l ,int r)
{
    if(l>r) swap(l,r);
    l++;
    r--;
    if(l>r) return 0;
    return queryRangeheight(1,1,n,l,r,segh);
}
void build()
{
    buildheight(1,1,n,segh);
    dpf[n] = a[n];
    stack<int> s;
    s.push(n);
    fni(n-1,1,1)
    {
        while(!s.empty() && h[i]>=h[s.top()]) s.pop();
        if(s.empty())
        {
            dpf[i] = a[i]; 
        }
        else
        {
            dpf[i] = dpf[s.top()] + a[i];
        }
        s.push(i);
    }
    while(!s.empty()) s.pop();
    dpb[1] = a[1];
    s.push(1);
    fpi(2,n,1)
    {
        while(!s.empty() && h[i]>=h[s.top()]) s.pop();
        if(s.empty())
        {
            dpb[i] = a[i]; 
        }
        else
        {
            dpb[i] = dpb[s.top()] + a[i];
        }
        s.push(i);
    }

    while(!s.empty()) s.pop();

    nextf[n] = n+1;
    s.push(n);
    fni(n-1,1,1)
    {
        while(!s.empty() && h[i]>h[s.top()]) s.pop();
        if(s.empty())
        {
            nextf[i] = n+1; 
        }
        else
        {
            nextf[i] = s.top();
        }
        s.push(i);
    }

    while(!s.empty()) s.pop();

    nextb[1] = 0;
    s.push(1);
    fpi(2,n,1)
    {
        while(!s.empty() && h[i]>h[s.top()]) s.pop();
        if(s.empty())
        {
            nextb[i] = 0; 
        }
        else
        {
            nextb[i] = s.top();
        }
        s.push(i);
    }
  
}
void solve()
{
    cin>>n>>q;
    fpi(1,n,1) cin>>h[i];
    fpi(1,n,1) cin>>a[i];
    build();
    fpi(1,q,1)
    {
        char c;int aw,bw;
        cin>>c>>aw>>bw;
        if(c=='1')
        {
            int t1 = nextb[aw];
            updateRange(1,1,n,t1+1,aw,bw-a[aw],segf,lazyf);
            int t2 = nextf[aw];
            updateRange(1,1,n,aw,t2-1,bw-a[aw],segb,lazyb);
            a[aw] = bw;
            // fpi(1,n,1) cout<<getdpf(i)<<" ";
            // cout<<endl;
            // fpi(1,n,1) cout<<getdpb(i)<<" ";
            // cout<<endl;
            // fpi(1,n,1) cout<<a[i]<<" ";
            // cout<<endl;
        }
        else
        {
            if(aw==bw)
            {
                d(a[aw])
                continue;
            }
            int mh = geth(aw,bw);
            //d(mh<<h[aw]<<" "<<h[bw])
            if(h[aw]<=h[bw] || mh>=h[aw])
            {
                d(-1)
                continue;
            }
            else
            {
                if(aw>=bw)
                {
                    d(getdpf(bw)-getdpf(aw)+a[aw])
                }
                else
                {
                    d(getdpb(bw)-getdpb(aw)+a[aw])
                }
            }
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
    //cin>>t;
    while(t--) solve();
    #ifndef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
}
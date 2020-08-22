#include <bits/stdc++.h>
using namespace std;
 
const int MAXN = 100005;
const int mod = 1000000007;
const int MAXM = 100005;
const int MAXA = 1000005;
const int LN = 19;
 
int N, M, K, cur, A[MAXN], LVL[MAXN], DP[LN][MAXN];
int BL[MAXN << 1], ID[MAXN << 1], VAL[MAXN], ANS[MAXM];
int d[MAXN], l[MAXN], r[MAXN];
bool VIS[MAXN];
vector < int > adjList[MAXN];
 
struct query{
	int id, l, r, lc;
	bool operator < (const query& rhs){
		return (BL[l] == BL[rhs.l]) ? (r < rhs.r) : (BL[l] < BL[rhs.l]);
	}
}Q[MAXM];
 
int pr[MAXA],cons[MAXA];pair<int,int> factors[MAXA][10];
int inv[MAXA<<1];
int modexp(long long int x,int y) 
{ 
    long long int res = 1;
    x = x % mod; 
    if (x == 0) return 0;
    while (y > 0) 
    {
        if (y & 1LL) 
            res = (res*x) % mod; 
        y = y>>1;
        x = (x*x) % mod;   
    } 
    return res; 
} 
int invmod(int p1)
{
    return modexp(p1,mod-2);
}

// Set up Stuff
void dfs(int u, int par){
	l[u] = ++cur; 
	ID[cur] = u;
	for (int i = 1; i < LN; i++) DP[i][u] = DP[i - 1][DP[i - 1][u]];
	for (int i = 0; i < adjList[u].size(); i++){
		int v = adjList[u][i];
		if (v == par) continue;
		LVL[v] = LVL[u] + 1;
		DP[0][v] = u;
		dfs(v, u);
	}
	r[u] = ++cur; ID[cur] = u;
}
 
// Function returns lca of (u) and (v)
inline int lca(int u, int v){
	if (LVL[u] > LVL[v]) swap(u, v);
	for (int i = LN - 1; i >= 0; i--)
		if (LVL[v] - (1 << i) >= LVL[u]) v = DP[i][v];
	if (u == v) return u;
	for (int i = LN - 1; i >= 0; i--){
		if (DP[i][u] != DP[i][v]){
			u = DP[i][u];
			v = DP[i][v];
		}
	}
	return DP[0][u];
}
 
inline void check(int x, long long& res){
	int val = A[x];
	if(VIS[x])
	{
		for(int i = 0;i<10;i++)
		{
			pair<int,int> t1 = factors[val][i];
			if(t1.first)
			{
				res*=inv[cons[t1.first]+1];
				res%=mod;
				cons[t1.first]-=t1.second;
				res*=(cons[t1.first]+1);
				res%=mod;
			}
			else break;
		}
		VIS[x] = 0;
	}
	else
	{
		for(int i = 0;i<10;i++)
		{
			pair<int,int> t1 = factors[val][i];
			if(t1.first)
			{
				res*=inv[cons[t1.first]+1];
				res%=mod;
				cons[t1.first]+=t1.second;
				res*=(cons[t1.first]+1);
				res%=mod;
			}
			else break;
		}
		VIS[x] = 1;
	}
}
 
void compute(){
 
	int curL = Q[0].l, curR = Q[0].l - 1;long long res = 1;
 
	for (int i = 0; i < M; i++){
		while (curL < Q[i].l) check(ID[curL++], res);
		while (curL > Q[i].l) check(ID[--curL], res);
		while (curR < Q[i].r) check(ID[++curR], res);
		while (curR > Q[i].r) check(ID[curR--], res);
 
		int u = ID[curL], v = ID[curR];
 
		// Case 2
		if (Q[i].lc != u and Q[i].lc != v) check(Q[i].lc, res);
 
		ANS[Q[i].id] = res;
 
		if (Q[i].lc != u and Q[i].lc != v) check(Q[i].lc, res);
	}
	for (int i = 0; i < M; i++) printf("%d\n", ANS[i]);
}
 
int main(){
	#ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    #endif
    pr[1] = 1;
	for(int i = 2;i<=1000000;i++) pr[i] = i;
	for(int i = 4;i<=1000000;i+=2) pr[i] = 2;
	for(int i = 3;i*i<=1000000;i++)
	{
		if(pr[i]==i) for(int j = i*i;j<=1000000;j+=i) if(pr[j]==j) pr[j] = i;
	}
	
	for(int i = 2;i<=1000000;i++)
	{
		int temp = i,t1,cou = 0;
		while(temp>1)
		{
			t1 = pr[temp];
			if(factors[i][cou].first==0)
			{
				factors[i][cou].first = t1;
				factors[i][cou].second = 1;
			}
			else if(factors[i][cou].first==t1) factors[i][cou].second++;
			else
			{
				cou++;
				factors[i][cou].first = t1;
				factors[i][cou].second = 1;
			}
			temp/=t1;
		}
	}
	inv[1] = 1;
	for(int i = 2;i<=2000000;i++)
	{
		inv[i] = invmod(i);
	}
 	int t;
 	int u, v, x;
	scanf("%d", &t);
	while (t--){
		scanf("%d\n", &N);
		cur = 0;
		memset(cons, 0, sizeof(cons));
		memset(VIS, 0, sizeof(VIS));
		memset(VAL, 0, sizeof(VAL));
		for (int i = 1; i <= N; i++) adjList[i].clear();

		for (int i = 1; i < N; i++){
			scanf("%d %d", &u, &v);
			adjList[u].push_back(v);
			adjList[v].push_back(u);
		}

		// Inputting Values
		for (int i = 1; i <= N; i++) scanf("%d", &A[i]);
		scanf("%d\n", &M);
		// Preprocess
		DP[0][1] = 1;
		dfs(1, -1);
		int size = 1000;

		for (int i = 1; i <= cur; i++) BL[i] = (i - 1) / size + 1;

		for (int i = 0; i < M; i++){
			scanf("%d %d", &u, &v);
			Q[i].lc = lca(u, v);
			if (l[u] > l[v]) swap(u, v);
			if (Q[i].lc == u) Q[i].l = l[u], Q[i].r = l[v];
			else Q[i].l = r[u], Q[i].r = l[v];
			Q[i].id = i;
		}

		sort(Q, Q + M);
		compute();
	}
}
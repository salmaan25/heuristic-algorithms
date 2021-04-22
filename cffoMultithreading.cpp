#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <fstream>
#include <chrono>


#include <array>
#include <climits>
#include <functional>
#include <memory>
#include <numeric>
#include <stack>
#include <pthread.h>

#include <unistd.h>
#include <cctype>
#include <type_traits>
using namespace std;
using namespace std::chrono;

#define int long long
#define all(x) (x).begin(), (x).end()
int powmod(int a,int l, int md){int res=1;while(l){if(l&1)res=res*a%md;l/=2;a=a*a%md;}return res;}
typedef long long ll; typedef vector<ll> vi; typedef pair<ll, ll> ii; typedef vector<ii> vii;
#define pb push_back
clock_t time_p=clock();
void time()
{
    time_p=clock()-time_p;
    cerr<<"Time Taken : "<<(float)(time_p)/CLOCKS_PER_SEC<<"\n";
}
long double e = 2.718281828459045235360287471352662497757247093699959574966967627724076630353;
//describe problem i.e y,g,p;
int p = 1009;
int g = 11;
int y = 337;
int threadcnt = 20;

//compare with obtained value
int correct_x=784;


//define parameters
long double alpha=0.6;
long double beta0=1.0;
long double gama=0.01;
long double mue=4.0;
int S=p-2;

long double alphat=alpha;
long double gamat=gama;

//check and change value;
int iter = 7500;
int n = 1000;

class data {
public:
	int l,r;
	data(int _l, int _r) {
		l = _l, r = _r;
	}
};
int f(int x) {
	int h = (y-powmod(g,x,p))%p;
	if(h < 0) h = (p-h)%p;
	return h;
}

long double beta(int r2) {
	return beta0*powl(e,-1*gamat*r2);
}

long double generate() {
	srand(time(0));
    int rnd=rand();
    if(rnd==RAND_MAX) rnd--;
    return (long double)rnd/(RAND_MAX);
}

long double nalpha(long double alphat) {
	return mue*alphat*(1.0-alphat);
}

long double ngama(long double gamat) {
	return mue*gamat*(1.0-gamat);
}

int ac=correct_x;
vi f_v;
vi x_v;
vector<long double> random1;
int mx;
int ind;
set<int> ans;
int hits;
int nmx;
int nind;
int x_best;

void* solve(void* da) {
	data* dd = (data *)da;
	for(int i = dd->l; i <= dd->r; i++) {
		if(f_v[i] == mx) continue;
		int d=x_v[ind]-x_v[i];
		long double attr = beta(d*d);
		int n_x=(int)((long double)x_v[i]+alphat*(long double)S*(random1[i]-(long double)0.5)+attr*((long double)d));
		if(n_x >= 0 && n_x < p-1) 
			x_v[i]=n_x;
		else {
			x_v[i]=rand()%p;
			if(x_v[i]==p-1) x_v[i]--;
		}
		if(powmod(g,x_v[i],p)==y) {
			ans.insert(x_v[i]);
			hits++;
		}
		f_v[i]=f(x_v[i]);
		if(mx < f_v[i]) {
			nmx=f_v[i];
			nind=i;
		}
	}
	return NULL;
}
int32_t main(void)
{
	//timer start
	auto start = high_resolution_clock::now();
	f_v.assign(n,0);
	x_v.assign(n,0);
	srand(time(0));
	for(int i = 0; i < n; i++) {
		x_v[i]=rand()%p;
		if(x_v[i]==p-1) x_v[i]--;
	}
	for(int i = 0; i < n; i++) {
		f_v[i]=f(x_v[i]);
	}
	mx = *max_element(all(f_v));
	ind = max_element(all(f_v))-f_v.begin();
	random1.assign(n,0.0);
	for(int i = 0; i < n; i++)
		random1[i]=generate();
	hits=0;
	while(iter--) {
		nmx=mx;
		nind=ind;
		x_best = x_v[ind];

		pthread_t pt[threadcnt];
		int eltCnt = n/threadcnt;
		int l = 0;
		for(int i = 0; i < threadcnt; i++) {
			int lo = l, hi = l+eltCnt-1;
			if(i == threadcnt-1)
				hi = n-1;
			data* d = new data(lo,hi);
			pthread_create(&pt[i], NULL, solve, d);
			l = hi+1;
		}
		for(int i = 0; i < threadcnt; i++) {
			pthread_join(pt[i],NULL);
		}
		mx=nmx;
		ind=nind;
		alphat=nalpha(alphat);
		gamat=ngama(gamat);
	}
	if(ans.size() > 0)
		cout<<"x = "<<*ans.begin()<<endl;
	else
		cout<<"No hits"<<endl;
	//timer end
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
  
    cout << duration.count()/1000000.0 << " seconds" << endl;
	// cout<<ans.size()<<endl;
	// for(auto i: ans) cout<<i<<" cx ";
	// 	cout<<endl;
	// cout<<hits<<endl;
	// cout<<powmod(g,*ans.begin(),p)<<endl;
	// time();
	return 0;
}

// 25-QWE-uo
#include <bits/stdc++.h>
using namespace std;
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
int p = 10486717;
int g = 7;
int y = 546423;

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

int32_t main(void)
{
	int ac=correct_x;
	vi f_v(n);
	vi x_v(n);
	srand(time(0));
	for(int i = 0; i < n; i++) {
		x_v[i]=rand()%p;
		if(x_v[i]==p-1) x_v[i]--;
	}
	for(int i = 0; i < n; i++) {
		f_v[i]=f(x_v[i]);
	}
	int mx = *max_element(all(f_v));
	int ind = max_element(all(f_v))-f_v.begin();
	long double random[n];
	for(int i = 0; i < n; i++)
		random[i]=generate();
	set<int> ans;
	int hits=0;
	while(iter--) {
		int nmx=mx;
		int nind=ind;
		int x_best = x_v[ind];
		for(int i = 0; i < n; i++) {
			if(f_v[i] == mx) continue;
			int d=x_v[ind]-x_v[i];
			long double attr = beta(d*d);
			int n_x=(int)((long double)x_v[i]+alphat*(long double)S*(random[i]-(long double)0.5)+attr*((long double)d));
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
		mx=nmx;
		ind=nind;
		alphat=nalpha(alphat);
		gamat=ngama(gamat);
	}
	cout<<ans.size()<<endl;
	for(auto i: ans) cout<<i<<" ";
		cout<<endl;
	cout<<hits<<endl;
	time();	
	return 0;
}
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


int N = 679213116511;
int p; //equal to sqrt(N);

//compare with obtained value
int correct_x=784;


//define parameters
long double alpha=0.6;//0.6;
long double beta0=1.0;//1.0;
long double gama=0.6;//0.01;
long double mue=4.0;//4.0;
int S;

long double alphat=alpha;
long double gamat=gama;

//check and change value;
int iter = 7500;
int n = 1000;

int f(int x) {
	return N%x;
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
	IOS;
	int ac=correct_x;
	p=(int)sqrt(N)+1;
	S=p-2;
	cout<<p<<endl;
	vi f_v(n);
	vi x_v(n);
	srand(time(0));
	for(int i = 0; i < n; i++) {
		int tp = rand()%p+1;
		while(tp==1 || tp==0)
			tp = rand()%p+1;
		x_v[i]=tp;
	}
	//compute(f_v, x_v);
	for(int i = 0; i < n; i++) {
		f_v[i]=f(x_v[i]);
	}
	int mx = *min_element(all(f_v));
	int ind = min_element(all(f_v))-f_v.begin();
	long double random[n];
	for(int i = 0; i < n; i++)
		random[i]=generate();
	int ans=-1;
	int hits=0;
	while(iter--) {
		int nmx=mx;
		int nind=ind;
		int x_best = x_v[ind];
		if(f_v[nind]==0) {
			ans=x_best;
		}
		for(int i = 0; i < n; i++) {
			if(f_v[i] == mx) continue;
			int d=x_v[ind]-x_v[i];
			long double attr = beta(d*d);
			int n_x=(int)((long double)x_v[i]+alphat*(long double)S*(random[i]-(long double)0.5)+attr*((long double)d));
			if(n_x >= 2 && n_x < p) 
				x_v[i]=n_x;
			else {
				int tp = rand()%p+1;
				while(tp==1 || tp==0)
					tp = rand()%p+1;
				x_v[i]=tp;
			}
				// check if new f is more than previous f 
			f_v[i]=f(x_v[i]);
			if(mx > f_v[i]) {
				nmx=f_v[i];
				nind=i;
			}
		}
		mx=nmx;
		ind=nind;
		alphat=nalpha(alphat);
		gamat=ngama(gamat);
	}
	if(ans==-1) {
		cout<<"ANSWER NOT FOUND"<<endl;
	} else {
		cout<<ans<<" "<<N/ans<<endl;
	}
	time();	
	return 0;
}
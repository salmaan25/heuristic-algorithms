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
// 10171165997
// 35

double EPS=1e-9;
const int N =60000; //wolf count;
int num=100673690842303; //change
int SC = 995; //sqrt(num);
int ITER = 400;
vi wolves(N);
double a,r21,r22,r23;
int alpha, beta, gama;
int f(int x) {
	return num%x;
}
double rnd() {
	return ((double)rand())/RAND_MAX;
}
double cha(double a) { //values between [1,2] CHANGE THIS
	// return a;
	a-=1.0;
	if(fabs(a-0.7) < EPS || a > 0.7)
		a=((double)10/3)*(1.0-a); 
	else
		a=a/0.7;
	return 1.0+a;
}
double chr2(double r2) { //value between [0,1] CHANGE THIS
	if(fabs(r2-0.7) < EPS || r2 > 0.7)
		r2=((double)10/3)*(1.0-r2); 
	else
		r2=r2/0.7;
	return r2;
}
signed main(void)
{
	// IOS;
	srand(time(0));
	SC=(int)sqrt(num)+1;
	cout<<SC<<endl;
	for(int i = 0; i < N; i++) {
		int tp = rand()%SC+1;
		while(tp==1)
			tp = rand()%SC+1;
		wolves[i]=tp;
	}
	a=2.0,r21=rnd(),r22=rand(),r23=rand();	
	int ans=-1;
	vi tpppppppppppppppppppppp;
	for(int itt = 0; itt < ITER; itt++) {
		// for(int i = 0; i < N; i++)
		// 	cout<<wolves[i]<<" ";
		// cout<<endl;
		vi NN(N,0);
		a=cha(a),r21=chr2(r21),r22=chr2(r22),r23=chr2(r23);
		vii tmp(N);
		for(int i = 0; i < N; i++) {
			tmp[i]={f(wolves[i]), i};
		}
		sort(all(tmp));
		alpha = tmp[0].ss, beta = tmp[1].ss, gama = tmp[2].ss;
		if(tmp[0].ff==0) {
			ans=wolves[alpha];
		}
		// for(int i = 0; i < N; i++) {
		// 	cout<<tmp[i].ff<<" ";
		// 	if(tmp[i].ff==0) {
		// 		tpppppppppppppppppppppp.pb(wolves[]);
		// 	}
		// }
		// cout<<endl;
		for(int i = 0; i < N; i++) {
			if(i==alpha || i==beta || i==gama) {
				NN[i]=wolves[i];
				continue;
			}
			double X=wolves[i];
			double X_alpha=wolves[alpha], X_beta=wolves[beta], X_gama=wolves[gama];
			double C1,C2,C3,D_alpha,D_beta,D_gama,A1,A2,A3;
			double X1,X2,X3;
			C1=2.0*r21,C2=2.0*r23,C3=2.0*r23;
			A1=2.0*a*rnd()-a,A2=2.0*a*rnd()-a,A3=2.0*a*rnd()-a;
			D_alpha=fabs(C1*X_alpha-X),D_beta=fabs(C2*X_beta-X),D_gama=fabs(C3*X_gama-X);
			X1=X_alpha-A1*D_alpha,X2=X_beta-A2*D_beta,X3=X_gama-A3*D_gama;
			NN[i]=(int)((X1+X2+X3)/3);
			if(NN[i] > SC || NN[i] < 2) {
				int tp = rand()%SC+1;
				while(tp==1)
					tp = rand()%SC+1;
				NN[i]=tp;
			}
		}
		for(int i = 0; i < N; i++) {
			wolves[i]=NN[i];
		}
	}
	if(ans==-1) cout<<"ANSWER NOT FOUND"<<endl;
	else cout<<ans<<" "<<num/ans<<endl;
	time();
	return 0;
}
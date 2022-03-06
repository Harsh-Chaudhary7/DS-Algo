#include<bits/stdc++.h>
#include<math.h>
#include<cmath>
using namespace std;

// Template

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define Harsh_Chaudhary std::ios::sync_with_stdio(false);
#define H_C std::cin.tie(nullptr);

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

typedef long long int              	ll;
typedef vector<int>                	vi;
typedef vector<ll>                 	vl;
typedef vector<vector<int>>        	vvi;
typedef pair<int, int>             	pi;
typedef vector<pair<int, int>>      vpi;
typedef vector<pair<ll, ll>>        vpl;
typedef unordered_map<int, int>		umi;
typedef unordered_map<char, int>	ums;
typedef map<int, char>				ms;
typedef map<int, int>				mi;

#define sz(x)                      	((int)(x).size()) //never forget to type into int
#define inp(a, n)                  	for(int Ele=0; Ele<(n); Ele++)std::cin>>a[Ele]
#define inpv(a, n)                  for(int Ele=0; Ele<(n); Ele++){int val;cin>>val;a.push_back(val);}
#define inps(a, n, sum)             for(int Ele=0; Ele<(n); Ele++){std::cin>>a[Ele]; sum += a[Ele];}
#define out(a, n)                  	for(int Ele=0; Ele<(n); Ele++)std::cout<<a[Ele]<<endl
#define inp1(a, n)                 	for(int Ele=1; Ele<=(n); Ele++)cin>>a[Ele]
#define FOR(i, a, b) 			   	for (int i = a; i < (b); i++)
#define F0R(i, a) 				   	for (int i = 0; i < (a); i++)
#define set_bits(n)                	__builtin_popcountll(n)
#define max(a, b)                  	(a < b ? b : a)
#define min3(a, b, c)               ((a<b)?(a<c)? a :c :(b<c)? b: c)
#define min(a, b)                  	((a > b) ? b : a)
#define kick(x)                    	cout << "Case #" << x << ": ";



#define INF                        	1e18
#define lb                         	lower_bound
#define ub                         	upper_bound
#define min_element                	*min_element
#define max_element                	*max_element
#define pb 							push_back
#define ll long long
#define rr return

#define mod                       (in1e9+7
#define mem(x,i) memset((x),(i),sizeof((x)))

// Template


void solve() {
	int n;
	cin >> n;

	vi a(n);
	for (int &i : a)
		cin >> i;

	int l = 0, mid = 0, h = n - 1;
	while (mid <= h) {
		if (a[mid] == 0)
			swap(a[l++], a[mid++]);
		else if (a[mid] == 1)
			mid++;
		else
			swap(a[mid], a[h--]);
	}

	for (int val : a)
		cout << val << " ";
	cout << endl;

}

int main() {
	fast_io
	Harsh_Chaudhary
	H_C
	// ll t;
	// cin >> t;
	// while (t--)
	solve();

	return 0;
}

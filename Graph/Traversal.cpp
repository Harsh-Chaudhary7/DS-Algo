#include<bits/stdc++.h>
using namespace std;

int main() {
	string s1 = "cdeeelt", s2 = "acost";
	string t1 = "", t2 = "";
	t1 = s1 - s2;
	t2 = s2 - s1;
	cout << t1 << " " << t2;
	return 0;
}
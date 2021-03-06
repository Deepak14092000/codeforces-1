/*input
we consider all primes from 3 to N/2. It is clear that primes > N/2 won't be matched.
For all such primes we find number of unmatched numbers that have p as the divisor.
Count such numbers. If it is even we can match all. Else we have to leave out one number. Which one? We can leave out 2*P and then match the rest
Now all even numbers can be matched if they are even in number. Else we have to leave out one number. which one? any one doesnt matter here
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long int

const int MAXN = 100005;

bool primes[MAXN];

vector<int>p;

bool used[MAXN];

void sieve(){
	ll i, j;
	for(i = 0; i < MAXN; ++i)
		primes[i] = true;
	primes[0] = primes[1] = false;
	for(i = 2; i < MAXN; ++i){
		if(primes[i]){
			for(j = i*i; j < MAXN; j += i){
				primes[j] = false;
			}
		}
	}	
	return;
}

int main(){

	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, i, j, temp;
		
	vector<pair<int,int>>ans;

	sieve();

	cin >> n;

	for(i = 3; i <= n/2; ++i){
		if(primes[i])
			p.push_back(i);
	}

	set<int>rem2;
	vector<int>rem;
	

	for(i = 2; i <= n; ++i){
		if(i % 2 == 0)
			rem2.insert(i);
	}	

	for(auto it: p){
		vector<int>temp;
		for(j = it; j <= n; j += it){
			if(!used[j]){
				temp.push_back(j);
			}
		}
		if(temp.size() % 2 == 0){
			for(j = 0; j < temp.size(); j += 2){
				used[temp[j]] = used[temp[j+1]] = true;
				ans.push_back({temp[j], temp[j+1]});
			}
		}	
		else{
			rem2.insert(temp[1]);
			ans.push_back({temp[0], temp[2]});
			used[temp[0]] = used[temp[2]] = true;
			for(j = 3; j < temp.size(); j += 2){
				used[temp[j]] = used[temp[j+1]] = true;
				ans.push_back({temp[j], temp[j+1]});
			}
		}
	}

	for(auto it: rem2){
		if(!used[it])
			rem.push_back(it);
	}

	if(rem.size() % 2 != 0){
		rem.pop_back();
	}
	
	for(j = 0; j < rem.size(); j+=2){
		ans.push_back({rem[j], rem[j+1]});
	}

	cout << ans.size() << endl;
	for(auto it: ans){
		cout << it.first << " " << it.second << endl;
	}

	return 0;
}

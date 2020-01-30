#include <bits/stdc++.h>

using namespace std;

char maxVar;
int nVars;

vector<string> vars;
set<char> setVars;
int printed;

bool countVar(char var, vector<bool> taken) { //returns true if we can place var as next one

	for(int index = 0; index < (int)vars[var].size(); ++index) {
		if(!taken[vars[var][index]]) return false; 	
	}
	return true;
}

void dag(vector<bool> taken, string ans) {

	if((int)ans.size() == (int)nVars) {
		printed++;
		for(int i = 0; i < (int)ans.size(); ++i) {
			if(i < (int)ans.size()-1) cout << ans[i] << " ";
			else cout << ans[i] << endl;
		}
		return;
	}
 
	char c;
	for(c = 'A'; c <= 'Z'; ++c) {
		if(!taken[c] && setVars.count(c) > 0 && countVar(c, taken)) {
			taken[c] = true;
			dag(taken, ans+c);
			taken[c] = false;
		}
	} 
}

int main() {

	int TC;
	string line; 
	scanf("%d", &TC);
	getline(cin, line);
	
	while(TC--) {
		
		vars.clear();
		setVars.clear();

		getline(cin, line); //blank line
		getline(cin, line);
		maxVar = 'A';	
		nVars = 0;

		for(int i = 0; i < (int)line.size(); i+=2) {
			setVars.insert(line[i]);	
			maxVar = max(maxVar, line[i]);
			nVars++;
		}
		
		vars.resize((int)maxVar+5);			
		
		getline(cin, line);

		for(int i = 0; i < (int)line.size(); ++i) {
			if(line[i] == '<') {
				vars[line[i+1]] += line[i-1];
			}
		}	

		vector<bool> taken;
		taken.resize((int)maxVar+5, false);
		printed = 0;
		dag(taken, "");
		if(printed == 0) cout << "NO" << endl;
		cout << endl;
		
	}

	return 0;
}

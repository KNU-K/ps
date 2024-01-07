#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> KMP(string &text, string &pat) {
	vector<int> ans, fail(pat.size(), 0);
	for (int i = 1, match = 0; i<pat.size(); ++i) {
		while (match && pat[i] != pat[match])
			match = fail[match - 1];
		if (pat[i] == pat[match])
			fail[i] = ++match;
	}
	for (int i = 0, match = 0; i<text.size(); ++i) {
		while (match && text[i] != pat[match])match = fail[match - 1]; 
        if (text[i] == pat[match]) 
			if (++match == pat.size()) {
				ans.push_back(i - match + 1);
				match = fail[match - 1];
			}
	}
	return ans;
}

int main()
{
	string a, b;
	vector<int> c;

	getline(cin, a);
	getline(cin, b);

	c = KMP(a, b);

	cout << c.size() << '\n';
	for (vector<int>::size_type i = 0; i < c.size(); ++i)
	{
		cout << c[i] + 1<< ' ' ;
	}
	cout << endl;
}
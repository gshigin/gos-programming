#include<iostream>
#include<string>
#include <vector>
using namespace std;

int main() {
    string s, line;
	int len, l = 0, r = 0, i;

	cin >> len >> s;
	line = s;
	for (i = 0; i < len; i++)
		line[i] = s[len - 1 - i];
	s = s + line;

    int n =  s.size();
    vector <int> z (n);

    for (i = 1; i < n; i++) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            z[i]++;
       if (i + z[i] - 1 > r){
            l = i;
            r = i + z[i] - 1;
       }
    }

	for (i = z.size() - 1; i >= z.size()/2 ; i--)
       cout << z[i] << " ";

	return 0;
}
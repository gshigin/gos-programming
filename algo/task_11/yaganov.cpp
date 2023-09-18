#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <string>
using namespace std;
 
 
 
int main()
{
    string str;
    cin >> str;
    int N = str.length();
    vector <int> prefix_function (N);
    for(int i = 1; i < N; ++i)
    {
        int j = prefix_function[i-1];
        while(j > 0 && str[i] != str[j])
        {
            j = prefix_function[j-1];
        }
        if(str[i] == str[j]) ++j;
        prefix_function[i] = j;
    }
 
	for(int i = 0; i < prefix_function.size(); ++i)
	{
		cout << prefix_function[i] << ' ';
	}
	cout << endl;
    system("Pause");
    return 0;
}
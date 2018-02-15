#include<string>
#include<iostream>
using namespace std;
#include <vector>
void longest_palindrome(string s)
{
	string s1;
	s1.resize(s.length() * 2 + 3);
	s1[0] = '$';
	s1[1] = '#';

	for(size_t i =0; i < s.length(); i++)
	{
		s1[(i+1) << 1] = s[i];
		s1[((i+1)<<1) + 1] = '#';
	}
		
	s1[s1.length()-1] = '%';
	vector<int> p(s1.size(),0);

	int mx = 0,max_len = 1,id = 0;

	for(int i=1; i < (s1.length()); i++)
	{
		if (i < mx)
			p[i] = min(p[2*id-i],mx-i);
		else
			p[i] = 1;

		while (s1[i+p[i]] == s1[i-p[i]])
			p[i]++;

		if (i+p[i] > mx)
		{
			mx = i + p[i];
			id = i;
		}
		max_len = max(max_len,p[i] - 1);
	}

	cout << max_len<<endl;
}

int main()
{
	int num;
	string s;
	cin >> num;
	while (num--)
	{
		cin >> s;
		longest_palindrome(s);
	}
	return 0;
}
int a = 10;
double b = 100;
long x = g;

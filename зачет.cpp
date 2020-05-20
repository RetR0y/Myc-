#include <iostream>
#include <windows.h>
#include <vector>
#include <string.h>

int main()
{
	
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	const int base = 1000*1000*1000;
	vector<int> b;
	
	cout<<"������� ������ �����"<<endl;
	string s;
	cin>>s;
	
	for (int i=s.length(); i>0; i-=9)
	if (i < 9)
		a.push_back (atoi (s.substr (0, i).c_str()));
	else
		a.push_back (atoi (s.substr (i-9, 9).c_str()));

	cout<<"������� ������ �����"<<endl;
	cin>>s;
	for (int i=s.length(); i>0; i-=9)
	if (i < 9)
		b.push_back (atoi (s.substr (0, i).c_str()));
	else
		b.push_back (atoi (s.substr (i-9, 9).c_str()));
		
	vector<int> c (a.size()+b.size());
	for (size_t i=0; i<a.size(); ++i)
		for (int j=0, carry=0; j<(int)b.size() || carry; ++j)
		{
			long long cur = c[i+j] + a[i] * 1ll * (j < (int)b.size() ? b[j] : 0) + carry;
			carry = int (cur / base);
		}

	while (c.size() > 1 && c.back() == 0)
		c.pop_back();
		
	cout<<"��������� ��������� "<<endl;
	if(c.empty())
		printf("0");
		else 
		{
			printf("%d",c.back());
			
			for (int i=(int)c.size()-2; i>=0; --i)
				printf ("%09d", c[i]);
		}
	
	cout<<endl;
	system("pause");
	return 0;
}

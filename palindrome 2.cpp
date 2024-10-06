#include<iostream>
using namespace std;
bool chekingifpalindrome(int x)
{
if(x<0)return false;
int original=x ,reversed=0;
while(x!=0)
 {
int number= x % 10;
	reversed = reversed * 10 + number;
	x/=10;
 }
return original==reversed;
}
int main()
{
	int num;
	cout << "enter a number:";
	cin >> num;
	if(chekingifpalindrome(num))
	{
		cout<<num<<" is a palindrome."<<endl;
	}
	else{
		cout<<num<<" is  not a palindrome."<<endl;
	}
	return 0;
}

	
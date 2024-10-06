#include<iostream>
using namespace std;
bool is_palindrome(string characters)
{
	for(int i=0;i<characters.length()/2;i++)
		if(characters[i] !=characters[characters.length()-i-1])
			return false;
		
		return true;
}
int main()
{
	string characters;
	cout<<"enter a word:";
	cin>>characters;
	if(is_palindrome(characters))
		cout<<characters<<" is a palindrome."<<endl;
	else
	{
		cout<<characters<<" is not a palindrome'"<<endl;
	}
	return 0;
}
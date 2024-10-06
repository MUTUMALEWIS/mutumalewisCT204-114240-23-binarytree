#include <iostream>
using namespace std;
int main()
{
	int arry[]={1,2,3,3,4,5};
	int j=0;
	int w=6;
	for(int i=0;i<w-1;i++)
		{
		if(arry[i]!=arry[i+1])
		{
				arry[j++]=arry[i];
		}
	    }
	arry[j++]=arry[w-1];
		for(int i=0;i<w-1;i++)
		{
		cout<<arry[i]<<" ";
	}
	return 0;
	}

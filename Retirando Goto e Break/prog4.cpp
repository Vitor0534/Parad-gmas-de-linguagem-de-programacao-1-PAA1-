#include <iostream>
using namespace std;

int main()
{
		
	int j=-3,k=0;
	
	for(int i=0; ((i<3) && (k=0)) ;i++)
	{
		
		if((j+2)==3)
		{
	
		}
		else
		{
			if((j+2)==2)
				j--;
			else
			{
				if((j+2)==0)
					j+=2;
				else
				{
					j=0;
				}
			}
		}
		if(j>0) k=1;
		j=3-i;
				
	}
		
		cout<<j<<endl;
	
}

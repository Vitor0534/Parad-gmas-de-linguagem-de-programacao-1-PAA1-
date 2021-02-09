#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	int linhas1,colunas1,linhas2,colunas2;
	linhas1=linhas2=colunas1=colunas2=4;
	int mat1[4][4],mat2[4][4],resultado[linhas2][colunas1];
	int soma=0;
	
	if(linhas2==colunas1)
	{
			for(int i=0;i<=colunas1;i++)
          	{
          		
          		for(int j=0;j<=linhas2;j++)
				  {
				  	soma=0;
				  	for(int k=0;k<=linhas2;k++)
					  {
					  	cout<<"i: "<<i<<" j: "<<j<<" k: "<<k<<endl;
						   	soma+=mat1[j][k]*mat2[k][j];

						  
					  }
					  resultado[i][j]=soma;
					  
				 
				  	
				  }
		
		
		
         	}
         	
         	for(int i=0;i<=linhas2;i++)
         		for(int j=0;j<=colunas1;j++)
         			cout<<resultado[i][j]<<endl;
	
		
		
	}
    else
	{
		cout<<"erro numero de linhas e colunas diferentes"<<endl;
	}
	
	
	
	
	
	return 0;
}
#include <iostream>
#include <vector>
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
using namespace std;


// By Vitor de Almeida Silva


int verificaPeso(int peso[],int teste[],int tam)
{
	
	int soma=0;
	for(int i=0;i<tam;i++)
		soma+=peso[i]*teste[i];
	
	return soma;
	
}

void imprimeVetor(int vetor[],int tam)
{
	cout<<"[ ";
	for(int i=0;i<tam;i++)
	{
		cout<<vetor[i]<<" ";
	}
	cout<<"]"<<endl;
	
}

void imprimeVetorPesos(int vetor[],int pesos[],int tam)
{
	cout<<"[ ";
	for(int i=0;i<tam;i++)
	{
		cout<<vetor[i]*pesos[i]<<" ";
	}
	cout<<"]"<<endl;
	
}

//isto � um treino basico de algoritimo gen�tico
//este c�digo faz um crosing over e uma muta��o
//ambos sem seguir nem um crit�rio de realiza��o
//que n�o seja os pr�prios da a��o, ou seja, n�o foi aplicada
//probabilidade e estat�stica alguma


//obs: este algoritimo s� acha uma combina��o qualquer que somada os pesos resulta em
//um valor pr�ximo ou igual a capacidade da mochila. N�o foi seguide nem um crit�rio do tipo
//                     *Deve aver mais qtd de itens possivel;
//                     *Deve-se somar os menores ou maiores pesos primeiro;
//                     *etc...

int main()
{
   // vector<int> *lista=new vector<int>();
	
	int tam=20;
	
	srand(time(NULL));
	
	int vetorPesos[20]={5,10,14,9,3,1,7,60,8,10,1,23,22,12,1,100,1,7,8,4};
	//int vetorPesos[20]={1,1,1,1,1,1,1,2,2,2,2,1,1,2,2,2,3,3,4,4};
	
	int vetor1[tam],vetor2[tam];
	
	int maiorVetor[tam];
	
	int capacidade=300;

	int i=0,p;
	
	
	
	
	//pai e m�e inicial
	//int vetor1[20]={1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0};
	//int vetor2[20]={0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1};
	
	//preenchimento aleat�rio dos vet�res
	 for(int i=0;i<tam;i++)
	 {
	 	vetorPesos[i]=rand()%40;
	 	vetor1[i]=rand()%2;
	 	vetor2[i]=rand()%2;
	 }
	
	
	
	cout<<"vetor1"<<endl;
	   imprimeVetor(vetor1,tam);
	cout<<"peso inicial v1: "<<verificaPeso(vetorPesos,vetor1,tam)<<endl;
	
	cout<<"vetor2"<<endl;
    imprimeVetor(vetor2,tam);
    cout<<"peso inicial v2: "<<verificaPeso(vetorPesos,vetor2,tam)<<endl;
    
    imprimeVetor(vetor1,tam);
    imprimeVetor(vetor2,tam);

	//inicializa
	for(int i=0;i<tam;i++)
	   maiorVetor[i]=vetor1[i];
	
   
   int limite=100000;
   
	while(i<=limite)
	{
       //srand (time(NULL));
       p=rand()%tam;
       cout<<"P: "<<p<<endl;
       
       
       //realiza o crosing over   "cruzamento"
       for(int j=p;j<tam;j++)
	   {
	   	
	   	if(vetor1[j]!=vetor2[j])
		   {
		   	
		   	if(vetor1[j]==0)
		   		vetor1[j]=1;
		   	else 
		   		vetor1[j]=0;
		   	
		   	if(vetor2[j]==0)
		   		vetor2[j]=1;
		   	else 
		   		vetor2[j]=0;
		   	
		   }
	   }
	   //**************
	   
	   cout<<"vetor1"<<endl;
	   imprimeVetor(vetor1,tam);
	   cout<<"peso final v1:"<<verificaPeso(vetorPesos,vetor1,tam)<<endl<<endl;
	   
       //maiorVetor=vetor2;
       cout<<"vetor2"<<endl;
	   imprimeVetor(vetor2,tam);
	   cout<<"peso final v2:"<<verificaPeso(vetorPesos,vetor2,tam)<<endl<<endl;
	   
	   int peso1,peso2,pesoM;
	   
	   pesoM=verificaPeso(vetorPesos,maiorVetor,tam);
	   peso1=verificaPeso(vetorPesos,vetor1,tam);
	   peso2=verificaPeso(vetorPesos,vetor2,tam);
	   
	   
	   //motra pesos usados para pondera��o do resultado
	   cout<<"pesoM: "<<pesoM<<endl;
	   cout<<"peso1: "<<peso1<<endl;
	   cout<<"peso2: "<<peso2<<endl;
	   
	   
	   if((pesoM>capacidade) && peso1<capacidade)
	   {
	   	for(int i=0;i<tam;i++)
	            maiorVetor[i]=vetor1[i];
	   	
	   	
	   }
	   	 else
			{
				if((pesoM>capacidade) && peso2<capacidade)
	   	               for(int i=0;i<tam;i++)
	                        maiorVetor[i]=vetor2[i];
				
				
			}
	   	 	
	   
	   
	   if( (pesoM < peso2) && (peso2 <= capacidade))
		   {
		   	//lista->push_back(vetor2);
		   	//*maiorVetor=*vetor2;
		   	for(int i=0;i<tam;i++)
	            maiorVetor[i]=vetor2[i];
	        
		   	cout<<"entrei mV < 2"<<endl;
		   	
		   }
		  
		else{	   
           if( (pesoM < peso1) && (peso1 <=capacidade))
		   {
		   	//lista->push_back(vetor2);
		   	//*maiorVetor=*vetor1;
            for(int i=0;i<tam;i++)
	            maiorVetor[i]=vetor1[i];
		   	
		   	cout<<"entrei mV < 1"<<endl;
		   	
		   }
		   
		}  
			
		
		//ele para caso j� se tenha achado um resultado �timo
		if(pesoM==capacidade)
			break;
		
			
       //faz uma muta��o 
	   if(i==limite*0.5)
	   {
	   	int muta;
	    muta=rand()%tam;
	    
          cout<<"muta: "<<muta<<endl;
        
          for(int i=0;i<tam;i++)
	          vetor1[i]=maiorVetor[i];
	   	
	    if(vetor1[muta]==0)
	    	vetor1[muta]=1;
	    else
	    	vetor1[muta]=0;
	   	
	   }
	   
	   	   
	   
	   i++;	
		
	}
	
	imprimeVetor(maiorVetor,tam);
	cout<<"maior peso: "<<verificaPeso(vetorPesos,maiorVetor,tam)<<endl;
	
    imprimeVetorPesos(maiorVetor,vetorPesos,tam);
	
	
	
}


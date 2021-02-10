Autor: Vitor De Almeida Silva


Este � uma algor�tmo gen�tico para solucionar um problema de otimiza��o de uma empresa de venda de carros. 

//problema: uma pequena empresa de compra e venda de carros adiquiriu um terreno com o objetivo de 
//construir um p�tio e um galp�o para colocar os carros. O objetivo da empresa � realizar um evento onde 
//as pessoas poderiam ver os carros que est�o dentro do galp�o, ela quer colocar os carros de acordo com 
//o pre�o e a �rea ocupada, seguindo os seguintes crit�rios:
//             * o pre�o dos carros devem ser somados para se ter um pre�o total
//             * a soma das �reas ocupadas pelos veiculos n�o deve exeder o limite do galp�o exedido pela empresa (60 m^2)


O algor�tmo funciona de forma simplificada, realizando somente crossing over e uma muta��o aleat�ria que ocorre em tempo aleat�rio. O programa somente utiliza uma popula��o de 3 indiv�duos, sendo 2 pais e 1 que � o melhor individuo obtido a cada intera��o. o melhor individuo � selecionado a cada intera��o para realizar o crossing over com o segundo melhor indiv�duo na popula��o com o objetivo de objeter o resultado �timo. 
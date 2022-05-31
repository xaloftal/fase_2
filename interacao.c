#include "header.h"

job* inserirJ(job* inicio)
{
	int novoJob, novaOperacao = 0, novaMaquina, novoTempo, maisJ = 1, maisO = 1;

	novoJob = ultimoJob(inicio) + 1;
	
	printf("Job: %d", novoJob);

	do
	{
		novaOperacao = novaOperacao + 1;
		printf("\nOpera��o: %d", novaOperacao);

		do
		{
			printf("\nM�quina: ");
			scanf("%d", &novaMaquina);
			
			int verMaq = verificarMaqExistente(inicio, novoJob, novaOperacao, novaMaquina);

			while (novaMaquina > MAXMACHINE)
			{
				printf("\n\nA m�quina %d n�o existe. \nInsira outra m�quina: ", novaMaquina);
				scanf("%d", &novaMaquina);
			}

			while (verMaq == 1)
			{
				printf("\n\nA m�quina %d j� se encontra associada � opera��o %d. \nInsira outra m�quina: ", novaMaquina, novaOperacao);
				scanf("%d", &novaMaquina);
				verMaq = verificarMaqExistente(inicio, novoJob, novaOperacao, novaMaquina);
			}

			printf("Tempo de processamento: ");
			scanf("%d", &novoTempo);

			inicio = inserirJob(inicio, novoJob, novaOperacao, novaMaquina, novoTempo);

			printf("\n\n\nDeseja adicionar mais alguma m�quina � opera��o atual?\n1 - Sim; 0 - N�o\nOp��o: ");
			scanf("%d", &maisO);

			while (maisO != 0 && maisO != 1)
			{
				printf("\n\nOp��o inv�lida.\nQuer adicionar mais alguma m�quina � opera��o atual?\n1 - Sim; 0 - N�o\nOp��o: ");
				scanf("%d", &maisO);
			}

		} while (maisO == 1);

		printf("\n\n\nDeseja adicionar mais alguma opera��o ao job?\n1 - Sim ; 0 - N�o\nOp��o: ");
		scanf("%d", &maisJ);

		while (maisJ != 0 && maisJ != 1)
		{
			printf("\n\nOp��o inv�lida.\nQuer adicionar mais alguma opera��o ao job atual?\n1 - Sim; 0 - N�o\nOp��o: ");
			scanf("%d", &maisJ);
		}
	} while (maisJ == 1);

	pressione();
	return(inicio);
}

job* removerJ(job* lista)
{
	int jobRemover, mais = 1;

	do
	{
		printf("Job a remover: ");
		scanf("%d", &jobRemover);

		int ver = verificarJobExistente(lista, jobRemover);

		while (ver != 1)
		{
			printf("\n\nO job %d n�o existe na lista ligada.\nInsira um job v�lido para remover: ", jobRemover);
			scanf("%d", &jobRemover);
			ver = verificarJobExistente(lista, jobRemover);
		}

		lista = removerJob(lista, jobRemover); 
		//maneira de reduzir os n�meros dos jobs anteriores!!!!!
		lista = reduzirJob(lista, jobRemover);

		printf("Remover mais algum job?\n1 - Sim; 0 - N�o\nOP��o: ");
		scanf("%d", &mais);
	} 
	while (mais == 1);
	return lista;
}
#include "header.h"

job* inserirJ(job* inicio)
{
	int novoJob, novaOperacao = 0, novaMaquina, novoTempo, maisJ = 1, maisO = 1;

	novoJob = ultimoJob(inicio) + 1;
	
	printf("Job: %d", novoJob);

	do
	{
		novaOperacao = novaOperacao + 1;
		printf("\nOperação: %d", novaOperacao);

		do
		{
			printf("\nMáquina: ");
			scanf("%d", &novaMaquina);
			
			int verMaq = verificarMaqExistente(inicio, novoJob, novaOperacao, novaMaquina);

			while (novaMaquina > MAXMACHINE)
			{
				printf("\n\nA máquina %d não existe. \nInsira outra máquina: ", novaMaquina);
				scanf("%d", &novaMaquina);
			}

			while (verMaq == 1)
			{
				printf("\n\nA máquina %d já se encontra associada à operação %d. \nInsira outra máquina: ", novaMaquina, novaOperacao);
				scanf("%d", &novaMaquina);
				verMaq = verificarMaqExistente(inicio, novoJob, novaOperacao, novaMaquina);
			}

			printf("Tempo de processamento: ");
			scanf("%d", &novoTempo);

			inicio = inserirJob(inicio, novoJob, novaOperacao, novaMaquina, novoTempo);

			printf("\n\n\nDeseja adicionar mais alguma máquina à operação atual?\n1 - Sim; 0 - Não\nOpção: ");
			scanf("%d", &maisO);

			while (maisO != 0 && maisO != 1)
			{
				printf("\n\nOpção inválida.\nQuer adicionar mais alguma máquina à operação atual?\n1 - Sim; 0 - Não\nOpção: ");
				scanf("%d", &maisO);
			}

		} while (maisO == 1);

		printf("\n\n\nDeseja adicionar mais alguma operação ao job?\n1 - Sim ; 0 - Não\nOpção: ");
		scanf("%d", &maisJ);

		while (maisJ != 0 && maisJ != 1)
		{
			printf("\n\nOpção inválida.\nQuer adicionar mais alguma operação ao job atual?\n1 - Sim; 0 - Não\nOpção: ");
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
			printf("\n\nO job %d não existe na lista ligada.\nInsira um job válido para remover: ", jobRemover);
			scanf("%d", &jobRemover);
			ver = verificarJobExistente(lista, jobRemover);
		}

		lista = removerJob(lista, jobRemover); 
		//maneira de reduzir os números dos jobs anteriores!!!!!
		lista = reduzirJob(lista, jobRemover);

		printf("Remover mais algum job?\n1 - Sim; 0 - Não\nOPção: ");
		scanf("%d", &mais);
	} 
	while (mais == 1);
	return lista;
}
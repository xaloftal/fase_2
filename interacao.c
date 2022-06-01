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
	} 
	while (maisJ == 1);

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

		printf("\n\nRemover mais algum job?\n1 - Sim; 0 - Não\nOpção: ");
		scanf("%d", &mais);
	} 
	while (mais == 1);

	pressione();
	return lista;
}

job* inserirO(job* inicio, int numJob)
{
	int novoJob = numJob, novaOperacao = ultimaOp(inicio, numJob) +1, novaMaquina, novoTempo, maisO = 1;

	printf("\nJob: %d", novoJob);
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

	pressione();
	return inicio;
}

job* removerO(job*inicio, int numJob)
{
	int opRemover, mais = 1;

	do
	{
		printf("Operação do job %d a remover: ", numJob);
		scanf("%d", &opRemover);

		int ver = verificarOpExistente(inicio,numJob, opRemover);

		while (ver != 1)
		{
			printf("\n\nA operação %d não existe no job %d.\nInsira um job válido para remover: ", opRemover, numJob);
			scanf("%d", &opRemover);
			ver = verificarOpExistente(inicio, numJob, opRemover);
		}

		inicio = removerOperacao(inicio, numJob, opRemover);

		printf("\n\nRemover mais alguma operação do job %d?\n1 - Sim; 0 - Não\nOpção: ", numJob);
		scanf("%d", &mais);
	} while (mais == 1);

	pressione();
	return inicio;
}

job* inserirM(job* inicio, int numJob, int numOp)
{
	int novoJob = numJob, novaOperacao = numOp, novaMaquina, novoTempo, maisO = 1;

	printf("\nJob: %d", novoJob);
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

	pressione();
	return inicio;
}
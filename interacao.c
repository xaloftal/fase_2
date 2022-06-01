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
			printf("\n\nO job %d n�o existe na lista ligada.\nInsira um job v�lido para remover: ", jobRemover);
			scanf("%d", &jobRemover);
			ver = verificarJobExistente(lista, jobRemover);
		}

		lista = removerJob(lista, jobRemover); 

		printf("\n\nRemover mais algum job?\n1 - Sim; 0 - N�o\nOp��o: ");
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

	pressione();
	return inicio;
}

job* removerO(job*inicio, int numJob)
{
	int opRemover, mais = 1;

	do
	{
		printf("Opera��o do job %d a remover: ", numJob);
		scanf("%d", &opRemover);

		int ver = verificarOpExistente(inicio,numJob, opRemover);

		while (ver != 1)
		{
			printf("\n\nA opera��o %d n�o existe no job %d.\nInsira uma opera��o v�lido para remover: ", opRemover, numJob);
			scanf("%d", &opRemover);
			ver = verificarOpExistente(inicio, numJob, opRemover);
		}

		inicio = removerOperacao(inicio, numJob, opRemover);

		printf("\n\nRemover mais alguma opera��o do job %d?\n1 - Sim; 0 - N�o\nOp��o: ", numJob);
		scanf("%d", &mais);
	} while (mais == 1);

	pressione();
	return inicio;
}

job* inserirM(job* inicio, int numJob, int numOp)
{
	int novoJob = numJob, novaOperacao = numOp, novaMaquina, novoTempo, maisO = 1;

	printf("\nJob: %d", novoJob);
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

	pressione();
	return inicio;
}

job* removerM(job* inicio, int numJob, int numOp)
{
	int maqRemover, mais = 1;

	do
	{
		printf("M�quina da opera��o %d do job %d a remover: ", numOp,numJob);
		scanf("%d", &maqRemover);

		int ver = verificarMaqExistente(inicio, numJob, numOp, maqRemover);

		while (ver != 1)
		{
			printf("\n\nA m�quina %d n�o existe na opera��o %d do job %d.\nInsira uma m�quina v�lida para remover: ", maqRemover, numOp,numJob);
			scanf("%d", &maqRemover);
			ver = verificarMaqExistente(inicio, numJob, numOp, maqRemover);
		}

		inicio = removerMaquina(inicio, numJob,numOp, maqRemover);

		printf("\n\nRemover mais alguma m�quina da opera��o %d do job %d?\n1 - Sim; 0 - N�o\nOp��o: ",numOp ,numJob);
		scanf("%d", &mais);
	} while (mais == 1);

	pressione();
	return inicio;
}

job* alterarM(job* inicio, int numJob, int numOp)
{
	int maqAlterar, mais = 1, temp;

	do
	{
		printf("M�quina da opera��o %d do job %d a alterar: ", numOp, numJob);
		scanf("%d", &maqAlterar);

		int ver = verificarMaqExistente(inicio, numJob, numOp, maqAlterar);

		while (ver != 1)
		{
			printf("\n\nA m�quina %d n�o existe na opera��o %d do job %d.\nInsira uma m�quina v�lida para alterar: ", maqAlterar, numOp, numJob);
			scanf("%d", &maqAlterar);
			ver = verificarMaqExistente(inicio, numJob, numOp, maqAlterar);
		}

		printf("\nTempo de processamento novo: ");
		scanf("%d", &temp);

		inicio = removerMaquina(inicio, numJob, numOp, maqAlterar);
		inicio = inserirJob(inicio, numJob, numOp, maqAlterar, temp);

		printf("\n\nAlterar mais alguma m�quina da opera��o %d do job %d?\n1 - Sim; 0 - N�o\nOp��o: ", numOp, numJob);
		scanf("%d", &mais);
	} while (mais == 1);

	pressione();
	return inicio;
}
#include "header.h"

int ultimoJob(job* lista) //vai procurar qual é o ultimo valor de job.
{
	int ultimo = 0;

	while (lista != NULL)
	{
		if (ultimo <= lista->nmrJob) ultimo = lista->nmrJob;
		lista = lista->seguinte;
	}
	return ultimo;
}

int ultimaOp(job* lista, int numJob)
{
	int ultimo = 0;

	while (lista != NULL)
	{
		if (ultimo <= lista->nmrOperacao && numJob == lista->nmrJob) ultimo = lista->nmrOperacao;
		lista = lista->seguinte;
	}
	return ultimo;
}

void listarJob(job* lista)
{
	job* inicio = lista;
	while (inicio != NULL)
	{
		printf("J: %d // O: %d // M: %d // T: %d\n", inicio->nmrJob, inicio->nmrOperacao, inicio->maquina, inicio->unidadeTempo);
		
		if (inicio->seguinte != NULL) if (inicio->nmrJob != inicio->seguinte->nmrJob) printf("\n\n");
		if (inicio->seguinte != NULL) if (inicio->nmrOperacao != inicio->seguinte->nmrOperacao) printf("\n");
	
		inicio = inicio->seguinte;
	}
}

job* removerJob(job* lista, int numJob) 
{
	job* jobAnterior, *jobAtual = lista;

	while (jobAtual != NULL) 
	{
		jobAtual = lista;

		if (numJob == lista->nmrJob) 
		{ 
			lista = jobAtual->seguinte;
			free(jobAtual); 
		}
		else 
		{ 
			jobAnterior = lista;

			while ((jobAtual != NULL) && (jobAtual->nmrJob != numJob)) 
			{				
				jobAnterior = jobAtual;

				if (jobAnterior->nmrJob > numJob) 
				{
					jobAnterior->nmrJob = jobAnterior->nmrJob - 1;
				}

				jobAtual = jobAtual->seguinte;
			}

			if (jobAtual != NULL) 
			{
				jobAnterior->seguinte = jobAtual->seguinte;
				free(jobAtual);

			}
		}
	}
	return(lista);
}

job* removerOperacao(job* inicio, int numJob, int numOp)
{
	job* jobAnterior, * jobAtual = inicio;

	while (jobAtual != NULL)
	{
		jobAtual = inicio;

		if (inicio->nmrJob == numJob && numOp == inicio->nmrJob)
		{
			inicio = jobAtual->seguinte;
			free(jobAtual);
		}
		else
		{
			jobAnterior = inicio;

			while ((jobAtual != NULL) && (jobAtual->nmrOperacao != numOp || jobAtual->nmrJob != numJob))
			{
				jobAnterior = jobAtual;

				if (jobAnterior->nmrOperacao > numOp && jobAnterior->nmrJob == numJob)
				{
					jobAnterior->nmrOperacao = jobAnterior->nmrOperacao - 1;
				}

				jobAtual = jobAtual->seguinte;
			}

			if (jobAtual != NULL) 
			{
				jobAnterior->seguinte = jobAtual->seguinte;
				free(jobAtual);

			}
		}
	}
	return(inicio);
}

job* removerMaquina(job* inicio, int numJob, int numOp, int numMaq)
{
	job* jobAnterior, * jobAtual = inicio;

	while (jobAtual != NULL)
	{
		jobAtual = inicio;

		if (inicio->nmrJob == numJob && numOp == inicio->nmrJob && inicio->maquina == numMaq)
		{
			inicio = jobAtual->seguinte;
			free(jobAtual);
		}
		else
		{
			jobAnterior = inicio;
			jobAtual = jobAtual->seguinte;

			while ((jobAtual != NULL) && (jobAtual->nmrOperacao != numOp || jobAtual->nmrJob != numJob || jobAtual->maquina != numMaq))
			{
				jobAnterior = jobAtual;
				jobAtual = jobAtual->seguinte;
			}

			if (jobAtual != NULL)
			{
				jobAnterior->seguinte = jobAtual->seguinte;
				free(jobAtual);

			}
		}
	}
	return(inicio);
}

job* inserirJob(job* inicio, int numeroJob, int numeroOp, int numeroMaq, int numeroTemp)
{
	int i = 0;
	job* novo = malloc(sizeof(job)), *ptr;

	if (novo != NULL)
	{
		novo->nmrJob = numeroJob;
		novo->nmrOperacao = numeroOp;
		novo->maquina = numeroMaq;
		novo->unidadeTempo = numeroTemp;
		novo->seguinte = inicio;
	}
	
	if (inicio == NULL) 
	{
		inicio = novo;
	}
	
	else if (novo->nmrJob <= inicio->nmrJob) 
	{
		novo->seguinte = inicio;
		inicio = novo;
	}
	
	else 
	{
		ptr = inicio;
		
		while (ptr->seguinte != NULL && ptr->seguinte->nmrJob <= novo->nmrJob) 
		{
			ptr = ptr->seguinte;
		}

		novo->seguinte = ptr->seguinte;
		ptr->seguinte = novo;
	}
	return (inicio);
}
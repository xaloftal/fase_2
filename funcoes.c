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

/*
job* ordemCrescente(job* lista)
{
	int troca;
	job* atual = lista;
	job* ultima = NULL;

	if (atual != NULL)
	{
		do
		{
			troca = 0;

			while (atual->seguinte != NULL)
			{
				if (atual->nmrJob > atual->seguinte->nmrJob)
				{
					int jobTemp = atual->nmrJob;
					atual->nmrJob = atual->seguinte->nmrJob;
					atual->seguinte->nmrJob = jobTemp;

					int opTemp = atual->nmrOperacao;
					atual->nmrOperacao = atual->seguinte->nmrOperacao;
					atual->seguinte->nmrOperacao = opTemp;

					int maqTemp = atual->maquina;
					atual->maquina = atual->seguinte->maquina;
					atual->seguinte->maquina = maqTemp;

					int temTemp = atual->unidadeTempo;
					atual->unidadeTempo = atual->seguinte->unidadeTempo;
					atual->seguinte->unidadeTempo = temTemp;

					troca = 1;
				}

				else if (atual->nmrJob == atual->seguinte->nmrJob)
				{
					if (atual->nmrOperacao > atual->seguinte->nmrOperacao)
					{
						int opTemp1 = atual->nmrOperacao;
						atual->nmrOperacao = atual->seguinte->nmrOperacao;
						atual->seguinte->nmrOperacao = opTemp1;

						int maqTemp1 = atual->maquina;
						atual->maquina = atual->seguinte->maquina;
						atual->seguinte->maquina = maqTemp1;

						int temTemp1 = atual->unidadeTempo;
						atual->unidadeTempo = atual->seguinte->unidadeTempo;
						atual->seguinte->unidadeTempo = temTemp1;

						troca = 1;
					}

					else if (atual->nmrOperacao == atual->seguinte->nmrOperacao)
					{
						if (atual->maquina > atual->seguinte->maquina)
						{
							int maqTemp2 = atual->maquina;
							atual->maquina = atual->seguinte->maquina;
							atual->seguinte->seguinte = maqTemp2;

							int temTemp2 = atual->unidadeTempo;
							atual->unidadeTempo = atual->seguinte->unidadeTempo;
							atual->seguinte->unidadeTempo = temTemp2;

							troca = 1;
						}
					}
				}
				atual = atual->seguinte;
			}
		} while (troca);
	}

	return lista;
}

job* ordemCrescenteMaquina (job* lista)
{
	int troca;
	job* atual = lista;
	job* ultima = NULL;

	if (atual != NULL)
	{
		do
		{
			troca = 0;

			while (atual->seguinte != NULL)
			{
				for (atual->nmrJob == atual->seguinte->nmrJob && atual->nmrOperacao == atual->seguinte->nmrOperacao; ;atual->seguinte == atual->seguinte->seguinte)
				{
					if (atual->maquina > atual->seguinte->maquina)
					{
						int maqTemp2 = atual->maquina;
						atual->maquina = atual->seguinte->maquina;
						atual->seguinte->seguinte = maqTemp2;

						int temTemp2 = atual->unidadeTempo;
						atual->unidadeTempo = atual->seguinte->unidadeTempo;
						atual->seguinte->unidadeTempo = temTemp2;

						troca = 1;
					}
				}
			}
		} while (troca);
	}	

	return lista;
}
*/ //tentativa de criação de duas funções de ordenação

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
	job* jobAtual = lista, * jobAnterior;

	while (jobAtual != NULL)
	{
		jobAtual = lista;

		if (jobAtual->nmrJob == numJob) //se for logo a primeira
		{
			jobAtual = jobAtual->seguinte;
			free(jobAtual);
		}

		else //se for no meio da lista
		{
			jobAnterior = lista;
			jobAtual = jobAtual->seguinte;

			while (jobAtual != NULL && jobAtual->nmrJob != numJob)
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
}

job* reduzirJob(job* lista, int numJobRemovido)
{
	job* jobAtual = lista, * jobAnterior, *novo;
	int i = 0, numJob;

	while (jobAtual != NULL)
	{
		if (jobAtual->nmrJob > numJobRemovido)
		{
			while (jobAtual != NULL)
			{
				numJob = jobAtual->nmrJob - 1;
				novo = inserirJob(jobAtual, numJob, jobAtual->nmrOperacao, jobAtual->maquina, jobAtual->unidadeTempo);
				jobAtual = jobAtual->seguinte;
				free(jobAtual);
			}
		}

		else
		{
			jobAnterior = lista;
			jobAtual = jobAtual->seguinte;

			while (jobAtual != NULL && jobAtual->nmrJob < numJobRemovido)
			{
				jobAnterior = jobAtual;
				jobAtual = jobAtual->seguinte;
			}
			if (jobAtual != NULL)
			{
				for (i = 0; i == 0; i++) //vai correr apenas uma vez este código.
				{
					numJob = jobAtual->nmrJob - 1;
					novo = inserirJob(jobAtual, numJob, jobAtual->nmrOperacao, jobAtual->maquina, jobAtual->unidadeTempo);
					jobAnterior->seguinte = novo;
					jobAtual = jobAtual->seguinte;
					free(jobAtual);
				}
				if (jobAtual->nmrJob > numJobRemovido)
				{
					novo = inserirJob(jobAtual, jobAtual->nmrJob - 1, jobAtual->nmrOperacao, jobAtual->maquina, jobAtual->unidadeTempo);
					jobAtual = jobAtual->seguinte;
					free(jobAtual);
				}
			}
		}
	}
}

job* inserirJob(job* inicio, int numeroJob, int numeroOp, int numeroMaq, int numeroTemp)
{
	int i = 0;
	job* novo = malloc(sizeof(job));

	if (novo != NULL)
	{
		novo->nmrJob = numeroJob;
		novo->nmrOperacao = numeroOp;
		novo->maquina = numeroMaq;
		novo->unidadeTempo = numeroTemp;
		novo->seguinte = inicio;
		return(novo);
	}
	else return (inicio);
}
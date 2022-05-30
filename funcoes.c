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

int ultimaOp(job* lista)
{
	int ultimo = 0;

	while (lista != NULL)
	{
		if (ultimo <= lista->nmrOperacao) ultimo = lista->nmrOperacao;
		lista = lista->seguinte;
	}
	return ultimo;
}

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

void listarUmJob(job* lista, int numJob)
{
	job* inicio = lista;

	while (lista != NULL)
	{
		if (lista->nmrJob == numJob)
		{
			printf("J: %d // O: %d // M: %d // T: %d\n", inicio->nmrJob, inicio->nmrOperacao, inicio->maquina, inicio->unidadeTempo);
			inicio = inicio->seguinte;
		}
		else inicio = inicio->seguinte;
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
#include "header.h"

int verificarJobExistente(job*lista, int numJob)
{
	int sim = 0;
	while (lista != NULL && sim !=1 )
	{
		if (lista->nmrJob == numJob)
		{
			sim = 1;
		}
		else lista = lista->seguinte;
	}
	return sim;
}

int verificarOpExistente(job* lista, int numJob, int numOp)
{
	int sim = 0;
	while (lista != NULL && sim != 1)
	{
		if (lista->nmrJob == numJob && lista->nmrOperacao == numOp)
		{
			sim = 1;
		}
		else lista = lista->seguinte;
	}
	return sim;
}

int verificarMaqExistente(job* lista, int numJob, int numOp, int numMaq)
{
	int sim = 0;
	while (lista != NULL && sim != 1)
	{
		if (lista->nmrJob == numJob && lista->nmrOperacao == numOp && lista->maquina == numMaq)
		{
			sim = 1;
		}
		else lista = lista->seguinte;
	}
	return sim;
}
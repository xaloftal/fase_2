#include "header.h"

job* escreverFicheiro(job* inicio) 
{
	FILE* infile = fopen("processplan.txt", "w"); //abrir ficheiro para escrever

	for (; inicio != NULL; inicio = inicio->seguinte)
	{
		fprintf(infile, "J: %d // O: %d // M: %d // T: %d\n", inicio->nmrJob, inicio->nmrOperacao, inicio->maquina, inicio->unidadeTempo);
	}

	if (fprintf != 0) printf("Dados guardados com sucesso!\n\n");
	else
	{
		printf("Ocorreu um erro na escrita do ficheiro!");
		pressione();
	}

	fclose(infile);
}

job* lerFicheiro()
{
	int numeroJob, numeroOp, numeroMaq, numeroTemp;
	job* lista = NULL;
	FILE* outfile = fopen("processplan.txt", "r");

	if (outfile != NULL)
	{
		while (!feof(outfile))
		{
			fscanf(outfile, "J: %d // O: %d // M: %d // T: %d\n", &numeroJob, &numeroOp, &numeroMaq, &numeroTemp);
			lista = inserirJob(lista, numeroJob, numeroOp, numeroMaq, numeroTemp);
		}
	}
	else printf("Ficheiro vazio!");

	fclose(outfile);

	return(lista);
}
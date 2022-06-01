#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_NONSTDC_NO_DEPRECATE
#define MAXMACHINE 9 

typedef struct Job
{
	int nmrJob;
	int nmrOperacao;
	int maquina;
	int unidadeTempo;
	struct Job* seguinte;
}job;

//funções para manipular os jobs
job* inserirJob(job* inicio, int numeroJob, int numeroOp, int numeroMaq, int numeroTemp);
job* removerJob(job* lista, int numJob);
job* removerOperacao(job* inicio, int numJob, int numOp);
job* removerMaquina(job* inicio, int numJob, int numOp, int numMaq);

//funções de listar
void listarJob(job* lista);

//funções para interação com utilizador
job* inserirJ(job* inicio);
job* removerJ(job* lista);
job* inserirO(job* lista, int numJob);
job* removerO(job* inicio, int numJob);
job* inserirM(job* inicio, int numJob, int numOp);
job* removerM(job* inicio, int numJob, int numOp);
job* alterarM(job* inicio, int numJob, int numOp);
int qualJob();
int qualOp(job* lista, int job);

//funções para ficheiros
job* escreverFicheiro(job* inicio);
job* lerFicheiro();

//funções de recolher informações automático
int ultimoJob(job* lista);
int ultimaOp(job* lista, int numJob);

//funções para verificar a existência de job ou operações
int verificarJobExistente(job*lista, int numJob);
int verificarOpExistente(job* lista, int numJob, int numOp);
int verificarMaqExistente(job* lista, int numJob, int numOp, int numMaq);

//funções de menu
void pressione();
int menu();
int alteracaoO(job* lista, int job, int op);
int alteracaoJ(job* lista,int job);
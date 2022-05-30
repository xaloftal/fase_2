#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_NONSTDC_NO_DEPRECATE
#define MAXMACHINE 9 
#define MAXOPERATION 9
#define MAXTIME 9
#define MAXJOB 9

//comentario

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

//funções de listar
void listarJob(job* lista);
void listarUmJob(job* lista, int numJob);
job* ordemCrescente(job* lista);
job* ordemCrescenteMaquina(job* lista);

//funções para interação com utilizador
job* inserirJ(job* inicio); //recolhe valores para inserir novo job
int alteracaoO(job* lista, int job, int op);
int alteracaoJ(job* lista,int job);
int qualJob();
int qualOp(job* lista, int job);

//funções para ficheiros
job* escreverFicheiro(job* inicio);
job* lerFicheiro();

//funções de recolher informações automático
int ultimoJob(job* lista);
int ultimaOp(job* lista);

//funções para verificar a existência de job ou operações
int verificarJobExistente(job*lista, int numJob);
int verificarOpExistente(job* lista, int numJob, int numOp);
int verificarMaqExistente(job* lista, int numJob, int numOp, int numMaq);

//funções de menu
void pressione();
int menu();
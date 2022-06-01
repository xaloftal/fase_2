#include <locale.h>
#include "header.h"

void pressione()
{
	printf("\n\nPrima qualquer tecla para ir para o menu!");
	getch();
	system("cls");
}

int menu()
{
	int opcaoMenu;

	printf("-------------* Menu principal *-------------\n\nEscolha uma op��o:\n\n1-Listar os jobs\n2-Inserir job\n3-Remover job\n4-Alterar job\n0-Sair\n\nOp��o: ");
	scanf("%d", &opcaoMenu);

	return opcaoMenu;
}

int qualJob()
{
	int job;

	printf("Qual � o job que pretende alterar?\n\nOpcao: ");
	scanf("%d", &job);

	return job;
}

int qualOp(job*lista, int nmrJob)
{
	system("cls");
	listarJob(lista);
	int op;

	printf("\n\nQual � a opera��o dentro do job %d que pretende alterar?\n\nOpcao: ", nmrJob);
	scanf("%d", &op);

	return op;
}

int alteracaoJ(job*lista,int nmrJob)
{
	system("cls");
	int opcaoAlterar;
	listarJob(lista);

	printf("\n\nO que pretende alterar dentro do job %d?\n\n1-Adicionar opera��o\n2-Remover Opera��o\n3-Alterar Opera��o \n0-Menu\n\nOp��o: ", nmrJob);
	scanf("%d", &opcaoAlterar);

	return opcaoAlterar;
}

int alteracaoO(job*lista,int job, int op)
{
	system("cls");
	listarJob(lista);
	int opcaoAlterar;

	printf("\n\nO que pretende alterar dentro da opera��o %d do job %d?\n\n1-Adicionar m�quina\n2-Remover m�quina\n3-Alterar m�quina\n0-Menu\n\nOp��o: ", op, job);
	scanf("%d", &opcaoAlterar);

	return opcaoAlterar;
}

void main()
{
	setlocale(LC_ALL, "Portuguese");

	job* lista = lerFicheiro();
	printf("PROCESSO DE ESCALONAMENTO E PROCESS PLAN EM LINGUAGEM C\nTrabalho realizado por: \nDiana A.C. Dinis, n�mero 23552\n\n");

	while (true)
	{
		int opcaoMenu = menu();

		switch (opcaoMenu)
		{
		case 1: //listar
			system("cls");
			printf("-------------* Listar os jobs *-------------\n\n");
			//lista = ordemCrescente(lista);
			listarJob(lista);
			pressione();
			break;

		case 2: //inserir
			system("cls");
			printf("-------------* Inserir um job *-------------\n\n");
			listarJob(lista);
			printf("\n\n");
			lista = inserirJ(lista);
			break;

		case 3: //remover
			system("cls");
			printf("-------------* Remover um job *-------------\n\n");
			listarJob(lista);
			printf("\n\n");
			lista = removerJ(lista);
			break;

		case 4: //alterar
			system("cls");
			printf("-------------* Alterar um job *-------------\n\n");
			listarJob(lista);
			printf("\n\n");

			int s = 0, i = 0;
			
			int qJob = qualJob();

			while (s == 0)
			{
				int verJ = verificarJobExistente(lista, qJob);

				if (verJ == 0)
				{
					printf("\n\nO job n�o existe. Escolha um job diferente para alterar\n\nOp��o: ");
					scanf("%d", &qJob);
				}

				else
				{
					int opcaoAlterarJ = alteracaoJ(lista, qJob);

					switch (opcaoAlterarJ)
					{
					case 1:
						s = 1;
						system("cls");
						printf("-------------* Inserir uma opera��o em J%d *-------------\n\n",qJob);
						listarJob(lista);
						printf("\n\n");
						lista = inserirO(lista, qJob);
						break;
					case 2:
						s = 1;
						system("cls");
						printf("-------------* Remover uma opera��o em J%d *-------------\n\n", qJob);
						listarJob(lista);
						printf("\n\n");
						lista = removerO(lista, qJob);
						break;
					case 3: //alterar opera��o
						s = 1;

						int qOp = qualOp(lista, qJob);

						while (i == 0)
						{
							int verO = verificarOpExistente(lista, qJob, qOp);

							if (verO == 0)
							{
								printf("\n\nA opera��o n�o existe dentro do job %d. Escolha uma opera��o diferente para alterar\n\nOp��o: ", qJob);
								scanf("%d", &qOp);
							}
							else
							{
								int opcaoAlterarO = alteracaoO(lista, qJob, qOp);

								switch (opcaoAlterarO)
								{
								case 1:
									i = 1;
									system("cls");
									printf("-------------* Inserir uma m�quina em O%d do J%d *-------------\n\n",qOp ,qJob);
									listarJob(lista);
									printf("\n\n");
									lista = inserirM(lista, qJob, qOp);
									break;

								case 2:
									i = 1;
									system("cls");
									printf("-------------* Inserir uma m�quina em O%d do J%d *-------------\n\n", qOp, qJob);
									listarJob(lista);
									printf("\n\n");
									lista = removerM(lista, qJob, qOp);

									break;

								case 3:
									i = 1;
									system("cls");
									printf("-------------* Alterar uma m�quina em O%d do J%d *-------------\n\n", qOp, qJob);
									listarJob(lista);
									printf("\n\n");
									lista = alterarM(lista, qJob, qOp);
									break;

								case 0:
									i = 1;
									s = 0;
									break;

								default:
									i = 0;
									system("cls");
									printf("Escolha inv�lida. Tente de novo.\n\n");
									continue;
								}
							}
						}

					case 0:
						s = 1;
						pressione();
						break;

					default:
						s = 0;
						system("cls");
						printf("Escolha inv�lida. Tente de novo.\n\n");
						continue;
					}
				}
			}
			break;

		case 0: //exit
			system("cls");
			escreverFicheiro(lista);
			printf("Obrigado! Prima qualquer tecla para fechar o programa.\n\n\n");
			exit(0);
			break;

		default:
			system("cls");
			printf("Op��o inv�lida. Por favor, tente de novo.\n\n");
			menu();
		}
	}
}
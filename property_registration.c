/*

Versao do compilador: gcc version 4.8.4

Descricao: o programa eh capaz de criar um cadastro de imoveis diversos e armazena-lo em um arquivo binario. Ele tambem gera um arquivo txt com todos os imoveis.

*/
#include <stdio.h>
#include <string.h> /*biblioteca de strings*/


struct cadastro { /*deficnicao da struct dos imoveis*/
  int cod;
  char categoria;
  int tipo;
  char endereco[41];
  int quartos;
  char garagem;
  float metragem;
  float preco;
  char obs[51];
  char data[9];
};
  typedef struct cadastro imovel;

void novoImovel (imovel um) { /*criacao de um novo imovel*/
	char op = 's';

	FILE * fp;
	fp = fopen("IMOVEIS.bin", "wb");
	if (fp == NULL)
	{
		printf("Não foi possivel criar o arquivo\n");
	}
	else
	{
		while ((op == 's') || (op == 'S')) /*leitura de uma struct*/
		{

			printf("Informe o codigo do imovel: ");
			scanf("%d", &um.cod);
			while(getchar()!= '\n');
			printf("\n");

			printf("Informe a categoria do imóvel ('V' para venda ou 'A' para aluguel): \n");
			scanf("%c", &um.categoria);
			while(getchar()!= '\n');
			printf("\n");

			printf("Informe o tipo do imovel\n1 - Apartamento\n2 - Casa\n3 - Lote\n4 - Loja\n");
			scanf("%d", &um.tipo);
			while(getchar()!= '\n');
			printf("\n");

			printf("Informe o endereco do imovel: ");
			fgets(um.endereco, 41, stdin);
			printf("\n");

			printf("Informe o numero de quartos do imovel: ");
			scanf("%d", &um.quartos);
			while(getchar()!= '\n');
			printf("\n");

			printf("Informe se o imovel tem garagem ou nao (Y para sim e N para nao): ");
			scanf("%c", &um.garagem);
			while(getchar()!= '\n');
			printf("\n");

			printf("Informe a metragem do imovel: ");
			scanf("%f", &um.metragem);
			while(getchar()!= '\n');
			printf("\n");

			printf("Informe o preco do imovel: ");
			scanf("%f", &um.preco);
			while(getchar()!= '\n');
			printf("\n");

			printf("Informe alguma observacao sobre o imovel: ");
			fgets(um.obs, 51, stdin);
			printf("\n");

			printf("Informe a data deste cadastro: ");
			fgets(um.data, 9, stdin);
			printf("\n");

			fprintf(fp,"%d\n%c\n%d\n%s%d\n%c\n%f\n%f\n%s%s", um.cod, um.categoria, um.tipo, um.endereco, um.quartos, um.garagem, um.metragem, um.preco, um.obs, um.data);

			printf("Voce deseja cadastrar mais algum imovel ? (S para sim e N para nao)\n");
			scanf("%c", &op);
			while(getchar()!= '\n');
			if (op == 's')
			{
				printf("\n\n");
			}
		}

	}
	fclose(fp);
}

void ApresentarImoveis(imovel um) /*funcao para a apresentacao dos imoveis cadastrados*/
{
	int cod;
	char categoria;
	int tipo;
	char endereco[41];
	int quartos;
	char garagem;
	float metragem;
	float preco;
	char obs[51];
	char data[9];

	int ordem = 1;
	char opc;
	char op = 's';

	FILE * fp;
	fp = fopen("IMOVEIS.bin", "rb");
	if (fp == NULL)
	{
		printf("Nao foi possivel verificar a existencia de nenhum cadastro\n");
		printf("Criando um novo cadastro ...\n");
		novoImovel(um);
	}
	else
	{
		printf("\n\nEstes sao os imoveis presentes no cadastro vigente\n"); /*apresentacao dos imoveis presentes no cadastro ate o momento*/
		while(fscanf(fp,"%d\n%c\n%d\n%[^\n]%d\n%c\n%f\n%f\n%[^\n]\n%[^\n]", &cod, &categoria, &tipo, endereco, &quartos, &garagem, &metragem, &preco, obs, data) != EOF)
		{
			printf("\n*****IMOVEL %d*****\n\n", ordem);

			printf("\nCodigo: %d", cod);
			printf("\nCategoria: %c", categoria);
			printf("\nTipo: %d", tipo);
			printf("\nEndereco: %s", endereco);
			printf("\nNumero de quartos: %d", quartos);
			printf("\nGaragem: %c", garagem);
			printf("\nMetragem: %f", metragem);
			printf("\nPreco: %f", preco);
			printf("\nObservaçoes: %s", obs);
			printf("\nData de cadastro: %s\n\n", data);

			ordem = ordem + 1;
		}
		while(getchar()!= '\n');
		printf("\nVoce deseja adicionar outro imovel ao cadastro ? (S para sim e N para nao)\n");
		scanf("%c", &opc);
		while(getchar()!= '\n');

		if ((opc == 's') || (opc == 'S'))
		{
			fclose(fp);
			fp = fopen("IMOVEIS.bin", "ab");
			if (fp == NULL)
			{
				printf("Não foi possivel abrir o arquivo\n");
			}
			else
			{
				while ((op == 's') || (op == 'S')) /*leitura de uma struct*/
				{

					printf("Informe o codigo do imovel: ");
					scanf("%d", &um.cod);
					while(getchar()!= '\n');
					printf("\n");

					printf("Informe a categoria do imóvel ('V' para venda ou 'A' para aluguel): \n");
					scanf("%c", &um.categoria);
					while(getchar()!= '\n');
					printf("\n");

					printf("Informe o tipo do imovel\n1 - Apartamento\n2 - Casa\n3 - Lote\n4 - Loja\n");
					scanf("%d", &um.tipo);
					while(getchar()!= '\n');
					printf("\n");

					printf("Informe o endereco do imovel: ");
					fgets(um.endereco, 41, stdin);
					printf("\n");

					printf("Informe o numero de quartos do imovel: ");
					scanf("%d", &um.quartos);
					while(getchar()!= '\n');
					printf("\n");

					printf("Informe se o imovel tem garagem ou nao (Y para sim e N para nao): ");
					scanf("%c", &um.garagem);
					while(getchar()!= '\n');
					printf("\n");

					printf("Informe a metragem do imovel: ");
					scanf("%f", &um.metragem);
					while(getchar()!= '\n');
					printf("\n");

					printf("Informe o preco do imovel: ");
					scanf("%f", &um.preco);
					while(getchar()!= '\n');
					printf("\n");

					printf("Informe alguma observacao sobre o imovel: ");
					fgets(um.obs, 51, stdin);
					printf("\n");

					printf("Informe a data deste cadastro: ");
					fgets(um.data, 9, stdin);
					printf("\n");

					fprintf(fp,"%d\n%c\n%d\n%s%d\n%c\n%f\n%f\n%s%s", um.cod, um.categoria, um.tipo, um.endereco, um.quartos, um.garagem, um.metragem, um.preco, um.obs, um.data);

					printf("Voce deseja cadastrar mais algum imovel ? (S para sim e N para nao)\n");
					scanf("%c", &op);
					while(getchar()!= '\n');
					if (op == 's')
					{
						printf("\n\n");
					}
				}

			}
		}

	}
	fclose(fp);
}

void MostraStruct(imovel um) /*funcao que mostra uma struct (imovel)*/
{
	printf("\n*****IMOVEL*****\n\n");

	printf("\nCodigo: %d", um.cod);
	printf("\nCategoria: %c", um.categoria);
	printf("\nTipo: %d", um.tipo);
	printf("\nEndereco: %s", um.endereco);
	printf("\nNumero de quartos: %d", um.quartos);
	printf("\nGaragem: %c", um.garagem);
	printf("\nMetragem: %f", um.metragem);
	printf("\nPreco: %f", um.preco);
	printf("\nObservaçoes: %s", um.obs);
	printf("\nData de cadastro: %s\n\n", um.data);
}

void PesquisaImoveisPorCodigo (){ /*funcao para a pesquisa de algum imovel por codigo*/

	int cod;
	char categoria;
	int tipo;
	char endereco[41];
	int quartos;
	char garagem;
	float metragem;
	float preco;
	char obs[51];
	char data[9];

	int ordem = 0;
	int input_codigo;
	int i=0;
	char op = 's';

	imovel um[1000];

	FILE * fp;
	fp = fopen("IMOVEIS.bin", "rb");
	if (fp == NULL)
	{
		printf("Nao foi possivel verificar a existencia de nenhum cadastro\n");
		printf("Pressione ENTER para retornar ao menu principal\n");
		while(getchar()!= '\n');
	}
	else
	{
		while(fscanf(fp,"%d\n%c\n%d\n%[^\n]%d\n%c\n%f\n%f\n%[^\n]\n%[^\n]", &cod, &categoria, &tipo, endereco, &quartos, &garagem, &metragem, &preco, obs, data) != EOF)
		{

			um[ordem].cod = cod;
			um[ordem].categoria = categoria;
			um[ordem].tipo = tipo;
			strcpy(um[ordem].endereco, endereco);
			um[ordem].quartos = quartos;
			um[ordem].garagem = garagem;
			um[ordem].metragem = metragem;
			um[ordem].preco = preco;
			strcpy(um[ordem].obs, obs);
			strcpy(um[ordem].data, data);

			ordem = ordem + 1;
		}

		while ((op == 's') || (op == 'S'))
		{

			printf("\nDigite o codigo que voce deseja pesquisar:");
			scanf("%d", &input_codigo);
			while(getchar()!= '\n');

			for (i = 0; i <= ordem; ++i)
			{
				if (input_codigo == um[i].cod)
				{
					MostraStruct(um[i]);
				}
			}
			printf("\n\nEste eh o imovel com o codigo pesquisado\n");
			printf("Voce deseja pesquisar mais algum imovel ? (S para sim e N para nao)\n");
			scanf("%c", &op);
			while(getchar()!= '\n');
		}
	}

}


void PesquisaImoveisPorCategoriaTipo (){ /*funcao para a pesquisa de um imovel por categoria/tipo*/

	int cod;
	char categoria;
	int tipo;
	char endereco[41];
	int quartos;
	char garagem;
	float metragem;
	float preco;
	char obs[51];
	char data[9];

	int ordem = 0;
	char input_categoria = 'v';
	int input_tipo = 1;
	int i=0;
	char op = 's';

	imovel um[1000];

	FILE * fp;
	fp = fopen("IMOVEIS.bin", "rb");
	if (fp == NULL) /*verificacao da existencia do arquivo binario*/
	{
		printf("Nao foi possivel verificar a existencia de nenhum cadastro\n");
		printf("Pressione ENTER para retornar ao menu principal\n");
		while(getchar()!= '\n');
	}
	else
	{
		while(fscanf(fp,"%d\n%c\n%d\n%[^\n]%d\n%c\n%f\n%f\n%[^\n]\n%[^\n]", &cod, &categoria, &tipo, endereco, &quartos, &garagem, &metragem, &preco, obs, data) != EOF)
		{

			um[ordem].cod = cod;
			um[ordem].categoria = categoria;
			um[ordem].tipo = tipo;
			strcpy(um[ordem].endereco, endereco);
			um[ordem].quartos = quartos;
			um[ordem].garagem = garagem;
			um[ordem].metragem = metragem;
			um[ordem].preco = preco;
			strcpy(um[ordem].obs, obs);
			strcpy(um[ordem].data, data);

			ordem = ordem + 1;
		}

		while ((op == 's') || (op == 'S'))
		{

			while(getchar()!= '\n');
			printf("\nDigite a categoria que voce deseja pesquisar:");
			scanf("%c", &input_categoria);
			while(getchar()!= '\n');

			printf("\nDigite o tipo que voce deseja pesquisar:");
			scanf("%d", &input_tipo);
			while(getchar()!= '\n');

			for (i = 0; i <= ordem; ++i)
			{
				if ((input_categoria == um[i].categoria) && (input_tipo == um[i].tipo))
				{
					MostraStruct(um[i]);
				}
			}
			printf("\n\nEste sao os imoveis com o tipo e categoria pesquisado\n");
			printf("Voce deseja pesquisar mais algum imovel ? (S para sim e N para nao)\n");
			scanf("%c", &op);
			while(getchar()!= '\n');
		}
	}

}


void GerarTXT(){ /*funcao para a geracao do arquivo de texto com as structs de imoveis em ordem de tipo e preco*/


	int cod;
	char categoria;
	int tipo;
	char endereco[41];
	int quartos;
	char garagem;
	float metragem;
	float preco;
	char obs[51];
	char data[9];

	int ordem = 0;
	int i=0;
	int j=0;
	int ultimo;
	int fim_1, fim_2, fim_3;

	imovel um[1000];
	imovel ordenado1[1000];
	imovel ordenado2[1000];
	imovel maior;
	imovel menor;
	int exclusao[1000];

	FILE * fp;
	fp = fopen("IMOVEIS.bin", "rb");
	if (fp == NULL) /*Verificacao da existencia do arquivo*/
	{
		printf("Nao foi possivel verificar a existencia de nenhum cadastro\n");
		printf("Pressione ENTER para retornar ao menu principal\n");
		while(getchar()!= '\n');
	}
	else
	{
		while(fscanf(fp,"%d\n%c\n%d\n%[^\n]%d\n%c\n%f\n%f\n%[^\n]\n%[^\n]", &cod, &categoria, &tipo, endereco, &quartos, &garagem, &metragem, &preco, obs, data) != EOF)
		{
			if ((categoria == 'v') || (categoria == 'V'))
			{

				um[ordem].cod = cod;
				um[ordem].categoria = categoria;
				um[ordem].tipo = tipo;
				strcpy(um[ordem].endereco, endereco);
				um[ordem].quartos = quartos;
				um[ordem].garagem = garagem;
				um[ordem].metragem = metragem;
				um[ordem].preco = preco;
				strcpy(um[ordem].obs, obs);
				strcpy(um[ordem].data, data);

				ordem = ordem + 1;
			}
		}
	}
	fclose(fp);

	ultimo = 0;

	for (i = 0; i < 1000; ++i)
	{
		exclusao[i] = 0;
	}

	for (i = 1; i <= 4; ++i)
	{
		for (j = 0; j <= ordem; ++j)
		{
			if (um[j].tipo == i)
			{
				ordenado1[ultimo] = um[j];
				ultimo = ultimo + 1;
			}
		}
	}

	fim_1 = 0;
	while (ordenado1[fim_1].tipo == 1) /*definicao da quantidade de structs de cada tipo*/
	{
		fim_1 = fim_1 + 1;
	}
	fim_1 = fim_1-1;
	fim_2 = fim_1+1;
	while (ordenado1[fim_2].tipo == 2)
	{
		fim_2 = fim_2 + 1;
	}
	fim_2 = fim_2-1;
	fim_3 = fim_2+1;
	while (ordenado1[fim_3].tipo == 3)
	{
		fim_3 = fim_3 + 1;
	}
	fim_3 = fim_3-1;

	ultimo = 0;

	/**********************************************************/

	maior = ordenado1[0];
	menor = ordenado1[0];

	for (i = 0; i <= fim_1; ++i) /*definicao da ordem das structs com tipo 1 em ordem de preco*/
	{
		if (ordenado1[i].preco < menor.preco)
		{
			menor = ordenado1[i];
		}
	}

	for (i = 0; i <= fim_1; ++i)
	{
		ultimo = 0;
		maior = menor;
		for (j = 0; j <= fim_1; ++j)
		{
			if ((ordenado1[j].preco > maior.preco) && (exclusao[j] == 0))
			{
				maior = ordenado1[j];
				ultimo = j;
			}
		}
		ordenado2[i] = maior;
		exclusao[ultimo] = 1;
	}

	/*********************************************************/

	maior = ordenado1[fim_1+1];
	menor = ordenado1[fim_1+1];

	ultimo = 0;

	for (i = fim_1+1; i <= fim_2; ++i) /*definicao da ordem das structs com tipo 2 em ordem de preco*/
	{
		if (ordenado1[i].preco < menor.preco)
		{
			menor = ordenado1[i];
		}
	}

	for (i = fim_1+1; i <= fim_2; ++i)
	{
		ultimo = 0;
		maior = menor;
		for (j = fim_1+1; j <= fim_2; ++j)
		{
			if ((ordenado1[j].preco > maior.preco) && (exclusao[j] == 0))
			{
				maior = ordenado1[j];
				ultimo = j;
			}
		}
		ordenado2[i] = maior;
		exclusao[ultimo] = 1;
	}

	/********************************************************/

	maior = ordenado1[fim_2+1];
	menor = ordenado1[fim_2+1]; 

	ultimo = 0;

	for (i = fim_2+1; i <= fim_3; ++i) /*definicao da ordem das structs com tipo 3 em ordem de preco*/
	{
		if (ordenado1[i].preco < menor.preco)
		{
			menor = ordenado1[i];
		}
	}

	for (i = fim_2+1; i <= fim_3; ++i)
	{
		ultimo = 0;
		maior = menor;
		for (j = fim_2+1; j <= fim_3; ++j)
		{
			if ((ordenado1[j].preco > maior.preco) && (exclusao[j] == 0))
			{
				maior = ordenado1[j];
				ultimo = j;
			}
		}
		ordenado2[i] = maior;
		exclusao[ultimo] = 1;
	}

	/********************************************************/


	maior = ordenado1[fim_3+1];
	menor = ordenado1[fim_3+1];

	ultimo = 0;

	for (i = fim_3+1; i <= ordem; ++i) /*definicao da ordem das structs com tipo 4 em ordem de preco*/
	{
		if (ordenado1[i].preco < menor.preco)
		{
			menor = ordenado1[i];
		}
	}

	for (i = fim_3+1; i <= ordem; ++i)
	{
		ultimo = 0;
		maior = menor;
		for (j = fim_3+1; j <= ordem; ++j)
		{
			if ((ordenado1[j].preco > maior.preco) && (exclusao[j] == 0))
			{
				maior = ordenado1[j];
				ultimo = j;
			}
		}
		ordenado2[i] = maior;
		exclusao[ultimo] = 1;
	}

	/****************************************************/

	for (i = 0; i < ordem; ++i) /*geracao do arquivo txt com o vetor de structs em ordem de tipo e preco*/
	{
		MostraStruct(ordenado2[i]);
		printf("%d\n", exclusao[i]);
	}

	fp = fopen("IMOVEIS_VENDA.txt", "w");
	if (fp == NULL)
	{
		printf("Nao foi possivel gerar um arquivo com o relatorio de vendas\n");
		printf("Pressione ENTER para retornar ao menu principal\n");
		while(getchar()!= '\n');
	}
	else
	{
		fprintf(fp, "*** LISTAGEM DE IMOVEIS PARA VENDA ***\n");
		fprintf(fp, "TIPO   CODIGO   ENDERECO                                PRECO\n");
		for (i = 0; i < ordem; ++i)
		{
			fprintf(fp, "%-6d %-8d %-39s %f\n", ordenado2[i].tipo, ordenado2[i].cod, ordenado2[i].endereco, ordenado2[i].preco);
		}
	}
	fclose(fp);
}




int main()
{
	int a, terminador = 0; /*Declaracao de variaveis usadas na main*/
	imovel um; 

	while (terminador == 0) { /*Apresentacao do menu ao usuario*/
		printf("1) Criar e iniciar um cadastro novo\n2) Incluir novos dados em um cadastro existente\n3) Consultar o cadastro por codigo do imovel\n4) Consultar o cadastro por categoria e tipo de imóvel\n5) Gerar arquivo de texto do cadastro de venda\n6) Sair do programa\nDigite uma opção\n");
		scanf("%d", &a);

		if (a == 1)
		{
			novoImovel(um);
		}

		if (a == 2)
		{
			ApresentarImoveis(um);
		}

		if (a == 3)
		{
			PesquisaImoveisPorCodigo();
		}

		if (a == 4)
		{
			PesquisaImoveisPorCategoriaTipo();
		}

		if (a == 5)
		{
			GerarTXT();
		}


		if (a == 6) /*opcao seis: o while nao eh realizado novamente quando terminador = 1*/
		{
			terminador = 1;
		}
	}
	return 0;
}

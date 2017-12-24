/*

Versão do compilador: gcc 4.8.4

Descrição: O programa a seguir efetua a transformção de números nas bases hexadecimal, binária ou octal para a base decimal. 

*/

#include <stdio.h>
#include <math.h> /* Biblioteca math.h para as funções exponenciais */

void inicializaVetor (char V[], int n) {  /* Essa função limpa o lixo de todos os vetores antes de pegar os dados inseridos pelo usuário */

	int i;

	for (i = 0; i < n; i++) {
		V[i] = '\0';
	}
}

void inicializaVetorNumerico (int V[], int n) { /* Essa função faz o mesmo, no entanto, com os vetores do tipo inteiro que receberão os valores numéricos dos vetores tipo char que receberam os dados inseridos pelo usuário */

	int i;

	for (i = 0; i < n; i++) {
		V[i] = -1;
	}
}

int charToInt (char c) { /* Função que transforma os caracteres que são letras em números (ex: quando o número inserido está na base hexadecimal) */

	if (c < 58) {
		return c - 48;
	}
	
	else {
		return c - 55;
	}
}

int determinaBase (int b[]) { /* Essa função retorna o valor da base a partir do vetor do tipo int que receber o valor contido no vetor tipo char que recebeu o valor inserido para a base */
	if (b[0] == 2 && b[1] == -1) {
		return 2;
	}

	else if (b[0] == 8 && b[1] == -1) {
		return 8;
	}

	else if (b[0] == 1 && b[1] == 6 && b[2] == -1) {
		return 16;
	}

	else {
		return 0;
	}
}

int verificaEntrada (int n[], int f[], int base) { /* Verifica se os dados inseridos pelo usuários condizem com as capacidades do programa. Retorna o tipo do erro. */

	int i = 0, j = 0, erro = 0;
	
	if (base == 0) {
		return 2;
	}

	else if (base == 2) {
		while (n[i] != -1) {
			if (n[i] != 0 && n[i] != 1) {
				erro = 1;
			}
			i++;
		}

		while (f[j] != -1) {
			if (f[j] != 0 && f[j] != 1) {
				erro = 1;
			}
			j++;
		}
	}

	else if (base == 8) {
		
		i = 0;
		j = 0;

		while (n[i] != -1) {
			if (n[i] < 0 || n[i] > 7) {
				erro = 1;
			}
			i++;
		}

		while (f[j] != -1) {
			if (f[j] < 0 || f[j] > 7) {
				erro = 1;
			}
			j++;
		}
	}

	else if (base == 16) {

		i = 0;
		j = 0;

		while (n[i] != -1) {
			if (n[i] < 0 || n[i] > 15) {
				erro = 1;
			}
			i++;
		}

		while (f[j] != -1) {
			if (f[j] < 0 || f[j] > 15) {
				erro = 1;
			}
			j++;
		}
	}

	if (erro == 1) {
		return 1;
	}

	else {
		return 0;
	}
}
void explicaErro(int erro) { /* Função destinada a mostrar uma mensagem explicativa ao usuário referente ao erro que ele cometeu ao inserir os dados */
	if (erro == 1) {
		printf("Os digitos informados nao condizem com a base numerica escolhida.\n");
	}

	else if (erro == 2) {
		printf("A base numerica digitada nao existe. Digite uma base valida (octal = 8, binario = 2 ou hexadecimal = 16).\n");
	}
}

float binToDec(int n[], int f[]) { /* Função responsável pela transformação do número na base binária para a decimal */

	int i = 0, j = 0, k = 1, inteiro = 0, base = 2;
	float fracionario = 0, soma = 0;

	while (n[i] != -1) {
		i++;
	}

	i--;

	while (i >= 0) {
		inteiro += pow(base, i) * n[j];
		j++;
		i--;

	}

	while (f[k-1] != -1) {
		fracionario += pow(base, -k) * f[k-1];
		k++;
	}

	soma = fracionario + inteiro;
	return soma;
}

float hexToDec(int n[], int f[]) { /* Função responsável pela transformação do número na base hexadecimal para a decimal */

	int i = 0, j = 0, k = 1, inteiro = 0, base = 16;
	float fracionario = 0, soma = 0;

	while (n[i] != -1) {
		i++;
	}

	i--;

	while (i >= 0) {
		inteiro += pow(base, i) * n[j];
		j++;
		i--;

	}

	while (f[k-1] != -1) {
		fracionario += pow(base, -k) * f[k-1];
		k++;
	}

	soma = fracionario + inteiro;
	return soma;
}

float octToDec(int n[], int f[]) { /* Função responsável pela transformação do número na base octal para a decimal */

	int i = 0, j = 0, k = 1, inteiro = 0, base = 8;
	float fracionario = 0;
	float soma = 0;

	while (n[i] != -1) {
		i++;
	}

	i--;

	while (i >= 0) {
		inteiro += pow(base, i) * n[j];
		j++;
		i--;

	}

	while (f[k-1] != -1) {
		fracionario += pow(base, -k) * f[k-1];
		k++;
	}

	soma = fracionario + inteiro;
	return soma;
}

int main()
{
	int i = 0, a = 0, k = 0, j = 0, base = 0, erro, fracionario = 0, m, w = 0;
	char N[7], F[4], B[5], vetor[100];
	int n[7], f[4], b[5];
	float resultado;

	printf("Insira um numero para a conversao no formato: <ParteInteira>,<ParteFracionaria>_<base>\n");

	inicializaVetor(N, 7); 
	inicializaVetor(F, 4);
	inicializaVetor(B, 5);
	inicializaVetor(vetor, 100);

	inicializaVetorNumerico(n, 7);
	inicializaVetorNumerico(f, 4);
	inicializaVetorNumerico(b, 5);

	scanf("%s", &vetor[0]); /* O número, sua parte fracionária e sua base são todos armazenados em um vetor do tipo char, para melhor entrada dos dados, que depois será repartido em três vetores diferentes para melhor manuseio dos dados inseridos. */

	while (vetor[w] != '\0') { /* verifica se existe parte fracionária */
		if (vetor[w] == ',') {
			fracionario = 1;
		}
		w++;
	}

	if (fracionario == 1) /* Se sim, o vetor do tipo char será repartido como feito abaixo em três vetores diferentes */
	{
		while (vetor[i] != ',') {
			N[i] = vetor[i];
			i++;
		}

		i++;

		while (vetor[i] != '_') {
			F[a] = vetor[i];
			i++;
			a++;
		}

		i++;

		while (vetor[i] != '\0') {
			B[k] = vetor[i];
			i++;
			k++;
		}
	}

	i = 0;

	if (fracionario == 0) /* Se o número inserido não tiver parte fracionária, o procedimento é o que se segue */
	{

		while (vetor[i] != '_') {
				N[i] = vetor[i];
				i++;
		}

		i++;

		while (vetor[i] != '\0') {
			B[k] = vetor[i];
			i++;
			k++;
		}
	}

	while (N[j] != '\0') { /* Depois que os dados inseridos são separados em seus respectivos vetores, seus valores são convertidos de char para int a seguir e transferidos para um novo vetor do tipo int */
		n[j] = charToInt(N[j]);
		j++;
	}

	j = 0;

	if (fracionario == 1) { /* O procedimento descrito acima apenas acontece com o vetor destinado à parte fracionária se essa parte existir */
		while (F[j] != '\0') {
			f[j] = charToInt(F[j]);
			j++;
		}
	}

	j = 0;

	while (B[j] != '\0') {
		b[j] = charToInt(B[j]);
		j++;
	}

	if (fracionario == 0) {
		for (m = 0; m < 4; m++) {
			f[m] = -1;
		}
	}

	base = determinaBase(b); /* A variável 'base' recebe seu valor final */

	erro = verificaEntrada(n, f, base); /* A variável 'erro' recebe seu valor */

	if (erro != 0) { 
		explicaErro(erro);
	}

	else { /* Se os dados inseridos estão corretos, as transformações de base ocorrerão */

		if (base == 2) {
			resultado = binToDec(n, f);
		}

		else if (base == 8) {
			resultado = octToDec(n, f);
		}

		else if (base == 16) {
			resultado = hexToDec(n, f);
		}
	} 

	printf("Erro = %d\n", verificaEntrada(n, f, base)); /* Impressão do erro encontrado para o usuário */
	
	if (erro == 0) {
		printf("O resultado e: %f\n", resultado); /* Impressão do resultado para o usuário quando não há erros */
	}

	return 0;
}
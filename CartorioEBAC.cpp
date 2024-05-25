#include <stdio.h>  // biblioteca de comunica��o com o usu�rio.
#include <stdlib.h> // biblioteca de aloca��o de espa�o em mem�ria.
#include <locale.h> // biblioteca de aloca��o de texto por regi�o.
#include <string.h> //biblioteca respons�vel por cuidar dos string

int registro() //fun��o respons�vel por cadastrar os usu�rios do sistema
 {  //in�cio cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/string
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf); //%s refere-se ao armazenamento de string
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w");//cria o arquivo
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
}

int consulta()  {
	setlocale(LC_ALL, "Portuguese"); // Definindo a Linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: "); //imprime um texto na tela
	scanf("%s",cpf);
	
	FILE *file; //Cria um arquivo
	file = fopen(cpf,"r");
	
	if(file== NULL)  {
		printf("N�o foi possivel abrir o arquivo, arquivo n�o localizado! \n");
	}
	
	while(fgets(conteudo, 200, file))  {
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int deletar()  {
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40]; //Declarando uma string para armazenar o CPF do usu�rio a ser deletado

	printf("Digite o CPF do usu�rio a ser deletado:  ");
	scanf("%s", cpf);
	
	// Tenta remover o arquivo correspondente ao CPF fornecido
	if (remove(cpf) == 0)  {
		printf("Usu�rio deletado com sucesso! \n");
	}
	else  {
		printf("Erro ao deletar o usu�rio. Arquivo n�o encontrado! \n");
	}
	
	system("pause");
}
 
int main()  {
    int opcao = 0; // definindo as vari�veis
    int laco = 1;

    for (laco = 1; laco = 1;)  {
        system("cls");

        setlocale(LC_ALL, "Portuguese"); // Definindo a Linguagem

        printf("### Cart�rio da EBAC ###\n\n"); // In�cio do menu
        printf("Escolha a opc�o desejada do menu:\n\n");
        printf("\t1 - Registrar nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar nomes\n\n");
        printf("\t4 - Sair\n\n");
        printf("Opcao: "); // Fim do menu

        scanf("%d", &opcao); // Armazenando a escolha do usu�rio

        system("cls");

        switch (opcao)  {
            case 1:
                registro();
                break;
            case 2:
                consulta();
                break;
            case 3:
                deletar();
                break;
            case 4:
            	printf("Sistema encerrado com sucesso!\n");
            	return 0;
            	break;
            	
            default:
                printf("Opcao invalida!\n");
                system("pause");
                break;
        }
    }
}

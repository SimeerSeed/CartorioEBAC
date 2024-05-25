#include <stdio.h>  // biblioteca de comunicação com o usuário.
#include <stdlib.h> // biblioteca de alocação de espaço em memória.
#include <locale.h> // biblioteca de alocação de texto por região.
#include <string.h> //biblioteca responsável por cuidar dos string

int registro() //função responsável por cadastrar os usuários do sistema
 {  //início criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/string
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf); //%s refere-se ao armazenamento de string
	
	strcpy(arquivo, cpf); //responsável por copiar os valores das string
	
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
		printf("Não foi possivel abrir o arquivo, arquivo não localizado! \n");
	}
	
	while(fgets(conteudo, 200, file))  {
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int deletar()  {
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40]; //Declarando uma string para armazenar o CPF do usuário a ser deletado

	printf("Digite o CPF do usuário a ser deletado:  ");
	scanf("%s", cpf);
	
	// Tenta remover o arquivo correspondente ao CPF fornecido
	if (remove(cpf) == 0)  {
		printf("Usuário deletado com sucesso! \n");
	}
	else  {
		printf("Erro ao deletar o usuário. Arquivo não encontrado! \n");
	}
	
	system("pause");
}
 
int main()  {
    int opcao = 0; // definindo as variáveis
    int laco = 1;

    for (laco = 1; laco = 1;)  {
        system("cls");

        setlocale(LC_ALL, "Portuguese"); // Definindo a Linguagem

        printf("### Cartório da EBAC ###\n\n"); // Início do menu
        printf("Escolha a opcão desejada do menu:\n\n");
        printf("\t1 - Registrar nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar nomes\n\n");
        printf("\t4 - Sair\n\n");
        printf("Opcao: "); // Fim do menu

        scanf("%d", &opcao); // Armazenando a escolha do usuário

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

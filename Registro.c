#include <stdio.h> //biblioteca de comunicação com o usuario
#include <stdlib.h> //biblioteca de alocação de espaço de memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar dos string


int registro() //Função responsavel por cadastrar os usuários no sistema
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	//inicio criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informações do usuários
	scanf("%s", cpf); //%s refere-se a string 
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "W" significa escrever
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: "); //coletando informações do usuários
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome); // salvo o valor da variavel
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,","); 
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando informações do usuários
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome); // salvo o valor da variavel
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: "); //coletando informações do usuários
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo); // salvo o valor da variavel
	fclose(file);	
	
    system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[100];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
  	
	FILE *file;
	file = fopen(cpf,"r");
  	
	if(file == NULL)
	{
	printf("Não foi possível abrir o arquivo, Cadastro Não localizado!.\n");
	}
	
	while(fgets(conteudo, 100, file) != NULL)
	{
	printf("\nEssas são as informações do Usuário: ");
	printf("%s", conteudo);
	printf("\n\n");
	}
	
 	system ("pause");
	
}


int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário que deseja Excluir: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf ("O usuário não esta cadastrado.\n");
		system("pause");
	}	
	
}

int main()
{
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("### Registro de Usuários da EBAC ###\n\n"); //Inicio do menu	
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar Nomes\n");
		printf("\t2 - Consultar Nomes\n");
		printf("\t3 - Excluir Nomes\n\n"); 
		printf("\t4 - Sair do Sistema\n\n");
		printf("Opção: ");//fim do menu
	
		scanf("%d",&opcao); //armazenando escolha dos usuário
	
		system("cls"); //responsavel por limpar a tela
		
		switch(opcao) //inicio da seleção do menu
		{
			case 1:
			registro(); //chamada de funções
			break;
		
			case 2:
			consulta();
			break;
		
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
					
			default:
			printf("ATENÇÃO - Essa opção não está disponível!\n");
			system("pause");
			break;
		} //fim da seleção
	
    }
}


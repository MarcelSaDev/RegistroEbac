#include <stdio.h> //biblioteca de comunica��o com o usuario
#include <stdlib.h> //biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar dos string


int registro() //Fun��o responsavel por cadastrar os usu�rios no sistema
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	//inicio cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��es do usu�rios
	scanf("%s", cpf); //%s refere-se a string 
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "W" significa escrever
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: "); //coletando informa��es do usu�rios
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome); // salvo o valor da variavel
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,","); 
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando informa��es do usu�rios
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome); // salvo o valor da variavel
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: "); //coletando informa��es do usu�rios
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
	printf("N�o foi poss�vel abrir o arquivo, Cadastro N�o localizado!.\n");
	}
	
	while(fgets(conteudo, 100, file) != NULL)
	{
	printf("\nEssas s�o as informa��es do Usu�rio: ");
	printf("%s", conteudo);
	printf("\n\n");
	}
	
 	system ("pause");
	
}


int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio que deseja Excluir: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf ("O usu�rio n�o esta cadastrado.\n");
		system("pause");
	}	
	
}

int main()
{
	int opcao=0; //Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("### Registro de Usu�rios da EBAC ###\n\n"); //Inicio do menu	
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar Nomes\n");
		printf("\t2 - Consultar Nomes\n");
		printf("\t3 - Excluir Nomes\n\n"); 
		printf("\t4 - Sair do Sistema\n\n");
		printf("Op��o: ");//fim do menu
	
		scanf("%d",&opcao); //armazenando escolha dos usu�rio
	
		system("cls"); //responsavel por limpar a tela
		
		switch(opcao) //inicio da sele��o do menu
		{
			case 1:
			registro(); //chamada de fun��es
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
			printf("ATEN��O - Essa op��o n�o est� dispon�vel!\n");
			system("pause");
			break;
		} //fim da sele��o
	
    }
}


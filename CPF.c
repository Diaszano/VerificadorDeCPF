#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


void ler_cpf(char palavra[11])
	{
		int tamanho = 11;
		int i = 0;
		char c;
	
		c = getchar();
		while ((c != '\n') && (i < tamanho)) 
			{
				if(c >= 48 && c <= 57)
					{
						palavra[i++] = c;
					}
				c = getchar();
			}
		palavra[i] = '\0';
	
		if (c != '\n') {
			c = getchar();
			while ((c != '\n') && (c != EOF)) {
				c = getchar();
			}
		}
	}
	
void conversao(char numero[11])
	{
		int acc[11];
		int i,j;
		
		for(i=0, j=0; i<11 && j < 11; i++, j++)
			{
		
				switch (numero[j]) 
					{
						case 48:
							
								acc[i] = 0;			
									
							break;
						case 49:
													
								acc[i] = 1;	
									
							break;
						case 50:
													
								acc[i] = 2;	
									
							break;
						case 51:
													
								acc[i] = 3;	
									
							break;
						case 52:
													
								acc[i] = 4;	
									
							break;
						case 53:
														
								acc[i] = 5;	
									
							break;
						case 54:
														
								acc[i] = 6;	
									
							break;
						case 55:
														
								acc[i] = 7;	
									
							break;
						case 56:
														
								acc[i] = 8;	
									
							break;
						case 57:
														
								acc[i] = 9;		
							
							break;
						default :
    						i--;
					}
			}
			
	codigo(acc, 10 , 1);
	codigo(acc, 11 , 1);

	printf("O CPF; ");
	imprimircpf(acc);
	printf(" é válido");
	
	estado(acc[8]);
	}

void estado(int num)
	{
		switch (num) 
			{
				case 0:
														
					printf("\nO CPF é correspondente ao estado brasileiro: Rio Grande do Sul.");	
							
					break;
				case 1:
						
					printf("\nO CPF é correspondentes aos estados brasileiros:  Distrito Federal, Goiás, Mato Grosso do Sul e Tocantins.");			
									
					break;
				case 2:
													
					printf("\nO CPF é correspondentes aos estados brasileiros: Pará, Amazonas, Acre, Amapá, Rondônia e Roraima.");		
									
					break;
				case 3:
													
					printf("\nO CPF é correspondentes aos estados brasileiros: Ceará, Maranhão e Piauí.");	
									
					break;
				case 4:
													
					printf("\nO CPF é correspondentes aos estados brasileiros: Pernambuco, Rio Grande do Norte, Paraíba e Alagoas.");	
									
					break;
				case 5:
														
					printf("\nO CPF é correspondentes aos estados brasileiros: Bahia e Sergipe.");	
									
					break;
				case 6:
														
					printf("\nO CPF é correspondente ao estado brasileiro: Minas Gerais.");	
									
					break;
				case 7:
														
					printf("\nO CPF é correspondentes aos estados brasileiros: Rio de Janeiro e Espírito Santo.");	
									
					break;
				case 8:
														
					printf("\nO CPF é correspondente ao estado brasileiro: São Paulo.");		
								
					break;
				case 9:
														
					printf("\nO CPF é correspondentes aos estados brasileiros: Paraná e Santa Catarina.");		
							
					break;
			}
	}

void codigo(int vet[11], int local, int opc)
	{
		int acc=0,resto,digito;
		int i,j;
		
		for(i=0, j = local; i < (local-1) ; i++ , j--)
			{
				acc += j * vet[i];
			}
		
		resto = acc % 11;
		
		if((resto == 1) || (resto == 0))
			{
				resto = 0;
				
			}
		else
			{
				resto = 11 - resto;	
			}
		if(opc == 0)
			{
				vet[local-1] = resto;
			}
			
		if( resto != vet[local - 1])
			{
				printf("O CPF; ");
				imprimircpf(vet);
				printf(" é inválido");
				getchar();
				main();
			}
	}

void imprimircpf(int cpf[11])
	{
		int k;
		for(k=0;k<11;k++)
			{
				if(k == 3 || k == 6)
					{
						printf(".");
					}
				if(k == 9)
					{
						printf("-");
					}
				printf("%i",cpf[k]);
			}
	}

void clear()
	{
		system("cls || clear");
	}

int menu(void)
	{
		clear();
		int c = 0;
		
		do 
			{
				printf("-- MENU:\n");
				printf("\t 1. Verificar o CPF\n");
				printf("\t 2. Criar um CPF válido\n");
				printf("\t 3. Sair\n");
				printf("-- Digite sua escolha: ");
				scanf("%d", &c);
				
			}while (c <= 0 || c > 7);
			
		getchar();
		return c;
	}
	
void criacao(void)
	{
		time_t t;
		srand((unsigned) time(&t));
		int c,i,criado[11];
		
		do
			{
				clear();
				printf("Tu deseja escolher algum estado? \n");
				printf("1. Sim\n");
				printf("2. Não\n");
				printf("-- Digite sua escolha: ");
				scanf("%d", &c);
			}while(c<=0 || c>=3);
		
		switch (c) 
			{
				case 1:
					clear();
					for(i=0;i<10;i++)
						{
							printf("\nNúmero; %i",i);
							estado(i);	
						}
					do
						{
							printf("\n\nQual estado tu deseja? \n");
							printf("\n-- Digite sua escolha: ");
							scanf("%d", &c);
						}while(c<0 || c>10);
						criado[8] = c;
					break;
				case 2:
						criado[8] = rand() % 10;
					break;
						
					}
		
		for(i=0;i<8;i++)
			{
				criado[i] = rand() % 10;
			}
		
		codigo(criado, 10 , 0);
		codigo(criado, 11 , 0);
		
		clear();
		printf("O CPF; ");
		imprimircpf(criado);
		printf(" é válido");
		estado(criado[8]);
		getchar();
		getchar();
	}
	
int main(int argc, char *argv[]) 
	{
		
		setlocale(LC_ALL, "Portuguese");
		
		char cpf[11];
		int i,j;
		
		int resposta;
		
		
		
		for (;;) 
			{
				clear();
				resposta = menu();
				switch (resposta) 
					{
						case 1:
							clear();
							printf("Por favor insira o CPF para a verificação; ");
							ler_cpf(cpf);
							conversao(cpf);
							getchar();
							break;
						case 2:
							clear();
							criacao();
							break;
						case 3:
							exit(0);
							break;
					}
			}
		
	}

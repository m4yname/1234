/*
Regras do Jogo da Velha
--> O tabuleiro  é uma matriz 5x5 sendo, três linhas por três colunas.
o espaço para jogo. Os demais espaços serão as demarcações do desenho.
--> Dois jogadores escolhem uma marcação cada um.
Para o jogador 1 - (x)
Para o jogador 2 - (o)
--> Os jogadores jogam alternadamente, uma marcação por vez, 
numa lacuna que esteja vazia. Seu programa não poderá permitir que 
uma jogada sobreponha a outra jogada. 
Ou preencher sobre o desenho 
ou valores maiores que o tamanho da matriz.
-->O objetivo é conseguir três círculos ou três xis em linha, coluna
ou diagonais(principal ou secundária).
--> Quando um jogador conquistar o objetivo, 
seu programa deverá imprimir 
qual jogador ganhou e uma mensagem de sucesso.
Se os dois jogadores jogarem sempre da melhor forma, o jogo 
terminará sempre em empate e seu programa imprimir a mensagem empate.
********************************************************************
*-Retirar todos os comentários do código,com exceção do cabeçalho  *            
*-Trabalhos copiados do colega e/ou internet 					   *
* automaticamente  serão zerados								   *	
*-Cada função funcionando valerá 0,4							   *	
*-Demais códigos: 												   *
*  $Seu programa não poderá permitir que uma jogada 			   * 
*   sobreponha a outra jogada[...].(0,25)						   *
*  $Mensagem de sucesso correta(0,25)							   *
*-Fechando 2,5                             						   *
********************************************************************/


/************************
Aluno(a):
Aluno(a):
Turma: 228B
Data:
************************/

#include<stdio.h>
#include<stdlib.h>
const int t = 5;
/*const significa que a variavel t nunca será alterada
no código todo. 
Toda variavel declarada antes das funções são chamadas de global
ou seja, t é visivel em todo o código 
por isso não precisamos declarar dentro das funções.
*/
void inicializaMatriz(char v[t][t]){
	/*
		Essa funcao desenha o jogo da velha na matriz
		observe que os campos do jogo sao apenas numeros
		pares.
	*/
	for(int i = 0; i < t; i++){
		for(int j = 0; j < t; j++){
			if(i % 2 != 0 && j % 2 == 0)
				v[i][j] = '-';
			else if(i % 2 == 0 && j % 2 != 0)
				v[i][j] = '|';
			else if(i % 2 == 0 && j % 2 == 0) // campos do jogo...  
				v[i][j] = ' ';
			else if(i % 2 != 0 && j % 2 != 0)  
				v[i][j] = '+';	
		}	
	}
}
void imprimeMatriz(char v[t][t]){
	printf(" ");
	for(int j = 0; j < t; j++){ // o primeiro for mostra as 
								// coordenadas para o jogo
			if(j % 2 != 0){
				printf("  ");			
			}else{
				if(j==0){
					printf(" %d ", j);	
				}else{
					printf("%d ", j);	
				}
								
			}			
	}
	printf("\n");
	// imprime a matriz 
	for(int i = 0; i < t; i++){
		for(int j = 0; j < t; j++){
			if(j == 0){
				if(i % 2 != 0){
				printf("  ");			
				}else{
					printf("%d ", i);				
				}
						
			}	
			printf("%c ", v[i][j]);			
		}
		printf("\n");	
	}
}
int verificaLinha(char jog, char v[t][t], int linha){
	int coluna=0, acertosTemp =0;
	while(coluna<t){
		for(linha=0;linha<t;linha++){
			if(jog == v[coluna][linha]){
				acertosTemp++;
			}
		}
		if(acertosTemp== 3){
			return 1;
			break;}
		else{
		acertosTemp=0;}
		coluna++;
		if(coluna ==t){
			return 0;
		}
	}
	/* Essa função verifica se a linha passada no parametro 
	possui as tres posicoes iguais a variavel jog ('x' ou 'o')
	x | x | x ou o | o | o
	- + - + -    - + - + - 
	  |   |        |   |  
	- + - + -    - + - + - 
	  |   |        |   |
	retorna 1
	o | x | x ou o | o | x
	- + - + -    - + - + - 
	  |   |        |   |  
	- + - + -    - + - + - 
	  |   |        |   |
	retorna 0
	caso as tres posicoes da linha sejam iguais, essa funcao deverá
	retornar 1, caso contrario 0. 
	*/
}
int verificaColuna(char jog, char v[t][t], int coluna){
	coluna=0;
	int acertosTemp =0, linha;
		while(coluna <t){
			for(linha=0;linha<t;linha++){
				if(coluna == linha){
					if(v[coluna][linha]== jog){
						acertosTemp++;	
				}
			}
		}
		if(acertosTemp==3){
			return 1;
			break;
		}
		else{
			acertosTemp=0;
			coluna++;
		}
	}
	/* Essa função verifica se a coluna passada no parametro 
	possui as tres posicoes iguais a variavel jog ('x' ou 'o')
	x |   |   ou o |   | 
	- + - + -    - + - + - 
	x |   |      o |   |  
	- + - + -    - + - + - 
	x |   |      o |   |
	retorna 1
	x |   |   ou x |   | 
	- + - + -    - + - + - 
	o |   |      o |   |  
	- + - + -    - + - + - 
	x |   |      o |   |
	retorna 0
	caso as tres posicoes da colunas sejam iguais, essa funcao deverá
	retornar 1, caso contrario 0. 
	*/
}
int verificaDigPrinc(char jog, char v[t][t]){
	int i,acm;
	for (i=0;i<5;i=i+2){
		if(v[i][i]==jog){
			acm++;
		}
	}
	if (acm==3){
		return 1;
	}
	else 
		return 0;
	/* Essa função verifica se a diagonal principal 
	possui as tres posicoes iguais a variavel jog ('x' ou 'o')
	x |   |   ou o |   | 
	- + - + -    - + - + - 
	  | x |        | o |  
	- + - + -    - + - + - 
	  |   | x      |   | o
	retorna 1
	x |   |   ou o |   | 
	- + - + -    - + - + - 
	  | x |        | x |  
	- + - + -    - + - + - 
	  |   | o      |   | o
	retorna 0
	caso as tres posicoes da diagonal principal sejam iguais, essa funcao deverá
	retornar 1, caso contrario 0. 
	*/
}
int verificaDigSec(char jog, char v[t][t]){
	int x,y,acm; //x=linha y= coluna
	x = 0;
	y = 5;
	while (x < 5){
		if(v[x][y]==jog){
			acm ++;
		}
		x ++;
		y --;
	}   
	if (acm==3){
		return 1;
	}
	else
		return 0;
	
	/* Essa função verifica se a diagonal secundaria 
	possui as tres posicoes iguais a variavel jog ('x' ou 'o')
	  |   | x  ou   |   | o
	- + - + -     - + - + - 
	  | x |         | o |  
	- + - + -     - + - + - 
	x |   |       o |   | 
	retorna 1
	  |   | x  ou   |   | o
	- + - + -     - + - + - 
	  | x |         | x |  
	- + - + -     - + - + - 
	o |   |       o |   | 
	retorna 0
	caso as tres posicoes da diagonal secundaria sejam iguais, essa funcao deverá
	retornar 1, caso contrario 0. 
	*/
}

int verificaJogada(int tam, int l, int c, int lin[], int col[]){
 /*Essa funcao verifica se os valores passados em l(linha) e c(coluna) ja existem
 no vetor lin e col que contem respectivamente as coordenadas
 ja jogadas. 
    0    2   4    
  0  x | o |   
	 - + - + -     
  2	   |   |     
  	 - + - + -
  4    |   | x  
lin e col armazenam as coordenadas já jogadas
	  _ _ _
 lin |0|0|4|.... 
 	  _ _ _
 col |0|2|4|....   
 */
}
int main(){
	char v[t][t];	
	inicializaMatriz(v);
	imprimeMatriz(v);
	verificaLinha(jog,v,linha);
	verificaColuna(jog,v,coluna);
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void pvp();
void pve();
void ranking();
char confere_linha(char** mat,int a,char marc);
char confere_coluna(char** mat,int a,char marc);
char confere_diagonal1(char** mat,int a,char marc);
char confere_diagonal2(char** mat,int a,char marc);
char confere_empate(char** mat,int a);
void mostra_matriz(char** mat,int a);
void vez_do_computador(int n,int* vet,char marc,char** mat,int a);
int main(){
	int b;
	do{
		puts("bem vindo ao menu do jogo da velha:\n1 para pvp\n2 para pve \n3 para ver ranking\n4 para sair\n5 para creditos");
		scanf("%d",&b);
		switch(b){
			case(1):
				pvp();
				break;
			case(2):
				pve();
				break;
			case (3):
				void ranking();
				break;
			case (4):
				puts("obrigado por escolher nosso programa, ate outra hora");
				break;
			case(5):
				puts("creditos:\nTiago Veloso\nElder de Sousa\n\n");
				break;	
			default:
				puts("comando invalido");
				break;			
		}	
	}while(b!=4);
	return 0;
}
void pvp(){
	int a,i,j,marc,coord1,coord2,res=0;
	char marc1,marc2,marc3;
	puts("informe o tamanho do jogo da velha(de 3 a 10):");
	scanf("%d",&a);
	if(a<3||a>10){
		puts("numero invalido");
		return ;
	}
	char** mat=(char**)malloc(a*sizeof(char*));
	for(i=0;i<a;i++){
		mat[i]=(char*)malloc(a*sizeof(char));
	}
	for(i=0;i<a;i++){
		for(j=0;j<a;j++){
			mat[i][j]='-';		
		}
	}
	do{
		puts("o jogador numero 1 sera X ou O?(1 para X, 2 para O):");
		scanf("%d",&marc);
		if(marc!=1&&marc!=2){
			puts("numero invalido, tente novamente");
		}}while(marc!=1&&marc!=2);
	if(marc==1){
		marc1='X';
		marc2='O';
	}	
	else{
		marc1='O';
		marc2='X';	
	}
	do{
		errado:
		do{
			i=0;
			printf("selecione as coordenadas onde voce quer marcar %c(de 1 a %d)",marc1,a);
			scanf("%d%d",&coord1,&coord2);
			if(coord1<1||coord1>a||coord2<1||coord2>a){
				puts("coordenada invalida,tente novamente");}
			else{
				i++;
			}	
			}while(i==0);
		if(mat[coord1-1][coord2-1]=='X'||mat[coord1-1][coord2-1]=='O'){
			printf("espaco ja ocupado, tente novamente:\n");
			goto errado;
		}
		else{
			mat[coord1-1][coord2-1]=marc1;
		}
		system("cls");
		mostra_matriz(mat,a);
		marc3=marc1;
		if(confere_linha(mat,a,marc3)=='a'||confere_coluna(mat,a,marc3)=='a'||confere_diagonal1(mat,a,marc3)=='a'||confere_diagonal2(mat,a,marc3)=='a'||confere_empate(mat,a)=='a'){
			goto fim;
		}
		errado2:
		do{
			i=0;
			printf("selecione as coordenadas onde voce quer marcar %c(de 1 a %d)",marc2,a);
			scanf("%d%d",&coord1,&coord2);
			if(coord1<1||coord1>a||coord2<1||coord2>a){
				puts("coordenada invalida,tente novamente");}
			else{
				i++;
			}	
			}while(i==0);
		if(mat[coord1-1][coord2-1]=='X'||mat[coord1-1][coord2-1]=='O'){
			printf("espaco ja ocupado, tente novamente:\n");
			goto errado2;
		}
		else{
			mat[coord1-1][coord2-1]=marc2;
		}
		system("cls");
		mostra_matriz(mat,a);
		marc3=marc2;
		if(confere_linha(mat,a,marc3)=='a'||confere_coluna(mat,a,marc3)=='a'||confere_diagonal1(mat,a,marc3)=='a'||confere_diagonal2(mat,a,marc3)=='a'||confere_empate(mat,a)=='a'){
			goto fim;
		}							
	}while (res!=1);
	fim:	
	free(mat);
	return ;
}
void pve(){
	int a,b=0,c,d,i,j,marc,coord1,coord2,res=0,n,jogador;
	int* vet;
	char marc1,marc2,marc3;
	puts("informe o tamanho do jogo da velha(de 3 a 10):");
	scanf("%d",&a);
	if(a<3||a>10){
		puts("numero invalido");
		return ;
	}
	char** mat=(char**)malloc(a*sizeof(char*));
	for(i=0;i<a;i++){
		mat[i]=(char*)malloc(a*sizeof(char));
	}
	for(i=0;i<a;i++){
		for(j=0;j<a;j++){
			mat[i][j]='-';		
		}
	}
	do{
		puts("voce sera X ou O?(1 para X, 2 para O):");
		scanf("%d",&marc);
		if(marc!=1&&marc!=2){
			puts("numero invalido, tente novamente");
		}}while(marc!=1&&marc!=2);
	if(marc==1){
		marc1='X';
		marc2='O';
	}	
	else{
		marc1='O';
		marc2='X';	
	}
	do{
		puts("deseja ser o primeiro ou o segundo jogador?(1 para primeiro,2 para segundo)");
		scanf("%d",&jogador);
		if(jogador!=1&&jogador!=2){
			puts("numero invalido,tente novamente");
		}
	}while(jogador!=1&&jogador!=2);
	if(jogador==1){
		do{
		do{
			if(b==0){
				n=a*a-1;
				b++;
				vet=(int*)malloc(sizeof(int)*(a*a));
				for(i=0;i<=a*a;i++){
					vet[i]=i;
				}
			}
			errado:
			i=0;
			printf("selecione as coordenadas onde voce quer marcar %c(de 1 a %d)",marc1,a);
			scanf("%d%d",&coord1,&coord2);
			if(coord1<1||coord1>a||coord2<1||coord2>a){
				puts("coordenada invalida,tente novamente");}
			else{
				i++;
			}	
			}while(i==0);
		if(mat[coord1-1][coord2-1]=='X'||mat[coord1-1][coord2-1]=='O'){
			printf("espaco ja ocupado, tente novamente:\n");
			goto errado;
		}
		else{
			mat[coord1-1][coord2-1]=marc1;
		}
		system("cls");
		mostra_matriz(mat,a);
		marc3=marc1;
		if(confere_linha(mat,a,marc3)=='a'||confere_coluna(mat,a,marc3)=='a'||confere_diagonal1(mat,a,marc3)=='a'||confere_diagonal2(mat,a,marc3)=='a'||confere_empate(mat,a)=='a'){
			goto fim;	
		}
		c=a*(coord1-1)+(coord2-1);
		for(i=0;i<=n;i++){
			if(vet[i]==c){
				d=vet[i];
				vet[i]=vet[n];
				vet[n]=d;
			}
		}
		n--;
		vez_do_computador(n,vet,marc2,mat,a);
		system("cls");
		mostra_matriz(mat,a);
		marc3=marc2;
		if(confere_linha(mat,a,marc3)=='a'||confere_coluna(mat,a,marc3)=='a'||confere_diagonal1(mat,a,marc3)=='a'||confere_diagonal2(mat,a,marc3)=='a'||confere_empate(mat,a)=='a'){
			goto fim;	
		}
		n--;
	}while(res!=1);
}
	else{
		if(b==0){
				n=a*a-1;
				b++;
				vet=(int*)malloc(sizeof(int)*(a*a));
				for(i=0;i<=a*a;i++){
					vet[i]=i;
				}
			}
		do{
		vez_do_computador(n,vet,marc2,mat,a);
		system("cls");
		mostra_matriz(mat,a);
		marc3=marc2;
		if(confere_linha(mat,a,marc3)=='a'||confere_coluna(mat,a,marc3)=='a'||confere_diagonal1(mat,a,marc3)=='a'||confere_diagonal2(mat,a,marc3)=='a'||confere_empate(mat,a)=='a'){
			goto fim;	
		}
		n--;
		do{
			errado4:
			i=0;
			printf("selecione as coordenadas onde voce quer marcar %c(de 1 a %d)",marc1,a);
			scanf("%d%d",&coord1,&coord2);
			if(coord1<1||coord1>a||coord2<1||coord2>a){
				puts("coordenada invalida,tente novamente");}
			else{
				i++;
			}	
			}while(i==0);
		if(mat[coord1-1][coord2-1]=='X'||mat[coord1-1][coord2-1]=='O'){
			printf("espaco ja ocupado, tente novamente:\n");
			goto errado4;
		}
		else{
			system("cls");
			mat[coord1-1][coord2-1]=marc1;
		}
		mostra_matriz(mat,a);
		marc3=marc1;
		if(confere_linha(mat,a,marc3)=='a'||confere_coluna(mat,a,marc3)=='a'||confere_diagonal1(mat,a,marc3)=='a'||confere_diagonal2(mat,a,marc3)=='a'||confere_empate(mat,a)=='a'){
			goto fim;	
		}
		c=a*(coord1-1)+(coord2-1);
		for(i=0;i<=n;i++){
			if(vet[i]==c){
				d=vet[i];
				vet[i]=vet[n];
				vet[n]=d;
			}
		}
		n--;	
		}while(res!=1);	
	}
	fim:
	free(vet);
	free(mat);
	return;
}
void mostra_matriz(char** mat,int a){
	int i,j;
	for(i=0;i<a;i++){
			for(j=0;j<a;j++){
				printf("%c\t",mat[i][j]);
			}
			printf("\n\n");
		}
}
char confere_linha(char** mat,int a,char marc){
	int i,j,qnt;
	for(i=0,qnt=0;i<a;i++){
			for(j=0;j<a;j++){
			if(mat[i][j]==marc){
				qnt++;
			}
			if(qnt==a){
				printf("fim do jogo, %c ganhou\n\n",marc);
				return 'a';
			}
			}
			qnt=0;}
}
char confere_coluna(char** mat,int a,char marc){
	int i,j,qnt;
		for(i=0,qnt=0;i<a;i++){
			for(j=0;j<a;j++){
			if(mat[j][i]==marc){
				qnt++;
			}
			if(qnt==a){
				printf("fim do jogo, %c ganhou\n\n",marc);
				return 'a';
			}
		}
		qnt=0;
		}
}
char confere_diagonal1(char** mat,int a,char marc){
	int i,j,qnt;
	for(i=0,j=0,qnt=0;j<a&&i<a;i++,j++){
			if(mat[i][j]==marc){
				qnt++;
		}}
		if(qnt==a){
				printf("fim do jogo, %c ganhou\n\n",marc);
				return 'a';
		}
}
char confere_diagonal2(char** mat,int a,char marc){
	int i,j,qnt;
	for(i=a-1,j=0,qnt=0;j<a&&i>=0;i--,j++){
			if(mat[i][j]==marc){
				qnt++;
		}}
		if(qnt==a){
				printf("fim do jogo, %c ganhou\n\n",marc);
				return 'a';
		}
}
char confere_empate(char** mat,int a){
	int i,j,qnt;
	for(i=0,qnt=0;i<a;i++){
			for(j=0;j<a;j++){
				if(mat[i][j]!='-'){
					qnt++;
				}
			}
		}
		if(qnt==a*a){
			puts("empate\n\n");
			return 'a';
		}
}
void vez_do_computador(int n,int* vet,char marc,char** mat,int a){
	int b,c;
	if(n==0){
		n++;
	}
	srand(time(NULL));
	b=rand()%n;
	mat[vet[b]/a][vet[b]%a]=marc;
	c=vet[b];
	vet[b]=vet[n];
	vet[n]=c;	
}

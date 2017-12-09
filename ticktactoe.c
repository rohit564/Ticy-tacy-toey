#include<stdio.h>
#include<time.h>
#include<stdlib.h>
char matrix [3][3]={};
int computermove()
{
	int flag=0;
	for(int i=0;i<3;i++)
	{
		for (int j = 0; j < 3; ++j)
		{
			if(!matrix [i][j])flag=1;
		}
	}
		

	if(!flag) return 0;
	srand(time(NULL));
	while(1)
	{
		int i=rand()%3;
		int j=rand()%3;
		if(!matrix [i][j])
		{
			matrix [i][j]='O';
			break;
		}
	}
	return 1;
}
void displaygrid()
{
	{
    printf("\n\n");
     
    printf("\t\t\t  %c | %c  | %c  \n", matrix[0][0],
                             matrix[0][1], matrix[0][2]);
    printf("\t\t\t--------------\n");
    printf("\t\t\t  %c | %c  | %c  \n", matrix[1][0],
                             matrix[1][1], matrix[1][2]);
    printf("\t\t\t--------------\n");
    printf("\t\t\t  %c | %c  | %c  \n\n", matrix[2][0],
                             matrix[2][1], matrix[2][2]);
  
    return;
}

	}
}
int checkXorO(char a,char b,char c)
{
	if(a=='X')if(b=='X')if(c=='X')return 1;
	if(a=='O')if(b=='O')if(c=='O')return -1;
	return 0;
}

int checkwin()
{
	for(int i=0;i<3;i++)if(checkXorO(matrix[i][0],matrix[i][1],matrix[i][2])==1) return 1;
	for(int i=0;i<3;i++)if(checkXorO(matrix[0][i],matrix[1][i],matrix[2][i])==1) return 1;
	if(checkXorO(matrix[0][0],matrix[1][1],matrix[2][2])==1)return 1;
	if(checkXorO(matrix[2][0],matrix[1][1],matrix[0][2])==1)return 1;
	for(int i=0;i<3;i++)if(checkXorO(matrix[i][0],matrix[i][1],matrix[i][2])==-1) return -1;
	for(int i=0;i<3;i++)if(checkXorO(matrix[0][i],matrix[1][i],matrix[2][i])==-1) return -1;
	if(checkXorO(matrix[0][0],matrix[1][1],matrix[2][2])==-1)return  -1;
	if(checkXorO(matrix[2][0],matrix[1][1],matrix[0][2])==-1)return  -1;

}




int main()
{
	int row,colunm;
	
	printf("THIS BEING TICK Y TACKY TOEY\n");
	printf("First turn is of the player\n");
	for(int i=0;i<9;i++)
	{
		printf("Enter row and column\n");
		
		while(1)
		{
			scanf("%d %d",&row,&colunm);
			fflush(stdin);
			if(row<=0||row>3||colunm<=0||colunm>3)
			{
				printf("Invalid move\n");
			}
			else{
			if(matrix [row-1][colunm-1]){
				printf("Invalid move\n");
			}
			else
			{
				matrix [row-1][colunm-1]='X';
				break;			
			}}
		}
		if(!computermove())
		{
			printf("Draw\n");
			break;
		}
		displaygrid();
		if(checkwin()==1){printf("You win\n");break;}
		if(checkwin()==-1){printf("You lose\n");break;}
			


	}
	printf("Game over\n");

}	


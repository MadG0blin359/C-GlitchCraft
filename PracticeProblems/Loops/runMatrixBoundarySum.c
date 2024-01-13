#include<stdio.h>

int main(){    
  int row,col;
  printf("Enter Rows & Coloumns for Array [Rows (space) Coloumns] : ");
  scanf("%d %d",&row,&col);
  
  int arr[row][col];
  int sum=0;

  for(int i=0; i<row; i++){
    for(int j=0; j<col; j++){
    printf("Enter Element for Row %d & Coloumn %d: ",i+1,j+1);
    scanf("%d", &arr[i][j]);
    }
  }

  for(int i = 0; i<row; i++){
    for(int j = 0; j<col; j++){
      if (i == 0 || j == 0 || i == row-1 || j == col-1){
        sum = sum + arr[i][j];
        printf("%d ", arr[i][j]);
      }
      
      else{
            printf(" ");
            printf(" ", arr[i][j]);
          }
    
    }
    
    printf("\n");
  
  }
  
  printf("Sum is: %d\n",sum);

}

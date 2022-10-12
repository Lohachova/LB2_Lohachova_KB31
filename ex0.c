#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

struct Node{
  int x;
  int y;
  int sizeOfStruct;
  int weight;
};


struct Node* Initiallization(int *size){
  srand(time(NULL));
  struct Node *arr;
  int N;
  printf("Введіть кількість точок: ");
  scanf("%d", &N);
  *size = N;
  arr = (struct Node*) malloc (N * sizeof(struct Node));
  arr->sizeOfStruct = N;
  int i;
  for(i = 0; i < N; i++){
    (arr + i)->x = rand() % 20;
    (arr + i)->y = rand() % 20;
    (arr + i)->weight = (rand() % 89) + 10;
  }    
  return arr;
}

void node_print(struct Node* arr){
  int i; 
  for (i = 0; i < arr->sizeOfStruct; i++){
    printf("Адреса = %p,  Точка #%2d: (%2d, %2d) Вага = %d, Розмір = %d\n",(arr+i), i, (arr + i)->x, (arr + i)->y, (arr + i)->weight, arr->sizeOfStruct);
  }
  printf("\n");  
}

struct Node* del_node(struct Node** arr, int index){
  struct Node* temp = (*arr + index);
  int i;
  for (i = index; i <= (*arr)->sizeOfStruct-1; i++){
    ((*arr) + i)->x = ((*arr) + i + 1)->x;
    ((*arr) + i)->y = ((*arr) + i + 1)->y;
    ((*arr) + i)->weight = ((*arr) + i + 1)->weight;
  }
  (*arr)->sizeOfStruct--;
  arr = (struct Node**) realloc (*arr, (*arr)->sizeOfStruct * sizeof(struct Node));
  return temp;  
}

int finde_min(struct Node* arr){
  struct Node* min = (arr + 0);
  int i, index = 0;
  for (i = 0; i < arr->sizeOfStruct; i++){
    if (((arr+i)->weight) < ((min)->weight)){
      min = (arr + i);
      index = i;
    }
    
  }
  return index;
}

void find_node(struct Node** arr){
  int minIndex = finde_min(*arr);
  struct Node* node = ((*arr) + minIndex);
  printf("Мінімальна вага =  %d\n",node->weight);
  int i;

  double minLen = 1000000;
  int cosestIndex = 0;
  if ((*arr)->sizeOfStruct != 1){
    for (i = 1; i < (*arr)->sizeOfStruct; i++){
      double len = ( (((*arr) + i)->x - node->x) * (((*arr) + i)->x - node->x)        +        (((*arr) + i)->y - node->y)  *   (((*arr) + i)->y - node->y) );
      if (minLen != 0){
        if ((len < minLen) && (len != 0)){
          minLen = len;
          cosestIndex = i;  
        }
      }
      
      
    }
    
    printf("Елемант:\n x = %d, y = %d, Вага = %d\nНайближчий елемант:\n x = %d, y = %d, Вага = %d\n\n", node->x, node->y, node->weight,  ((*arr) + cosestIndex)->x, ((*arr) + cosestIndex)->y, ((*arr) + cosestIndex)->weight );
   
    ((*arr) + cosestIndex)->weight = ((*arr) + cosestIndex)->weight + node->weight;
    del_node(arr, minIndex);
  }
  
}

int main(){
    int i;
  int size;
  struct Node *arr = Initiallization(&size);
  node_print(arr);
  for (i = 0; i < size-1; i++){
    find_node(&arr);
    node_print(arr);
  }
  
    return 0; 
}

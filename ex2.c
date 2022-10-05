#include <stdio.h>
#include <stdlib.h>

int main(){

  double arr[] = {7, 1, 5, 12, -1, 8, 10, -2, 0, 3};
  double num1 = 0, num2 = 0;
  double count = 0;
  int i, flag;
  
  printf("Ваш масив: ");
  for (i = 0; i < 10; i++){
    printf("%.0lf  ", arr[i]);
    }
  
  for (i = 0; i < 10; i++){
    count += arr[i];
  }
  count = count/10;
  printf("\nСереднье значення чисел масива: %lf\n", count);
  for (i = 0; i < 10; i++){
    if (arr[i] > count) num1++;
  }
  printf("Кількість елементів більше середнього значення елементів масива: %.0lf\n", num1);
  
  for (i = 0; i < 10; i++){
    if (arr[i] < 0) {
      flag = i;
      break;
    }
  }
    for (i = flag + 1; i < 7; i++) 
    num2 += abs(arr[i]);
    printf("Сума модулів елементів розташованих після першого від'ємного елемента: %.0lf\n", num2);
    
    return 0;
}


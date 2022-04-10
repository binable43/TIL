/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int list[])
{
	int min, temp;
	for (int i = 0; i < 19; i++)
	{
		min = i;
		for (int j = i + 1; j < 20; j++)
			if (list[j] < list[min])
				min = j;
		
		temp = list[min];
		list[min] = list[i];
		list[i] = temp;
	}
}

int binarySearchIter(int A[], int left, int right, int key) 
{
    int mid, count = 0;
    
    while(left <= right)
    {
        count++;
        mid = (left + right) / 2;
        
        if (key == A[mid])
            return count;
        else if (key < A[mid]) //key가 mid 보다 작을 경우 오른쪽은 볼 필요가 없음
            right = mid -1; //상한 값을 수정
        else
            left = mid + 1; //하한 값을 수정
    }
    return 0;
}

int main()
{
    int A[20], k;
    srand(time(NULL));
    for(int i = 0; i < 20; i++)
        A[i] = rand() % 100;
        
    selectionSort(A);    
    
    for(int i = 0; i < 20; i++)
        printf("%d ", A[i]);
    
    printf("\n");
    
    printf("Key : ");
    scanf("%d", &k);
    
    printf("%d\n", binarySearchIter(A, 0, 19, k));
    
    return 0;
}





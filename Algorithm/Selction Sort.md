## 선택정렬 Selection Sort

- 입력 배열 전체에서 최솟값 선택하여 배열의 0번 원소와 자리 교환. 0번 원소를 제외한 나머지 원소에서 최솟값 선택하여 배열의 1번 원소와 자리 교환
- 이러한 방식으로 마지막 2개의 원소 중 작은 것을 선택하여 자리 교환

```c
SelectionSort
입력 : 크기가 n인 배열 A
출력 : 정렬된 배열 A

1. for i = 0 to (n-2)
2.   min = i
3.   for j = (i+1) to (n-1)  // A[i] ~ A[n-1]에서 최솟값을 찾는다
4.     if A[j] < A[min]
5.       min = j
6.   A[i] <-> A[min]   // min이 최솟값이 있는 원소의 인덱스
7. return A
```
<br>

### 시간복잡도

O(n^2)

<br>

### 특징

- 항상 일정한 시간 복잡도를 가짐
    - 입력이 거의 정렬되어 있거나 역으로 정렬되거나 랜덤하게 되어 있든 상관 없음
- **입력에 민감하지 않은(input insensitive) 알고리즘**
- 원소 간의 자리바꿈 횟수가 최소인 알고리즘

<br>

## Reference
- [알기 쉬운 알고리즘 (양성봉 지음)](http://www.kyobobook.co.kr/product/detailViewKor.laf?mallGb=KOR&ejkGb=KOR&linkClass=&barcode=9788970504896)

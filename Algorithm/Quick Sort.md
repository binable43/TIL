# 퀵정렬

각 부분 문제의 크기가 일정하지 않은 2개의 부분 문제로 분할하는 분할 정복 알고리즘

<br>
<br>

**IDEA**

- pivot 이라고 불리는 배열의 원소(숫자)를 기준으로 pivot보다 작은 숫자들은 왼편, pivot보다 큰 숫자들은 오른편에 위치하도록 분할. pivot은 가운데 위치.
- 분할된 부분문제들에 대해 위와 동일한 과정을 순환으로 수행하며 정렬
- 이 때, pivot은 분할된 왼편이나 오른편에 포함되지 않음 (ex. [10,20,30,40,50,60]을 2개로 분할하여 pivot을 30이라고 했을 때, 30은 [10,20]이나 [40,50,60] 사이에 위치하며, 2개의 부분 문제에 포함되지 않는다)

<br>
<br>

**Pseudo-Code**

```c
QuickSort(A, left, right):
Input : A[left] ~ A[right]
Output : 정렬된 A[left] ~ A[right]

if (left<right) {
	select pivot

	pivot과 A[left] 자리 교환
	pivot과 각 자리의 원소 비교
	pivot보다 작은 숫자는 A[left]~A[p-1]에 위치
	pivot보다 큰 숫자는 A[p+1]~A[right]에 위치
	pivot = A[p]

	QuickSort(A, left, p-1)
	QuickSort(A, p+1, right)
}
```

<br>
<br>

**시간 복잡도**

퀵 정렬의 성능은 pivot을 어느 것으로 선택하느냐에 따라 달라진다. 만일 pivot으로 가장 작은 숫자나 가장 큰 숫자가 선택되면 한 부분으로 치우치는 분할이 된다.

- 최악의 경우
    - pivot으로 항상 가장 작은(큰) 숫자가 선택되는 경우
    - 시간복잡도 : $O(n^2)$
- 최선의 경우
    - 항상 1/2씩 분할, 입력의 중앙값이 pivot으로 선택되는 경우
    - 시간복잡도 : $O(n log_2n)$

<br>
<br>

**pivot 선정 방법**
- random으로 선정   
- 3개의 숫자들의 중앙값 (Median of Three)   
  - 가장 왼쪽, 가장 오른쪽, 가장 가운데 숫자 중 중앙값을 pivot으로 설정   
- 중앙값들 중에서 중앙값 (Median of Medians / Turkey’s Ninther)   
  - 입력을 3등분하여 각 부분에서 가장 왼쪽, 오른쪽, 가운데 숫자 중 중앙값을 찾음. 다시 3개의 중앙값들 중에서 중앙값을 pivot으로 설정

<br>
<br>

**성능 향상**

- 입력 크기가 매우 클 때 삽입 정렬을 동시에 사용하면 성능이 향상될 수 있다!   
- 입력 크기가 작을 때는 퀵 정렬이 삽입 정렬보다 빠르지만은 않다. 퀵 정렬은 순환 호출로 수행되기 때문에   
- 부분 문제의 크기가 작아지면 더 이상의 분할(순환 호출)은 중단하고 삽입 정렬을 사용한다   

<br>
<br>

- 퀵 정렬은 커다란 크기의 입력에 대해 가장 좋은 성능을 보인다!
- 실질적으로 어떠한 정렬 알고리즘보다 좋은 성능을 보인다!
- 생물 정보 공학(Bioinformatics)에서 특정 유전자를 효율적으로 찾는데 접미 배열(suffix arrray)와 함께 퀵 정렬이 사용된다고 한다   

<br>
<br>

## Reference
- [알기 쉬운 알고리즘 (양성봉 지음)](http://www.kyobobook.co.kr/product/detailViewKor.laf?mallGb=KOR&ejkGb=KOR&linkClass=&barcode=9788970504896)

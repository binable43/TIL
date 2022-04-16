# 선택(selection) 문제 알고리즘

n개의 숫자들 중에서 k번째로 작은 숫자를 찾는 문제

<br>

단순한 알고리즘으로 접근했을 때..

1) 최소 숫자를 k번 찾는다. 단, 최소 숫자 찾은 뒤에는 입력에서 최소 숫자 제거

2) 숫자들을 정렬한 후, k번째 숫자를 찾는다

하지만 위의 알고리즘들은 각각 최악의 경우 O(kn)과 O(nlogn)의 시간복잡도가 필요

<br>
<br>

**IDEA**

임의의 숫자를 효율적으로 찾는 이진탐색(Binary Search)에서 아이디어를 얻어보자. 이진탐색은 정렬된 입력의 중간에 있는 숫자와 찾으려고 하는 숫자를 비교. 입력을 1/2로 나눈 두 개의 부분 중에서 한 부분만 검색.

<br>

선택문제는..

- 입력이 정렬되어 있지 않음 → pivot 선택하여 분할 (퀵 정렬처럼!)
- small group : pivot보다 작은 숫자 그룹
- large group : pivot보다 큰 숫자 그룹
- 각 group의 크기를 알면, k번째 작은 숫자가 어느 group에 속하는지 알 수 있다 → 그 group에서 몇 번째로 작은 숫자를 찾는지 알 수 있음

<br>

- small group에 k번째 작은 숫자가 있는 경우
    - small group에서 k번째로 작은 숫자를 찾으면 됨!
- large group에 k번째 작은 숫자가 있는 경우
    - (k - |small group| - 1)번째로 작은 숫자를 large group에서 찾으면 됨!
    - |small group| = small group에 속한 숫자 개수, 1 = pivot
    
<br>
<br>

**Pseudo-Code**

```c
Selection(A, left, right, k):
Input : A[left] ~ A[right], k (단, 1=<k=<|A|, |A|=right-left+1)
Output : A[left] ~ A[right]에서 k번째 작은 원소

A[left]~A[right] 중에서 pivot 랜덤하게 선택
A[left]와 pivot 자리 교체
pivot과 각 원소 비교

pivot은 A[p]에 위치
if (pivot보다 작을 경우):
	A[left] ~ A[p-1]에 위치
else if (pivot보다 클 경우):
	A[p+1] ~ A[right]에 위치

// S = small group의 크기
S = (p-1) - left + 1

if (k =< S):   // small group에서 찾기
	Selection(A, left, p-1, k)
else if (k = S+1):   // pivot = k번째 작은 숫자
	return A[p]
else:    // large group에서 찾기
	Selection(A, p+1, right, k-S-1)
```

<br>
<br>

**고려사항**

- 분할 정복 알고리즘이기도 하지만 랜덤(random) 알고리즘이기도 하다 → 맨 처음 pivot을 random하게 정하기 때문
- pivot이 입력을 너무 한쪽으로 치우치게 분할하면 알고리즘 수행시간이 길어진다
    - |Small group| << |Large group| or |Small group| >> |Large group|
- 선택 알고리즘 호출될 때마다 line1에서 입력을 한쪽으로 치우치게 분할될 확률은?
    - 동전 던지기에서 한쪽 면만 나올 확률, 즉 1/2

<br>
<br>

**좋은/나쁜 분할 정의**

- 나쁜(Bad) 분할 : 분할된 두 그룹 중 하나의 크기가 입력 크기의 3/4과 같거나 그보다 크게 분할될 경우
- 좋은(Good) 분할 : 나쁜 분할의 반대의 경우
- 좋은 분할이 되는 pivot을 선택할 확률 = 나쁜 분할이 되는 pivot을 선택할 확률 = 1/2

<br>
<br>

**시간복잡도**

- pivot을 random하게 정했을 때, 좋은 분할이 될 확률이 1/2이므로, 평균적으로 2회 연속 pivot을 랜덤하게 정하면 좋은 분할을 할 수 있다.
- 매 2회 호출마다 좋은 분할이 된다 (like 앞면이 나올 때까지 동전을 평균 2회 던져야한다)
    - 평균 시간복잡도는 좋은 분할만 연속으로 이루어졌을 때만의 시간복잡도 구한 후 x2하면 구할 수 있다

<img width="629" alt="스크린샷 2022-04-16 오후 5 23 52" src="https://user-images.githubusercontent.com/81629116/163668016-7ffd4f2f-71f3-48e6-87e2-7d59f9ae3028.png">

    
- 평균 2회마다 좋은 분할이 되므로 2 x O(n) = O(n)

<br>
<br>

**선택 알고리즘 & 이진탐색**

- 유사성
    - 이진탐색 : 분할과정 진행하면서 범위를 1/2로 좁혀가며 숫자 탐색
    - 선택 알고리즘 : pivot으로 분할하여 범위 좁혀감
- 공통점
    - 부분 문제들을 취합하는 과정이 별도로 필요 x

<br>
<br>

**Applications**

- 선택 알고리즘은 정렬 하지 않고 k번째 작은 수를 선형 시간에 찾도록 함
- 데이터 분석을 위한 중앙값(median)을 찾는데 활용
    - 데이터 분석에서는 평균값도 유용하지만 경우에 따라 median이 더 설득력 제공

<br>
<br>

## Reference
- [알기 쉬운 알고리즘 (양성봉 지음)](http://www.kyobobook.co.kr/product/detailViewKor.laf?mallGb=KOR&ejkGb=KOR&linkClass=&barcode=9788970504896)

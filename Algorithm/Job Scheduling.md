# 작업 스케줄링 (Job Scheduling) 문제

작업의 수행 시간이 중복되지 않도록 모든 작업을 가장 적은 수의 기계에 배정하는 문제. 학술대회에서 발표자들(=작업)을 강의실(=기계)에 배정하는 문제와 같다.

작업 스케줄링 문제에서 ‘작업의 수’는 입력의 크기이며, 알고리즘을 고안하기 위해 고려해야 하는 직접적인 요소는 아니다. 이 외에도 각 작업의 시작시간과 종료시간, 작업의 길이 등의 문제 요소가 주어진다.

<br>

작업 스케줄링 문제는 시작시간, 종료시간, 작업길이에 따라 각각 다른 방식으로 그리디 알고리즘을 적용할 수 있다.

- 빠른 시작시간 작업 우선 (Earliest start time first) 배정
- 빠른 종료시간 작업 우선 (Earliest finish time first) 배정
- 짧은 작업 우선 (Shortest job first) 배정
- 긴 작업 우선 (Longest job first) 배정

→ 위 중에서 1번째 알고리즘을 제외하고 나머지 3가지는 항상 최적해를 찾지 못한다

<br>
<br>

**Pseudo-Code**

```c
JobScheduling():
Input : n개의 작업 t1, t2... tn
Output : 각 기계에 배정된 작업 순서

시작 시간으로 정렬한 작업 리스트 : L
while L ≠ ∅
	L에서 가장 빠른 시작 시간 작업 ti를 가져온다
	if ti를 수행할 기계가 있으면
		ti를 수행할 수 있는 기계에 배정
	else
		새 기계에 ti 배정
	ti를 L에서 제거
return 각 기계에 배정된 작업 순서
```

<br>
<br>

**시간복잡도**

- 시작 시간 기준으로 작업 리스트 정렬 : O(nlogn)
- while-loop에서 수행 가능한 기계 m개에 배정 & while-loop n 번 수행 : O(mn)

→ O(nlogn) + O(mn)

<br>
<br>

**Application**

- 비즈니스 프로세싱
- 공장 생산 공정
- 강의실/세미나 룸 배정
- 컴퓨터 태스크 스케줄링

<br>
<br>

## Reference
- [알기 쉬운 알고리즘 (양성봉 지음)](http://www.kyobobook.co.kr/product/detailViewKor.laf?mallGb=KOR&ejkGb=KOR&linkClass=&barcode=9788970504896)

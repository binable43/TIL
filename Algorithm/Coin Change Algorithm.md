# 동전 거스름돈 문제 (Coin Change)

**가장 간단하고 효율적인 방법**

남은 액수를 초과하지 않는 조건 하에서 ‘욕심 내서' = 최대한 가장 큰 액면의 동전을 취하는 것

→ 그리디 알고리즘을 통해 최소 동전 수를 찾을 수 있다

<br>
<br>

**Pseudo-Code**

500원, 100원, 50원, 10원, 1원의 동전이 있을 때 거스름돈 액수에 대한 최소 동전 수는 아래와 같이 구할 수 있다.

```c
CoinChange():
Input : 거스름돈 액수 W
Output : 거스름돈 액수에 대한 최소 동전의 수

change = W
n500 = n100 = n50 = n10 = n1 = 0  // 각 동전의 카운트 수

while (change >= 500)
	change = change - 500, n500++     // 500원 동전의 수 1개 증가
while (change >= 100)
	change = change - 100, n100++     // 100원 동전의 수 1개 증가
while (change >= 50)
	change = change - 50, n50++       // 50원 동전의 수 1개 증가
while (change >= 10)
	change = change - 10, n10++       // 10원 동전의 수 1개 증가
while (change >= 1)
	change = chagne -1, n1++          // 1원 동전의 수 1개 증가

return (n500 + n100 + n50 + n10 + n1)  // 총 동전의 수 return
```

<br>
<br>

**Coin Change 알고리즘의 특성**

- 남아있는 거스름돈인 change에 대해 가장 높은 액면의 동전을 거스른다
- 예를 들어 500원 동전을 처리하는 while문에서 100원, 50원, 10원, 1원 동전을 몇 개씩 거슬러 주어야 하는지에 대해서는 전혀 고려하지 않는다 → 그리디 알고리즘의 근시안적인 특성

<br>
<br>

**Coin Change 알고리즘의 문제점**

- 만일 은행에서 160원짜리 동전을 추가로 새로 발행한다면 Coin Change 알고리즘은 항상 최소 동전 수를 계산할 수 있을까?
- 200원의 거스름돈에 대하여 Coin Change 알고리즘은 160원 동전 1개와 10원 동전 4개, 총 5개의 동전을 리턴할 것이다 → 최적의 답이 아님! 최적의 답은 100원짜리 2개
- Coin Change 알고리즘은 항상 최적의 답을 주지 못한다.
- 그러나 실제로 거스름돈에 대한 그리디 알고리즘이 적용되도록 동전이 발행된다.

<br>
<br>

## Reference
- [알기 쉬운 알고리즘 (양성봉 지음)](http://www.kyobobook.co.kr/product/detailViewKor.laf?mallGb=KOR&ejkGb=KOR&linkClass=&barcode=9788970504896)

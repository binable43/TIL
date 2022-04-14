# 합병정렬
입력이 2개인 부분문제로 분할되고, 부분문제의 크기가 1/2로 감소하는 분할 정복 알고리즘

- 합병정렬 과정
  1) 분할 (Divide)   
입력 배열 n개의 숫자들을 같은 크기의 2개의 부분 문제(부분 배열)로 분할
    
  2) 정복 (Conquer)   
각 부분 문제 정렬. 만일 부분 배열의 크기가 충분히 작지 않을 경우 순환적으로 분할-정복
    
  3) 합병 (Merge)   
정렬된 부분을 합병하여 하나의 배열로 정렬
    
    - 실제로 정렬이 이루어지는 것은 line 7에서 2개의 배열을 합병(Merge)하는 과정이다   
    
    
![Mergesort](https://user-images.githubusercontent.com/81629116/159433410-f13136cb-adfa-4e36-a205-676a9f2f71c6.png)
<p align="left">Merge Sort : Khan Acamedy<p align="left">

<br>
<br>
  
- 단점
    - 대부분의 정렬 알고리즘들은 입력을 위한 메모리 공간과 O(1) 크기의 메모리 공간만 사용하여 정렬
    - O(1) 크기의 메모리 공간 : 입력 크기 n과 상관 없는 크기의 공간 (ex. 변수, 인덱스 등)
    - 하지만 합병 정렬의 공간 복잡도는 O(n)으로, 입력을 위한 메모리 공간(입력 배열) 외에 추가로 입력과 같은 크기의 임시 배열 공간이 별도로 필요
    - 2개의 정렬된 부분을 하나로 합병하기 위해 합병된 결과를 저장할 곳이 필요하기 때문
  
<br>
<br>
  
- 합병정렬은 외부정렬의 기본이 되는 알고리즘
- 연결리스트에 있는 데이터를 정렬할 때 퀵 정렬이나 힙 정렬보다 훨씬 효율적
- 멀티코어(Multi-Core) CPU와 다수의 프로세서로 구성된 그래픽 처리 장치(Graphic Processing Unit)의 등장으로 정렬 알고리즘을 병렬화하는데 합병정렬 알고리즘이 활용됨   
  
<br>
<br>
  
## Reference
- [알기 쉬운 알고리즘 (양성봉 지음)](http://www.kyobobook.co.kr/product/detailViewKor.laf?mallGb=KOR&ejkGb=KOR&linkClass=&barcode=9788970504896)

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

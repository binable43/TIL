# 최근접 점의 쌍 찾기 (Closest Pair)

2차원 평면 상의 n개의 점이 입력으로 주어질 때, 거리가 가장 가까운 한 쌍의 점을 찾는 문제. 기상 예보, 충돌 탐지, 계층적 클러스터링 등에서 다양하게 응용됨.

<br>
<br>

**간단한 방법**

- 모든 점에 대하여 각각의 두 점 사이의 거리를 계산하여 가장 가까운 점의 쌍 찾기
    - 무차별 대입 알고리즘 (brute force algorithm)
- 시간 복잡도 : O(n^2)

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define N 10

// 한 점의 x좌표와 y좌표를 저장하는 구조체 선언
typedef struct
{
    int x, y;
}Point;

void print(Point p[]) {
    for (int i = 0 ; i<N ; i++) {
        printf("[%d %d]", p[i].x, p[i].y);
    }
    printf("\n");
}

double dist(Point p1, Point p2) {
    return sqrt(pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2));
}

void closestPairIter(Point p[]) {
    double dMin = 10000000.0, d;
    int iMin, jMin;

    for (int i=0 ; i<N ; i++) {
        for (int j=i+1 ; j<N ; j++) {
            d = dist(p[i], p[j]);
            if (d < dMin) {
                dMin = d;
                iMin = i;
                jMin = j;
            }
        }
    }

    printf("[%d %d] [%d %d] %.2f\n", p[iMin].x, p[iMin].y, p[jMin].x, p[jMin].y, dMin);
}

int main() {    
    Point p[N];
    srand(time(NULL));

    for (int i=0 ; i<N ; i++) {
        p[i].x = rand() % 100;
        p[i].y = rand() % 50;
    }

    print(p);

    closestPairIter(p);

    return 0;
}
```

<br>
<br>

**분할 정복 이용하여 찾기**

- solution
    - n개의 점을 1/2로 분할하여 각각의 부분 문제 중 최근접 점의 쌍 찾음
    - 2개의 부분 해 중에서 짧은 거리를 가진 점의 쌍 찾음
    - 중간 영역 안에 있는 점들 중 최근접 쌍이 있는지 확인

- Pseudo Code

```c
ClosestPair(S):
Input : x-좌표의 오름차순으로 정렬된 배열 S. S에는 (x,y)로 표현되는 i개의 점
Output : S에 있는 점들 중 최근접 점의 쌍의 거리

if (i =< 3)
	return (2 또는 3개의 점들 사이의 최근접 쌍)

정렬된 S를 같은 크기의 S_L과 S_R로 분할. 단 |S|가 홀수면, |S_L|=|S_R|+1이 되도록.
CP_L = ClosestPair(S_L)  // CP_L은 S_L에서 최근접 점의 쌍
CP_R = ClosestPair(S_R)  // CP_R은 S_R에서 최근접 점의 쌍

d = min{dist(CP_L), dist(CP_R)}  // dist는 두 점 사이의 거리
중간 영역에 속하는 점들 중 최근접 점의 쌍을 찾아서 이를 CP_C라고 하자

return (CP_L, CP_C, CP_R 중 거리가 가장 짧은 쌍)
```

<br>
<br>

**시간복잡도**

- S의 n개의 점들 중 전처리 과정으로서 x-좌표 기준으로 정렬 : O(nlogn)
- S에 2개/3개의 점이 있을 때 각각 1번/2번의 거리 계산이 필요 : O(1)
- 정렬된 S를 S_L과 S_R로 분할할 때 이미 배열에 정렬되어 있으므로 배열 중간 인덱스로 분할 : O(1)
- S_L과 S_R에 대하여 각각 ClosestPair를 호출하는데, 분할되며 호출하는 과정은 합병 정렬과 동일
- d = min{dist(CP_L), dist(CP_R)} 일 때, 중간 영역에 속하는 점들 중 최근접 점의 쌍을 찾음. 이 때 중간 영역 점들을 y-좌표 기준으로 정렬(O(nlogn))하고, 아래에서 위로 올라가며 각 점에서 주변 점들 사이 거리 계산(O(1))
- 3개의 점의 쌍 중 가장 짧은 거리 가진 점의 쌍 리턴 : O(1)
- ClosestPair 알고리즘의 분할과정은 합병 정렬의 분할과정과 동일
    - But ClosestPair 알고리즘에서는 해를 취합하여 올라가는 과정에서 O(nlogn) 필요
- k층까지 분할된 후 층별로 취합되는 과정 : 각 층의 수행시간(O(nlogn)) * 층 수(logn) = O(n(logn)^2)

<br>
<br>

**Applications**

- 컴퓨터 그래픽스
- 컴퓨터 비전(Vision)
- 지리 정보 시스템 (Geographic Information System, GIS)
- 분자 모델링 (Molecular Modeling)
- 항공 트래픽 조정 (Air Traffic Control)
- 마케팅 (주유소, 프랜차이즈 신규 가맹점 등의 위치 선정) 등

## Reference
- [알기 쉬운 알고리즘 (양성봉 지음)](http://www.kyobobook.co.kr/product/detailViewKor.laf?mallGb=KOR&ejkGb=KOR&linkClass=&barcode=9788970504896)

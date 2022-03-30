# Pull Request (PR)

## 정의

original 소스에 내가 기여한 바가 있으니 해당 내용을 가져가주세요~ 라는 요청

## 목적

원본 저장소의 내용을 Fork해서 내 저장소로 가지고 온 후, 거기서 개발   
이후 내가 작업한 내용을 원본 저장소에 반영하길 원할 때 pull request!

## 방법

### 1) Fork   
원본 Repository를 내 저장소로 Fork 해온다

### 2) clone, remote 설정
```
$ git clone (url)
```

### 3) local에 원격 저장소 추가   
clone해온 origin을 원격저장소인 github에 추가
```
$ git remote add (별명) (url)
```

이때 fork, clone해온 프로젝트는 origin이라는 별명이 기본으로 추가

### 4) branch 생성
로컬에서 코드를 추가하기 위해 branch 생성
```
$ git checkout -b develop
```

### 5) 작업 후 add, commit, push
작업이 끝나면 Github repository에 add, commit, push
이 때, push할 때 branch 이름을 명시해야 함
```
$ git add .
$ git commit -m "commit message"
$ git push -u origin master
```

### 6) Pull Request 생성
push 완료한 후에 github에서 ```compare & pull request``` 버튼 활성
클릭하여 pull request 생성!

### 7) Merge Pull Request
PR 요청 받은 관리자는 변경 내용 확인하여 merge 여부 결정   
관리자가 승인하면 원격 저장소에 변경 내용이 반영되고 Pull Request는 closed로 변경


### 8) Merge 이후 동기화 및 branch 삭제
로컬 코드와 원본 저장소의 코드 병합, 최신 상태 유지하기 위해 동기화
```
$ git pull (remote 별명)
```

작업하던 로컬의 branch 삭제
```
$ git branch -d (브랜치 별명)
```

### Reference
[https://inpa.tistory.com/entry/GIT-%E2%9A%A1%EF%B8%8F-%EA%B9%83%ED%97%99-PRPull-Request-%EB%B3%B4%EB%82%B4%EB%8A%94-%EB%B0%A9%EB%B2%95-folk-issue](https://inpa.tistory.com/entry/GIT-%E2%9A%A1%EF%B8%8F-%EA%B9%83%ED%97%99-PRPull-Request-%EB%B3%B4%EB%82%B4%EB%8A%94-%EB%B0%A9%EB%B2%95-folk-issue)
[https://velog.io/@zansol/Pull-Request-%EC%9D%B4%ED%95%B4%ED%95%98%EA%B8%B0](https://velog.io/@zansol/Pull-Request-%EC%9D%B4%ED%95%B4%ED%95%98%EA%B8%B0)

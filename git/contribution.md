## Github 잔디가 안심어질 때 (contribution 표시)

### 브랜치 이름 바꿔보기 (main -> master)   
~~직접 시도해봤을 때 실패 ㅜㅜ~~

<br/>

### 프로젝트 email과 github에 등록된 email 확인   
- terminal에서 user name과 email 리셋
```
git config --global --unset user.name
git config --global --unset user.email
```

```
git config --global user.email "이메일주소"
git config --global user.name "계정이름"
```

- 간혹 global이 아니라 local로 설정해야 문제가 해결되는 경우도 있음
```
git config --local user.email "이메일주소"
git config --local user.name "계정이름"
```

<br/>

### SourceTree   
설정 - '전역사용자 설정사용' 해제 - Github에 등록되어있는 이메일인지 확인   
[SourceTree 커밋 후 잔디 심기](https://burning-camp.tistory.com/26)

<br/>

### 기타 사항
- github 계정 이메일에 온점(.)이 들어갈 경우 다른 이메일로 인식하는 경우도 있다고 함
  - 온점(.)이 빠진 버전의 이메일도 깃허브 계정에서 설정 필요
  - ex) ab.abcde@gmail.com  &  ababcde@gmail.com

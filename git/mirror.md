## fork해온 repository에서 작업한 내용들이 잔디로 심어지지 않을 때

1. Github에서 새로운 Repository 생성 (new-repo)   
2. 복사하고 싶은 forked Repository 주소를 copy (forked-repo)    
3. terminal open한 후 forked-repo를 bare clone       
  `$ git clone --bare https://github.com/userID/forked-repository.git`   
4. new-repo로 Mirror-push   
  `$ cd forked-repository.git`   
  `$ git push --mirror https://github.com/userID/new-repository.git`   
5. 처음에 임시로 생성했던 local repository 삭제   
  `$ cd ..`   
  `$ rm -rf forked-repository.git`

## Reference
- [[Github] fork 해온 repository 잔디 심는 방법 : repository 복사해오기 duplicate the repository](https://soranhan.tistory.com/11)

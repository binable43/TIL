## 프로젝트 환경설정

- 사전 준비물
    - Java 11 설치
    - IDE: IntelliJ 또는 Eclipse 설치   
 

- 스프링 부트 스타터 사이트로 이동해서 스프링 프로젝트 생성
    
    [https://start.spring.io/](https://start.spring.io/)
    
    - 아래와 같은 조건으로 설정하여 GENERATE
    ![spring initializr](https://user-images.githubusercontent.com/81629116/159496633-007e8816-c4f5-44a2-94b6-fdcc25997020.png)

    
- IntelliJ에서 build.gradle 파일 오픈

- main > java > hello.hellospring > HelloSpringApplication

```java
package hello.hellospring;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

@SpringBootApplication
public class HelloSpringApplication {

	public static void main(String[] args) {
		SpringApplication.run(HelloSpringApplication.class, args);
	}

}
```

main 함수 run

`Tomcat started on port(s): 8080 (http) with context path '’` 라는 메시지 확인 가능

http://localhost:8080으로 접속했을 때 아래와 같은 페이지가 뜨면 기본 설정 완료된 것

![localhost8080](https://user-images.githubusercontent.com/81629116/159497178-85adb14a-2b44-4d2f-934e-96a8951bdccd.png)



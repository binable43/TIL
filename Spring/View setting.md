## View 환경설정

### **Welcome Page 만들기**

- recources/static/index.html

```html
<!DOCTYPE HTML>
<html>
<head>
    <title>Hello</title>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
</head>
<body>
Hello
<a href="/hello">hello</a>
</body>
</html>
```

- 스프링 부트가 제공하는 Welcome Page 기능
    - `static/index.html` 을 올려두면 Welcome page 기능 제공
    - [https://docs.spring.io/spring-boot/docs/current/reference/html/web.html#web.whats-next](https://docs.spring.io/spring-boot/docs/current/reference/html/web.html#web.whats-next)

- thymeleaf 템플릿 엔진
    - 공식 사이트 : [https://www.thymeleaf.org/](https://www.thymeleaf.org/)

- main/java/hello.hellospring/controller/HelloController

```java
package hello.hellospring.controller;

import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;

@Controller
public class HelloController {

    @GetMapping("hello")
    public String hello(Model model) {
        model.addAttribute("data", "hello!!");
        return "hello";
    }
}
```

- main/resources/templates/hello.html

```html
<!DOCTYPE HTML>
<html xmlns:th="http://www.thymeleaf.org">
<head>
    <title>Hello</title>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
</head>
<body>
<p th:text="'안녕하세요. ' + ${data}" >안녕하세요. 손님</p>
</body>
</html>
```

- thymeleaf 템플릿엔진 동작 확인
    - 실행 : http://localhost:8080/hello


<img width="822" alt="스크린샷 2022-03-29 오후 2 57 18" src="https://user-images.githubusercontent.com/81629116/160543274-813d0e07-b739-4882-b213-90a3ab856045.png">


- 컨트롤러에서 리턴 값으로 문자를 반환하면 뷰 리졸버(’`viewResolver`’)가 화면 찾아서 처리
    - 스프링 부트 템플릿엔진은 기본 viewName 매핑
    - ‘`resources:templates/`’ + {ViewName} + ‘`.html`’
    - ex) hello.html
    

> 참고 : ‘spring-boot-devtools’ 라이브러리 추가하면 ‘html’ 파일을 컴파일만 해주면 서버 재시작 없이 View 변경이 가능
> 

> 인텔리J 컴파일 방법 : 메뉴 build → Recomplie
> 

- - -


### 빌드하고 실행하기

- 콘솔로 이동
    - spring 폴더로 이동

```
1   ./gradlew build
2   cd build/libs
3   java -jar hello-spring-0.0.1-SNAPSHOT.jar
4   실행확인

(만약에 잘 안될경우)
1   ./gradlew clean build
#완전히 비우고 다시 실행시킨다는 의미
```
![spring run](https://s3.us-west-2.amazonaws.com/secure.notion-static.com/c9260d1d-526d-4a0b-bc18-5704d63ceb0f/%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA_2022-03-29_%E1%84%8B%E1%85%A9%E1%84%8C%E1%85%A5%E1%86%AB_8.42.16.png?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Content-Sha256=UNSIGNED-PAYLOAD&X-Amz-Credential=AKIAT73L2G45EIPT3X45%2F20220329%2Fus-west-2%2Fs3%2Faws4_request&X-Amz-Date=20220329T055248Z&X-Amz-Expires=86400&X-Amz-Signature=5f807187e34f69f0f248cded78e92965bb09c3f004091bfbd3eff0ade1ecb2b1&X-Amz-SignedHeaders=host&response-content-disposition=filename%20%3D%22%25E1%2584%2589%25E1%2585%25B3%25E1%2584%258F%25E1%2585%25B3%25E1%2584%2585%25E1%2585%25B5%25E1%2586%25AB%25E1%2584%2589%25E1%2585%25A3%25E1%2586%25BA%25202022-03-29%2520%25E1%2584%258B%25E1%2585%25A9%25E1%2584%258C%25E1%2585%25A5%25E1%2586%25AB%25208.42.16.png%22&x-id=GetObject)

- 과거에는 tomcat을 활용해야했지만, 지금은 jar 파일을 실행시키면 서버에서 동작함

### reference
- [인프런 스프링 입문 - 코드로 배우는 스프링 부트, 웹 MVC, DB 접근 기술](https://www.inflearn.com/course/%EC%8A%A4%ED%94%84%EB%A7%81-%EC%9E%85%EB%AC%B8-%EC%8A%A4%ED%94%84%EB%A7%81%EB%B6%80%ED%8A%B8)


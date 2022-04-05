스프링으로 웹을 개발하는 것은 크게 아래의 3가지의 방법이 있다.

1. 정적 컨텐츠
2. MVC와 템플릿 엔진
3. API


## 정적 컨텐츠

- 파일을 그대로 웹브라우저에 전달하는 웹개발 방법
- 스프링 부트에서 정적 컨텐츠 자동으로 제공 (documentation에서 static content 검색)
- [Static Content in Spring Documentation](https://docs.spring.io/spring-boot/docs/current/reference/html/web.html#web.whats-next)

- static/hello-static.html

```html
<!DOCTYPE html>
<html>
<head>
    <title>static content</title>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8"/>
</head>
<body>
정적 컨텐츠 입니다.
</body>
</html>
```

- [localhost:8080/hello-static.html](http://localhost:8080/hello-static.html) 로 접속

* **정적 컨텐츠 구조**   
내장 톰캣 서버가 요청 받고 스프링 컨테이너에 넘기면 컨트롤러 쪽에서 hello-static이 있는지 찾아본다.   
만일 없으면, 내부에 있는 resources의 hello-static.html을 찾아서 웹브라우저에 반환

## MVC와 템플릿 엔진

- 요즘은 이걸로 주로 엔진
- MVC : Model, View, Controller

**Controller**

 `main/java/hello.hellospring/controller/HelloController` 

```java
@Controller
public class HelloController {

    @GetMapping("hello-mvc")
    public String helloMVC(@RequestParam("name") String name, Model model) {
        model.addAttribute("name", name);
        return "hello-template";
    }
}
```

**View**

 `main/resources/templates/hello-template.html` 

```html
<html xmlns:th="http://www.thymeleaf.org">
<body>
<p th:text="'hello '+ ${name}">hello! empty</p>
</body>
</html>
```

[http://localhost:8080/hello-mvc?name=spring](http://localhost:8080/hello-mvc?name=spring)

* **MVC, 템플릿 엔진 구조**   
위에서 본 정적컨텐츠에서는 HTML로 변환하지 않고 그대로 전달했지만, MVC에서는 HTML로 변환 후 전달   

- thymeleaf의 장점
    - 서버 없이 html 파일을 열어봐도 바로 확인해볼 수 있다.

## API

- json으로 전달해줌
- 서버끼리 통신할 때 주로 사용

**@ResponseBody 문자 반환**

 `main/java/hello.hellospring/controller/HelloController` 

```java
@Controller
public class HelloController {

    @GetMapping("hello-string")
    @ResponseBody
    public String helloString(@RequestParam("name") String name) {
        return "hello " + name;
    }
}
```

[http://localhost:8080/hello-string?name=spring](http://localhost:8080/hello-string?name=spring)!!

- @ResponseBody 사용하면 viewResolver 사용하지 않음
- 대신 HTTP의 BODY에 문자 내용을 직접 반환 (HTML BODY TAG을 말하는 것은 아님)

**@ResponseBody 객체 반환**

 `main/java/hello.hellospring/controller/HelloController` 

```java
@Controller
public class HelloController {

    @GetMapping("hello-api")
    @ResponseBody
    public Hello helloApi(@RequestParam("name") String name) {
        Hello hello = new Hello();
        hello.setName(name);
        return hello;
    }

    static class Hello{
        private String name;

        public String getName() {
            return name;
        }

        public void setName(String name) {
            this.name = name;
        }
    }
}
```

- @ResposeBody 사용하고, 객체 반환하면 객체가 JSON으로 변환됨

[http://localhost:8080/hello-api?name=spring](http://localhost:8080/hello-api?name=spring)!!

**@ResponseBody 실행 원리**   

- HTTP의 BODY에 문자 내용을 직접 반환 (객체를 json으로 반환)
- viewResolver 대신에 HttpMessageConverter 가 동작
- 기본 문자처리 : StringHttpMessageConverter
- 기본 객체처리 : MappingJackson2HttpMessageConverter
- byte 처리 등등 기타 여러 HttpMessageConverter가 기본으로 등록되어 있음 (

> 참고: 클라이언트 HTTP Accept 헤더와 서버의 컨트롤러 반환 타입 정보 둘을 조합해서 HttpMessageConverter 가 선택된다. 더 자세한 내용은 스프링 MVC 강의에서 배우기~


## reference
- [인프런 스프링 입문 - 코드로 배우는 스프링 부트, 웹 MVC, DB 접근 기술](https://www.inflearn.com/course/%EC%8A%A4%ED%94%84%EB%A7%81-%EC%9E%85%EB%AC%B8-%EC%8A%A4%ED%94%84%EB%A7%81%EB%B6%80%ED%8A%B8)

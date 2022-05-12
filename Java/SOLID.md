# SOLID (객체 지향 설계 5대 원칙)

- 클린코드로 유명한 로버트 마틴이 좋은 객체 지향 설계의 5가지 원칙을 정리함

<br>

## 1. SRP : 단일 책임 원칙 (Single Responsibility Principle)

- 한 클래스는 하나의 책임만 가져야 한다
- 하나의 책임 (모호한 개념)
    - 클 수도 있고, 작을 수도 있다
    - 문맥과 상황에 따라 다르다
- 중요한 기준은 **변경**! 변경이 있을 때 파급 효과가 적으면 단일 책임 원칙을 잘 따른 것
- ex) UI 변경, 객체의 생성과 사용 분리

<br>

## 2. OCP : 개방-폐쇄 원칙 (Open/Closed Principle)

- 소프트웨어 요소는 **확장에는 open, 변경에는 closed!**
- 확장을 하려면 당연히 기존 코드를 변경해야하지 않나?
- **다형성**을 활용해보자!
- 인터페이스를 구현한 새로운 클래스를 하나 만들어서 새로운 기능을 구현
- 지금까지 배운 역할과 구현의 분리를 생각해보자

**문제점**

```java
public class MemberService {
			private MemberRepository memberRepository = new MemoryMemberRepository();
}
```

```java
public class MemberService {
	//  private MemberRepository memberRepository = new MemoryMemberRepository();
			private MemberRepository memberRepository = new JdbcMemberRepository();
}
```

- `MemberService` 클라이언트가 구현 클래스를 직접 선택
- **구현 객체를 변경하려면 클라이언트 코드를 변경해야 한다!**
    - 즉, `MemoryMemberRepository` 를 변경하기 위해 `MemberService` 를 변경해야한다!
- 분명 다형성을 사용했지만 OCP 원칙을 지킬 수 없다
- To solve..
    - 객체를 생성하고, 연관관계를 맺어주는 별도의 조립, 설정자가 필요 (나중에 코드로 학습할 것)

<br>

## 3. LSP : 리스코프 치환 원칙 (Liskov Subsitution Principle)

- 프로그램의 객체는 프로그램의 정확성을 깨뜨리지 않으면서 하위 타입의 인스턴스로 바꿀 수 있어야 한다
- **다형성에서 하위 클래스는 인터페이스 규약을 다 지켜야 한다**는 것, 다형성을 지원하기 위한 원칙, 인터페이스를 구현한 구현체는 믿고 사용하려면 이 원칙이 필요
- 단순히 컴파일이 된다 안된다 라는 개념을 넘어서는 이야기
- ex) 자동차 인터페이스에서 엑셀은 전진 기능으로 설정, 후진 기능 구현하려면 LSP 위반, 느리더라도 앞으로 가야한다

<br>

## 4. ISP : 인터페이스 분리 원칙 (Interface Segregation Principle)

- 특정 클라이언트를 위한 인터페이스 여러 개가 범용 인터페이스 하나보다 낫다 **(인터페이스를 잘 쪼개는 것이 좋다!)**
    - 자동차 인터페이스 → 운전 인터페이스, 정비 인터페이스로 분리
    - 사용자 클라이언트 → 운전자 클라이언트, 정비사 클라이언트로 분리
    - 분리하면 정비 인터페이스 자체가 바뀌어도 운전자 클라이언트에 영향 X
- 인터페이스가 명확해지고, 대체 가능성이 높아짐

<br>

## 5. DIP : 의존관계 역전 원칙 (Dependency Inversion Principle)

- 프로그래머는 “추상화에 의존해야지, 구체화에 의존하면 안된다”
- 의존성 주입은 이 원칙을 따르는 방법 중 하나
- **구현 클래스에 의존하지 말고, 인터페이스에 의존하라!**
- **역할(Role)에 의존하게 해야 한다**는 것. 객체 세상도 클라이언트가 인터페이스에 의존해야 유연하게 구현체를 변경할 수 있다. 구현체에 의존하게 되면 변경이 아주 어려워진다.
    - ex) 운전자는 자동차 역할 자체에 대해서만 알면 되는것이지, 테슬라, K3 등에 대해서는 몰라도 된다
- 그런데.. OCP에서 설명한 `MemberService` 는 인터페이스와 구현 클래스 동시에 의존
    - `MemberService` 클라이언트가 구현 클래스를 직접 선택
        - `MemberRepository m = new MemoryMemberRepository();`
    - **DIP 위반** (MemberRepository라는 추상화에도 의존하고, 구체화인 MemoryMemberRepository에도 의존)


<br>

## Reference

- [인프런 스프링 핵심 원리 - 기본편](https://www.inflearn.com/course/%EC%8A%A4%ED%94%84%EB%A7%81-%ED%95%B5%EC%8B%AC-%EC%9B%90%EB%A6%AC-%EA%B8%B0%EB%B3%B8%ED%8E%B8)
- [객체 지향 프로그래밍 - 위키백과](https://ko.wikipedia.org/wiki/%EA%B0%9D%EC%B2%B4_%EC%A7%80%ED%96%A5_%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%B0%8D)
- [SOLID(객체 지향 설계) - 위키백과](https://ko.wikipedia.org/wiki/SOLID_(%EA%B0%9D%EC%B2%B4_%EC%A7%80%ED%96%A5_%EC%84%A4%EA%B3%84))

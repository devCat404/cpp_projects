# 📘 C++ 상속, 업캐스팅, 다운캐스팅, 가상 상속 정리 노트 (심화)

---

## 1. 상속 (Inheritance)

* 기존 클래스를 기반으로 새로운 클래스를 정의
* `public`, `protected`, `private` 상속 방식에 따라 접근 범위가 달라짐
* **자식 클래스는 부모 클래스의 멤버를 상속받지만, 접근 가능 여부는 지정자에 따라 다름**

| 접근 지정자      | 자식 클래스에서의 접근 | 외부 객체에서의 접근 |
| ----------- | ------------ | ----------- |
| `public`    | ✅ 접근 가능      | ✅ 접근 가능     |
| `protected` | ✅ 접근 가능      | ❌ 접근 불가     |
| `private`   | ❌ 접근 불가      | ❌ 접근 불가     |

```cpp
class Parent {
public:
    void show() { cout << "Parent"; }
};
class Child : public Parent {
    // Parent의 public 멤버 접근 가능
};
```

---

## 2. 업캐스팅 (Upcasting)

* 자식 객체를 부모 클래스 포인터/참조로 변환
* **암시적 변환**이며, 타입 안정성이 높아 안전함
* **부모 클래스에 정의된 멤버 함수만 접근 가능**
* \*\*다형성(polymorphism)\*\*을 통해 자식 클래스의 오버라이딩 함수 실행 가능 (virtual 사용 시)

```cpp
class Base {
public:
    void baseFunc() { cout << "Base"; }
    virtual void speak() { cout << "Base speaking\n"; }
};

class Derived : public Base {
public:
    void derivedFunc() { cout << "Derived"; }
    void speak() override { cout << "Derived speaking\n"; }
};

int main() {
    Derived d;
    Base* ptr = &d;  // 업캐스팅
    ptr->baseFunc();      // ✅ Base 함수 접근 가능
    // ptr->derivedFunc(); // ❌ 불가 (Base*는 derivedFunc() 모름)
    ptr->speak();         // ✅ "Derived speaking" (virtual 덕분에 자식 함수 실행)
}
```

➡️ **질문 반영 설명:**

> "부모 포인터로 자식을 가리켜도 결국 자식의 주소인데, 왜 자식 멤버에 접근 못해요?"

➡️ **답변:** 컴파일러는 포인터 타입(부모)의 정보만 보고 멤버 접근을 제한합니다. 포인터가 자식 주소를 가리켜도 타입이 부모이므로 부모의 인터페이스만 인식합니다. 다형성은 오직 virtual 함수로만 작동합니다.

---

## 3. 다운캐스팅 (Downcasting)

* 부모 클래스 포인터/참조를 자식 타입으로 강제 형변환
* **명시적 형변환 필요**, 실제 객체가 자식일 때만 안전함
* 런타임 타입 검사를 하려면 `dynamic_cast` 권장

```cpp
Base* ptr = new Derived();  // 실제 객체는 자식
Derived* dp = static_cast<Derived*>(ptr);  // 다운캐스팅

if (dp) {
    dp->derivedFunc();  // ✅ 자식 멤버 접근 가능
    dp->speak();        // ✅ 자식의 가상 함수 호출
}
```

➡️ **질문 반영 설명:**

> "다운캐스팅은 부모를 자식처럼 강제 형변환하는 건가요?"

➡️ **답변:** 맞습니다. 부모 포인터가 실제로 자식 객체를 가리키고 있는 경우, 강제로 자식 포인터로 바꾸면 자식 멤버까지 접근할 수 있게 됩니다. 하지만 객체가 진짜 자식이 아니면 위험합니다.

---

## 4. 업/다운 캐스팅 접근 가능 멤버 정리

```cpp
class Base {
public:
    void showBase() { cout << "Base 함수"; }
    virtual void speak() { cout << "Base speaking"; }
    virtual ~Base() {}
};
class Derived : public Base {
public:
    void showDerived() { cout << "Derived 함수"; }
    void speak() override { cout << "Derived speaking"; }
};

int main() {
    Derived d;
    Base* ptr = &d;           // 업캐스팅
    ptr->showBase();          // ✅ 가능
    // ptr->showDerived();    // ❌ 불가
    ptr->speak();             // ✅ "Derived speaking"

    Derived* dp = static_cast<Derived*>(ptr); // 다운캐스팅
    dp->showBase();          // ✅
    dp->showDerived();       // ✅
    dp->speak();             // ✅
}
```

---

## 5. 생성자 / 소멸자 호출 순서

* 생성자: **부모 → 자식 순서로 호출**
* 소멸자: **자식 → 부모 순서로 호출**
* 부모 클래스 소멸자는 **반드시 virtual**로 선언할 것 (그래야 자식 소멸자도 호출됨)

```cpp
class Base {
public:
    virtual ~Base() { cout << "Base 소멸자\n"; }
};
class Derived : public Base {
public:
    ~Derived() { cout << "Derived 소멸자\n"; }
};

int main() {
    Base* b = new Derived();  // 업캐스팅
    delete b;  // ✅ virtual 없으면 Derived 소멸자 미호출
}
```

➡️ **질문 반영 설명:**

> "부모 포인터로 delete 하는데 왜 자식 소멸자도 호출되나요?"

➡️ **답변:** 부모 소멸자가 virtual일 경우, 자식 타입을 감지해 자식 소멸자도 호출합니다. virtual 없으면 부모 소멸자만 호출되어 메모리 누수 발생 가능.

---

## 6. 가상 상속 (Virtual Inheritance)

### 📌 문제 상황: 다이아몬드 상속

```cpp
class A { public: void showA() {} };
class B : public A { public: void showB() {} };
class C : public A { public: void showC() {} };
class D : public B, public C {
    void show() {
        // showA();  // ❌ A가 2번 상속되어 모호함
    }
};
```

### ✅ 해결 방법: 가상 상속 사용

```cpp
class B : virtual public A { };
class C : virtual public A { };
class D : public B, public C {
    void show() {
        showA();  // ✅ A는 1번만 상속되어 모호성 제거
    }
};
```

➡️ **접근 범위 요약:**

* D는 A, B, C의 모든 public 멤버에 접근 가능
* A는 오직 한 번만 상속되어 메모리 낭비/모호성 없음
* `virtual` 키워드를 통해 공통 조상 1개만 유지

---

## ✅ 최종 요약

| 분류    | 설명                   | 접근 가능 범위                      |
| ----- | -------------------- | ----------------------------- |
| 업캐스팅  | 자식 → 부모 포인터          | 부모 멤버만 (virtual 함수는 자식 버전 실행) |
| 다운캐스팅 | 부모 → 자식 포인터 (명시적 필요) | 부모 + 자식 멤버 모두 (단, 타입 확인 필요)   |
| 가상 상속 | 공통 조상을 중복 없이 상속      | A는 1회만 상속, 다이아몬드 구조 해결        |

---

✅ 다음 확장 학습 추천:

* `dynamic_cast`로 안전한 다운캐스팅
* `vtable`과 가상 함수의 내부 작동 구조
* 추상 클래스 & 순수 가상 함수
* 인터페이스 설계 및 다형성 실전 활용

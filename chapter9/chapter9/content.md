# 📘 C++ 가상 함수 이후 핵심 개념 총정리 노트

---

## ✅ 1. 가상 함수와 접근 지정자

### 📌 접근 지정자란?

* 클래스 멤버 앞에 붙는 `public`, `protected`, `private`로 접근 범위를 결정합니다.

| 접근 지정자    | 외부 접근 | 자식 클래스 접근 |
| --------- | ----- | --------- |
| public    | ✅ 가능  | ✅ 가능      |
| protected | ❌ 불가  | ✅ 가능      |
| private   | ❌ 불가  | ❌ 불가      |

### 📌 가상 함수에 접근 지정자 적용

* `virtual` 함수는 `public`, `protected`, `private` 어디에도 선언 가능
* 하지만 **자식 클래스에서 오버라이딩하려면 최소 `protected` 이상**이어야 함
* `private virtual`은 오버라이딩 불가, 자식 클래스가 접근 자체를 못 하기 때문

```cpp
class Base {
public:
    virtual void sayHiPublic() { cout << "public 함수\n"; }

protected:
    virtual void sayHiProtected() { cout << "protected 함수\n"; }

private:
    virtual void sayHiPrivate() { cout << "private 함수\n"; } // 오버라이딩 불가
};
```

---

## ✅ 2. 오버라이딩과 범위 지정 연산자(::)

### 📌 오버라이딩이란?

* 부모의 `virtual` 함수를 자식 클래스에서 **같은 시그니처로 재정의**하는 것

```cpp
class Animal {
public:
    virtual void speak() { cout << "Animal speaks\n"; }
};

class Dog : public Animal {
public:
    void speak() override { cout << "Dog barks\n"; }
};
```

### 📌 범위 지정 연산자 `::`란?

* 부모 클래스의 함수를 명시적으로 호출할 때 사용

```cpp
void Dog::speak() {
    Animal::speak();  // 부모의 speak 호출
    cout << "Dog barks\n";
}
```

---

## ✅ 3. 오버로딩 vs 함수 재정의 vs 오버라이딩

### 🟦 (1) 오버로딩 (Overloading)

* 같은 클래스 내에서 **함수 이름은 같고, 인자 타입이나 개수 다르면 허용**

```cpp
class Example {
public:
    void show() { cout << "기본 show()\n"; }
    void show(int x) { cout << "int 받는 show(): " << x << endl; }
    void show(string s) { cout << "string 받는 show(): " << s << endl; }
};
```

### 🟩 (2) 함수 재정의 / 이름 숨김 (Hiding)

* 부모 함수와 같은 이름이지만 매개변수가 다르면 자식에서 부모 함수가 가려짐

```cpp
class Base {
public:
    void print(int x) { cout << "Base: " << x << endl; }
};

class Derived : public Base {
public:
    void print(double y) { cout << "Derived: " << y << endl; }
};

// 사용 시
Derived d;
d.print(10); // Base::print(int) 호출되지 않음!
d.Base::print(10); // 명시적 호출 필요
```

### 🟥 (3) 오버라이딩 (Overriding)

* 부모의 `virtual` 함수를 자식이 **동일한 시그니처**로 다시 정의

```cpp
class Base {
public:
    virtual void speak() { cout << "Base speak\n"; }
};

class Derived : public Base {
public:
    void speak() override { cout << "Derived speak\n"; }
};
```

* 반드시 부모에 `virtual` 있어야 함
* 함수 시그니처 완전히 일치해야 함

### ✅ 한눈에 정리표

| 항목         | 오버로딩 (Overload) | 재정의 / 숨김 (Hiding) | 오버라이딩 (Override) |
| ---------- | --------------- | ----------------- | ---------------- |
| 정의         | 같은 이름, 다른 인자    | 부모 함수 이름 숨김       | virtual 함수 재정의   |
| 위치         | 같은 클래스          | 상속 관계             | 상속 관계            |
| 시그니처       | 다르게             | 다르게               | 완전히 동일           |
| virtual 필요 | ❌               | ❌                 | ✅                |
| 호출 시점      | 정적 바인딩          | 정적 바인딩            | 동적 바인딩           |
| 특징         | 함수 여러 개 공존 가능   | 부모 함수가 감춰짐        | 부모 함수의 기능을 대체함   |

---

## ✅ 4. 정적 바인딩 vs 동적 바인딩 예시

```cpp
class Base {
public:
    void show() { cout << "Base"; }           // 정적 바인딩
    virtual void speak() { cout << "Base"; }  // 동적 바인딩
};

class Derived : public Base {
public:
    void show() { cout << "Derived"; }
    void speak() override { cout << "Derived"; }
};

int main() {
    Base* ptr = new Derived();
    ptr->show();   // "Base" 출력 (정적 바인딩)
    ptr->speak();  // "Derived" 출력 (동적 바인딩)
}
```

---

## ✅ 5. 추상 클래스와 순수가상함수

### 📌 추상 클래스란?

* 하나 이상의 순수 가상 함수(pure virtual function)를 가지는 클래스
* 직접 객체 생성 불가능, 반드시 파생 클래스에서 구현 필요

```cpp
class Shape {
public:
    virtual void draw() = 0; // 순수 가상 함수
};

class Circle : public Shape {
public:
    void draw() override { cout << "Draw Circle"; }
};
```

---

## ✅ 6. 소멸자와 가상 소멸자

### 📌 소멸자는 왜 virtual 이어야 할까?

* 부모 포인터로 자식 객체를 delete할 때 자식 소멸자도 호출되게 하기 위해

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
    Base* b = new Derived();
    delete b; // virtual 없으면 Derived 소멸자 호출 안됨
}
```

---

## ✅ 7. 업캐스팅과 다운캐스팅, 접근 가능 범위

```cpp
class Base {
public:
    void baseMethod() { cout << "Base method\n"; }
    virtual void show() { cout << "Base show\n"; }
};

class Derived : public Base {
public:
    void derivedMethod() { cout << "Derived method\n"; }
    void show() override { cout << "Derived show\n"; }
};
```

```cpp
Base* basePtr = new Derived();  // 업캐스팅
basePtr->baseMethod(); // ✅
basePtr->derivedMethod(); // ❌ 불가능
basePtr->show(); // ✅ Derived의 show 호출 (동적 바인딩)

Derived* derivedPtr = (Derived*)basePtr;  // 다운캐스팅 (명시적 형변환 필요)
derivedPtr->derivedMethod(); // ✅ 가능
```

---

## ✅ 8. 가상 상속 (virtual inheritance)

### 📌 다중 상속 시 중복된 기본 클래스 방지 기법

```cpp
class A { public: int a; };
class B : virtual public A {};
class C : virtual public A {};
class D : public B, public C {
    void access() {
        a = 10; // A가 하나만 상속됨
    }
};
```

* `virtual` 키워드로 인해 A의 복사본이 하나만 생성되어 diamond 문제 해결

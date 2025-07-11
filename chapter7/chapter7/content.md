# C++ 연산자 오버로딩 & friend 함수 총정리 노트

---

## 1. friend 함수란?

* 클래스 외부에서 정의되지만, 해당 클래스의 private/protected 멤버에 접근 가능
* 선언은 클래스 내부에, 정의는 외부에 위치
* 보통 연산자 오버로딩에 자주 사용

```cpp
class A {
    int val;
    friend A operator+(const A&, const A&);
};
```

---

## 2. 연산자 오버로딩 방식

| 방식        | 설명                      | 특징                        |
| --------- | ----------------------- | ------------------------- |
| 멤버 함수     | 클래스 내부에 정의, this 사용 가능  | 왼쪽 피연산자가 해당 클래스여야 함       |
| friend 함수 | 외부 함수지만 클래스에 friend로 선언 | 왼쪽 피연산자가 클래스가 아닐 경우 사용 가능 |

> ✅ 동일한 연산자에 대해 friend와 멤버 함수로 "동시에" 정의할 수 없음 → 모호성(ambiguity) 에러 발생

---

## 3. 오버로딩 가능한 vs 불가능한 연산자

### 오버로딩 가능:

* 산술: `+`, `-`, `*`, `/`, `%`
* 비교: `==`, `!=`, `<`, `>`, `<=`, `>=`
* 논리: `!`, `&&`, `||`
* 증감: `++`, `--`
* 기타: `[]`, `()`, `<<`, `>>`, `=`, `+=`, `-=`, `*=`, `/=`, `new`, `delete`, `new[]`, `delete[]`

### 오버로딩 불가능:

* 범위 지정자: `::`
* 멤버 접근: `.`, `.*`
* 기타: `sizeof`, `typeid`, `alignof`, `noexcept`, `?:`, `#`, `##`

---

## 4. 전위 / 후위 연산자 오버로딩

| 연산자      | 함수 시그니처             | 리턴 | 설명                               |
| -------- | ------------------- | -- | -------------------------------- |
| 전위 `++a` | `T& operator++()`   | 참조 | 먼저 증가 후 자기 자신 반환                 |
| 후위 `a++` | `T operator++(int)` | 값  | 복사본 반환 후 원본 증가 (int는 dummy 매개변수) |

> 전위는 참조 반환, 후위는 복사본 반환

---

## 5. const의 쓰임

| 위치                  | 의미               |
| ------------------- | ---------------- |
| `const Type& param` | 참조로 받고 읽기 전용     |
| `Type func() const` | 멤버 값을 변경하지 않는 함수 |

* `const`를 쓰면 실수 방지, 최적화, const 객체에서도 함수 사용 가능

---

## 6. friend vs 멤버 함수 오버로딩 차이

| 구분          | 멤버 함수      | friend 함수             |
| ----------- | ---------- | --------------------- |
| 정의 위치       | 클래스 내부     | 클래스 외부 (선언만 내부에 위치)   |
| this 사용     | 가능         | 불가능                   |
| 왼쪽 피연산자     | 반드시 해당 클래스 | 아무거나 가능 (ex. int + A) |
| int + A 가능? | ❌ 불가능      | ✅ 가능                  |

---

## 7. 오버로딩 판단 규칙

| 피연산자      | 작동 방식                 |
| --------- | --------------------- |
| 클래스 + 클래스 | ✅ 오버로딩 가능             |
| 클래스 + 기본형 | ✅ 오버로딩 가능             |
| 기본형 + 클래스 | ✅ friend 필요           |
| 기본형 + 기본형 | ❌ 오버로딩 불가 (내장 연산자 사용) |

> 즉, 피연산자 중 "하나라도" 클래스일 경우 오버로딩 함수 탐색이 이루어짐

---

## 8. 참조 반환이 필요한 경우

* `operator=`, `operator++`(전위), `operator--`(전위), `operator[]` 등
* 이유:

  1. 성능 최적화 (복사 최소화)
  2. 연산자 체이닝 허용 (예: `a = b = c;` 또는 `++(++a);`)

```cpp
A& operator=(const A& other) {
    this->val = other.val;
    return *this;
}
```

---

## 9. 디폴트 매개변수 사용 여부

| 상황                | 디폴트 인자 가능? | 설명                        |
| ----------------- | ---------- | ------------------------- |
| 멤버 연산자 함수         | ✅ 가능       | 예: `operator+(int x = 5)` |
| friend 연산자 함수     | ✅ 가능       | 의미가 불명확해질 수 있어 잘 안 씀      |
| 후위 연산자(dummy int) | ⚠️ 가능하나 비추 | 의미 없는 dummy 매개변수이므로       |

---

## 10. 실전 예시 키워드

* `SmartNumber` 클래스 사용 예시
* 연산자 오버로딩: `+`, `==`, `!=`, `++`, `--`
* friend 함수로 이항 연산 구현
* 전위/후위 연산자 오버로딩은 멤버 함수로 작성
* const는 읽기 전용 함수/매개변수에 필수

---

## 11. 대표 질문 요약

* Q: friend로만 오버로딩 가능한가요?

  * A: ❌ 멤버 함수로도 가능. 단, 왼쪽 피연산자가 클래스여야 함

* Q: 연산자 함수에 디폴트 매개변수 사용 가능한가요?

  * A: ✅ 가능하지만 거의 안 씀. 의미 불명확할 수 있음

* Q: 연산자 함수는 참조 리턴이 필수인가요?

  * A: 경우에 따라 다름. 체이닝 가능한 연산자 (`=`, `++`, `[]`)는 참조 리턴이 권장됨

* Q: friend와 멤버 함수로 같은 연산자를 동시에 정의할 수 있나요?

  * A: ❌ 안 됨. 모호성 오류 발생

---

## ✅ 최종 요약 정리

> 연산자 오버로딩은 클래스에 자연스러운 연산을 부여하기 위해 사용되며, friend는 접근 제어를 넘어서 외부 함수에게 특별 권한을 부여함 전위/후위, 이항/단항 연산자는 시그니처가 다르므로 주의하고, const와 참조 반환은 논리적 안정성과 성능 최적화를 위해 반드시 고려해야 한다.

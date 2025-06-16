✅ 1. 함수 중복의 약점과 템플릿의 필요성

✔ 함수 중복 (Overloading)의 한계
예를 들어 두 숫자를 더하는 함수가 있다고 할 때:

```cpp
int add(int a, int b) { return a + b; }
double add(double a, double b) { return a + b; }
float add(float a, float b) { return a + b; }
```

이렇게 타입마다 일일이 작성하면 코드가 중복되고 유지보수가 어려워져요.

👉 해결책: 템플릿 함수
하나의 함수 정의로 여러 타입을 자동으로 처리할 수 있도록 만든 문법이에요.

```cpp
template<typename T>
T add(T a, T b) {
    return a + b;
}
```

이제는 int, double, float, 심지어 string까지도 자동으로 처리됩니다.

```cpp
add(3, 5);            // int
add(2.5, 4.1);        // double
add(string("A"), "B"); // string 덧붙이기
```

✅ 2. 함수 템플릿의 선언 및 구조

기본 형식:

```cpp
template<typename T>
반환형 함수명(매개변수) {
    // 템플릿을 이용한 일반화된 연산
}
```

예시: 두 값 중 큰 값을 반환

```cpp
template<typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}
```

```cpp
max(3, 5)        // int
max(3.14, 2.5)   // double
max('a', 'z')    // char
```

템플릿 함수 호출 시 형식 지정도 가능:

```cpp
max<int>(10, 20);
```

✅ 3. 두 개 이상의 제네릭 타입

✔ 템플릿 타입을 2개 이상 쓰고 싶다면?

```cpp
template<typename T1, typename T2>
void printTwo(T1 a, T2 b) {
    cout << a << ", " << b << endl;
}
```

```cpp
printTwo(1, "apple");   // int, const char*
printTwo(3.14, 42);      // double, int
```

이처럼 서로 다른 타입을 받아 처리할 수 있어요.

✅ 4. 함수 중복 vs 템플릿 함수

🔸중복 함수의 단점:

* 모든 타입마다 복사/붙여넣기 수준의 코드
* 실수 유발 (타입 누락, 시그니처 충돌)

🔹템플릿 함수의 장점:

* 유지보수성 향상 (하나만 고치면 다 적용)
* 코드 재사용성 극대화
* 컴파일 시 자동으로 타입별 함수 생성 (템플릿 인스턴스화)

✅ 5. 제네릭 클래스 (클래스 템플릿)

함수만이 아니라 클래스도 일반화할 수 있어요.

✔ 예시: 여러 타입을 저장할 수 있는 Pair 클래스

```cpp
template<typename T1, typename T2>
class Pair {
    T1 first;
    T2 second;
public:
    Pair(T1 a, T2 b) : first(a), second(b) {}
    void show() {
        cout << "(" << first << ", " << second << ")" << endl;
    }
};
```

```cpp
Pair<int, string> p1(1, "apple");
p1.show();  // 출력: (1, apple)

Pair<double, char> p2(3.14, 'A');
p2.show();  // 출력: (3.14, A)
```

📌 장점:

* 타입에 독립적인 재사용 가능한 클래스 생성
* STL도 이런 방식으로 만들어짐

✅ 6. STL 컨테이너 (vector, map 등)

✔ vector: 가변 크기 배열

```cpp
#include <vector>

vector<int> v;
v.push_back(1);
v.push_back(2);
v.push_back(3);

for (int x : v) {
    cout << x << " ";
}
```

* 자동으로 메모리 늘어남
* 인덱스로 접근 가능 (v\[0])
* 타입 지정 필수 (vector<string> 등)

✔ map: 키-값 쌍 저장소 (딕셔너리 역할)

```cpp
#include <map>

map<string, int> age;
age["Alice"] = 23;
age["Bob"] = 30;

cout << age["Alice"];  // 23
```

* 자동 정렬됨 (기본은 key 기준 오름차순)
* \[]로 접근 가능
* 키 중복 불가

✅ 7. STL 알고리즘

STL에는 반복자 기반으로 작동하는 다양한 알고리즘이 있습니다.

✔ 예시: sort()

```cpp
#include <algorithm>
#include <vector>

vector<int> v = {5, 1, 4, 2, 3};
sort(v.begin(), v.end());  // 오름차순 정렬

for (int x : v) cout << x << " ";  // 1 2 3 4 5
```

✔ 예시: find()

```cpp
auto it = find(v.begin(), v.end(), 3);
if (it != v.end()) cout << "찾음!";
```

sort, find, reverse, count, unique, binary\_search 등 수십 개의 알고리즘 제공

✅ 8. auto: 타입 자동 추론

📌 auto란?
컴파일러가 우변의 값을 보고 변수 타입을 자동으로 추론해주는 키워드입니다.

✔ 예시 1: 기본적인 타입 추론

```cpp
auto a = 10;       // int
auto b = 3.14;     // double
auto c = "hi";     // const char*
```

✔ 예시 2: 반복자(iterator) 선언에 유용

```cpp
vector<int> v = {1, 2, 3, 4};

for (auto it = v.begin(); it != v.end(); ++it) {
    cout << *it << " ";
}
```

✔ 예시 3: 복잡한 STL 알고리즘 결과 처리

```cpp
auto it = find(v.begin(), v.end(), 3);
if (it != v.end()) cout << "3 있음";
```

it은 vector<int>::iterator지만 굳이 다 쓰지 않아도 됨!

✅ 9. 람다식 (Lambda Expression)

📌 람다식이란?
이름 없는 함수(익명 함수)를 inline으로 정의하는 문법입니다.

📌 기본 문법:

```cpp
[capture](parameters) -> return_type { body }
```

* capture: 외부 변수를 람다 안에서 어떻게 쓸지 정함
* parameters: 매개변수
* return\_type: 생략 가능 (추론됨)
* body: 실행할 코드

✔ 예시 1: 간단한 람다식

```cpp
auto f = [](int a, int b) {
    return a + b;
};
cout << f(3, 4);  // 출력: 7
```

f는 함수처럼 사용할 수 있는 람다 표현식

✅ 10. 캡처 리스트 (Capture List)

📌 외부 변수를 람다식에서 사용하려면 캡처 리스트를 써야 합니다.

✔ 캡처 방식

| 캡처 방식  | 의미                      |
| ------ | ----------------------- |
| \[=]   | 외부 변수 값 복사로 캡처 (읽기 전용)  |
| \[&]   | 외부 변수 참조로 캡처 (읽기/쓰기 가능) |
| \[x]   | 변수 x만 값 복사로 캡처          |
| \[\&x] | 변수 x만 참조로 캡처            |

✔ 예시 1: 값 캡처 \[=]

```cpp
int a = 10;
auto f = [=]() {
    cout << a << endl; // ✅ 가능 (값 복사)
};
```

✔ 예시 2: 참조 캡처 \[&]

```cpp
int a = 10;
auto f = [&]() {
    a += 5;           // ✅ 수정 가능
};
f();
cout << a;            // 15 출력
```

✔ 예시 3: STL + 람다

```cpp
vector<int> v = {1, 2, 3, 4, 5};

for_each(v.begin(), v.end(), [](int x) {
    cout << x * 2 << " ";
});
// 출력: 2 4 6 8 10
```

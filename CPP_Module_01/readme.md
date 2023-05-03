# CPP_Module_01

## Exercise 00: BraiiiiiiinnnzzzZ

***학습 포인트***
- 생성자
- 소멸자
- new delete 동적할당

### 소멸자(Destructor)

소멸자는 객체가 소멸될 때 자동으로 실행되는 클래스의 멤버 함수다

생성자는 클래스의 초기화를 돕도록 설계됐지만

소멸자는 청소를 돕도록 설계되었다

소멸자가 자동으로 호출되는 경우는 다음과 같다

1. 지역에서 생성된 객체가 지역 범위를 벗어나는 경우
2. 동적으로 할당된 객체가 delete를 통해 명시적으로 삭제되는 경우

객체가 메모리에서 제거되기 전에 자동으로 소멸자를 호출해 필요한 정리를 수행한다

클래스의 멤버 변수들이 단순하게 기본 자료형이 값 형식이라면 크게 필요 없지만

다른 리소스(예: 동적 메모리, 파일 또는 데이터베이스 핸들러)라면 객체가 소멸되기 전에 어떤 종류의 유지보수를 해야 한다

이때 소멸자는 객체가 소멸되기 전에 마지막으로 호출되는 특별한 함수이므로 완벽한 장소가 된다

생성자처럼 소멸자도 특별한 `규칙`이 있다

소멸자 이름은 `클래스 이름과 같아야 하고` 

앞에 `~`를 달아야 한다

소멸자는 `인수가 없다`

소멸자는 `반환 값이 없다`

이런 규칙 때문에 소멸자는 클래스당 `하나밖에 존재`할 수 없다

또한, 소멸자를 명시적으로 호출하는 경우는 없다

[예시]

```cpp
#include <iostream>
#include <cstddef>

using namespace std;

class IntArray
{
private:
    int* m_Array;
    int m_Length;

public:
    IntArray(int length) // 생성자
    {        
        m_Array = new int[static_cast<size_t>(length)]{};
        m_Length = length;
    }

    ~IntArray() // 소멸자
    {
        // 동적으로 할당한 배열을 삭제한다.
        delete[] m_Array;
    }

    void SetValue(int index, int value)
    {
        m_Array[index] = value;
    }


    int GetLength()
    {
        return m_Length;
    }
};

int main()
{
    IntArray ar(10);

    for(int count = 0; count < ar.GetLength(); ++count)
        ar.SetValue(count, count + 1);


    return 0;
} // ar 객체는 여기서 삭제되므로 ~IntArray() 소멸자 함수는 여기서 호출된다.
```

## Exercise 01: Exercise 01: Moar brainz!

***학습 포인트***
- 객체 배열

### c++의 객체 배열

- 기본적인 배열 선언 및 초기화 방법

```cpp
int arr[] = {1, 2, 3};
int arr[3]; // 초기화 되지 않고 쓰레기값을 가리킨다
int arr[3] = {1, 2, 3};

Point pointArr[] = {Point(), Point(), Point()};
Point pointArr[3]; // 초기화 된다
Point pointArr[3] = {Point(), Point(), Point()};
```
객체 배열은 무조건(?) 선언과 함께 default constructor가 호출되면서 초기화된다

- 객체 배열이 초기화 되는 원리

```cpp
Point pointArr[3];
```
선언과 함께 default constructor가 호출된다

```cpp
Point *p1 = new Point[3];
```
동적으로 객체 배열을 선언하는 경우에도 default constructor을 이용해 모두 초기화된다

`Point형 객체`에 대한 `3`개를 사용할 수 있는 메모리 공간을 `동적으로 확보`하고

각 공간에 `default constructor`로 객체를 생성한다

이후 `첫 번째 객체의 주소`를 p1 pointer에 `저장`한다는 뜻

- 객체의 포인터 배열이 선언되는 원리

배열을 동적으로 할당하고 그 안에 정적으로 생성하는 객체를 담는 것이 아니라,

배열은 정적이되 객체를 동적으로 할당하면?

```cpp
Point *parr[3]; // 아무 객체도 생성되지 않는다. 배열만 선언

for(int i = 0; i < 5; i++){
    parr[i] = new Point(i * 10, i * 10);
}
```

- 각 생성자마다 하나의 인자를 전달할 수 있다

```cpp
Point parr[5]{10, 20, 30}; -> Point(10), Point(20), Point(30), Point(), Point()
```


## Exercise 03: Unnecessary violence

***학습 포인트***
- const 위치

https://m.blog.naver.com/oh-mms/222044543049


## Exercise 04: Sed is for losers

***학습 포인트***
- 파일 읽기
- 파일 쓰기

### 파일 읽기

```cpp
#include <iostream>
#include <fstream>

int main(int ac, char **av) {
    std::string line;

    std::ifstream file("a.txt");
    if (file.is_open()) {
        while (std::getline(file, line)) {
            std::cout << line << std::endl;
        }
        file.close();
    } else {
        std::cout << "Unable to open file";
        return 1;
    }
    return 0;
}
 
```

- fstream 헤더
- ifstream 이름(파일경로);
- 이름.is_open()
    열렸다면 true

    그렇지 않다면 false

- getline(이름, string) 열었던 텍스트 파일을 한 줄씩 읽어와 string 형태로 저장

- 이름.close(); 로 닫기

### 파일 쓰기

```cpp
#include <iostream>
#include <fstream>

int main(int ac, char **av) {
    std::string line;
    
    std::ofstream file("b.txt");
    if (file.is_open()) {
        file << "This is the first line.\n";
        file << "This is the second line.\n";
        file.close();
    } else {
        std::cout << "Unable to open file";
        return 1;
    }
    return 0;
}
```

- fstream 헤더
- ofstream 이름(파일경로);

### 파일 읽기 간 주의사항

```c++
try {
        validateInput(ac, av);
        FileDto fileDto(av[1]);

        // while (!fileDto.getFin().eof() && fileDto.getFout().good()) { // 파일이 비어있을 때 한번 돈다
        while (std::getline(fileDto.getFin(), buf) && fileDto.getFout().good()) {
            fileDto.replaceString(buf, av[2], av[3]);
        }     
        return 0;
    }   catch (const std::string message) {
        std::cerr << "Error: " << message << std::endl;
        return 1;
    }
```

`std::ifstream 클래스의 eof()`

-> 파일의 끝을 나타내는 flag 값을 반환

- 파일이 끝나는 경우 true
- 파일이 끝나지 않았을 경우 false

`!fileDto.getFin().eof()`는 마지막 줄에서만 true를 반환하므로

파일이 비었을 경우에도 한 번은 false를 반환하게 된다

따라서 위 주석대로 실행할 경우 while문이 한번 돌게 된다

예상치 못한 동작이 발생할 수 있으므로 주의하자



## Exercise 05: Harl 2.0

***학습 포인트***
- 메서드의 포인터 배열


## Exercise 06: Harl filter

***학습 포인트***
- 메서드의 포인터 배열

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
- ㅇ

### 
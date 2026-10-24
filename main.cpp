#include <iostream>
#include "holiday.h"
#include "dayOfYear.h"
#include <array>
// 3. main.cpp: 테스트

// 1의 본인이름학번의 네임스페이스안에 print클래스Array 함수를 정의하세요. 
// 리턴은 없고, 매개변수는 const 클래스형 배열과 const int형 배열크기이고, 
// for구문을 이용하여 배열원소를 하나씩 표준스트림으로 출력연산자를 이용해 출력하세요.
namespace KwonMinSung2693018
{
    void printHolidayArray(const holiday a[], const int n)
    {
        for(int i = 0; i < n; ++i)
            std::cout << a[i];
        
        std::cout << std::endl;
    }   
}

// -main

int main()
{
using namespace KwonMinSung2693018;
// 상수를 4로 선언하세요. 
// 클래스형을 상수개 갖는 배열을 선언합니다. 
// 배열의 첫번째 원소는 생성자를 이용하여 원하는 값으로 초기화합니다. 
// 배열의 두번째 원소는 set함수들을 호출하여 원하는 값을 넣어줍니다. 
// 배열의 세번째 원소는 input멤버함수를 호출하여 원하는 값을 넣어줍니다. 
// 배열의 네번째 원소는 입력연산자를 이용하여 표준스트림으로 원하는 값을 입력합니다. 
// print클래스Array 함수에 배열과 상수를 넣어 호출합니다. 
    const int n = 4;
    holiday a[n];
    a[0] = holiday{"Christmas", dayOfYear{12,25}, false};
    a[1].setName("NewYear day"); a[1].setDate({1,1}); a[1].setParkingEnforcement(true);
    a[2].input();
    std::cin >> a[3];

    printHolidayArray(a,n);

// 클래스형이 상수개인 std::array를 선언합니다. 
// for구문을 이용하여 std::array의 각 원소에 배열의 각 원소를 각각 할당합니다. 
//  (size(), at() 멤버함수 사용)
// for each 구문을 이용하여 std::array의 각 원소에서 print함수를 호출합니다. 
    std::array<holiday,n> arr;
    for(int i = 0; i < arr.size(); ++i)
        arr.at(i) = a[i];
    for(const auto& arri : arr)
        arri.print();
        //for (int i=0; i < arr.size(); ++i)
        //    arr.at(i).print();

return 0;
}
#pragma once
#include "dayOfYear.h"
#include <iostream>
#include <string>

namespace KwonMinSung2693018
{
// 3. holiday.h : 클래스2 정의
// 1의 본인이름학번의 네임스페이스 안에 클래스2를 정의하고 멤버함수들도 모두 인라인으로 구현합니다. 
// private 멤버변수 선언: 클래스1형 객체, 그 외 멤버변수 1개 이상

//[lab6]
// 2. holiday.h : 지난 실습에서 만든 클래스에 다음을 추가 
// private
// -std::string형 멤버변수
class holiday
{
private:
    std::string name{};
    dayOfYear date{};
    bool parkingEnforcement{};
// public 멤버함수 인라인으로 정의
// -생성자: 모든 멤버변수 초기화, 기본값 설정
// -print: 표준스트림출력으로 멤버변수들 출력
// -클래스1형 객체의 접근함수를 참조형식으로 구현

// [lab6]
// public
// -생성자 변경: std::string형 멤버변수를 초기화
// -print함수 변경: std::string형 멤버변수도 표준스트림으로 출력
// -input함수 추가: std::string형 멤버변수는 std::string의 getline함수와 입력조작기 std::ws를 사용
// -friend 입력연산자 추가
// -friend 출력연산자 추가
// -접근함수 추가: std::string형 멤버변수 접근함수 (get, set)
public:
    holiday(const std::string& n = "No name yet", dayOfYear d = {1,1}, bool p = false) : name{n}, date{d}, parkingEnforcement{p}
    {}

    void print() const
    {
        std::cout << name << " : ";
        date.print();
        if (parkingEnforcement) std::cout << "Parking laws will be enforced\n";
        else std::cout << "Parking laws will NOT be enforced\n";
    }

    void input()
    {
        std::cout << "Enter holiday name: ";
        std::getline(std::cin >> std::ws, name);
        date.input();
        std::cout << "Enter parking law enforcement as 1(true) or 0(flase): ";
        std::cin >> parkingEnforcement;
    }

    friend std::istream& operator>>(std::istream& is, holiday& h) 
    {
        std::cout << "Enter holiday name: ";
        std::getline(is >> std::ws, h.name);
        is >> h.date;
        std::cout << "Enter parking law enforcement as 1(true) or 0(flase): ";
        is >> h.parkingEnforcement;
        return is;
    }

    friend std::ostream& operator<<(std::ostream& os, const holiday& h)
    {
        os << h.name << " : ";
        os << h.date;
        if (h.parkingEnforcement) os << "Parking laws will be enforced";
        else os << "Parking laws will NOT be enforced";
        return os;
    }

    void setDate(const dayOfYear& d) {date = d;}
    const dayOfYear& getDate() const {return date;}

    void setName (const std::string& n) {name = n;}
    const std::string& getName() const {return name;}

    void setParkingEnforcement(bool p) {parkingEnforcement = p;}

};
}

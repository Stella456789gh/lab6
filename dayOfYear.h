#pragma once
#include <iostream>
#include <cstdlib>

// 2. dayOfYear.h : 클래스1 정의
namespace KwonMinSung2693018
{
// 1의 본인이름학번의 네임스페이스 안에 클래스1을 정의하고 멤버함수들도 모두 인라인으로 구현합니다. 
// private 멤버변수 선언 (2개 이상)
// private 멤버함수 정의
// -test멤버변수1: 멤버변수1 범위가 아니면 프로그램 종료
// -test멤버변수2: 멤버변수2 범위가 아니면 프로그램 종료
class dayOfYear
{
private:
    int month{};
    int day{};
    void testMonth()
    {
        if((month<1) || (month>12))
        {
            std::cout << "Invalid month\n";
            std::exit(1);
        }
    }
    void testDay()
    {
        if((day<1) || (day>31))
        {
            std::cout << "Invalid day\n";
            std::exit(1);
        }
    }

// public 멤버함수 정의
// -생성자: 모든 멤버변수 초기화, 기본값 설정, test함수들 호출
// -input: 표준스트림입력으로 멤버변수들 입력, test함수들 호출
// -set 접근함수들: 멤버변수 값 설정 및 test함수 호출
// -print: 표준스트림출력으로 멤버변수들 출력
// -get 접근함수들: 멤버변수 값 리턴
public:
    dayOfYear (int m=1, int d=1) : month{m}, day{d}
    {testMonth(); testDay();}

    void input()
    {
        std::cout << "Enter Month as a number: ";
        std::cin >> month; testMonth();
        std::cout << "Enter Day as a number: ";
        std::cin >> day; testDay();
    }

    void setMonth(int m) {month = m; testMonth();}
    void setday(int d) {day = d; testDay();}

    void print() const
    {
        switch (month)
        {
            case 1: std::cout << "Jan. "; break;
            case 2: std::cout << "Feb. "; break;
            case 3: std::cout << "Mar. "; break;
            case 4: std::cout << "Apr. "; break;
            case 5: std::cout << "May. "; break;
            case 6: std::cout << "Jun. "; break;
            case 7: std::cout << "Jul. "; break;
            case 8: std::cout << "Aug. "; break;
            case 9: std::cout << "Sep. "; break;
            case 10: std::cout << "Oct. "; break;
            case 11: std::cout << "Nov. "; break;
            case 12: std::cout << "Dec. "; break;
        }
        std::cout << day << std::endl;
    }

    int getMonth() const {return month;}
    int getDay() const {return day;}

 // -프렌드함수로서 입력연산자 >>
   friend std::istream& operator>>(std::istream& is, dayOfYear& d)
   {
        std::cout << "Enter Month as a number: ";
        is >> d.month; d.testMonth();
        std::cout << "Enter Day as a number: ";
        is >> d.day; d.testDay();
        return is;
   }
 // -프렌드함수로서 출력연산자 <<
    friend std::ostream& operator<<(std::ostream& os, const dayOfYear& d)
    {
        switch (d.month)
        {
            case 1: std::cout << "Jan. "; break;
            case 2: std::cout << "Feb. "; break;
            case 3: std::cout << "Mar. "; break;
            case 4: std::cout << "Apr. "; break;
            case 5: std::cout << "May. "; break;
            case 6: std::cout << "Jun. "; break;
            case 7: std::cout << "Jul. "; break;
            case 8: std::cout << "Aug. "; break;
            case 9: std::cout << "Sep. "; break;
            case 10: std::cout << "Oct. "; break;
            case 11: std::cout << "Nov. "; break;
            case 12: std::cout << "Dec. "; break;
        }
        std::cout << d.day << std::endl;
        return os;
    }
 // -멤버함수로 전위증가연산자 정의 (멤버변수가 범위를 벗어났을때도 고려하여 조치함)
    dayOfYear operator ++()
    {
            ++day;
            if (day>31)
            {
                ++month;
                if(month >12) month = month-12;
                day = day - 31;
            }
            return dayOfYear{month,day};
    }
 // -멤버함수로 후위증가연산자 정의
        dayOfYear operator ++(int)
    {
            dayOfYear temp{month,day};
            ++day;
            if (day>31)
            {
                ++month;
                if(month >12) month = month-12;
                day = day - 31;
            }
            return temp;
    }
 //프렌드함수로서 이항연산자 ==
    friend bool operator == (const dayOfYear& d1, const dayOfYear& d2)
    {
        return ((d1.month == d2.month) || (d1.day == d2.day));
    }
 //프렌드함수로서 이항연산자 + 정의
    friend dayOfYear operator+ (const dayOfYear& d1, const dayOfYear& d2)
    {
        return dayOfYear {d1.month+d2.month, d1.day+d2.day};
    }
};

}
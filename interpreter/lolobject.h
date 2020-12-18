#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <cctype>

const char CHAR_POINT = '.';
const char CHAR_MINUS = '-';

const std::string WIN_CONST = "WIN";
const std::string LOSE_CONST = "LOSE";

enum LOL_TYPE {
    NOOB,
    NUMBR,
    NUMBAR,
    YARN,
    TROOF
};

class LolObject {
public:
    LolObject();
    LOL_TYPE val_type() const;

    explicit LolObject(const std::string& str);
    explicit LolObject(const char *str);
    explicit LolObject(double num);
    explicit LolObject(int num);
    explicit LolObject(bool value);

    // Unary operators
    LolObject& operator++();    
    LolObject operator++(int);  
    LolObject& operator--();    
    LolObject operator--(int);  
    LolObject operator-() const;

    // arithmetic operators
    friend LolObject operator+(const LolObject &left, const LolObject &right);
    friend LolObject operator-(const LolObject &left, const LolObject &right);
    friend LolObject operator*(const LolObject &left, const LolObject &right);
    friend LolObject operator/(const LolObject &left, const LolObject &right);
    friend LolObject operator%(const LolObject &left, const LolObject &right);

    // arithmetic with assignment
    LolObject& operator+=(const LolObject& other);
    LolObject& operator-=(const LolObject& other);
    LolObject& operator*=(const LolObject& other);
    LolObject& operator/=(const LolObject& other);
    LolObject& operator%=(const LolObject& other);

    // Comparison operators
    friend LolObject operator< (const LolObject& left, const LolObject& right);
    friend LolObject operator> (const LolObject& left, const LolObject& right);
    friend LolObject operator<=(const LolObject& left, const LolObject& right);
    friend LolObject operator>=(const LolObject& left, const LolObject& right);
    friend LolObject operator==(const LolObject& left, const LolObject& right);
    friend LolObject operator!=(const LolObject& left, const LolObject& right);

    explicit operator bool() const;

    friend std::ostream& operator<<(std::ostream& out, const LolObject& obj);
    friend std::istream& operator>>(std::istream& in, LolObject& obj);

    friend std::string gttp(LolObject x);

private:
    LOL_TYPE type;

    bool bool_value;
    int int_value;
    double double_value;
    std::string string_value;

    void int_update();
    void string_update();
    void double_update();
    void bool_update();

    friend LOL_TYPE get_type(const std::string& str);
};
#include "lolobject.h"

LOL_TYPE get_type(const std::string& str) {
    if (str == WIN_CONST || str == LOSE_CONST) {
        return TROOF;
    }
    size_t point_cnt = 0;
    for (auto it = str.begin(); it != str.end(); ++it) {
        if (*it == CHAR_POINT) {
            ++point_cnt;
        }
        if (point_cnt > 1 || !isdigit(*it) && !(*it == CHAR_MINUS && it == str.begin()) && !(*it == CHAR_POINT)) {
            return YARN;
        }
    }
    if (point_cnt == 1) {
        return NUMBAR;
    } else {
        return NUMBR;
    }
}

LOL_TYPE LolObject::val_type() const {
    return type;
}

///CONSTRUCTORS//////////////////////////////////////////////////////////////////////////////////////////////////////////

LolObject::LolObject()           : type(NOOB),
                                   bool_value(false),
                                   int_value(0),
                                   double_value(0),
                                   string_value(LOSE_CONST) {};


LolObject::LolObject(bool value) : type(TROOF),
                                   bool_value(value), 
                                   int_value(value ? 1 : 0),
                                   double_value(value ? 1. : 0.),
                                   string_value(value ? WIN_CONST : LOSE_CONST) {};

LolObject::LolObject(int num)    : type(NUMBR),
                                   bool_value(num != 0),
                                   int_value(num),
                                   double_value(num),
                                   string_value(std::to_string(num)) {};

LolObject::LolObject(double num) : type(NUMBAR),
                                   bool_value(num != 0), 
                                   int_value(static_cast<int>(num)),
                                   double_value(num),
                                   string_value(std::to_string(num)) {};

LolObject::LolObject(const std::string &str) {
    type = YARN;
    string_value = str;
    string_update();
    type = get_type(str);
}

LolObject::LolObject(const char *str) {
    *this = LolObject(static_cast<std::string>(str));
}

///UPDATING//////////////////////////////////////////////////////////////////////////////////////////////////////////

void LolObject::int_update() {
    if (type != NUMBR) {
        return;
    }
    double_value = static_cast<double>(int_value);
    string_value = std::to_string(int_value);
    bool_value = int_value != 0;
}

void LolObject::double_update() {
    if (type != NUMBAR) {
        return;
    }
    int_value = static_cast<int>(double_value);
    string_value = std::to_string(double_value);
    bool_value = double_value != 0;
}

void LolObject::string_update() {
    if (type != YARN) {
        return;
    }
    bool_value = string_value.length() > 0;
    LOL_TYPE tmp_type = get_type(string_value);
    if (tmp_type == NUMBR) {
        int_value = stoi(string_value);
        double_value = static_cast<double>(int_value);
        bool_value = double_value != 0. ? true : false;
    } else if (tmp_type == NUMBAR) {
        double_value = stod(string_value);
        int_value = static_cast<int>(double_value);
        bool_value = int_value ? true : false;
    } else {
        int_value = 0;
        double_value = 0;
    }
}

void LolObject::bool_update() {
    if (type != TROOF) {
        return;
    }
    int_value = bool_value ? 1 : 0;
    double_value = bool_value ? 1. : 0.;
    string_value = bool_value ? WIN_CONST : LOSE_CONST;
}

///UNARY//////////////////////////////////////////////////////////////////////////////////////////////////////////

LolObject& LolObject::operator++() {
    if (type != NUMBR) {
        return *this;
    }
    ++int_value;
    int_update();
    return *this;
}

LolObject LolObject::operator++(int) {
    if (type != NUMBR) {
        return *this;
    }
    LolObject res = *this;
    ++int_value;
    int_update();
    return res;
}

LolObject& LolObject::operator--() {
    if (type != NUMBR) {
        return *this;
    }
    --int_value;
    int_update();
    return *this;
}

LolObject LolObject::operator--(int) {
    if (type != NUMBR) {
        return *this;
    }
    LolObject res = *this;
    --int_value;
    int_update();
    return res;
}

LolObject LolObject::operator-() const {
    if (type == NUMBR) {
        return LolObject(int_value);
    }
    if (type == NUMBAR) {
        return LolObject(double_value);
    }
    return *this;
}

///ARITHMETIC//////////////////////////////////////////////////////////////////////////////////////////////////////////

LolObject operator+(const LolObject &left, const LolObject &right) {
    LolObject res = left;
    res += right;
    return res;
}

LolObject operator-(const LolObject &left, const LolObject &right) {
    LolObject res = left;
    res -= right;
    return res;
}

LolObject operator*(const LolObject &left, const LolObject &right) {
    LolObject res = left;
    res *= right;
    return res;
}

LolObject operator/(const LolObject &left, const LolObject &right) {
    LolObject res = left;
    res /= right;
    return res;
}

LolObject operator%(const LolObject &left, const LolObject &right) {
    LolObject res = left;
    res %= right;
    return res;
}

///ASSIGNMENT///ARITHMETIC///////////////////////////////////////////////////////////////////////////////////////////////

LolObject& LolObject::operator+=(const LolObject& other) {
    if (type == YARN && other.type == YARN) {
        string_value += other.string_value;
        string_update();
    }
    if (type == NUMBAR && other.type == NUMBAR) {
        double_value += other.double_value;
        double_update();
    }
    if (type == NUMBR && other.type == NUMBR) {
        int_value += other.int_value;
        int_update();
    }
    if (type == NUMBAR && other.type == NUMBR) {
        double_value += other.int_value;
        double_update();
    }
    if (type == NUMBR && other.type == NUMBAR) {
        double_value += other.double_value;
        type = NUMBAR;
        double_update();
    }
    if (type == TROOF && other.type == TROOF) {
        bool_value = bool_value || other.bool_value;
        bool_update();
    }
    return *this;
}

LolObject& LolObject::operator-=(const LolObject& other) {
    if (type == NUMBAR && other.type == NUMBAR) {
        double_value -= other.double_value;
        double_update();
    }
    if (type == NUMBR && other.type == NUMBR) {
        int_value -= other.int_value;
        int_update();
    }
    if (type == NUMBAR && other.type == NUMBR) {
        double_value -= other.int_value;
        double_update();
    }
    if (type == NUMBR && other.type == NUMBAR) {
        double_value -= other.double_value;
        type = NUMBAR;
        double_update();
    }
    return *this;
}

LolObject& LolObject::operator*=(const LolObject& other) {
    if (type == NUMBAR && other.type == NUMBAR) {
        double_value *= other.double_value;
        double_update();
    }
    if (type == NUMBR && other.type == NUMBR) {
        int_value *= other.int_value;
        int_update();
    }
    if (type == NUMBAR && other.type == NUMBR) {
        double_value *= other.int_value;
        double_update();
    }
    if (type == NUMBR && other.type == NUMBAR) {
        double_value *= other.double_value;
        type = NUMBAR;
        double_update();
    }
    if (type == TROOF && other.type == TROOF) {
        bool_value = bool_value && other.bool_value;
        bool_update();
    }
    return *this;
}

LolObject& LolObject::operator%=(const LolObject& other) {
    if (type == NUMBR && other.type == NUMBR) {
        int_value %= other.int_value;
        int_update();
    }
    return *this;
}

LolObject& LolObject::operator/=(const LolObject& other) {
    if (type == NUMBAR && other.type == NUMBAR) {
        double_value /= other.double_value;
        double_update();
    }
    if (type == NUMBR && other.type == NUMBR) {
        int_value /= other.int_value;
        int_update();
    }
    if (type == NUMBAR && other.type == NUMBR) {
        double_value /= other.int_value;
        double_update();
    }
    if (type == NUMBR && other.type == NUMBAR) {
        double_value /= other.double_value;
        type = NUMBAR;
        double_update();
    }
    return *this;
}

///COMPARISON//////////////////////////////////////////////////////////////////////////////////////////////////////////

LolObject::operator bool() const {
    return bool_value;
}

LolObject operator< (const LolObject& left, const LolObject& right) {
    if (left.type == NUMBAR && right.type == NUMBAR) {
        return LolObject(left.double_value < right.double_value);
    }
    if (left.type == NUMBR && right.type == NUMBR) {
        return LolObject(left.int_value < right.int_value);
    }
    if (left.type == NUMBAR && right.type == NUMBR) {
        return LolObject(left.double_value < right.int_value);
    }
    if (left.type == NUMBR && right.type == NUMBAR) {
        return LolObject(left.int_value < right.double_value);
    }
    return LolObject(false);
}

LolObject operator> (const LolObject& left, const LolObject& right) {
    return LolObject(right < left);
}

LolObject operator<=(const LolObject& left, const LolObject& right) {
    return LolObject(left < right || left == right);
}

LolObject operator>=(const LolObject& left, const LolObject& right) {
    return LolObject(right <= left);
}

LolObject operator==(const LolObject& left, const LolObject& right) {
    return LolObject(!(left != right));
}

LolObject operator!=(const LolObject& left, const LolObject& right) {
    return LolObject(left < right || left > right);
}

///IO/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

std::ostream& operator<<(std::ostream& out, const LolObject& obj) {
    out << obj.string_value;
    return out;
}

std::istream& operator>>(std::istream& in, LolObject& obj) {
    std::string str;
    in >> str;
    LOL_TYPE tp = get_type(str);
    if (tp == NUMBAR) {
        obj = LolObject(stod(str));
    } else if (tp == NUMBR) {
        obj = LolObject(stoi(str));
    } else if (tp == TROOF) {
        obj = LolObject(str == WIN_CONST ? true : false);
    } else {
        obj = LolObject(str);
    }
    return in;
}

std::string gttp(LolObject x) {
    if (x.type == NUMBAR) {
        return "NUMBAR ";
    } else if (x.type == NUMBR) {
        return "NUMBR ";
    } else if (x.type == YARN) {
        return "YARN ";
    } else if (x.type == TROOF) {
        return "TROOF ";
    } else {
        return "NOOB ";
    }    
}

// int main() {
//     std::vector<LolObject> a(7);

//     a[0] = LolObject(123);
//     a[1] = LolObject(10.11);
//     a[2] = LolObject("BABOBA");
//     a[3] = LolObject("-2020");
//     a[4] = LolObject("3001");
//     a[5] = LolObject("9.2");
//     a[6] = LolObject(true);

//     for (LolObject x : a) {
//         if (x.type == NUMBAR) {
//             std::cout << "NUMBAR ";
//         } else if (x.type == NUMBR) {
//             std::cout << "NUMBR ";
//         } else if (x.type == YARN) {
//             std::cout << "YARN ";
//         } else if (x.type == TROOF) {
//             std::cout << "TROOF ";
//         } else {
//             std::cout << "NOOB ";
//         }
//         std::cout << x.bool_value << " " << x.int_value << " " << x.double_value << " " << x.string_value << std::endl;
//     }

//     for (int i = 0; i < 7; ++i) {
//         for (int j = i; j < 7; ++j) {
//             std::cout << a[i] << " + " << a[j] << " = " << a[i] + a[j] << "          | " << gttp(a[i]) << " " << gttp(a[j]) << std::endl;
//             std::cout << a[i] << " - " << a[j] << " = " << a[i] - a[j] << "          | " << gttp(a[i]) << " " << gttp(a[j]) << std::endl;
//             std::cout << a[i] << " * " << a[j] << " = " << a[i] * a[j] << "          | " << gttp(a[i]) << " " << gttp(a[j]) << std::endl;
//             std::cout << a[i] << " / " << a[j] << " = " << a[i] / a[j] << "          | " << gttp(a[i]) << " " << gttp(a[j]) << std::endl;
//             std::cout << a[i] << " % " << a[j] << " = " << a[i] % a[j] << "          | " << gttp(a[i]) << " " << gttp(a[j]) << std::endl;
//         }
//     }

//     return 0;
// }

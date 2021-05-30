#include <iostream>
#include <string>
#include <windows.h>
#include <ctime>
#include <cstdlib>//import system
#include <vector>
#include <cassert>
using namespace std;
/*
void write_in_str(string&& text, int x, int y) {
    HANDLE hout;
    COORD coord;
    coord.X = y;
    coord.Y = x;
    hout = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hout, coord);
    cout << text;
}*/
void write_in_str(string text, int x, int y) {
    HANDLE hout;
    COORD coord;
    coord.X = y;
    coord.Y = x;
    hout = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hout, coord);
    cout << text;
}
template <typename T>
void write_in_num(T Number, int x, int y) {
    HANDLE hout;
    COORD coord;
    coord.X = y;
    coord.Y = x;
    hout = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hout, coord);
    cout << Number;
}
void eraseInputWindow(int& quick_p) {
    for (int i = 1; i < 8; i++) {
        write_in_str(string(100, ' '), quick_p + i, 0);
    }

}
bool isNumChar(char c) {
    if (static_cast<int>(c) >= static_cast<int>('0') && static_cast<int>(c) <= static_cast<int>('9')) {
        return true;
    }
    else {
        return false;
    }
}
int numCharToInt(char c) {
    assert(c >= '0' && c <= '9');
    return static_cast<int>(c) - static_cast<int>('0');
}
template<typename T>
char numToChar(T num) {
    assert(num >= 0 && num <= 9);
    return static_cast<char>(num + static_cast<int>('0'));
}
long long int  strToNum(string str) {
    long long int out = 0;
    for (unsigned int i = 0; i < str.length(); i++) {
        if (isNumChar(str[i])) {
            out *= 10;
            out += numCharToInt(str[i]);
        }
        else {
            return -1;
        }
    }
    return out;
}
template<typename T>
string numToString(T num) {
    assert(num - static_cast<T>(num) == 0);
    string str = "";
    num *= 10;
    for (int i = 0; num >= 10; i++) {
        num = num / 10;
        str = numToChar(num%10) + str;
    }
    return str;
}
class Curriculum {
public:
    string courseId;
    string courseName;
    string instructor;
    int usualScore{};
    int midTernScore{};
    int finalTernScore{};//需要扩展
    Curriculum* nextCurriculum = nullptr;
    Curriculum() {
        this->courseId = "null";
    }
    explicit Curriculum(string&& _courseId) {
        this->courseId = "HeNan University" + _courseId;
    }
    void setNext(Curriculum* curriculum) {
        this->nextCurriculum = curriculum;
    }
    //如何设计使得 对于每一个选择这个课程的学生来说，只需设置一次即可实现所有学生的这个课程的参数一致
    //并且这个设置是来自于输入而不是来自于默认设置？
    //---->解决方案，设置一个指针使得所有选择这个课程的学生共用这一个课程对象。
};
class classProperty {
public:
    string classEnum{};
    int numsOfStudent{};
    classProperty() = default;
    explicit classProperty(string&& _classEnum) {
        this->classEnum = _classEnum;
    }
    classProperty(string&& _classEnum, int _numOfStudent) {
        this->classEnum = _classEnum;
        this->numsOfStudent = _numOfStudent;
    }
};
class Student {
public:
    string name;
    string studentId;
    string classId;
    int age;
    string gender;
    //    Student* nextStudent = nullptr; 用于设计链表
    Student() {
        this->name = "undefined 1";
        this->age = 19;
        this->gender = "man";
    }
    Student(string&& _name, int _age, string&& _gender) {
        this->name = _name;
        this->age = _age;
        this->gender = _gender;
    }
};
void work_22_showAllCourse(int low_p, int quick_p,Curriculum* curriculum) {
    eraseInputWindow(quick_p);
    write_in_str("", quick_p + 1, 0);
    cout << "CurriculumId: " << curriculum->courseId << " courseName: " << curriculum->courseName << endl;
    auto* middleCurriculum = curriculum;
    while (middleCurriculum->nextCurriculum != nullptr) {
        middleCurriculum = middleCurriculum->nextCurriculum;
        cout << "CurriculumId: " << middleCurriculum->courseId << " courseName: " << middleCurriculum->courseName << endl;
    }
    cout << "input a char to continue!\n";
    string i;
    cin >> i;
    return;
}
void addCurriculumInformation(int& low_p, int& quick_p,Curriculum* curriculum) {
    string courseId;
    string courseName;
    eraseInputWindow(quick_p);
    write_in_str("", quick_p + 1, 0);
    cout << "Please input the CourseId\n";
    cin >> courseId;
    curriculum->courseId = courseId;
    cout << "Please input the courseName\n";
    cin >> courseName;
    curriculum->courseName = courseName;
    return;
}
void work_21_addNewCourse(int& low_p, int& quick_p,Curriculum* curriculum) {
    auto* newCurriculum = new Curriculum();
    if (curriculum->courseId == "null") {
        addCurriculumInformation(low_p,quick_p,curriculum);
        return;
    }
    Curriculum* middlePointer;
    middlePointer = curriculum;
    while (middlePointer->nextCurriculum != nullptr) {
        middlePointer = middlePointer->nextCurriculum;//获得最后一个非空课程指针
    }
    addCurriculumInformation(low_p,quick_p,newCurriculum);
    middlePointer->nextCurriculum = newCurriculum;
}
void paintTitle(int x, int& low_p, int& quick_p) {
    write_in_str(string(x, '-'), 0, 0); quick_p = 0;
    cout << "\n\n"; quick_p = 2;
    write_in_str(string(int(x / 3), ' '), quick_p, 0);
    cout << "Welcome to use this students manage System!";
    cout << "\n\n"; quick_p = 4;
    write_in_str(string(x, '-'), quick_p, 0);
    cout << "\n"; quick_p = 5;
    write_in_str("here are the instructors", quick_p, 0);
    cout << "\n"; quick_p = 6;
    write_in_str(string(x, '-'), quick_p, 0);
    cout << "\n"; quick_p = 7;
}
void printInstructions(int& low_p, int& quick_p) {
    write_in_str("1.Curriculum Management", quick_p,0);
    cout << "\n\n"; quick_p = 9;
    cout << "11-->add a curriculum info "; 
    write_in_str(" ", quick_p, 60);
    cout<< "12->show all available curriculum" << endl; quick_p = 10;
    cout << "13->modify the curriculum information" <<"\n\n"; quick_p = 12;
    cout << "2-->Students Information Management" << "\n\n"; quick_p = 14;
    cout << "21->Add student information for a course"; 
    write_in_str(" ", quick_p, 60);
    cout << "22->modify a student's information" << endl;
    cout << "23->query student information" << "\n\n"; quick_p = 16;
    cout << "3-->Students Performance Management" << "\n\n"; quick_p = 19;
    cout << "31->add a student's grade";
    write_in_str(" ", quick_p, 60);
    cout << "32->modify a student's grade" << endl;
    cout << "33->show all students' grade"; quick_p = 20;
    write_in_str(" ", quick_p, 60);
    cout << "34->query a student's grade" << endl;
    cout << "35->delete or resume a student's grade" << "\n\n"; quick_p = 23;
}
void paintControl(int& low_p, int& quick_p) {
    paintTitle(80, low_p, quick_p);
    printInstructions(low_p,quick_p);
}
bool isvalid(int instructCode2, vector<vector<string> > vec) {
    int index = numCharToInt(numToString(instructCode2)[0])+3;
    for (unsigned int i = 0; i < vec[index].size(); i++) {
        if (numToString(instructCode2) == vec[index][i]) {
            return true;
        }
    }
    return false;
}
void instructController(int low_p, int quick_p, Curriculum* curriculum, int instructCode2) {
    switch (instructCode2) {
    case 11:
        work_21_addNewCourse(low_p, quick_p, curriculum);
        break;
    case 12:
        work_22_showAllCourse(low_p, quick_p, curriculum);
        break;
    }
}
void paintTackle2(int& low_p, int& quick_p, int instructCode, vector<vector<string> > vec, Curriculum* curriculum) {
    bool signal0 = true;
    while (signal0) {
        eraseInputWindow(quick_p);
        write_in_str("whick instruct do you want to do?", quick_p, 0);
        for (unsigned int i = 0; i < vec[instructCode + 3].size(); i++) {
            cout << " " << vec[instructCode + 3][i];
        }
        cout << endl;
        write_in_str("echo>> ", quick_p + 1, 0);
        int instructCode2;
        cin >> instructCode2;
        if (isvalid(instructCode2, vec)) {
            write_in_str(string(100, ' '), quick_p, 0);
            write_in_str("you choose " + numToString(instructCode2)+"  R"+string(30,' '), quick_p, 0);//合法吗？不合法，退回上一步，合法根据输入，修改hang on数据展示块
        }
        else {
            write_in_str(string(100, ' '), quick_p, 0);
            write_in_str("you choose " + numToString(instructCode2) + " Not valid", quick_p, 60);
        }
        //work_21_addNewCourse(low_p,quick_p,curriculum);
        instructController(low_p, quick_p, curriculum, instructCode2);
    }

}
void paintData(int& low_p, int& quick_p, int instructCode, Curriculum* curriculum) {
    bool signal = true;
    vector< vector<string> > instructs(7);
    instructs[0] = vector<string>(1);
    instructs[1] = vector<string>(3);//1
    instructs[2] = vector<string>(3);//2
    instructs[3] = vector<string>(5);//3
    instructs[4] = vector<string>(3);//1
    instructs[5] = vector<string>(3);//2
    instructs[6] = vector<string>(5);//3
    instructs[0][0] = "0";
    instructs[1][0] = "add a curriculum info"; instructs[1][1] = "show all available curriculum"; 
    instructs[1][2] = "modify the curriculum information";
    instructs[2][0] = "Add student information for a course"; instructs[2][1] = "modify a student's information"; 
    instructs[2][2] = "query student information";
    instructs[3][0] = "add a student's grade"; instructs[3][1] = "modify a student's grade";
    instructs[3][2] = "show all students' grade"; instructs[3][3] = "query a student's grade";
    instructs[3][4] = "delete or resume a student's grade";
    instructs[4][0] = "11"; instructs[4][1] = "12"; instructs[4][2] = "13";
    instructs[5][0] = "21"; instructs[5][1] = "22"; instructs[5][2] = "23";
    instructs[6][0] = "31"; instructs[6][1] = "32"; instructs[6][2] = "33"; instructs[6][3] = "34"; instructs[6][4] = "35";
    paintTackle2(low_p, quick_p, instructCode, instructs,curriculum);
}
void paintInstruct(int& low_p, int& quick_p, int instructCode, Curriculum* curriculum) {
    if (instructCode == 1) {
        write_in_str("Curriculum Management              ", low_p, 60);
        write_in_str("echo>> 1", quick_p + 1, 0);
        paintData(low_p, quick_p, instructCode, curriculum);
    }
    else if (instructCode == 2) {
        write_in_str("Students Information Management   ", low_p, 60);
        write_in_str("echo>> 2", quick_p + 1, 0);
        paintData(low_p, quick_p, instructCode, curriculum);
    }
    else if(instructCode==3){
        write_in_str("Students Performance Management   ", low_p, 60);
        write_in_str("echo>> 3", quick_p + 1, 0);
        paintData(low_p, quick_p, instructCode, curriculum);
    }
    else {
        write_in_str("Invalid instructCode              ", low_p, 60);
        write_in_num(instructCode, quick_p + 1, 7);
    }
    
}
int main() {
    auto* firstCurriculum = new Curriculum();
    int instruct;
    int quick_p = 0;
    int low_p = 0;
    paintControl(low_p,quick_p);
    low_p = quick_p;
    quick_p = quick_p + 1;   //low_p = 23;  quick_p = 24;
    bool sign2 = true;
    while (true) {
        write_in_str(string(100, ' '), quick_p, 0);
        write_in_str("please input the System Code!",quick_p, 0);
        eraseInputWindow(quick_p);
        write_in_str("echo>> ", quick_p + 1, 0);
        cin >> instruct;
        paintInstruct(low_p,quick_p,instruct,firstCurriculum);
        
    }
    return 0;
    
}

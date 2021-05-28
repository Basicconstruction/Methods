#include <iostream>
#include <string>
#include <windows.h>
#include <ctime>
#include <cstdlib>//import system
using namespace std;
void write_in_str(string&& text, int x, int y) {
    HANDLE hout;
    COORD coord;
    coord.X = y;
    coord.Y = x;
    hout = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hout, coord);
    cout << text;
}
void write_in_num(int Number, int x, int y) {
    HANDLE hout;
    COORD coord;
    coord.X = y;
    coord.Y = x;
    hout = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hout, coord);
    cout << Number;
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
void showAllCourse(Curriculum* curriculum) {
    //    cout<<"CurriculumId: "<<curriculum->courseId<<" courseName: "<<curriculum->courseName<<" "<<&curriculum<<endl;
    cout << "CurriculumId: " << curriculum->courseId << " courseName: " << curriculum->courseName << endl;
    auto* middleCurriculum = curriculum;
    while (middleCurriculum->nextCurriculum != nullptr) {
        //        cout<<&(middleCurriculum->nextCurriculum)<<endl;
        middleCurriculum = middleCurriculum->nextCurriculum;
        //        cout<<"CurriculumId "<<middleCurriculum->courseId<<" courseName: "<<middleCurriculum->courseName
        //        <<" "<<&middleCurriculum<<endl;
        cout << "CurriculumId " << middleCurriculum->courseId << " courseName: " << middleCurriculum->courseName << endl;
    }
    return;
}
void addCurriculumInformation(Curriculum* curriculum) {
    string courseId;
    string courseName;
    cout << "Please input the CourseId\n";
    cin >> courseId;
    curriculum->courseId = courseId;
    cout << "Please input the courseName\n";
    cin >> courseName;
    curriculum->courseName = courseName;
    return;
}
void addNewCourse(Curriculum* curriculum) {
    auto* newCurriculum = new Curriculum();
    if (curriculum->courseId == "null") {
        addCurriculumInformation(curriculum);
        //        addCurriculumInformation(newCurriculum);
        //        curriculum = newCurriculum;
        return;
    }
    Curriculum* middlePointer;
    middlePointer = curriculum;
    //    cout<<&middlePointer<<endl;
    while (middlePointer->nextCurriculum != nullptr) {
        middlePointer = middlePointer->nextCurriculum;//获得最后一个非空课程指针
//        cout<<&middlePointer<<endl;
    }
    addCurriculumInformation(newCurriculum);
    middlePointer->nextCurriculum = newCurriculum;
}
void paintTitle(int x) {
    write_in_str(string(x, '-'), 0, 0);
    cout << endl;//x-1在这里很随意，实际上0-118都可以//endl尽管在这里也不是必须的
    write_in_str(string(int(x / 3), ' '), 2, 0);
    cout << "Welcome to use this students manage System!";
    cout << endl;//尽管在这里也不是必须的
    write_in_str(string(x, '-'), 4, 0);
    cout << endl;
    write_in_str("here are the instructors", 5, 0);
    cout << endl;
    write_in_str(string(x, '-'), 6, 0);
    cout << endl;
}
void printInstructions(int col) {
    write_in_str("1.Curriculum management",col,0);
    cout << "\n\n";
    cout << "11-->add a curriculum info ";
    write_in_str(" ", col + 2, 60);
    cout<< "12->show all available curriculum" << endl;
    cout << "13->modify the curriculum information" <<"\n\n";
    cout << "2-->Students Information Management" << "\n\n";
    cout << "21->Add student information for a course";
    write_in_str(" ", col + 7, 60);
    cout << "22->modify a student's information" << endl;
    cout << "23->query student information" <<"\n\n";
    cout << "3-->Students Performance Management"<<"\n\n";
    cout << "31->add a student's grade";
    write_in_str(" ", col + 12, 60);
    cout << "32->modify a student's grade" << endl;
    cout << "33->show all students' grade";
    write_in_str(" ", col + 13, 60);
    cout << "34->query a student's grade" << endl;
    cout << "35->delete or resume a student's grade" << "\n\n";
}
void paintControl() {
    paintTitle(118);
    printInstructions(7);
}
int main() {
    auto* firstCurriculum = new Curriculum();
    //    cout<<&firstCurriculum<<endl;
    string instruct;
    paintControl();
    while (true) {
        cin >> instruct;
        if (instruct == "0") {
            break;
        }
        else if (instruct == "11") {
            //添加课程信息
            addNewCourse(firstCurriculum);
        }
        else if (instruct == "12") {
            showAllCourse(firstCurriculum);
        }
    }
    return 0;
}
/* 以下用于命令行风格设计
bool outBreak;
int data = 0;
string s;
while(true){
    cout<<"shell>>";
    cin>>s;
    data++;
    if(data>=50){
        break;
    }
}*/
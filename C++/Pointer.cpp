#include <iostream>
#include <string>
using namespace std;
class Curriculum{
public:
    string courseId;
    string courseName;
    string instructor;
    int usualScore;
    int midTernScore;
    int finalTernScore;
    Curriculum* nextCurriculum = nullptr;
    Curriculum(){
        this->courseId = "1234";
    }
    Curriculum(string _courseId){
        this->courseId = "HeNan University"+_courseId;
    }
    void setNext(Curriculum* curriculum){
        this->nextCurriculum = curriculum;
    }
    //如何设计使得 对于每一个选择这个课程的学生来说，只需设置一次即可实现所有学生的这个课程的参数一致
    //并且这个设置是来自于输入而不是来自于默认设置？
    //---->解决方案，设置一个指针使得所有选择这个课程的学生共用这一个课程对象。
};
class Student{
public:
    int age;
    string name;
    string gender;
//    Student* nextStudent = nullptr; 用于设计链表
    Student(){
        this->name = "undefined 1";
        this->age = 19;
        this->gender = "man";
    }
    Student(string&& _name,int _age,string&& _gender){
        this->name = _name;
        this->age = _age;
        this->gender = _gender;
    }
};
void showAllCourse(Curriculum* curriculum){
    cout<<"CurriculumId "<<curriculum->courseId<<" courseName"<<curriculum->courseName;
    while(curriculum->nextCurriculum!= nullptr){
        cout<<"CurriculumId "<<curriculum->nextCurriculum->courseId<<" courseName"<<curriculum->nextCurriculum->courseName;
    }
    return;
}
void addCurriculumInformation(Curriculum* curriculum){
    string courseId;
    string courseName;
    cout<<"Please input the CourseId\n";
    cin>>courseId;
    curriculum->courseId = courseId;
    cout<<"Please input the courseName\n";
    cin>>courseName;
    curriculum->courseName = courseName;
    return;
}
void addNewCourse(Curriculum* curriculum){
    Curriculum* middlePointer;
    auto* newCurriculum = new Curriculum();
    if(curriculum==nullptr){
        curriculum = new Curriculum();
        cout<<curriculum->courseId;
        addCurriculumInformation(curriculum);
//        addCurriculumInformation(newCurriculum);
//        curriculum = newCurriculum;
        return;
    }
    Curriculum* df;
    middlePointer = curriculum;
    while(middlePointer->nextCurriculum!=nullptr){
        df = middlePointer->nextCurriculum;//获得最后一个非空课程指针
    }
    addCurriculumInformation(newCurriculum);
    df->nextCurriculum = newCurriculum;
}
int main() {
    Curriculum *firstCurriculum = nullptr;
    string instruct;
    while(true){
        cin>>instruct;
        if(instruct=="0"){
            break;
        }else if(instruct=="11"){
            //添加课程信息
            addNewCourse(firstCurriculum);
        }else if(instruct=="12"){
            cout<<firstCurriculum->courseId;
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
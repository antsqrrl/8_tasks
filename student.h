#include <List>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <windows.h>

using namespace std;

struct StudentInfo {
    char* name;
    char* surname;
    int age;
    char* numTicket;
};

struct SubjMark {
    char subj[100];
    int id_subj;
    vector<int> marks_list;
    float averMark;

//homework fill constructors
    SubjMark()
    {

    }
    SubjMark(const char* _subj)
    {
        memset(subj, 0 ,100);
        memcpy(subj, _subj, strlen(_subj));

    }
    SubjMark(const char* _subj, int _idSubj)
    {
        memset(subj, 0 ,100);
        memcpy(subj, _subj, strlen(_subj));
        id_subj = _idSubj;
    }
    ~SubjMark() {

    }

};


class Student {
private :
    StudentInfo* info;
    list<SubjMark*> listSubjMark;
    list<SubjMark*>::iterator lookForSub(const char* subjName);

public :

    Student();
    Student(const char* _name, const char* _surname, const int _age, const char* _numTicket);
    ~Student();

    void addSubject(const char* subjName, int idSubj = 0);

    int addMarkToSubj(const char* subjName, int mark);

    void print(void);
};

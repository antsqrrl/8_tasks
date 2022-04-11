#include "student.h"
using namespace std;

    list<SubjMark*>::iterator Student::lookForSub(const char* subjName) {
        for (list<SubjMark*>::iterator it = listSubjMark.begin(); it != listSubjMark.end(); ++it)
        {
            if (strcmp((*it)->subj, subjName) == 0)
            {
                return it;
            }
        }
        listSubjMark.push_back(new SubjMark(subjName));
        return listSubjMark.end();
    }



Student::Student()
    {

    }
Student::Student(const char* _name, const char* _surname, const int _age, const char* _numTicket)
    {
        info = new StudentInfo();
        info->name = (char*)_name;
        info->surname = (char*)_surname;
        info->age = _age;
        info->numTicket = (char*)_numTicket;
    }
Student::~Student()
    {
        delete info;
    }

    void Student::addSubject(const char* subjName, int idSubj) {


        for (list<SubjMark*>::iterator it = listSubjMark.begin(); it != listSubjMark.end(); ++it)
        {
            if (strcmp((*it)->subj, subjName) == 0)
            {
                (*it)->id_subj = idSubj;
                return;
            }
        }
        listSubjMark.push_back(new SubjMark(subjName, idSubj));
    }

    int Student::addMarkToSubj(const char* subjName, int mark) {
        auto subjMarkIt = lookForSub(subjName);
        if ((*subjMarkIt) != nullptr)
        {
            (*subjMarkIt)->marks_list.push_back(mark);
            float av_mark = 0;
            for(const auto& mark: (*subjMarkIt)->marks_list)
            {
                av_mark += mark;
            }
            av_mark /= (*subjMarkIt)->marks_list.size();
            (*subjMarkIt)->averMark = av_mark;
            return av_mark;
        }
        return 0;
    }

    void Student::print(void)
    {
        char buff[255];
        sprintf(buff, "%s %s, %u лет, билет №: %s", info->name, info->surname, info->age, info->numTicket);
        cout << buff << endl;
        for (list<SubjMark*>::iterator it = listSubjMark.begin(); it != listSubjMark.end(); ++it)
        {
            sprintf(buff, "Предмет: %s; Средняя оценка: %.1f", (*it)->subj, (*it)->averMark);
            cout << buff << endl;
        }
    }



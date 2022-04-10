#include <List>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <windows.h>
#include "student.h"

using namespace std;

void task8()
{
    auto student = new Student("Иван", "Иванов", 19, "билет 17");
    student->addSubject("Матан", 1);
    student->addMarkToSubj("Матан", 4);
    student->addMarkToSubj("Матан", 5);
    student->addSubject("Инфа", 2);
    student->addMarkToSubj("Инфа", 5);
    student->addMarkToSubj("Инфа", 5);
    student->print();
}

int main(int argc, char *argv[])
{
    SetConsoleOutputCP(CP_UTF8);
    task8();
}
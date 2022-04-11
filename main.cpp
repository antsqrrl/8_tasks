#include <List>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <windows.h>
#include "student.h"

using namespace std;

const int N = 2;
const int M = 3;

struct Node
{
    Node* prev;
    Node* next;
    char* string;
    int size;
};
class LinkedList
        {
        private:
            Node *HEAD;
            Node *TAIL;
        public:
            LinkedList();
            ~LinkedList();
        };
LinkedList::LinkedList()
{

}
LinkedList::~LinkedList()
{
    while (HEAD)
    {
        TAIL = HEAD->next;
        delete HEAD;
        HEAD = TAIL;
    }
}

void readFromFile1(const char* fileName, unsigned int* buff)
{
    FILE *f1;
    f1 = fopen(fileName, "r");
    if (f1 == nullptr)
    {
        return;
    }
    char i;
    do
    {
        i = fgetc(f1);
        if (i != EOF)
        {
            buff[i]++;
        }
    }while (i != EOF);
    fclose(f1);
}
void writeToFile(unsigned int* chars, const char* fileName)
{
    FILE *f1;
    f1 = fopen(fileName, "w");
    for (int i = 33; i < 127; i++)
    {
        fprintf(f1, "%c -> %u\n", (char)i, chars[i]);
    }

    fclose(f1);
}
void tempT() {

    for (int i = 0; i < 256; i++) {
        cout << (int)i << "\t" << (char)i;
    }

}
void fillArray(int **ar, const int N, const int M)
{
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            ar[i][j] = count;
            count++;
        }
    }
}
void printArray(int **ar, const int N, const int M)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << ar[i][j] << " ";
        }
        cout << endl;
    }
}
void linkedListToFile(Node *TAIL)
{
    Node* cur_node = TAIL;
    int elements_count = 0;

}

void task1()
{
    unsigned int buff[255] = {0};
    readFromFile1("C:\\8 tasks\\main.cpp", buff);
    writeToFile(buff, "C:\\8 tasks\\task1_result.txt");
}
void task2(int num)
{
    FILE  *f1;
    f1=fopen("outputfile2","w");
    char binNumb[32];
    for (int i = 0; i < 32; i++)
    {
        binNumb[i] = ((num & (1 << i)) >> i) + 0x30;
        fprintf(f1,"%c", binNumb[i]);
    }
    fclose(f1);
}
void task5(int **ar, const int N, const int M)
{
    float av_str = 0;
    float *result = new float[N];
    for (int i = 0; i < N; i++)
    {
        float summ = 0;
        for (int j = 0; j < M; j++)
        {
            summ+= ar[i][j];
        }
        summ/=M;
        result[i] = summ;
    }
    for (int i = 0; i < N; i++)
    {
        cout << result[i] << endl;
    }
}
void task6()
{

}
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
    task1();
//    int num = 17;
//    int **ar = new int*[N];
//    for (int i = 0; i < N; i++)
//    {
//        ar[i] = new int[M];
//    }
//    fillArray(ar, N, M);
//    printArray(ar, N, M);
//    cout << endl;
//    task5(ar, N, M);
//    task2(num);
//    task8();
//    tempT();
}
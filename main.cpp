#include <List>
#include <stdio.h>
#include <iostream>
#include <windows.h>
#include <algorithm>
#include <string>
#include <regex>
#include "student.h"

using namespace std;

struct Node
{
    Node* prev;
    Node* next;
    int element;
    int size;
};
class LinkedList
        {
        private:
            Node *Head;
            Node *Tail;
            unsigned int length = 0;
        public:
            LinkedList();
            ~LinkedList();
            void addFirstToList(int number);
            void showList();
            void writeListToFile(const char* fileName);
            void insertTo(int index, int number);
        };

LinkedList::LinkedList()
{
    Head = Tail = NULL;
}
LinkedList::~LinkedList()
{
    while (Head)
    {
        Tail = Head->next;
        delete Head;
        Head = Tail;
    }
}

void LinkedList::addFirstToList(int number)
{
    Node *temp = new Node;
    //temp->next = NULL; // По следующему адресу пусто
    temp->element = number;
    if (Head == NULL)
    {
        temp->next = Tail;
        Tail = temp;
    }
    else
    {
        temp->next = Head;
        Head->prev = temp;
    }
    Head = temp;
    Head->prev = NULL;
    length++;
}
void LinkedList::showList()
{
    if (Head != NULL)
    {

        Node* temp = Head;
        //cout << "Size: " << length;
        //cout << endl;
        while (temp != NULL)
        {
            cout << temp->element << endl;
            //cout << " ";
            temp = temp->next;
        }


    }
    else
    {
        cout << "Empty" << endl;
    }
    cout << endl;
}
void LinkedList::insertTo(int index, int number)
{
    if (index > length)
    {
        return;
    }
    if (index == 0)
    {
        addFirstToList(number);
        return;
    }
    Node *temp = new Node;
    temp->element = number;
    Node *it = Head;
    for (int i = 0; i <= index; i++)
    {
        if (i == index)
        {
            temp->next = it;
            if (it != NULL)
            {
                temp->prev = it->prev;
                it->prev->next = temp;
                it->prev = temp;
            }
            else
            {
                Tail->next = temp;
                temp->prev = Tail;
                Tail = temp;
            }
            length++;
        }
        else
        {
            it = it->next;
        }
    }
}
void LinkedList::writeListToFile(const char* fileName)
{
    FILE *f1;
    f1 = fopen(fileName, "w");
    Node* tempHead = Head;
    Node* tempTail = Tail;
    while (tempHead != NULL)
    {
        fprintf(f1, "%d ", tempHead->element);
        tempHead = tempHead->next;
    }
    fprintf(f1, "\n");
    while (tempTail != NULL)
    {
        fprintf(f1, "%d ", tempTail->element);
        tempTail = tempTail->prev;
    }
    fclose(f1);
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
void writeToFile(unsigned int* chars)
{
    FILE *f1;
    f1 = fopen("outputfile1.txt", "w");
    for (int i = 33; i < 127; i++)
    {
        fprintf(f1, "%c -> %u\n", (char)i, chars[i]);
    }

    fclose(f1);
}
void fillArray(int **ar, const int N, const int M)
{
    srand(time(nullptr));
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            ar[i][j] = rand();
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

void task1()
{
    unsigned int buff[255] = {0};
    readFromFile1("inputfile1.txt", buff);
    writeToFile(buff);
}
void task2(int num)
{
    FILE  *f1;
    f1=fopen("outputfile2.txt","w");
    char binNumb[32];
    bool isLeadZero = true;
    int firstNonZero = 0;
    for (int i = 31; i >= 0; i--)
    {
        binNumb[i] = ((num & (1 << i)) >> i) + 0x30;
        if (isLeadZero && (binNumb[i] == 0x31))
        {
            isLeadZero = false;
            firstNonZero = i;
        }
        if (!isLeadZero)
        {
            fprintf(f1,"%c", binNumb[i]);
            cout << binNumb[i];
        }
    }
    cout << endl;
    fprintf(f1,"\n");
    for (int i = 0; i <= firstNonZero; i++)
    {
        cout << binNumb[i];
    }
    for (int i = 0; i <= firstNonZero; i++)
    {
        fprintf(f1,"%c", binNumb[i]);
    }
    fclose(f1);

}
void task3(const char* bin, int length)
{
    int num = 0;
    for (int i = 0; i < length; i++)
    {

        if (bin[i] == 0x31)
        {
            num++;
        }
        if (i != length-1)
        {
            num = num << 1;
        }

    }
    printf(" в шестнадцатеричном виде:%x", num);

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
    cout << "Средние значения для строчек:" << endl;
    for (int i = 0; i < N; i++)
    {
        cout << i+1 << " строчка: " << result[i] << endl;
    }
}
void task6_7()
{
    LinkedList lst;
    bool ok = true;
    cout << "1 - добавить элемент в начало списка." << endl;
    cout << "2 - добавить элемент в заданное место списка." << endl;
    cout << "3 - вывести список на экран." << endl;
    cout << "4 - записать список в файл." << endl;
    cout << "5 - выйти" << endl;
    while (ok)
    {
        int oper;
        cout << "Выберите операцию:";
        cin >> oper;
        switch (oper)
        {
            case 1:
                int number;
                cout << "Введите число:";
                cin >> number;
                lst.addFirstToList(number);
                break;
            case 2:
                int num;
                int index;
                cout << "Введите число:";
                cin >> num;
                cout << "Введите порядковый номер:";
                cin >> index;
                lst.insertTo(index-1, num);
                break;
            case 3:
                lst.showList();
                break;
            case 4:
                lst.writeListToFile("outputfile6.txt");
                break;
            case 5:
                ok = false;
                break;
        }
    }
//    lst.addFirstToList(1);
//    lst.addFirstToList(21);
//    lst.addFirstToList(31);
//    lst.showList();
//    cout << endl;
//    lst.insertTo(0, 79);
//    lst.showList();
//    lst.writeListToFile("C:\\8 tasks\\task6_result.txt");
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
void callTasks()
{
    // Задача 1
    task1();
    cout << "1 задача выполнена." << endl;
    cout << endl;

    // Задача 2
    int num;
    cout << "Введите число, которое нужно перевести в двоичный вид:";
    cin >> num;
    cout << "Результат:" << endl;
    task2(num);
    cout << endl;
    cout << "2 задача выполнена." << endl;
    cout << endl;

    // Задача 3
    const char* inpt = "0x31 0x30 0x31 0x30 0x30";
    cout << "Входное число " << inpt;
    string line = string(inpt);
    regex rx("0x3");
    string fmt("");
    regex lx(" ");
    string fml("");
    line = regex_replace(line, rx, fmt);
    line = regex_replace(line, lx, fml);
    inpt = line.c_str();
    task3(inpt, strlen(inpt));
    cout << endl;
    cout << "3 задача выполнена." << endl;
    cout << endl;

    // Задача 5
    int N, M;
    cout << "Введите кол-во строк матрицы:";
    cin >> N;
    cout << "Введите кол-во столбцов матрицы:";
    cin >> M;
    cout << "Матрица заполняется случайными числами. Созданная матрица:" << endl;
    int **ar = new int*[N];
    for (int i = 0; i < N; i++)
    {
        ar[i] = new int[M];
    }
    fillArray(ar, N, M);
    printArray(ar, N, M);
    cout << endl;
    task5(ar, N, M);
    cout << "5 задача выполнена." << endl;
    cout << endl;

    // Задачи 6 и 7
    task6_7();
    cout << "6 и 7 задачи выполнены." << endl;
    cout << endl;

    // Задача 8
    task8();
    cout << "8 задача выполнена." << endl;
}

int main(int argc, char *argv[])
{
    SetConsoleOutputCP(CP_UTF8);
    callTasks();
}
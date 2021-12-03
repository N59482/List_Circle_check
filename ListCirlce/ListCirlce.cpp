#include <iostream>
#include <ctime>

using namespace std;
/*
односвязный список
элемент списка реализован через вложенный класс
элемент хранит данные типа int и указатель на следующий элемент
У списка есть:
-Указатель head на начало списка
-Количество элементов в переменной size
-Функция push_back()
-Функция Make_Circle() для намеренного создания цикла (петли) внутри списка
Make_Circle() находит случайный элемент списка кроме первого - pnt1 и привязывает его указатель next
к случайному элементу списка pnt2 который расположен не дальше элемента с индесом pnt1
-Функция show() для вывода списка БЕЗ цикла
-Функция Circle_show(int a) для вывода куска списка содержащего цикл от 0 до элемента с индесом 'a'
    */
class List
    {
    private:
        class element
        {
        public:
            int data = 0;
            element* next = nullptr;
            element(element* n = nullptr, int d = 0)
            {
                data = d;
                next = n;
            };
        };

    public:
        element* head = nullptr;
        int size = 0;
        void push_back(int a)
            {
                if (head == nullptr)
                {
                    head = new element(nullptr, a);

                }
                else
                {
                    element* temp = head;
                    while (temp->next != nullptr) temp = temp->next;
                    temp->next = new element(nullptr, a);
                };
                size++;
            };

        void Make_Circle()
            {
                cout << "START Make_Circle\n";
                if (size > 1)
                {
                    cout << "Processed Make_Circle\n";
                    element * temp1 = head;
                    element * temp2 = head;
                    int pnt1 = (rand() % (size - 1)) + 1;
                    int pnt2 = (rand() % (pnt1 - 1));
                    cout << "pnt1 = " << pnt1 << " pnt2 = " << pnt2 << endl;
                    for(int a = 0; a < pnt1; a++) temp1 = temp1->next;
                    for(int a = 0; a < pnt2; a++) temp2 = temp2->next;
                    temp1->next = temp2;
                }
                cout << "END Make_Circle\n";
            }

        void show()
            {
                element* temp = head;
                while (temp != nullptr)
                {
                    cout << temp->data << " ";
                    temp = temp->next;
                };
                cout << endl;
            };

        void Circle_show(int a)
            {
                element* temp = head;
                while (a)
                {
                    cout << temp->data << " ";
                    temp = temp->next;
                    a--;
                };
                cout << endl;
            };
    };

/*
Фунция isCircle(List &l) - принимает односвязный список List(включая пустой список) и возвращает 0 - если он имеет конец и 1 - если он содержит цикл
на первый и второй элемент списка присваиваются указатели p1 и р2 соответственно
пока p2 не указывает на nullptr (если массив состоит из 1 элемента то p2 == nullptr сразу)
Цикл продолжается до тех пор, пока p2 != nullptr, увеличивая р1 на единицу и р2 на два в каждой итерации. р2 гарантированно достигнет конца первым 
(если есть конец) Если нет конца (то есть, если есть цикл), они в конечном итоге будут указывать на один и тот же элемент
это означает что алгоритм нашёл цикл
    */
bool isCircle(List& l)
    {
        if(l.head == nullptr) return 0;
        auto* p1 = l.head;
        auto* p2 = p1->next;
        while(p2 != nullptr)
            {
                if(p1 == p2) return 1;
                    else if(p2->next == nullptr) return 0;
                         else 
                            {
                                p2 = p2->next->next;
                                p1 = p1->next;
                            };
            };
        return 0;
    };

/*
тесты для функции Circle_test
    */
bool Circle_test(int l_size)
{
    List tl;
    for(int i = 0; i < l_size; i++) tl.push_back(rand() % 100); 
    auto * pe = tl.head;
    for(int i = 0; i < tl.size; i++) pe = pe->next;
    if ((pe != nullptr) == (isCircle(tl))) return 1;
    return 0;
};

int main()
    {
        srand(time(0));
        List l;
        for (int i = 0; i < 4; i++) l.push_back(i);
        l.show();
        cout<<((isCircle(l))? "Circle detected" : "no Circle here!")<<endl;
        l.Make_Circle();
        l.Circle_show(20);
        cout<<((isCircle(l))? "Circle detected" : "no Circle here!")<<endl;
 
        for(int i = 0; i < 2000; i++)  if(!Circle_test(20)) cout<<"ERROR\n";
        // cout<<(Circle_test(10)? "Good":"test fallen!")<<endl;


        return 0;
    };

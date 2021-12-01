#include <iostream>
#include <ctime>

using namespace std;

class List
{
    private:
    class element
        {
            public:
            int data = 0;
            element * next = nullptr;
            element(element * n = nullptr, int d = 0)
                {
                    data = d;
                    next = n;
                };
        };
    
    public:
    element * head = nullptr;
    int size = 0;
    void push_back(int a)
        {
            if(head == nullptr)
                {
                    head = new element(nullptr, a);
                
                }else
                {
                    element* temp = head;
                    while(temp->next != nullptr) temp = temp->next;
                    temp->next = new element(nullptr, a);
                };
            size++;
        };
       
    void Make_Circle()
        {
            if (size > 1)
            {
                element * temp1 = head;
                element * temp2 = head;
                int pnt1 = (rand() % size-1)+2;
                int pnt2 = (rand() % pnt1)+1;
                for(int a = 0; a < pnt1; a++) temp1 = temp1->next;
                for(int a = 0; a < pnt2; a++) temp2 = temp2->next;
                temp1->next = temp2;
            }
        }; 

    void show()
        {
            element* temp = head;
            while(temp != nullptr) 
            {
                cout<<temp->data<<" ";
                temp = temp->next;
            };
            cout<<endl;
        };

    void Circle_show(int a)
        {
            element* temp = head;
            while(a) 
            {
                cout<<temp->data<<" ";
                temp = temp->next;
                a--;
            };
            cout<<endl;
        };
};


int main()
{
    srand(time(0));
    List l;
    for(int i = 0; i<10 ; i++) l.push_back(i);

    l.show();

    l.Make_Circle();

    l.Circle_show(20);
    return 0;
}

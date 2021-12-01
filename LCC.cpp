#include <iostream>

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
       
    void Make_Curcle()
        {
            if (size > 1)
            {
                element * temp = head;
                for(int a = 0; a < (rand() % size); a++) temp = temp->next;
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
};


int main()
{
    List l;
    l.push_back(12);
    l.push_back(14);
    l.push_back(15);
    l.push_back(13);

    cout<<(rand() % size)<<endl;
    cout<<(rand() % size)<<endl;
    cout<<(rand() % size)<<endl;
    cout<<(rand() % size)<<endl;
    cout<<(rand() % size)<<endl;
    cout<<(rand() % size)<<endl;
    cout<<(rand() % size)<<endl;
    cout<<(rand() % size)<<endl;

    l.show();
    return 0;
}

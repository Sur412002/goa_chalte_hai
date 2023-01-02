#include <iostream>
using namespace std;
#define SIZE 100
class Pr_Q
{
    private:
    int que[SIZE];
    public:
    int rear,front;
    Pr_Q();
    int insert(int rear,int front);
    int Qfull(int rear);
    int delet(int front);
    int Qempty(int rear,int front);
    void display(int rear,int front);
};
Pr_Q::Pr_Q()
{
    front=0;
    rear=-1;
}
int Pr_Q::insert(int rear,int front)
{
    int item,j;
    cout<<"\nEnter the element: ";
    cin>>item;
    if(front ==-1)
        front++ ;
    j=rear;
    while(j>=0 && item<que[j])
    {
        que[j + 1] =que[j];
        j--;
    }
    que[j+1]=item;
    rear=rear+ 1;
    return rear;
}
int Pr_Q::Qfull(int rear)
{
    if(rear==SIZE-1)
        return 1;
    return 0;
}
int Pr_Q::delet(int front)
{
    int item;
    item=que[front];
    cout << "\n The item deleted is "<< item;
    front++;
    return front;
}
int Pr_Q::Qempty(int rear,int front)
{
    if((front==-1) || (front>rear))
        return 1;
    return 0;
}
void Pr_Q::display(int rear,int front)
{
    int i;
    cout<<"\n The queue is: ";
    for(i=front;i <=rear;i++) {
        cout<<" "<<que[i] ;
    }
}
int main() {
    int choice;
    char ans;
    Pr_Q obj;
    do
    {
        cout<<"\n\t\t Priority Queue\n";
        cout<<"\n Main Menu";
        cout << "\n1.Insert\n2.Delete\n3.Display\n4.Exit\n";
        cout<<"\n Enter Your Choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                if(obj.Qfull(obj.rear))
                    cout<<"\n Queue IS full";
                else {
                    obj.rear= obj .insert( obj.rear ,obj.front);
                }
                break;
            case 2 :
                if( obj.Qempty( obj.rear ,obj.front))
                    cout<<"\n Cannot delete element";
                else {
                    obj.front= obj.delet( obj.front);
                }
                break;
            case 3 :
                if( obj.Qempty( obj.rear ,obj.front))
                    cout<<"\n Queue is empty";
                else {
                    obj.display( obj.rear ,obj.front);
                }
                break;
            case 4:
                cout << "\n-----------EXITING----------\n";
                exit(0);
            default:
                cout<<"\nWrong choice: ";
                break;
        }
    }
    while(true);
    return 0;
}

#include <iostream>
#include <algorithm>
using namespace std;

template <class T>
struct node
{
    T data;
    node<T> *next;
    node<T> *back;
};


template<class T>
class List {
private:
   int c;
   node<T> *head;
   node<T> *tail;
   node<T>*dummynode=NULL;


public:

class iterator {
public:
    node<T> *nodeptr;
    node<T> *first;

iterator(){
nodeptr=nullptr;
first=nullptr;
}
iterator(node<T> *n,node<T>* h){
   nodeptr=n;
    first=h;
    }

void operator++(){
    if(nodeptr->next==NULL){
        throw" can't increment,it is pointing now past the last element";
    }
    nodeptr=nodeptr->next;

}
void operator++(int){
    if(nodeptr->next==NULL){
        throw" can't increment,it is pointing now past the last element";
    }
    nodeptr=nodeptr->next;
}

void operator --(int){
    if(nodeptr==first){
        throw" can't decrement,it is pointing now to the first element";
    }
     nodeptr=nodeptr->back;
}

void operator --(){
    nodeptr=nodeptr->back;
    if(nodeptr==first){
        throw" can't decrement,it is pointing now to the first element";
    }
     nodeptr=nodeptr->back;

}


T& operator*(){
        return nodeptr->data;
        }


bool operator==(const  iterator & it){
    return nodeptr==it.nodeptr;
}

bool operator!=(const iterator& it) {
            return nodeptr != it.nodeptr;
        }

};


List(){
    head= NULL;
    tail= NULL;
    c=0;
    }

List(T value, int initialsize){
    node<T> *temp;
    temp=new node <T>;
    temp->data=value;
    temp->next=NULL;
    temp->back=NULL;
    head=temp;
    tail=temp;
    c=initialsize;
    for(int i=1;i<initialsize;i++){
            node<T> *n;
            n=new node <T>;
            n->data=value;
            n->next=NULL;
            tail->next=n;
            n->back=tail;
            tail=n;
    }
}



void destroylist(){
    node<T>* temp;
    while(head!=NULL){
        temp=head;
        head=head->next;
        delete temp;
    }
    tail=NULL;
    c=0;}


~List(){
    destroylist();
    }



List<T>& operator = (List<T> otherlist){
if (otherlist.head == nullptr){
        return *this;}
else{
    node<T>*current=new node<T>;
    node<T>*temp= otherlist.head;
    head = new node<T>;
    head->data = temp->data;
    head->next = nullptr;
    current = head;
    temp = temp->next;

    while (temp != nullptr)
    {
        current->next = new node<T>;
        current = current->next;
        current->data = temp->data;
        current->next = nullptr;
        temp = temp->next;
    }
    return *this;}
}













int size(){
    int count=0;
    node<T>* current;
    current=head;
    while(current!=NULL){
        count++;
        current=current->next;
        }
    return count;
}

void insert(T value,iterator position){
    bool found;
    node<T> *newnode=new node<T>;
    node<T> *current;
    node<T> *trailcurrent;
    newnode->data=value;
    newnode->next=NULL;
    newnode->back=NULL;
    if(head==NULL){
        head=newnode;
        tail=newnode;
        c++;
    }
    else{
            found=false;
            current=head;
            trailcurrent=current->back;
            while(current!=NULL&&!found){
                if(current==position.nodeptr){
                    found=true;}
                else{
                trailcurrent=current;
                current=current->next;}}
                if(found){
                if(current==head){
                            head->back = newnode;
                            newnode->next = head;
                            head = newnode;
                            c++;
                            }
                        else {
                            trailcurrent->next = newnode;
                            newnode->back = trailcurrent;
                            newnode->next = current;
                            current->back = newnode;
                            if(current=NULL){
                                tail= newnode;}
                        c++;}
                        }}

    }



iterator begin(){
    return iterator(head,head);

}


iterator end(){
    return iterator(tail,head);
}



 void push_back(T value)
    {
        node<T> *newnode=new node<T>;
        newnode->data=value;
        newnode->next=NULL;
        newnode->back=NULL;
        if(head==NULL){
            head=newnode;
            tail=newnode;
            c++;
        }
        else{
            tail->next=newnode;
            newnode->back=tail;
            tail=newnode;
            c++;
        }
    }


iterator erase(iterator position) {
    node<T> *current;
    node<T> *trailCurrent;
    current=position.nodeptr;
    position.nodeptr= position.nodeptr->next;
    if(current->back==NULL){
        head=position.nodeptr;
        delete current;
        c--;
        return position;
    }
    else{
    if(position.nodeptr==NULL){
       throw"Out of Range";
    }
    trailCurrent = current->back;
    trailCurrent->next = current->next;
    if (current->next != NULL){
        current->next->back = trailCurrent;}
    if (current == tail){
            tail = trailCurrent;}
     c--;
    delete current;
    return position;}
}


void display()
    {
        node<T> *current=new node<T>;
        current=head;
        while(current!=NULL)
        {
            cout<<current->data<<" ";
            current=current->next;
        }
        cout<<endl;
    }




};

int main()
{
List<int> myList(8,2);
cout<<"Our list at first = ";
myList.display();
cout<<"The initial size= "<<myList.size()<<endl;
myList.push_back(9);
myList.push_back(10);
myList.push_back(1);
myList.push_back(4);
myList.push_back(6);
cout<<"Our first list = ";
myList.display();
cout<<"The size= "<<myList.size()<<endl;
try{
List<int>::iterator it = myList.begin();
cout<<"The first element in the list = "<<*it<<endl;
it++;
it++;
cout<<"After incrementing the iterator Twice,The third element in the list = "<<*it<<endl;
cout<<"------------------------------------"<<endl;
cout<<"The second list"<<endl;
List <int> list2;
list2.push_back(50);
list2.display();
list2.push_back(45);
list2.display();
list2.push_back(6);
list2.display();
list2.push_back(21);
list2.display();
list2.push_back(100);
list2.display();
list2.push_back(3);
list2.display();
list2.push_back(25);
list2.display();
cout<<endl;
cout<<"So,Our second list = ";
list2.display();
cout<<"its size= "<<list2.size()<<endl;

List<int>::iterator it3 = list2.begin();
it3++;
it3++;
it3++;
it3++;
it3++;
list2.insert(1000,it3);
cout<<"By inserting 1000 value in the place of 3 ,the list will be = ";
list2.display();
cout<<"So, the size will be= "<<list2.size()<<endl;
list2.erase(it3);
List<int>::iterator it4 = list2.begin();
it4++;
list2.erase(it4);
cout<<"After erasing 45 and 3 the list will be = ";
list2.display();

cout<<"-------------------------------------"<<endl;
List<int> l;
l=myList;
cout<<"The third list after deep copying with the first list= ";
l.display();
List<int>::iterator it5 = l.begin();
it5;
cout<<"The first element= "<<*it5;
cout<<endl;
it5--;
cout<<endl;
}
catch (const char *msg) // Handle exception
{
cout << "Error: " << msg;
}

return 0;

}

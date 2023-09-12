#include <iostream>
#include <bits/stdc++.h>

using namespace std;

  //Array List
template<class T>
class ArrayList        //DONE
{
private:
    int Size;
    int length;
    T* arr;
public:

    ArrayList()
    {
        Size = 10;
        length = 0;
        arr = new T[Size];
    }

    ArrayList(int s)
    {
        length = 0;
        Size = s;
        arr = new T[Size];
    }

    bool isEmpty()
    {
        return length == 0;
    }

    bool isFull()
    {
        return length == Size;
    }

    void Insert (T element)
    {
        if (!isFull())
        {
            arr[length++] = element;
        }
        else
        {
            cout << "Full!\n";
        }
    }

    void insertAt(T val, int index)
    {
        if (index >= 0 && index <= length)
        {
            if (length == 0)
            {
                arr[0] = val;
                length++;
            }
            else if (length < Size-1)
            {
                for (int i=length-1; i>=index ; i-- )
                {
                    arr[i+1] = arr[i];
                }
                arr[index] = val;
                length++;
            }

        }
        else
        {
            cout << "Invalid Index!!\n";
        }
    }

    void removeAt(int index)
    {
        if(index >= 0 && index < length)
        {
            if (index==length)
            {
                length--;
            }
            else
            {
                for (int i=index; i<length-1 ; i++ )
                {
                    arr[i] = arr[i+1];
                }
                length--;
            }
        }
        else
        {
            cout << "Invalid Index!!\n";
        }
    }

    int Search(T val)
    {
        if(!isEmpty())
        {
            for (int i =0; i<length ; i++ )
            {
                if (arr[i] == val)
                {
                    return i;
                }
            }
            cout << "Have not been founded in the array!!\n";
            return -1;
        }
        else
        {
            cout << "Empty array\n";
        }
    }

    void UpdateAt(T val, int index)
    {
        if (isEmpty())
        {
            cout << "Empty Array\n";
        }
        else if (index >= 0 && index < length)
        {
            arr[index] = val;
        }
        else
        {
            cout << "Invalid Index!!\n";
        }
    }

    int getSize()
    {
        return Size;
    }

    int getLength()
    {
        return length;
    }

    void Print()
    {
        if (length > 0)
        {
            cout << "[ ";
            for (int i=0 ; i<length-1 ; i++ )
            {
                cout << arr[i] << " - ";
            }
            cout << arr[length-1] << " ]\n";
        }
        else
        {
            cout << "Empty Array\n";
        }
    }

    ~ArrayList()
    {
        delete[]arr;
    }

    void Clear()
    {
        length = 0;
    }
};



  //Linked Lists
template<class T>
class LinkedList       //DONE
{
    struct Node
    {
        T val;
        Node* next;
    };
    Node* Head;
    Node* Tail;
    int Size;
public:


    LinkedList()
    {
        Head = nullptr;
        Tail = nullptr;
        Size = 0;
    }

    LinkedList(Node* h)
    {
        Head = h;
        Tail = h;
        Size = 0;
    }

    int getSize()
    {
        return Size;
    }

    Node* getHead()
    {
        return Head;
    }

    T tHead()
    {
        return Head->val;
    }

    void setHead (Node* h)
    {
        this->clear();
        Head = h;
    }

    bool isEmpty(){
        return Head == nullptr;
    }

    void pushBack(T val)
    {
        if(isEmpty())
        {
            Node* temp = new Node;
            temp->val = val;
            temp->next=nullptr;
            Head = temp;
            Tail  = temp;
            temp = nullptr;
            delete temp;
            Size++;
        }
        else
        {
            Node* temp = new Node;
            temp->val = val;
            temp->next=nullptr;
            Tail->next = temp;
            Tail = temp;
            temp = nullptr;
            delete temp;
            Size++;
        }
    }

    void pushFront(T val)
    {
        if (Head == nullptr){
            Node* temp = new Node;
            temp->val = val;
            temp->next = nullptr;
            Head = temp;
            temp = nullptr;
            delete temp;
            Size++;
        }else{
            Node* temp = new Node;
            temp->val = val;
            temp->next = Head;
            Head = temp;
            temp = nullptr;
            delete temp;
            Size++;
        }
    }

    T PopFront()
    {
        if (Head != 0){
            T val = Head->val;
            Node* temp = Head;
            Head = Head->next;
            delete temp;
            Size--;
            return val;
        }
    }

    T popBack()
    {
        Node* current = Head;
        while(current->next!=Tail)
        {
            current = current->next;
        }
        T val = Tail->val;
        delete Tail;
        Tail = current;
        Tail->next = nullptr;
        current = nullptr;
        delete current;
        Size--;
        return val;
    }

    void InsertAt(int pos, T val)
    {
        if(isEmpty())
        {
            pushFront(val);
        }
        else
        {
            if (pos <= 0)
            {
                pushFront(val);
            }
            else if (pos >= Size-1)
            {
                pushBack(val);
            }
            else
            {
                Node* current = Head;
                for (int i=0 ; i < pos-1 ; i++ )
                {
                    current = current->next;
                }
                Node* newNode = new Node();
                newNode->val = val;
                newNode->next=current->next;
                current->next=newNode;
                newNode=nullptr;
                current=nullptr;
                delete newNode;
                delete current;
                Size++;
            }
        }
    }

    void Update (int indx, int newVal)
    {
        if (indx >=0 && indx < Size && !isEmpty())
        {
            Node* current = Head;
            int c =0;
            while(current != nullptr)
            {
                if (c == indx)
                {
                    current->val = newVal;
                    break;
                }
                c++;
            }
        }
        else
        {
            cout << "Invalid Index!\n";
        }
    }

    void DeleteAt(int pos)
    {
        if(isEmpty())
        {
            cout << "Empty List\n";
        }
        else
        {
            if (pos <= 0)
            {
                PopFront();
            }
            else if (pos >= Size-1)
            {
                popBack();
            }
            else
            {
                Node* current = Head;
                for (int i=0 ; i < pos-1 ; i++ )
                {
                    current = current->next;
                }
                Node* del = current->next;
                current->next=del->next;
                del=nullptr;
                current=nullptr;
                delete del;
                delete current;
                Size--;
            }
        }
    }

    int getPos(T val)
    {
        Node* current = Head;
        int i = -1;
        while(current!= nullptr)
        {
            if (current->val == val)
            {
                i++;
                return i;
            }
            i++;
            current = current->next;
        }
        return i;
    }

    void DeleteItem(T item)
    {
        if(isEmpty())
        {
            cout << "Empty List\n";
        }
        else
        {
            DeleteAt(getPos(item));
        }
    }

    void Reverse()
    {
        if (isEmpty())
        {
            cout << "Empty List\n";
        }
        else if(Head->next==nullptr)
        {
            cout<<"";
        }
        else
        {
            Node* prev = nullptr;
            Node* current = Head;
            Node* next = current->next;
            while(next!=nullptr)
            {
                next=current->next;
                current->next=prev;
                prev = current;
                current=next;
            }
            Head = prev;
        }
    }

    void Print(){
        if (Head != nullptr){
            Node* current = Head;
            cout << "[ ";
            while(current != nullptr){
                cout << current->val << " ";
                current = current->next;
            }
            cout << "]" << endl;
        }else{
            cout << "Empty List\n";
        }
    }

    void clear()
    {
        if (Head != nullptr){
            Node* current = Head;
            Node* prev = current;
            while(current != nullptr){

                current = current->next;
                delete prev;
                prev = current;
            }
            delete current;
            Head = nullptr;
            Tail = nullptr;
        }else{
            cout << "Empty List\n";
        }
    }

    bool Search(T val)
    {
        if (!isEmpty())
        {
            Node* current = Head;
            while(current != nullptr)
            {
                if (current->val == val)
                {
                    return true;
                }
            }
        }
        return false;
    }

    void Swap(int indx1, int indx2)
    {
        if (!isEmpty() && max(indx1, indx2) < Size && !(indx1 == indx2))
        {
            if (indx2 < indx1)
            {
                swap(indx1, indx2);
            }
            int c =0;
            Node* temp2;
            Node* temp1;
            Node* current = Head;
            while(current != nullptr)
            {
                if (c = indx2)
                {
                    temp2 = current;
                    break;
                }
                c++;
            }

            current = Head;
            while(current != nullptr)
            {
                if (c = indx1)
                {
                    temp1 = current;
                    break;
                }
                c++;
            }

            DeleteAt(indx2);
            InsertAt(indx2, temp2->val);
            DeleteAt(indx1);
            InsertAt(indx1, temp1->val);
        }
        else
        {
            cout << "Invalid indexes\n";
        }
    }

};



template<class T>
class DoublyLinkedList //DONE
{
private:
    struct Node
    {
        T val;
        Node* next;
        Node* prev;
    };
    Node* Head;
    Node* Tail;
    int Size;
public:
    DoublyLinkedList()
    {
        Head = nullptr;
        Tail = nullptr;
        Size = 0;
    }

    bool isEmpty()
    {
        return Head == nullptr;
    }

    void pushBack(T val)
    {
        if(isEmpty())
        {
            Node* temp = new Node;
            temp->val = val;
            temp->next=nullptr;
            temp->prev=nullptr;
            Head = temp;
            Tail  = temp;
            temp = nullptr;
            delete temp;
            Size++;
        }
        else
        {
            Node* temp = new Node;
            temp->val = val;
            temp->next=nullptr;
            temp->prev=Tail;
            Tail->next = temp;
            Tail = temp;
            temp = nullptr;
            delete temp;
            Size++;
        }
    }

    void pushFront(T val)
    {
        if (isEmpty()){
            Node* temp = new Node;
            temp->val = val;
            temp->next = nullptr;
            temp->prev = nullptr;
            Head = temp;
            temp = nullptr;
            delete temp;
            Size++;
        }else{
            Node* temp = new Node;
            temp->val = val;
            temp->next = Head;
            temp->prev = nullptr;
            Head = temp;
            temp = nullptr;
            delete temp;
            Size++;
        }
    }

    void Update (int indx, int newVal)
    {
        if (indx >=0 && indx < Size && !isEmpty())
        {
            Node* current = Head;
            int c =0;
            while(current != nullptr)
            {
                if (c == indx)
                {
                    current->val = newVal;
                    break;
                }
                c++;
            }
        }
        else
        {
            cout << "Invalid Index!\n";
        }
    }

    T PopFront()
    {
        if (Head!=nullptr){
            T val = Head->val;
            Node* temp = new Node();
            temp = Head;
            Head = Head->next;
            Head->prev = nullptr;
            delete[] temp;
            temp = nullptr;
            Size--;
            return val;
        }else{
            cout << "Empty List\n";
        }
    }

    T popBack()
    {
        Node* current = Head;
        while(current->next!=Tail)
        {
            current = current->next;
        }
        T val = Tail->val;
        delete Tail;

        Tail = current;
        Tail->next=nullptr;
        current = nullptr;
        delete current;
        Size--;
        return val;
    }

    void InsertAt(int pos, T val)
    {
        if(isEmpty())
        {
            pushFront(val);
        }
        else
        {
            if (pos <= 0)
            {
                pushFront(val);
            }
            else if (pos >= Size-1)
            {
                pushBack(val);
            }
            else
            {
                Node* current = Head;
                for (int i=0 ; i < pos-1 ; i++ )
                {
                    current = current->next;
                }
                Node* newNode = new Node();
                newNode->val = val;
                newNode->next=current->next;
                current->next->prev=newNode;
                current->next=newNode;
                newNode->prev=current;
                newNode=nullptr;
                current=nullptr;
                delete newNode;
                delete current;
                Size++;
            }
        }
    }

    void DeleteAt(int pos)
    {
        if(isEmpty())
        {
            cout << "Empty List\n";
        }
        else
        {
            if (pos <= 0)
            {
                PopFront();
            }
            else if (pos >= Size-1)
            {
                popBack();
            }
            else
            {
                Node* current = Head;
                for (int i=0 ; i < pos-1 ; i++ )
                {
                    current = current->next;
                }
                Node* del = current->next;
                current->next=del->next;
                del->next->prev=current;
                del=nullptr;
                current=nullptr;
                delete del;
                delete current;
                Size--;
            }
        }
    }

    int getPos(T val)
    {
        Node* current = Head;
        int i = -1;
        while(current!= nullptr)
        {
            if (current->val == val)
            {
                i++;
                return i;
            }
            i++;
            current = current->next;
        }
        return i;
    }

    void DeleteItem(T item)
    {
        if(isEmpty())
        {
            cout << "Empty List\n";
        }
        else
        {
            DeleteAt(getPos(item));
        }
    }

    void Reverse()
    {
        if (isEmpty())
        {
            cout << "Empty List\n";
        }
        else if(Head->next==nullptr)
        {
            cout<<"";
        }
        else
        {
            Node* prev = nullptr;
            Node* current = Head;
            Node* next = current->next;
            while(next!=nullptr)
            {
                next=current->next;
                current->next=prev;
                prev = current;
                current=next;
            }
            Head = prev;
        }
    }

    void PrintForward(){
        if (Size > 0){
            Node* current = Head;
            cout << "[ ";
            while(current != nullptr){
                cout << current->val << " ";
                current = current->next;
            }
            cout << "]" << endl;
        }else{
            cout << "Empty List\n";
        }
    }

    void PrintBackword(){
        if (Size > 0){
            Node* current = Tail;
            cout << "[ ";
            while(current != nullptr){
                cout << current->val << " ";
                current = current->prev;
            }
            cout << "]" << endl;
        }else{
            cout << "Empty List\n";
        }
    }

    bool Search(T val)
    {
        if (!isEmpty())
        {
            Node* current = Head;
            while(current != nullptr)
            {
                if (current->val == val)
                {
                    return true;
                }
            }
        }
        return false;
    }

    void Swap(int indx1, int indx2)
    {
        if (!isEmpty() && max(indx1, indx2) < Size && !(indx1 == indx2))
        {
            if (indx2 < indx1)
            {
                swap(indx1, indx2);
            }
            int c =0;
            Node* temp2;
            Node* temp1;
            Node* current = Head;
            while(current != nullptr)
            {
                if (c = indx2)
                {
                    temp2 = current;
                    break;
                }
                c++;
            }

            current = Head;
            while(current != nullptr)
            {
                if (c = indx1)
                {
                    temp1 = current;
                    break;
                }
                c++;
            }

            DeleteAt(indx2);
            InsertAt(indx2, temp2->val);
            DeleteAt(indx1);
            InsertAt(indx1, temp1->val);
        }
        else
        {
            cout << "Invalid indexes\n";
        }
    }

    void clear()
    {
        if (Head != nullptr){
            Node* current = Head;
            Node* prev = current;
            while(current != nullptr){

                current = current->next;
                delete prev;
                prev = current;
            }
            delete current;
            Head = nullptr;
            Tail = nullptr;
        }else{
            cout << "Empty List\n";
        }
    }
};

template<class T>
class CircularLinkedList
{
    struct Node
    {
        T val;
        Node* next;
    };
    Node* Head;
    Node* Tail;
    int Size;
public:

    CircularLinkedList()
    {
        Head = nullptr;
        Tail = nullptr;
        Size = 0;
    }

    bool isEmpty()
    {
        return Head == nullptr;
    }

    void pushBack(T val)
    {
        if(isEmpty())
        {
            Node* temp = new Node;
            temp->val = val;
            temp->next=nullptr;
            Head = temp;
            Tail  = temp;
            temp = nullptr;
            delete temp;
            Size++;
        }
        else
        {
            Node* temp = new Node;
            temp->val = val;
            temp->next=Head;
            Tail->next =temp;
            Tail = temp;
            temp = nullptr;
            delete temp;
            Size++;
        }
    }

    void pushFront(T val){
        if (Size == 0)
        {
            Node* temp = new Node;
            temp->val = val;
            temp->next = nullptr;
            Head = temp;
            temp = nullptr;
            delete temp;
            Size++;
        }
        else
        {
            Node* temp = new Node;
            temp->val = val;
            temp->next = Head;
            Head = temp;
            Tail->next=Head;
            temp = nullptr;
            delete temp;
            Size++;
        }
    }

    void Update (int indx, int newVal)
    {
        if (indx >=0 && indx < Size && !isEmpty())
        {
            Node* current = Head;
            int c =0;
            while(current != nullptr)
            {
                if (c == indx)
                {
                    current->val = newVal;
                    break;
                }
                c++;
            }
        }
        else
        {
            cout << "Invalid Index!\n";
        }
    }

    T PopFront(){
        if (Head!=nullptr){
            T val = Head->val;
            Node* temp = new Node();
            temp = Head;
            Head = Head->next;
            Tail->next = Head;
            delete[] temp;
            temp = nullptr;
            Size--;
            return val;
        }else{
            cout << "Empty List\n";
        }
    }

    T popBack()
    {
        Node* current = Head;
        while(current->next!=Tail)
        {
            current = current->next;
        }
        Tail = current;
        current= current->next;
        T x = current->val;
        Tail->next=Head;
        delete current;
        Size--;
        return x;
    }

    void InsertAt(int pos, T val)
    {
        if(isEmpty())
        {
            pushFront(val);
        }
        else
        {
            if (pos <= 0)
            {
                pushFront(val);
            }
            else if (pos >= Size-1)
            {
                pushBack(val);
            }
            else
            {
                Node* current = Head;
                for (int i=0 ; i < pos-1 ; i++ )
                {
                    current = current->next;
                }
                Node* newNode = new Node();
                newNode->val = val;
                newNode->next=current->next;
                current->next=newNode;
                newNode=nullptr;
                current=nullptr;
                delete newNode;
                delete current;
                Size++;
            }
        }
    }

    void DeleteAt(int pos)
    {
        if(isEmpty())
        {
            cout << "Empty List\n";
        }
        else
        {
            if (pos <= 0)
            {
                PopFront();
            }
            else if (pos >= Size-1)
            {
                popBack();
            }
            else
            {
                Node* current = Head;
                for (int i=0 ; i < pos-1 ; i++ )
                {
                    current = current->next;
                }
                Node* del = current->next;
                current->next=del->next;
                del=nullptr;
                current=nullptr;
                delete del;
                delete current;
                Size--;
            }
        }
    }

    int getPos(T val)
    {
        Node* current = Head;
        int i = -1;
        while(current!= nullptr)
        {
            if (current->val == val)
            {
                i++;
                return i;
            }
            i++;
            current = current->next;
        }
        return i;
    }

    void DeleteItem(T item)
    {
        if(isEmpty())
        {
            cout << "Empty List\n";
        }
        else
        {
            DeleteAt(getPos(item));
        }
    }

    void Reverse()
    {
        if (isEmpty())
        {
            cout << "Empty List\n";
        }
        else if(Head->next==nullptr)
        {
            cout<<"";
        }
        else
        {
            Node* prev = nullptr;
            Node* current = Head;
            Node* next = current->next;
            while(next!=Head)
            {
                next=current->next;
                current->next=prev;
                prev = current;
                current=next;
            }
            Head = prev;
            while(current->next!=nullptr)
            {
                current = current->next;
            }
            Tail=current;
            Tail->next=Head;
        }
    }

    void Print(){
        if (Size > 1){
            Node* current = Head;
            cout << "[ ";
            while(current->next != Head){
                cout << current->val << " ";
                current = current->next;
            }
            cout << Tail->val <<" ]" << endl;
        }
        else if (Size == 1)
        {
            cout << "[ "<<Head->val<<" ]n";
        }
        else
        {
            cout << "Empty List\n";
        }
    }

    bool Search(T val)
    {
        if (!isEmpty())
        {
            Node* current = Head;
            while(current != Head)
            {
                if (current->val == val)
                {
                    return true;
                }
            }
        }
        return false;
    }


    void Swap(int indx1, int indx2)
    {
        if (!isEmpty() && max(indx1, indx2) < Size && !(indx1 == indx2))
        {
            if (indx2 < indx1)
            {
                swap(indx1, indx2);
            }
            int c =0;
            Node* temp2;
            Node* temp1;
            Node* current = Head;
            while(current->next != Head)
            {
                if (c = indx2)
                {
                    temp2 = current;
                    break;
                }
                c++;
            }

            current = Head;
            while(current->next != Head)
            {
                if (c = indx1)
                {
                    temp1 = current;
                    break;
                }
                c++;
            }

            DeleteAt(indx2);
            InsertAt(indx2, temp2->val);
            DeleteAt(indx1);
            InsertAt(indx1, temp1->val);
        }
        else
        {
            cout << "Invalid indexes\n";
        }
    }

    void clear()
    {
        if (Head != nullptr){
            Node* current = Head;
            Node* prev = current;
            while(current != Tail){

                current = current->next;
                delete prev;
                prev = current;
            }
            delete current;
            Head = nullptr;
            Tail = nullptr;
        }else{
            cout << "Empty List\n";
        }
    }

};


  //Stack & L Stack & Queue & L Queue

template<class T>
class Stack            //DONE
{
private:
    int Size;
    int Top;//the index of the last element added in the stack
    T* arr;

public:
    Stack(){
        Top = -1;
        Size = 10;
        arr = new T[Size];
    }

    Stack(int s){
        Top = -1;
        if (s >= 1){
            Size = s;
        }else{
            Size = 5;
        }
        arr = new T[Size];
    }

    bool isEmpty(){
        return Top == -1;
    }

    T getTop(){
        if (Top > -1)
            return arr[Top];
    }

    int getTopindx()
    {
        return Top;
    }

    int getSize ()
    {
        return Size;
    }

    T Pop(){
        if (Top != -1)
        {
            T temp = arr[Top];
            Top --;
            return temp;
        }else{
            cout << "Empty Stack" << endl;
        }
    }

    void Pop(T&Element){
        if (Top != -1){
            Element = arr[Top];
            Top --;
        }else{
            cout << "Empty Stack" << endl;
        }
    }

    void Push(T val){
        if (Top < Size-1){
            Top++;
            arr[Top] = val;
        }else{
            cout << "Stack Over Flow" << endl;
        }
    }

    void Print(){
        if (Top >= 0){
            cout << "[ ";
            for (int i=Top ; i >= 0 ; i-- ){
                cout << arr[i] << " ";
            }
            cout << "]" << endl;
        }else{
            cout << "Empty Stack" << endl;
        }
    }

    void clear()
    {
        Top = -1;
    }

    ~Stack()
    {
        delete[]arr;
    }
};

template<class T>
class StackLinkedList  //DONE
{
private:
    struct Node
    {
        T val;
        Node* next;
    };
    Node* Top;
    int Size;
public:
    StackLinkedList(){
        Top = nullptr;
        Size = 0;
    }

    bool isEmpty(){
        return Top == nullptr;
    }

    void Push(T val){
        if (Size == 0){
            Node* temp = new Node;
            temp->val = val;
            temp->next = nullptr;
            Top = temp;
            temp = nullptr;
            Size++;
        }else{
            Node* temp = new Node;
            temp->val = val;
            temp->next = Top;
            Top = temp;
            temp = nullptr;
            Size++;
        }
    }

    T Pop(){
        if (Size > 0){
            T val = Top->val;
            Node* temp = new Node();
            temp = Top;
            Top = Top->next;
            delete[] temp;
            temp = nullptr;
            Size--;
            return val;
        }else{
            cout << "Empty Stack\n";
        }
    }

    T getTop(){
        if (Size > 0){
            return Top->val;
        }else{
            cout << "Empty Stack\n";
        }
    }

    void Print(){
        if (Size > 0){
            Node* current = Top;
            cout << "[ ";
            while(current != nullptr){
                cout << current->val << " ";
                current = current->next;
            }
            cout << "]" << endl;
        }else{
            cout << "Empty Stack\n";
        }
    }
};

template<class T>
class Queue            //DONE
{
private:
    int Front;
    int Rear;
    int length;
    int Size;
    T* arr;
public:
    Queue(){
        length=0;
        Front = -1;
        Rear = -1;
        Size = 5;
        arr = new T[Size];
    }

    bool isEmpty(){
        return length == 0;
    }

    bool isFull(){
        return length == Size;
    }

    T first ()
    {
        if (length != 0)
            return arr[Front];
    }

    void Enqueue(T val){
        if (isFull())
        {
            cout << "Full Stack\n";
        }
        else{
            if (Rear < Size-1){
                if (Front > -1){
                    Rear++;
                    arr[Rear] = val;
                }
                else{
                    Front = 0;
                    Rear = 0;
                    arr[Rear] = val;
                }
                length++;
            }
            else {
                if (Front > 0){
                    Rear = (Rear+1)%Size;
                    arr[Rear] = val;
                    length++;
                }
            }
        }
    }

    T Dequeue(){
        if (isEmpty()){
            cout << "Empty Queue\n";
        }
        else if (Rear == Front){
            T val = arr[Front];
            Rear = -1;
            Front = -1;
            length--;
            return val;
        }
        else{
            T val = arr[Front];
            Front = (Front+1)%Size ;
            length--;
            return val;
        }
    }

    void Print(){
        if (Rear == -1){
            cout << "Empty Queue\n";
        }
        else{
            if (Front == Rear){
                cout << "[ " << arr[Front] << " ]" << endl;
            }
            else{
                cout << "[ ";
                for (int i = Front ; i!=Rear ; i=(i+1)%Size){

                    cout << arr[i] << " ";
                }
                cout << arr[Rear] <<" ]\n";
            }
        }
    }

    void Printw(){
        if (!isEmpty()){
            int i = length;
            int indx = Front;
            cout << "[ ";
            while(i--){
                cout << arr[indx] << " ";
                indx = (indx+1)%Size;
            }
            cout << "]" << endl;
        }
        else{
            cout << "Empty Stack\n";
        }
    }

    int getSize(){
        return Size;
    }

    int getLength(){
        return length;
    }

    void Clear(){
        delete[]arr;
        Front=-1;
        Rear=-1;
        length=0;
        arr = new T[Size];
    }

    ~Queue()
    {
        delete[]arr;
    }
};

template<class T>
class QueueLinkedList  //DONE
{
    struct Node
    {
        T val;
        Node* next;
    };
    Node* Front;
    Node* Rear;
    int length;
public:
    QueueLinkedList()
    {
        Front = nullptr;
        Rear  = nullptr;
        length = 0;
    }

    bool isEmpty()
    {
        return Front == nullptr;
    }

    void Enqueue(T val)
    {
        if(isEmpty())
        {
            Node* temp = new Node;
            temp->val = val;
            temp->next=nullptr;
            Front = temp;
            Rear  = temp;
            temp = nullptr;
            delete temp;
            length++;
        }
        else
        {
            Node* temp = new Node;
            temp->val = val;
            temp->next=nullptr;
            Rear->next = temp;
            Rear = temp;
            temp = nullptr;
            delete temp;
            length++;
        }
    }

    T Dequeue()
    {
        if(isEmpty())
        {
            cout << "Empty Queue\n";
        }
        else if (length == 1)
        {
            delete Front;
            Front = nullptr;
            Rear  = nullptr;
            length--;
        }
        else
        {
            Node* temp = Front->next;
            delete Front;
            Front = temp;
            temp = nullptr;
            delete temp;
            length--;
        }
    }

    void Print()
    {
        if(isEmpty())
        {
            cout << "Empty queue\n";
        }
        else
        {
            cout << "[ ";
            Node* current =  Front;
            while(current!=nullptr)
            {
                cout << current->val << " ";
                current = current->next;
            }
            cout << "]\n";
        }
    }

    void Clear()
    {
        if(isEmpty())
        {
            cout << "Already Empty Queue\n";
        }
        else
        {
            Node* current = Front->next;
            while(current!=nullptr)
            {
                delete Front;
                Front = current;
                current = current->next;
            }
            delete Rear;
            Front = nullptr;
            Rear = nullptr;
            length = 0;
            delete current;
        }
    }
};





template <typename T>
class StackQueue
{
private:
    Queue<T> q1;
    Queue<T> q2;
    T top_element;
    T popped_element;

public:
    void push(T element)
    {
        q1.Enqueue(element);
    }

    T pop()
    {
        if (isEmpty())
        {
            cout<<"Stack is empty!"<<endl;
            return 0;
        }

        while (q1.getLength() > 1)
        {
            q2.Enqueue(q1.Dequeue());
        }
         popped_element = q1.Dequeue();
        swap(q1, q2);
        return popped_element;
    }

    T top()
    {
        if (isEmpty())
        {
            //throw runtime_error("Stack is empty!");
            cout<<"Stack is empty!"<<endl;
            return 0;
        }

        while (q1.getLength() > 1)
        {
            q2.Enqueue(q1.Dequeue());
        }
         top_element = q1.first();
        q2.Enqueue(q1.Dequeue());
        swap(q1, q2);
        return top_element;
    }

    bool isEmpty()
    {
        return q1.isEmpty();
    }

    int stackSize()
    {
        return q1.getLength();
    }

    void clear()
    {
        q1.Clear();
        q2.Clear();
    }

    // void print()
    // {
    //     if (isEmpty())
    //     {
    //         cout << "Stack is empty!" << endl;
    //         return ;
    //     }

    //     else
    //     {
    //         Queue<T> temp = q1;
    //         while (!temp.isEmpty())
    //         {
    //             cout << temp.dequeue() << " ";
    //         }
    //         cout << endl;
    //     }
    // }

//     void print()
//     {
//     if (isEmpty())
//     {
//         cout << "Stack is empty!" << endl;
//         return;
//     }

//     Node* temp = head;
//     while (temp != nullptr)
//     {
//         cout << temp->data << " ";
//         temp = temp->next;
//     }
//     cout << endl;
//    }

    void print()
    {
        if (isEmpty())
        {
            cout << "Stack is empty!" << endl;
            return;
        }

        Queue<T> temp = q1;
        vector<T> elements;

        while (!temp.isEmpty())
        {
            elements.push_back(temp.Dequeue());
        }

        for (int i = elements.size() - 1; i >= 0; i--)
        {
            cout << elements[i] << " ";
        }

        cout << endl;
    }


};


int main()
{

    /*StackLinkedList<int> s;
    s.Push(3);
    s.Push(6);
    s.Push(5);
    s.Push(8);
    s.Push(9);
    s.Print();
    cout << s.isEmpty() << endl;
    cout << "Popped element :" <<s.Pop() << endl;
    s.Print();*/

    /*Queue<int> q;
    q.Print();
    q.Enqueue(4);
    q.Printw();
    q.Enqueue(6);
    q.Enqueue(7);
    q.Enqueue(3);
    q.Enqueue(5);
    q.Printw();
    q.Dequeue();
    q.Dequeue();
    q.Printw();
    q.Enqueue(55);
    q.Enqueue(66);

    q.Enqueue(637);
    q.Enqueue(93);
    q.Printw();
    q.Clear();
    q.Printw();
    */

    /*QueueLinkedList<int> q;
    q.Print();
    q.Enqueue(4);
    q.Print();
    q.Enqueue(6);
    q.Enqueue(7);
    q.Enqueue(3);
    q.Enqueue(5);
    q.Print();
    q.Dequeue();
    q.Dequeue();
    q.Print();
    q.Enqueue(55);
    q.Enqueue(66);

    q.Enqueue(637);
    q.Enqueue(93);
    q.Print();
    q.Clear();
    q.Print();*/

    /*int arr[5]= {4,6,2,1,3};
    print(arr,5);*/

    /*ArrayList<int> a(10);
    a.insertAt(3,0);
    a.insertAt(5,1);
    a.insertAt(6,2);
    a.insertAt(4,1);
    a.Print();
    a.insertAt(7,1);
    a.Print();
    a.removeAt(1);
    a.Print();
    cout << "The index of 5 is :" << a.Search(5) << endl;
    a.UpdateAt(2,0);
    a.Print();*/

    /*LinkedList<int> l;
    l.pushBack(0);
    l.pushBack(1);
    l.pushBack(0);
    l.pushBack(3);
    l.pushBack(0);
    l.pushBack(2);
    l.pushBack(2);
    l.pushBack(0);
    l.Print();*/




    //l.popBack();
    //l.pushBack(5);
    //l.pushBack(6);
    //l.Print();
    //l.PopFront();
    //l.Print();
    //l.popBack();
    //l.Print();
    //l.Reverse();
    //cout << "After reversing : ";
    //l.Print();

    /*
    LinkedList<int> l;
    l.pushBack(0);
    l.pushBack(1);
    l.pushBack(0);
    l.pushBack(3);
    l.pushBack(0);
    l.pushBack(2);
    l.pushBack(2);
    l.pushBack(0);
    l.Print();

    /*
    cout << "Testing Stack using Queue:" << endl;
    StackQueue<int> StackQueue;
    StackQueue.push(10);
    StackQueue.push(20);
    StackQueue.push(30);
    StackQueue.push(40);
    StackQueue.push(50);
    //stack.print();
    cout << "Top element: " << StackQueue.top() << endl;
    cout << "Popped element: " << StackQueue.pop() << endl;
    StackQueue.print();
    cout << endl;


    Queue<int> q;
    q.Enqueue(5);
    q.Enqueue(3);
    q.Enqueue(7);
    q.Enqueue(1);
    q.Enqueue(9);
    q.Enqueue(2);


}




#include <iostream>
#include<bits/stdc++.h>
using namespace std::chrono;

using namespace std;

 class Element{
 private:
int value;
int priority;
 public:
     Element(int val,int pr)
     {
         this->priority=pr;
         this->value=val;
     }
    bool operator<(const Element& other) const {
    return priority < other.priority;
    }
     bool operator>(const Element& other) const {
    return priority > other.priority;
    }
     bool operator==(const Element& other) const {
    return priority == other.priority;
    }
    void afficher()
    {
        cout<<"Value : "<<value<<" --> Priority :  "<<priority<<endl;
    }

};

template <class T>
class PriorityQueu{
private:
     set<T> pq;

public:
    PriorityQueu()=default;

        //this->pq=new set<Element<T>>;

    void inserer(T elem)
    {
        this->pq.insert(elem);
    }
    void afficherPQ()
    {
        for(Element x:pq)
            x.afficher();
    }
};

void test_priorityQueu_personnalise()
{

PriorityQueu<Element> p;
    auto start = high_resolution_clock::now();
    for(int i=1;i<=5000000;i++)
    p.inserer({i,i});

    /** si vous voulez afficher  **/
    //p.afficherPQ();

    auto stop = high_resolution_clock::now();
auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken by function: "<< duration.count()<<" microseconds"<<endl;
}

void fonction_PQparDefaut()
{
    priority_queue<int> p;
    auto start = high_resolution_clock::now();
    for(int i=1;i<=5000000;i++)
    p.push(i);

    /** si vous voulez afficher  **/
    //p.afficherPQ();

    auto stop = high_resolution_clock::now();
auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken by function: "<< duration.count()<<" microseconds"<<endl;
}



int main()
{
    cout<<"Comparaison entre notre priority queue et priority queue par defaut  \n\n "
    test_priorityQueu_personnalise();

    cout<<"*************-----------------------------------**********************\n";
    fonction_PQparDefaut();
    return 0;
}

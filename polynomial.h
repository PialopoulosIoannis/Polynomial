#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include <iostream>  
using namespace std;  
#include <cmath>  
/* 
void merge (int a[], int first, 
 int mid, int last) { 
    int b[last-first+1]; 
    int i = first, j = mid+1, k = 0; 
    while (i <= mid && j <= last) 
        if (a[i] < a[j]) b[k++] = a[i++]; 
        else b[k++] = a[j++]; 
    while (i <= mid) b[k++] = a[i++]; 
    while (j <= last) b[k++] = a[j++]; 
    for(i=0; i<k; i++) a[first+i] = b[i]; 
} 
 
void mergesort (int a[], int first, 
 int last) { 
    int mid; 
    if (first >= last) return; 
    mid = (first + last) / 2; 
    mergesort(a, first, mid); 
    mergesort(a, mid+1, last); 
    merge(a, first, mid, last); 
} 
 
*/  
  
class Polynomial {  
public:                           
    class Term {  
    public:  
        int exponent;  
        int coefficient;  
        Term *next;  
        Term(int exp=0, int coeff=0, Term *n=nullptr) { exponent=exp; coefficient=coeff;  
            next=n;} // = for default constructor  
        friend class Polynomial;              
    };  
public:  
    Polynomial() { head=rear=nullptr; }  
    Polynomial(const Polynomial &p) {  
        if (p.head == nullptr) return;  
  
        head=rear=nullptr;  
        Term *myp=p.head;  
        while (myp!=nullptr) {  
            this->addTerm(myp->exponent, myp->coefficient);  
            myp=myp->next;  
        }  
  
    }  
    ~Polynomial() {  
  
        Term *myp; myp=head;  
        while (myp!=nullptr) { Term* myd=myp; myp=myp->next; delete myd;}  
        head=rear=nullptr;  
    }  
  
    Polynomial &operator=(const Polynomial &p)  {  
        Term *myp = head;  
        while (myp!=nullptr) {  
            Term* myd=myp;  
            myp=myp->next;  
            delete myd;  
        }  
        head=rear=nullptr;  
        myp=p.head;  
        while (myp!=nullptr) {  
            this->addTerm(myp->exponent, myp->coefficient);  
            myp=myp->next;  
        }  
        return *this;  
    }  
  
    void addTerm(int expon,int coeff) {  
        Term *myp= new Term(expon, coeff);  
        Term *myq=head;  
        bool flag=false;  
        while (myq!=nullptr && flag==false)  
        {  
            if (myq->exponent==expon) { myq->coefficient+=coeff; flag=true;}  
            myq=myq->next;  
        }  
        if (head==nullptr) { head=rear=myp; rear->next=nullptr;}  
        else if (flag==false) {  
            myq=head;  
            int j=0;  
            if (myq->exponent<expon) {  
                myp->next=head;  
                head=myp;  
            }  
            else{  
                while ( myq!=nullptr && myq->exponent>expon ) {  
                    myq=myq->next; j++;  
                }  
                Term *myf=head;  
                for (int i=0; i<j-1; i++) myf=myf->next;  
                myf->next=myp;  
                myp->next=myq;  
            }  
        }  
    }  
  
  
  
    double evaluate(double x) {  
        Term *myp=head;  
        double result=0;  
        while (myp!=nullptr) {  
            result=result + pow(x,myp->exponent)*myp->coefficient;  
            myp=myp->next;  
        }  
        return result;  
    }  
  
    friend Polynomial operator+ (const Polynomial &p, const Polynomial &q) {  
     Polynomial n(p); Term *myq=q.head; Term *myn=n.head;  
        while (myq!=nullptr) {  
            n.addTerm(myq->exponent,myq->coefficient); myq=myq->next;  
        }  
        return n;  
    }  
    friend Polynomial operator* (const Polynomial &p, const Polynomial &q) {  
        Term *myp=p.head;  
        Term *myq=q.head;  
        Polynomial ans;  
        while (myp!=nullptr) {  
            while (myq!=nullptr) {  
                ans.addTerm(myp->exponent+myq->exponent, myp->coefficient*myq->coefficient);  
                myq=myq->next;  
            }  
            myp=myp->next;  
            myq=q.head;  
        }  
        return ans;  
    }  
  
    friend ostream & operator << (ostream &out, const Polynomial &p) {  
      Term *myp=p.head; bool f=true;  
        while (myp!=nullptr && myp->coefficient==0 && myp->exponent>0) myp=myp->next;  
        if (myp==nullptr) {out<<"0"; return out;}  
        if (myp->exponent==0 && myp->coefficient==0) {out<<"0"; return out;}  
if (myp->exponent!=0) {  
  
    if (myp->coefficient<0) {  
        out<<"- "; f=false;  
        if (myp->coefficient!=-1) out<<abs(myp->coefficient)<<"x"; else out<<"x";  
        if (myp->exponent!=1) out<<"^"<<myp->exponent;  
        if (myp->next!=nullptr && myp->next->exponent==0 && myp->next->coefficient==0)  return out;  
        myp=myp->next;  
    }  
    else if (myp->coefficient>0) { f=false;  
        if (myp->coefficient!=1) out<<abs(myp->coefficient)<<"x"; else out<<"x";  
        if (myp->exponent!=1) out<<"^"<<myp->exponent;  
        if (myp->next!=nullptr && myp->next->exponent==0 && myp->next->coefficient==0)  return out;  
        myp=myp->next;  
    }  
    else if (myp->coefficient==0) {myp=myp->next;}  
  
}  
  
          while (myp!=nullptr && myp->exponent!=0 ) {  
              if (myp->coefficient<0 ) {out<<" - ";  
                  if (myp->coefficient!=-1) out<<abs(myp->coefficient)<<"x"; else out<<"x";  
                  if (myp->exponent!=1) out<<"^"<<myp->exponent;  
                  if (myp->next!=nullptr && myp->next->exponent==0 && myp->next->coefficient==0)  return out;  
              }  
              else if (myp->coefficient>0) {out<<" + ";  
                  if (myp->coefficient!=1) out<<abs(myp->coefficient)<<"x"; else out<<"x";  
                  if (myp->exponent!=1) out<<"^"<<myp->exponent;  
                  if (myp->next!=nullptr && myp->next->exponent==0 && myp->next->coefficient==0)  return out;  
              }  
              myp=myp->next;  
          }  
  
if (myp!=nullptr && f==false ) {  
    if (myp->coefficient>0) out<<" + "<<myp->coefficient;  
    else if (myp->coefficient<0) out<<" - "<<abs(myp->coefficient);  
    else if (myp->coefficient==0) return out;  
}  
        if (myp!=nullptr && f==true ) {  
            if (myp->coefficient>0) out<<myp->coefficient;  
            else out<<"- "<<abs(myp->coefficient);  
        }  
        return out;  
        }  
  
private:  
    Term *head;  
    Term *rear;  
  
};  
#endif
/* 
int main() { 
    Polynomial p;// 0 
    p.addTerm(1, 3); // 3x 
 
    p.addTerm(2, 1); // x^2 
    p.addTerm(0, -1); // -1 
 
    Polynomial q(p); // x^2 + 3x - 1 
    q.addTerm(1, -3); // -3x 
 
    cout << "P(x) = " << p << endl; 
    cout << "P(1) = " << p.evaluate(1) << endl; 
    cout << "Q(x) = " << q << endl; 
   cout << "Q(1) = " << q.evaluate(1) << endl; 
cout << "(P+Q)(x) = " << p+q << endl; 
    cout << "(P*Q)(x) = " << p*q << endl; 
} 
*/  

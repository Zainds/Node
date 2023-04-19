

#include <iostream>
#include <vector>
using namespace std;

                    
struct Node {
    double val;
    Node* next;

    Node(double _val) : val(_val), next(nullptr) {}

};

struct list {
    Node* first;
    Node* last;

    list() : first(nullptr), last(nullptr) {}

    bool is_empty() {
        return first == nullptr;
    }

    void push_back(double _val) {
        Node* p = new Node(_val);
        if (is_empty()) {
            first = p;
            last = p;
            return;
        }
        last->next = p;
        last = p;
    }
    int size() {
        int i = 0;
        if (is_empty()) return i;
        Node* p = first;
        while (p) {
            p = p->next;
            i++;
        }
        return i;
    }
    double back() {
        if (is_empty()) return 0;
        Node* p = first;
        while (p->next != last) p = p->next;
        return last->val;
        
    }

    void print() {
        if (is_empty()) return;
        Node* p = first;
        while (p) {
            cout << p->val << " ";
            p = p->next;
        }
        cout << endl;
    }
    Node* operator[] (const int index) {
        if (is_empty()) return nullptr;
        Node* p = first;
        for (int i = 0; i < index; i++) {
            p = p->next;
            if (!p) return nullptr;
        }
        return p;
    }
    double getAt (const int index) {
        if (is_empty()) return 0;
        Node* p = first;
        for (int i = 0; i < index; i++) {
            p = p->next;
            if (!p) return 0;
        }
        return p->val;
    }
    
};
                    /// Коэффициенты многочлена делимого - dividend, индекс в массиве - степень элемента многочлена
                    /// Коэффициенты многочлена делителя - divisor, индекс в массиве - степень элемента многочлена
                    /// Коэффициенты многочлена частного - quotient, индекс в массиве - степень элемента многочлена
                    /// Коэффициенты многочлена остатка - remainder, индекс в массиве - степень элемента многочлена
void DividePolynom(vector<double> dividend, vector<double> divisor, vector<double>& quotient, vector<double>& remainder)
{
    if (dividend.back() == 0)
    {
        throw new exception("Старший член многочлена делимого не может быть 0");
    }
    if (divisor.back() == 0)
    {
        throw new exception("Старший член многочлена делителя не может быть 0");
    }
    remainder = dividend;
    
	quotient.resize(remainder.size() - divisor.size() + 1);
	
	for (int i = 0; i < quotient.size(); i++)
	{
		double coeff = remainder[remainder.size() - i - 1] / divisor.back();
		quotient[quotient.size() - i - 1] = coeff;
		for (int j = 0; j < divisor.size(); j++)
		{
			remainder[remainder.size() - i - j - 1] -= coeff * divisor[divisor.size() - j - 1];
		}
	}
}

int main()
{   
    setlocale(LC_ALL, "");
    cout << "Hello World!\n";
    // 2*x^2+4*x+3
    vector<double> dividend = { -42, 0, -12, 1 };
    // 2*x+1
    vector<double> divisor = { -3, 1 };
    vector<double> quotient;
    vector<double> remainder;

    DividePolynom(dividend, divisor, quotient, remainder);
   
    cout<<"Частное:"<<endl;
    for (int i = 0; i < quotient.size(); i++)
    {
        if (quotient[quotient.size() - i - 1] != 0)
        {
            cout<<quotient[quotient.size() - i - 1] <<endl;
            
        }
    }
    cout << endl;
    cout << "Остаток:";
    for (int i = 0; i < remainder.size(); i++)
    {
        if (remainder[remainder.size() - i - 1] != 0)
        {
            cout<<remainder[remainder.size() - i - 1]<<endl;
        }
    }
    list l;
    for (double x : dividend) {
        l.push_back(x);
    }
    l.print();
    cout << l[1]->val;
    
}



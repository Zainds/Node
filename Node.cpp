

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
    void pop_back(double _val)
    {
        Node* p = new Node(_val);
        if (is_empty()) {
            first = p;
            last = p;
            return;
        }
        p->next = first;
        first = p;
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
    void deleteFirst() {
        if (first == NULL) return;

        if (first == last) {
            delete last;
            first = last = NULL;
            return;
        }

        Node* node = first;
        first = node->next;
        delete node;
    }
    void erase(int k) {
        if (k < 0) return;
        if (k == 0) {
            deleteFirst();
            return;
        }

        Node* left = getNodeAt(k - 1);
        Node* node = left->next;
        if (node == NULL) return;

        Node* right = node->next;
        left->next = right;
        if (node == last) last = left;
        delete node;
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
    Node* getNodeAt(const int index) {
        if (is_empty()) return 0;
        Node* p = first;
        for (int i = 0; i < index; i++) {
            p = p->next;
            if (!p) return 0;
        }
        return p;
    }
    
};
                    /// Коэффициенты многочлена делимого - dividend, индекс в массиве - степень элемента многочлена
                    /// Коэффициенты многочлена делителя - divisor, индекс в массиве - степень элемента многочлена
                    /// Коэффициенты многочлена частного - quotient, индекс в массиве - степень элемента многочлена
                    /// Коэффициенты многочлена остатка - remainder, индекс в массиве - степень элемента многочлена
void DividePolynom(list dividend, list divisor, list& quotient, list& remainder)
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
    int k = remainder.size() - divisor.size() + 1;
	//quotient.resize(remainder.size() - divisor.size() + 1);
    
	
	for (int i = 0; i < k; i++)
	{
        if (quotient[k - i - 1] != nullptr) {
			cout << quotient[k - i - 1]->val << endl;
			double coeff = remainder.getAt(remainder.size() - i - 1) / divisor.back();
			quotient[k - i - 1]->val = coeff;
			for (int j = 0; j < divisor.size(); j++)
			{
				remainder[remainder.size() - i - j - 1]->val -= coeff * divisor[divisor.size() - j - 1]->val;
			}
        }
        
	}
}

int main()
{   
    setlocale(LC_ALL, "");
    cout << "Hello World!\n";
    // 2*x^2+4*x+3
    vector<double> dividend1 = { -42, 0, -12, 1 };
    // 2*x+1
    vector<double> divisor1 = { -3, 1 };
    vector<double> quotient1;
    vector<double> remainder1;
    list dividend, divisor, quotient, remainder;
    dividend.push_back(-42); dividend.push_back(0); dividend.push_back(-12); dividend.push_back(1);
    divisor.push_back(-3); divisor.push_back(1);
    

    DividePolynom(dividend, divisor, quotient, remainder);
   
    cout<<"Частное:"<<endl;
    for (int i = 0; i < quotient.size(); i++)
    {
        if (quotient.getAt(quotient.size() - i - 1) != 0)
        {
            cout<<quotient.getAt(quotient.size() - i - 1) <<endl;
            
        }
    }
    cout << endl;
    cout << "Остаток:";
    for (int i = 0; i < remainder.size(); i++)
    {
        if (remainder.getAt(remainder.size() - i - 1) != 0)
        {
            cout<<remainder.getAt(remainder.size() - i - 1)<<endl;
        }
    }
    
    dividend.erase(2);
    dividend.print();
}



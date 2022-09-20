#include <bits/stdc++.h>
#include "MYSTACK.h"
using namespace std;

int globalID = 100;

class person
{
    string name;
    int id;
    float salary;

public:
    person()
    {
        name = "";
        id = -1;
        salary = -1.0;
    }

    void setName(string name)
    {
        this->name = name;
    }

    void setSalary(float salary)
    {
        this->salary = salary;
    }

    person(string name, float salary)
    {
        setName(name);
        setSalary(salary);
        id = globalID;
        globalID++;
    }

    getID()
    {
        return id;
    }

    string getName()
    {
        return name;
    }

    float getSalary()
    {
        return salary;
    }

    void print()
    {
        cout << name << " | " << id << " | " << salary << endl;
    }
};

int main()
{
    // Stack<pair<int, char>> st;

    // st.push(make_pair(1, 'a'));
    // st.push(make_pair(2, 'b'));
    // st.push(make_pair(3, 'c'));
    // st.push(make_pair(4, 'd'));

    // while (!st.empty())
    // {
    //     pair<int, char> chk;
    //     chk = st.pop();
    //     cout << chk.first << " | " << chk.second << endl;
    //     // st.print();
    // }
    // cout << st.size() << endl;
    // if (!st.empty())
    // {
    //     pair<int, char> chk;
    //     chk = st.Top();
    //     cout << chk.first << " | " << chk.second << endl;
    // }

    Stack<person> st;
    person a("Shihab Al Ratul", 1000);
    person b("abcd ", 450.4);
    person c("efgh", 1200.60);
    st.push(a);
    st.push(b);
    st.push(c);

    // while (!st.empty())
    // {
    person printObj;
    printObj = st.Top();
    printObj.print();
    cout << st.size();
    // }
    return 0;
}
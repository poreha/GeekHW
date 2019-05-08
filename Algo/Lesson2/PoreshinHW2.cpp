/*
    1. Реализовать функцию перевода из 10 системы в двоичную используя рекурсию.
    2. Реализовать функцию возведения числа a в степень b:
        a. без рекурсии;
        b. рекурсивно;
        c. *рекурсивно, используя свойство чётности степени.
    3. Исполнитель Калькулятор преобразует целое число, записанное на экране. 
    У исполнителя две команды, каждой команде присвоен номер:
        1.Прибавь 1
        2.Умножь на 2 
    Первая команда увеличивает число на экране на 1, вторая увеличивает это число в 2 раза. 
    Сколько существует программ, которые число 3 преобразуют в число 20? 
        а) с использованием массива; 
        б) с использованием рекурсии.

*/

# include <iostream>
# include <string>
# include <algorithm>


using namespace std;

float myPower(float x, int n)
{
    if (n < 0)
        switch(n){
        case 1: return x;
        default: return myPower(x, n+1) / x;
        }
    
    else 
    switch(n){
        case 0: return 1;
        case 1: return x;
        default: return x * myPower(x, n-1);
        }
    
}


int myCalc(int x){
    int flag;
    cout << "\nInput command\n1)+1\t2)*2: ";
    cin >> flag;
    switch(flag){
        case 1: x++; cout << x <<"\t"; return myCalc(x);
        case 2: x*=2; cout << x <<"\t"; return myCalc(x);
        default: cout << "\nGoodbye!\n"; break;
    }

}

void toBin(long x, string &strbin)
{
    
    if(x%2 == 0)
        strbin += "0";
    else strbin += "1";
    if(x/2 != 0){
        toBin(x / 2, strbin); 
    }
    else return;

    
}



int main(int argc, char** args)
{
    long dec;
    int com, pw;
    float val;
    string sbin;
// Task 1
cout << "Input value: ";
cin >> val;
cout << "Input power: ";
cin >> pw;
cout << myPower(val,pw) << endl;
// Task 2
cout << "Enter decimal(>0):";
cin >> dec;
toBin(dec, sbin);
reverse(sbin.begin(), sbin.end());
cout << sbin << endl;
// Task 3
cout << "\nInput number to operate with: ";
cin >> com;
myCalc(com);

}
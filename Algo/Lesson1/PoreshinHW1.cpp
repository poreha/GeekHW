/*
11. С клавиатуры вводятся числа, пока не будет введён 0. 
        Подсчитать среднее арифметическое всех положительных чётных чисел, 
        оканчивающихся на 8.

12. Написать функцию нахождения максимального из трёх чисел.

13. * Написать функцию, генерирующую случайное число от 1 до 100: 
a. С использованием стандартной функции rand().
b. Без использования стандартной функции rand().

14. *Автоморфные числа. Натуральное число называется автоморфным, 
        если оно равно последним цифрам своего квадрата. 
        Например, 25 \ :sup: '2' = 625. Напишите программу, 
        которая получает на вход натуральное число N и 
        выводит на экран все автоморфные числа, не превосходящие N.
*/


# include <iostream>
# include <ctime>

# define ARR_SIZE 100

using namespace std;

int Avg8(){

    int nstr[ARR_SIZE]; //change it to a string
    int i = 0, eq = 0, count = 0;
cout << "Input numbers (\"0\" to stop)\n";
while(1){
    cin >> nstr[i];
    if(nstr[i] == 0) 
        break;
    else
        i++;
}

for (int j = 0; j < i; j++)
{
    if(nstr[j] > 0){
        if(nstr[j] % 10 == 8){
            eq = eq + nstr[j];
            count ++;
        }   else continue;
    }   else continue;
}

if(count) {
    cout << "Average is: " << eq / count << endl;
    return eq / count;
}
else {
    cout << "There were 0 positive numbers, ending with \"8\"\n";
    return 0;
}

};

int MaxOfThree(int a, int b, int c){
    int max = a;
if(b > max) max = b;
if(c > max) max = c;
//могу написать с потерей значений и без буфферной переменной
//но не считаю нужным
return max;
};

void Rrand(int mod, int max){
int x, a, b;
    //m = 1000; // Вершина последовательности
    //b = time(NULL);
    a = 117;
    x = 1;

    for (int i = 0; i < mod; i++)
    {
        b = time(NULL)%10;
        x = (a * x + b) % max;
        cout << x << " ";
    }
    cout << endl;

}


int main(int argc, char** args)
{
    int a, b, c, amount, top;
cout << "\tTask #11:" << endl;
  //  Avg8();

cout << "\tTask #12:" << endl;
cout << "Input three nums:" << endl;
//cin >> a >> b >> c;
 //  cout << "The highest value is: " << MaxOfThree(a,b,c) << endl;

cout << "\tTask #13:" << endl;
cout << "Input amount of numbers: ";
cin >> amount;
cout << "and the top value: ";
cin >> top;
Rrand(amount, top);

    return 0;
}
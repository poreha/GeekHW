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
# include <math.h>

# define ARR_SIZE 100

using namespace std;

// Task 11
int Avg8(){

    int nstr[ARR_SIZE];
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

//Task 12
int MaxOfThree(int a, int b, int c){
    int max = a;
if(b > max) max = b;
if(c > max) max = c;
//могу написать с потерей значений и без буфферной переменной
//но не считаю нужным
return max;
};

//Task 13a
void Rrand(int max){
int x, a, b;
    a = 117;
    x = 1;
    b = time(NULL)%10;    
        x = (a * x + b) % max;
        cout << x << endl;
}

//Task 13b
int Rng(int range, int min){
    srand(time(NULL));
    return (rand() % range + min);
}

//Task 14
void Automorph(int orig){
    int origAr[ARR_SIZE], sqorigAr[ARR_SIZE];
    int sqorig = pow(orig, 2);
    int i, power = 1, flag = 0;
    int buff = orig, sqbuff = sqorig;
    for(i = 0; buff > 0; i++, buff /= 10)
    {
        origAr[i] = buff % 10;
        sqorigAr[i] = sqbuff % 10;
        power *= 10; 
        sqbuff /= 10; 
        if(origAr[i] != sqorigAr[i]){
            cout << orig <<" is Not Automorpic" << endl;
            flag++;
            break;
        }
    }
if(flag == 0){
    for (int j = 0; j < sqorig; j++)
        if((j % power) == orig) cout << j << " ";
}
    cout << "\nSquare: " << sqorig << endl;
}

int main(int argc, char** args)
{
    int a, b, c, top, range, min, morph;

cout << "\tTask #11(8-checking):" << endl;
    Avg8();

cout << "\tTask #12(Max of three):" << endl;
cout << "Input three nums:" << endl;
cin >> a >> b >> c;
   cout << "The highest value is: " << MaxOfThree(a,b,c) << endl;

cout << "\tTask #13a(my randomizer from 0):" << endl;
cout << "Input the top value: ";
cin >> top;
Rrand(top);

cout << "\tTask #13b(Built-in rand()):" << endl;
cout << "Input the lowest value: ";
cin >> min;
cout << "and range: ";
cin >> range;
cout << "RNG: " << Rng(range, min) << endl;


cout << "\tTask #14(Automorphism):" << endl;
cout << "Input num to check automorphism: ";
cin >> morph;
Automorph(morph);
    return 0;
}

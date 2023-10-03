//============================================================================
// Name        : ExercVector.cpp
// Author      : Gustavo Rothstein
// Copyright   : No copyrights
//============================================================================
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int input, i=1;
    char letra = 0;

    vector<int> numbers;
    vector<int>::iterator vi;
    vector<int>::reverse_iterator rvi;

    cout << "Insira quantos numeros inteiros desejar;" << endl;
    cout << "Para corrigir o ultimo numero, insira a letra C;" << endl;
    cout << "Para finalizar, insira a letra S." << endl << endl;

    while (letra != 'S'){
        cout << "Insira o " << i << " numero: ";
        cin >> input;
        if(!cin.fail()){
            numbers.push_back(input);
            i++;
        }else{
            cin.clear();
            cin >> letra;
            if(letra == 'C'){
                if (numbers.size()){
                    numbers.pop_back();
                    i--;
                }
            }
            cin.ignore(256,'\n');
        }
    }

    cout <<endl << "Os numeros informados foram:" << endl;
    for(vi = numbers.begin(); vi != numbers.end(); vi++){
        cout << *vi << " ";
    }

    sort(numbers.begin(),numbers.end());
    cout <<endl << "Os numeros informados ordenados:" << endl;
    for(vi = numbers.begin(); vi != numbers.end(); vi++){
        cout << *vi << " ";
    }

    cout <<endl << "Os numeros informados ordenados inversamente (reverse iterator):" << endl;
    for(rvi = numbers.rbegin(); rvi != numbers.rend(); rvi++){
        cout << *rvi << " ";
    }
    cout << endl;

    return 0;
}


#pragma once
#include <iostream>
#include <string.h>
#include <math.h>

template <class Y>
class Matrix
{
    class Inner //Corchetes internos
    {
    private:
        Y* array2;
    public:
        Inner(){}
        Inner(Y* _array)
        {
            array2 = _array;
        }
        Y& operator[](int index)
        {
            return array2[index];
        }
    };
private:
    Y** array;
    int rows;
    int columns;
    
public:
    int GetRows(){return rows;}
    int GetColumns(){return columns;}
    Y** GetArray(){return array;}
    
    Matrix()
    {
        array = new Y*;
        array[0] = new Y;
        rows = 1;
        columns = 1;
    }
    Matrix(int rows)
    {
        this->rows = rows;
        columns = rows;
        array = new Y*[rows];
        for (int i = 0; i<rows; ++i)
        {
            array[i] = new Y[columns];
        }
    }
    Matrix(int rows,int columns)
    {
        this->rows = rows;
        this->columns = columns;
        array = new Y*[columns];
        for (int i = 0; i<columns; ++i)
        {
            array[i] = new Y[rows];
        }
    }
    
    void FillRandom()
    {
        for (int i = 0; i<columns; ++i)
        {
            for (int j = 0; j< rows; ++j)
            {
                array[i][j] = rand()+1;
            }
        }
    }
    
    void FillRandom(int maxNumber)
    {
        for (int i = 0; i<columns; ++i)
        {
            for (int j = 0; j< rows; ++j)
            {
                array[i][j] = rand()%maxNumber+1;
            }
        }
    }
    void FillUser()
    {
        for (int i = 0; i< columns; ++i)
        {
            for (int j = 0; j< rows; ++j)
            {
                std::cout<<"("<<j<<","<<i<<") : "; // J = x, I = y
                std::cin>>array[i][j]; // [Y][X]
            }
        }
    }
    
    bool isNegative(Y number)
    {
        if (number<0)
        {
            return true;
        }
        return false;
    }
    bool isPrime(Y number)
    {
        bool esPrimo = true;
        if (number == 2) {return true;}
        if (number%2 == 0)
        {return false;}
        
        for (int i = 3;i<=sqrt(number); ++i)
            {
                if (number % i == 0) {return false;}
                else { esPrimo = true; }
            }
        return esPrimo;
    }
    bool isCircular(Y number)
    {
        if (number < 5)
            return false;
        
        bool circular = false;
        int result = number*number;
        
        std::string num = std::to_string(number);
        std::string res = std::to_string(result);
        
        int j = 0;
        for (int i = (res.size()-num.size()); i < res.size(); ++i)
        {
            if(res[i] == num[j])
            {
                circular = true;
                continue;
            }
            circular = false;
            break;
        }
        return circular;
    }
    bool isNaturalPerfect(Y number)
    {
        if (number<6)
            return false;
        
        int suma = 1;
        for (int i = 2; i<number; ++i)
        {
            if(number%i==0)
            {
                suma = suma+i;
            }
        }
        if (suma == number)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isCircularPrimo(Y number)
    {
        if (number<10)
            return false;
        
        int combination, combination2;
        if (isPrime(number))
        {
            if(checkDigit(number)) //Si True = no hay pares,5,0 en digitos
            {
                if (number<100) //Acomodar digitos 2,3 con 3,2
                            {
                                combination = getDigits(number,3)*10 +getDigits(number, 2);
                                if (isPrime(combination))
                                {
                                    return true;
                                }
                            }
                            else if(number>99 && number<1000)//Acomodar digito 1,2,3 con 3,1,2 y 2,3,1
                            {
                                combination = getDigits(number, 3)*100 + getDigits(number, 1)*10 + getDigits(number, 2);
                                combination2 = getDigits(number, 2)*100 + getDigits(number, 3)*10 + getDigits(number, 1);
                                if (isPrime(combination) && isPrime(combination2))
                                {
                                    return true;
                                }
                            }
                        }
                    }
        return false;
        
}
bool checkDigit(int number) //Eliminar si algun digito es par,5,0
{
    int firstDigit = 1;
    int zeroDigit = 1;
    
    if (number>99)
        int firstDigit = getDigits(number, 1);
    if(number >999)
        int zeroDigit = getDigits(number, 0);
    
    int secondDigit = getDigits(number, 2);
    int thirdDigit = getDigits(number, 3);
    
    if (firstDigit == 0||secondDigit== 0||thirdDigit==0||zeroDigit==0)
    { //Si tiene 0 no puede ser primo el circular
        return false;
    }
    if (firstDigit%2 == 0||secondDigit%2 == 0||thirdDigit%2 == 0||zeroDigit%2==0)
    { //tampoco si tiene pares
        return false;
    }
    if (firstDigit==5||secondDigit==5||thirdDigit==5||zeroDigit==5)
    {//o si tiene 5
        return false;
    }
    return true;
}
int getDigits(int number,int place)
{
    switch (place)
    {
        case 0:
            return floor(number/1000);
            break;
        case 1:
            return int(floor(number/100))%10;
            break;
        case 2:
            return int(floor(number/10))%10;
            break;
        case 3:
            return number%10;
            break;
    }
    return 0;
}

    bool MayorQue(Y numUno, int numDos)
    {
        return numUno > numDos;
    }
    bool MenorQue(Y numUno, int numDos)
    {
        return numUno < numDos;
    }

    void operator ~()
    {
            for (int i = 0; i< columns; ++i)
            {
                for (int j = 0; j<rows; ++j)
                {
                    array[i][j] = array[i][j]*(-1);
                }
            }
        }
    void operator ^(int exponente)
    {
        for (int i = 0; i< columns; ++i)
        {
            for (int j = 0; j<rows; ++j)
            {
                array[i][j] = pow(array[i][j], exponente);
            }
        }
    }
    void operator()(int multiplo); //Multiplica todo por el numero
    
    friend std::ostream& operator << (std::ostream& os, const Matrix& matriz); //Imprimir matriz
    friend std::istream& operator >> (std::istream& is, Matrix& matriz); //Cada valor de la matriz
    
    template <class Param, class Func>
    void findIf(Param value, Func metodo) //Mayor que menor que
    {
        for (int i = 0; i< columns; ++i)
        {
            for (int j = 0; j< rows; ++j)
            {
                
                if ((this->*metodo)(array[i][j],value))
                {
                    std::cout<<array[i][j]<<"\n";
                    return;
                }
            }
        }
        std::cout<<"Error 400, number not found"<<"\n";
    }

    template <class Func>
    void findIf(Func metodo) //Cualquier is
    {
        for (int i = 0; i< columns; ++i)
        {
            for (int j = 0; j< rows; ++j)
            {
                if ((this->*metodo)(array[i][j]))
                {
                    std::cout<<array[i][j]<<"\n";
                    return;
                }
            }
        }
        std::cout<<"Error 400, number not found"<<"\n";
    }
    
    template <class Func>
    void findAdyacent(Func metodo)
    {
        for (int i = 0; i< columns; ++i)
        {
            for (int j = 0; j< rows-1; ++j)
            {
                if ((this->*metodo)(array[i][j]) && (this->*metodo)(array[i][j+1]))
                {
                    std::cout<<array[i][j]<<" "<<array[i][j+1]<<"\n";
                    return;
                }
            }
        }

    }
    
    void findSameAdyacent()
    {
        for (int i = 0; i< columns; ++i)
        {
            for (int j = 0; j< rows-1; ++j)
            {
                if (array[i][j] == array[i][j+1])
                {
                    std::cout<<array[i][j]<<" "<<array[i][j+1]<<"\n";
                    return;
                }
            }
        }
    }

    Inner operator[](int index)
    {
        return Inner(array[index]); //Corchetes de fuera
    }
    
    /*
     void PrintTranspose();
     void PrintUpper();
     void PrintLower();
     void PrintSuma(Y** Suma);
     
     Y** Upper(); //Elementos debajo de la diagonal principal son 0
     Y** Lower(); //Elementos arriba de la diagonal principal son 0
     Y** Transpose(); //Convierte la matriz original rows a columns y columns a rows
     Y** operator +(Matrix& matriz); //Crea una matriz nueva con los resultados, solo si ambas matrices tienen mismos tamaños, si son diferentes tamaños devolver un error*/
};

template <class Y>
void Matrix<Y> ::operator ()(int multiplo)
{
    for (int i = 0; i< columns; ++i)
    {
        for (int j = 0; j<rows; ++j)
        {
            array[i][j] = (array[i][j]*multiplo);
        }
    }
}


template <class Y>
std::ostream& operator << (std::ostream& os, Matrix<Y>& matriz)
{
    for (int i = 0; i< matriz.GetColumns(); ++i)
    {
        for (int j = 0; j< matriz.GetRows(); ++j)
        {
            os << matriz[i][j] << " ";
        }
        os<<"\n";
    }
    os<<"\n";
    return os;
}

template <class Y>
std::istream& operator >> (std::istream& is, Matrix<Y>& matriz)
{
    for (int i = 0; i< matriz.columns; ++i)
    {
        for (int j = 0; j< matriz.rows; ++j)
        {
            std::cout<<"("<<j<<","<<i<<") : "; // J = x, I = y
            std::cin>>matriz[i][j]; // [Y][X]
        }
    }
    std::cout<< "\n";
    return is;
}


/*template <class Y>
void Matrix<Y> ::PrintTranspose()
{
    Y** transp = Transpose();
    
    for (int i = 0; i< rows; ++i)
    {
        for (int j = 0; j<columns; ++j)
        {
            std::cout<< transp[i][j] << " ";
        }
        std::cout<< "\n";
    }
    std::cout<< "\n";
    delete [] transp;
}

template <class Y>
void Matrix<Y> ::PrintUpper()
{
    Y** upper = Upper();
    
    for (int i = 0; i< columns; ++i)
    {
        for (int j = 0; j<rows; ++j)
        {
            std::cout<< upper[i][j] << " ";
        }
        std::cout<< "\n";
    }
    std::cout<< "\n";
    delete [] upper;
}

template <class Y>
void Matrix<Y> ::PrintSuma(Y** Suma)
{
    for (int i = 0; i< columns; ++i)
    {
        for (int j = 0; j<rows; ++j)
        {
            std::cout<< Suma[i][j] << " ";
        }
        std::cout<< "\n";
    }
    std::cout<< "\n";
    //delete [] Suma;
}

template <class Y>
void Matrix<Y> ::PrintLower()
{
    Y** lower = Lower();
    
    for (int i = 0; i< columns; ++i)
    {
        for (int j = 0; j<rows; ++j)
        {
            std::cout<< lower[i][j] << " ";
        }
        std::cout<< "\n";
    }
    std::cout<< "\n";
    delete [] lower;
}*/


/*
 template <class Y>
 Y** Matrix<Y>::Lower()
 {
 Y** lower = new Y*[columns];
 
 for (int i = 0; i<columns; ++i)
 {
 lower[i] = new Y[rows];
 }
 
 for (int i = 0; i<columns; ++i)
 {
 for (int j = 0; j<rows; ++j)
 {
 lower[i][j] = array[i][j];
 }
 }
 
 for (int i = 0; i<columns; ++i)
 {
 for (int j = 0; j+i+1<rows; ++j)
 {
 lower[i][j+i+1] = 0;
 }
 }
 return lower;
 }
 
 template <class Y>
 Y** Matrix<Y>::Upper()
 {
 Y** upper = new Y*[columns];
 
 for (int i = 0; i<columns; ++i)
 {
 upper[i] = new Y[rows];
 }
 
 for (int i = 0; i<columns; ++i)
 {
 for (int j = 0; j<rows; ++j)
 {
 upper[i][j] = array[i][j];
 }
 }
 for (int j = 1; j<columns; ++j)
 {
 for (int i = 0; i<rows; ++i)
 {
 if(j == i)
 break;
 upper[j][i] = 0;
 }
 }
 return upper;
 }
 
 template <class Y>
 Y** Matrix<Y>::Transpose()  //Invertir rows y columns del original
 {
 Y** transpose = new Y*[rows];
 
 for (int i = 0; i<rows; ++i)
 {
 *(transpose+i) = new Y[columns];
 }
 
 for (int i = 0; i<rows; ++i)
 {
 for (int j = 0; j< columns; ++j)
 {
 transpose[i][j] = array[j][i];
 }
 }
 return transpose;
 }
 template <class Y>
 Y** Matrix<Y>::operator +(Matrix& matriz)
 {
 if(rows != matriz.GetRows())
 {
 std::cout<<"Error, no puedes sumar matrices con diferente numero de filas"<<"\n";
 return array;
 }
 if(columns != matriz.GetColumns())
 {
 std::cout<<"Error, no puedes sumar matrices con diferente numero de columnas"<<"\n";
 return array;
 }
 
 Y** matrizSuma = new Y*[columns];;
 
 
 for (int i = 0; i<columns; ++i)
 {
 *(matrizSuma+i) = new Y[rows];
 }
 
 for (int i = 0; i< columns; ++i)
 {
 for (int j = 0; j<rows; ++j)
 {
 matrizSuma[i][j] = array[i][j] + matriz[i][j];
 }
 }
 
 return matrizSuma;
 }*/






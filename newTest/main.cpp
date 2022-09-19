#include <iostream>
#include <wiringPi.h>
#include <Led.h>
#include <Button.h>

Button *makeButtonIns(int pin)
{
    return new Button(pin);
}
Led *makeLedIns(int pin)
{
    return new Led(pin);
}
void delButtonIns(Button *btn)
{
    delete btn;
}
void delLedIns(Led *led)
{
    delete led;
}
int add(int a, int b)
{
    return a+b;
}
double add (double a ,double b)
{
    return a + b ;
}
char add(char a , char b)
{
    return a + b;
}

template<typename T>
T addTemp(T x, T y)
{
    return x + y ;
}

template<typename T>
class ArrayList
{

private:

    T arrayList[10]; //int array List[10];
    int count;

public: 
    ArrayList();
    ~ArrayList();
    void add(T t);
    T read(int index);
};

template <typename T>
ArrayList<T>::ArrayList() :count(0)
{}

template <typename T>
ArrayList<T>::~ArrayList()
{

}


template <typename T>
void ArrayList<T>::add(T t)
{
    if(count >= 10) return;
    arrayList[count] = t;
    count ++;
}

template <typename T>
T ArrayList<T>::read(int index)
{
    if(index >= count ) return 0;
    return arrayList[index];
}



int main()
{
    std::cout<<"Hello World!"<<std::endl;
    //Button *lightOnOffButton = makeButtonIns(27);
   // Button *delLightButton = makeButtonIns(28);
    Led *light1 = makeLedIns(25);
    Led *light2 = makeLedIns(24);

    int a = 10;
    int b = 20;
    double c = 11.1;
    double d = 22.2;
    char e =31;
    char f =33;
    
    std::cout << "int + int = " <<add(a,b) << std::endl;
    std::cout << "double + double = " <<add(c,d) << std::endl;
    std::cout << "char + char = " << add(e,f) << std::endl;

    std::cout << "temp : int + int = " <<addTemp(a,b) << std::endl;
    std::cout << "temp : double + double = " <<addTemp(c,d) << std::endl;
    std::cout << "temp : char + char = " << addTemp(e,f) << std::endl;

    ArrayList<Button * > list;
    list.add(new Button(27));
    list.add(new Button(28));
    // list.add(20);
    // list.add(30);
    // list.add(40);
    // list.add(50);

    // for(int i = 0; i<10; i++)
    // {
    //     std::cout << "list :" << list.read(i) << std::endl;
    // }
    Button *listButton;

    while(1)
    {
        listButton = list.read(0);
        if(listButton -> getState() == RELEASE_ACTIVE)
        {
            light1 -> Toggle();
        }
        // if(lightOnOffButton->getState() == RELEASE_ACTIVE)
        // {
        //     light -> Toggle();
        // }
        listButton = list.read(1);
        if(listButton->getState() == RELEASE_ACTIVE)
        {
            light2 -> Toggle();
        }

        delay(50);
    }

    // delete lightOnOffButton;
    // delete light;
    
    return 0;
}
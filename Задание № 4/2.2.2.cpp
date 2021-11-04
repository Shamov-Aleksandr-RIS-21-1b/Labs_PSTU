#include <iostream>
#include <cmath>//подключение библиотеки для функции abs() - нахождения модуля числа 
using namespace std;
int hours1,hours2;//часы начала и окончания события
int hours;//разница часов
int minutes1,minutes2;//минуты начала и окончания события
int minutes;//разница минут
int seconds1,seconds2;//секунды начала и окончания события
int seconds;//разница секунд
int main()
{
    setlocale(LC_ALL,"RUSSIAN");
    cout<<"Начало события.\n";
    
      do
      {
          cout<<"Введите часы (от 0 до 23): ";
          cin>>hours1;
          if (hours1<0 || hours1>23) cout<<"Неверный формат времени, попробуйте снова...\n";
      }
      while (hours1<0 || hours1>23);//проверка на корректный ввод 
      
      do
      {
          cout<<"Введите минуты (от 0 до 59): ";
          cin>>minutes1;
          if (minutes1<0 || minutes1>59) cout<<"Неверный формат времени, попробуйте снова...\n";
      }
      while (minutes1<0 || minutes1>59);//проверка на корректный ввод
      
      do
      {
          cout<<"Введите секунды (от 0 до 59): ";
          cin>>seconds1;
          if (seconds1<0 || seconds1>59) cout<<"Неверный формат времени, попробуйте снова...\n";
      }
      while (seconds1<0 || seconds1>59);//проверка на корректный ввод
      
    cout<<"Конец события.\n";
    
      do
      {
          cout<<"Введите часы (от 0 до 23): ";
          cin>>hours2;
          if (hours2<0 || hours2>23) cout<<"Неверный формат времени, попробуйте снова...\n";
      }
      while (hours2<0 || hours2>23);//проверка на корректный ввод
      
      do
      {
          cout<<"Введите минуты (от 0 до 59): ";
          cin>>minutes2;
          if (minutes2<0 || minutes2>59) cout<<"Неверный формат времени, попробуйте снова...\n";
      }
      while (minutes2<0 || minutes2>59);//проверка на корректный ввод
      
      do
      {
          cout<<"Введите секунды (от 0 до 59): ";
          cin>>seconds2;
          if (seconds2<0 || seconds2>59) cout<<"Неверный формат времени, попробуйте снова...\n";
      }
      while (seconds2<0 || seconds2>59);//проверка на корректный ввод

    hours=abs(hours1-hours2);//модуль разницы часов
    minutes=abs(minutes1-minutes2);//модуль разницы минут
    seconds=abs(seconds1-seconds2);//модуль разницы секунд
    
    if (hours1>hours2) hours=24-hours;/*если часы начала события больше часов оконачания (событие закончилось на следующие сутки), то разница находится по этой формуле*/
    
    if (minutes1>minutes2)//если минуты начала события больше минут оконачания, то разница находится по данной формуле
       {
        minutes=60-minutes;
        --hours;//так же происходит занимание у старшего разряда - часов
        if (hours<0) hours=23;/*если часы начала и окончания совпадают, их разница равна нулю, тогда при занимании у разряда часов разница становится отрицательной. такая ситуация невозможна, следовательно прошло максимум 23 часа*/
       }  
       
    if (seconds1>seconds2)//по аналогии с часами и минутами
       {
        seconds=60-seconds;
        --minutes;
        if (minutes<0)
           {
               minutes=59;
               --hours;
               if (hours<0) hours=23;
           }
       }

    cout<<"Событие, которое началось в "<<hours1<<":"<<minutes1<<":"<<seconds1<<
          " и завершилось в "<<hours2<<":"<<minutes2<<":"<<seconds2<<", продлилось "
          <<hours<<" часов, "<<minutes<<" минут, "<<seconds<<" секунд.";//вывод продолжительности события
    return(0);      
}
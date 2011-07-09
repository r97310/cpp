#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

class HeapSort
{
      private:
              int list[10];
      protected:
               void fixup(int, int, int);
               void buildheap();
      public:
             void heapsort();
             void store(int, int);
             void printHeap();
             
};

void
HeapSort::fixup(int value, int start, int last)
{
     int look;
     bool done;
     done = false;
     look = 2*start+1;
     
     while(look <= last && !done)
     {
          if(look < last)
          {
              if(list[look] < list[look+1])
                   look = look+1;
          }
          if(value > list[look])
              done = true;
          else
          {
              list[start] = list[look];
              start = look;
              look = 2*start+1;
          }
     }
}

void
HeapSort::buildheap()
{
     int count;
     int item;
     
     for(count = (10/2)-1; count >= 0; count--)
     {
          item = list[count];
          fixup(item, count, 9);          
     }             
}

void
HeapSort::heapsort()
{
     int count;
     int item;
     
     buildheap();
     for(count = 9; count >= 1; count--)
     {
          //cout << list[count] << endl;
          //cout <<"count " <<  count << endl;
          item = list[count];
          list[count] = list[0];
          fixup(item, 0, count-1);
          //cout << list[count] << endl;
     }
}

void
HeapSort::store(int number, int place)
{
    list[place] = number;      
}

void
HeapSort::printHeap()
{
     for(int i = 0; i < 10; i++)
         cout << list[i] << endl;                     
}
int
main()
{
     HeapSort heap1;
     HeapSort heap2;

     int x = 0;
     int numberInput;
     
     cout << "Enter ten numbers: " << endl;
     
     while(x < 10)
     {
          cin >> numberInput;
          //heap1.heapsort();
          //cout << x;
          heap1.store(numberInput, x);  
          x++;
     }
     
     x = 0;
     
     /*while(x < 10)
     {
         cin >> numberInput;
         heap2.store(numberInput, x);
         x++;
     }
     */
     heap1.heapsort();
     heap1.printHeap();
     //heap2.printHeap();
    // heap2.heapsort();
     //heap2.printHeap();
     
     system("pause");      
}

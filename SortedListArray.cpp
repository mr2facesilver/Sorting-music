
#include<cmath>

#include "CD.h"
using CSC2110::CD;
#include "ListArray.h"
using CSC2110::ListArray;
#include "ListArrayIterator.h"
using CSC2110::ListArrayIterator;


 using namespace std;
 namespace CSC2110
{
template < class T >
class SortedListArray
{

   private:
   int max_list;
   T** items;
   // ListArray<T>* Theitems;// int compare_items;// int compare_keys;
      int sze;
	  void arrayResize(int new_max_size)

	  int (*comp_item)(T* item_1,T* item_2);
	  int (*comp_key)(String* key,T* item );
	  int  binary_search(T* item )
	  int binary_search2(T* item )
    public:
      SortedListArray(int*comp_items,int * comp_keys);
      ~SortedListArray();
      bool isEmpty();
      int size();
      void add(T* item); 
      T* get(String* search_key);
      void remove(String* search_key);
	  ListArrayIterator<T>* iterator();
};
SortedListArray::size()
{
	return sze;
}

template	<class	T>
SortedListArray<T>::SortedListArray(int (*comp_items)(T* item_1,T* item_2), int (*comp_keys) (String* key, T* item))
{
	max_list = 2;
	items = new T*[max_list];
	sze = 0;
	//copy the memory address of the function into a private instance variable
	compare_items = comp_items;
	compare_keys = comp_keys;
}
template	<class	T>
SortedListArray<T>::~SortedListArray()
{
	delete[] items;
	
}

template < class T >
void SortedListArray<T>::add(T* item)
{
	int index= binary_search(T* item )
   if (index < 1 || index > sze  + 1)
   {
      return;
   }

   //need more room in the array list
   if (sz == max_list) 
   {
      arrayResize(2*max_list);
   }  
 
   for (int i = sz; i >= index; i--)
   { 
      items[i] = items[i - 1];
   }

   items[index - 1] = item;
   sz++;
}

template	<class	T>
bool SortedListArray<T>::isEmpty()
{
	 return (sze == 0);
}
template	<class	T>
T* SortedListArray<T>::get(String* search_key)
{ 

    
    int index =binary_search2(search_key)
    if(index==-1)
        return NULL
    
    return items[index];
    
}

template	<class	T>
void SortedListArray<T>::remove(String* search_key)
{
	int index =binary_search2(String* search_key)
   if (index < 1 || index > sz)
   {
      return;
   }

   for (int i = index; i < sz; i++)
   {
      items[i - 1] = items[i];
   }

   items[sz - 1] = NULL;
   sz--;


}

template	<class	T>
ListArrayIterator<T>* SortedListArray<T>::iterator()
{//list array iterator
   ListArrayIterator<T>* iter = new ListArrayIterator<T>(items, sz);
   return iter;
}

template	<class	T>
int SortedListArray<T>::binary_search(T* item);
{
	//post: If the search is successful, the index of the match is returned (1-based)
//if the search is unsuccessful, -1 is returned
    int front,end,mid;
    front=0
    end=sze-1
    mid= front+((end-front)/2)
    
    while(front <=end)
    {
        int cmp =comp_item(item_1,items[mid] ) ;
        if(0 == cmp)
            return mid+1;
        else if(-1==cmp)
            end=mid-1
            else
                front=mid+1
                mid=front+ floor((end-front)/2)
                }
    return mid+1;
}


template	<class	T>
int SortedListArray<T>::binary_search2(T* item_1 )
{//post: If the search is successful, the index of the match is returned (1-based)
	int front,end,mid;
	front=0
	end=sze-1
	mid= front+((end-front)/2)
	
	while(front <=end)
	{
        int cmp =comp_key(item_1 ,items[mid] ) ;
		if(0 == cmp)
            return mid+1;
		else if(-1==cmp)
			end=mid-1
		else
		front=mid+1
		mid=front+ floor((end-front)/2)
	}
    return -1;
}

template	<class	T>
void SortedListArray<T>::arrayResize(int new_max_size)
{
	max_list = new_max_size;
   T** temp = new T*[max_list];

   for (int i = 0; i < sz; i++)
   {
      temp[i] = items[i];
   }

   delete[] items;
   items = temp;
	
}
}
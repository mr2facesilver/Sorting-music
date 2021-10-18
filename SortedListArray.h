#include <iostream>
#include<cmath>

#include "CD.h"
using CSC2110::CD;
#include "ListArray.h"
using CSC2110::ListArray;
#include "ListArrayIterator.h"
using CSC2110::ListArrayIterator;
#include "text.h"

 using namespace std;
 using namespace CSC2110;

template < class T >
class SortedListArray
{

   private:
   int max_list;
   T** items;
   // ListArray<T>* Theitems;// int compare_items;// int compare_keys;
      int sze;
	  //pre:none
	  //post:none
	  void arrayResize(int new_max_size);
		//pre:it get a new maxsize
	  //post:it returns nothing just changes the size of the array
	  int (*compare_items)(T* item_1,T* item_2);
	  //pre:takes in two items of the same type
	  //post:returns an int
	  
	  int (*compare_keys)(String* key,T* item );
	  //pre:takes in a string and item
	  //post:return 1 ,0 or -1
	  
	  int  binary_search(T* item );
	 
	  //pre:used for add and need an item
	  //post:it returns a int
	  
	  int binary_search2(String* item );
	  //pre:used for delete and get
	  //post: it returns a int
	  
    public:
      SortedListArray(int (*comp_items)(T* item_1,T* item_2), int (*comp_keys)(String* key, T* item));
	  //pre:takeing in two funtions that compare.
	  //post: contruct a array of size two
	  
      ~SortedListArray();
	  //pre:none
	  //post:a deleted array
      bool isEmpty();
	  //pre:nothing
	  //post:nothing
      int size();
	  //pre:none
	  //post:return the size
      void add(T* item); 
	  //pre:takes in a item
	  //post:adds that item to a list
      T* get(String* search_key);
	  //pre:takes in a stirng 
	  //post: returns the location of a item
      void remove(String* search_key);
	  //pre:takes in a string
	  //post:returns the item to be deleted
	  ListArrayIterator<T>* iterator();
	  //pre:none
	  //post:creats and iterator
};
template <class T>
int SortedListArray<T>::size()
{
	return sze;
}

template	<class	T>
SortedListArray<T>::SortedListArray(int (*comp_items)(T* item_1,T* item_2), int (*comp_keys)(String* key, T* item))
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
	
	int index= binary_search(item );//finds the index
   if (index < 1 || index > sze  + 1)
   {
      return;
   }

   //need more room in the array list
   if (sze == max_list) 
   {
      arrayResize(2*max_list);
   }  
 
   for (int i = sze; i >= index; i--)
   { 
      items[i] = items[i - 1];
   }

   items[index - 1] = item;
   sze++;

}

template	<class	T>
bool SortedListArray<T>::isEmpty()
{
	 return (sze == 0);
}
template	<class	T>
T* SortedListArray<T>::get(String* search_key)
{ 

    
    int index =binary_search2(search_key);
    if(index==-1)
        return NULL;
    
    return items[index-1];
    
}

template	<class	T>
void SortedListArray<T>::remove(String* search_key)
{
	int index =binary_search2(search_key);
   if (index < 1 || index > sze)//check index
   {
      return;
   }
if(index==-1)// checks the compare
	return;
   for (int i = index; i < sze; i++)
   {
      items[i-1]=items[i];
   }

   items[sze - 1] = NULL;
   sze--;


}

template	<class	T>
ListArrayIterator<T>* SortedListArray<T>::iterator()
{//list array iterator
   ListArrayIterator<T>* iter = new ListArrayIterator<T>(items, sze);
   return iter;
}

template	<class	T>
int SortedListArray<T>::binary_search(T* item)
{
	//post: If the search is successful, the index of the match is returned (1-based)
//if the search is unsuccessful, -1 is returned
    int front,end,mid;
    front=0;
    end=sze-1;
    mid= front+((end-front)/2);
    
    while(front <=end)
    {
        int cmp =compare_items(item,items[mid] );//compares
        if(0 == cmp)
            return mid+1;
        else if(-1==cmp)
            end=mid-1;// moves the end
        else 
			front=mid+1;
            mid=front+ floor((end-front)/2);
		
                }
    return mid+1;
}


template	<class	T>
int SortedListArray<T>::binary_search2(String* item_1 )
{//post: If the search is successful, the index of the match is returned (1-based)
	int front,end,mid;
	front=0;
	end=sze-1;
	mid= front+((end-front)/2);
	
	while(front <=end)
	{
        int cmp =compare_keys(item_1 ,items[mid] ) ;
		if(0 == cmp)
            return mid+1;
		else if(cmp<0)
			end=mid-1;
		else{
		front=mid+1;//moves  the front
		}
		mid=front+ floor((end-front)/2);
		
	}
    return -1;
}

template	<class	T>
void SortedListArray<T>::arrayResize(int new_max_size)
{
	max_list = new_max_size;
   T** temp = new T*[max_list];//double the max

   for (int i = 0; i < sze; i++)
   {
      temp[i] = items[i];
   }

   delete[] items;
   items = temp;
	
}

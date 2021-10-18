#include "SortedListArray.h"
#include "CD.h"
using CSC2110::CD;
#include "ListArray.h"
using CSC2110::ListArray;
#include "ListArrayIterator.h"
using CSC2110::ListArrayIterator;
#include "text.h"
using namespace CSC2110;
#include <iostream>
using namespace std;

void deleteCDs(ListArray<CD>* list)
{
   ListArrayIterator<CD>* iter = list->iterator();

   while(iter->hasNext())
   {
      CD* cd = iter->next();
      delete cd;
   }
   delete iter;
}

int main()
{
   ListArray<CD>* cds = CD::readCDs("cds.txt");

   //thoroughly test your sorted list here
SortedListArray<CD>* sl	=new	SortedListArray<CD>(&CD::compare_items,	&CD::compare_keys);
    ListArrayIterator<CD>* iter= cds->iterator();
	
    while(iter->hasNext())
     {
	
      CD* cd = iter->next();
      sl->add(cd);
	// cd->displayCD();
	}

	delete iter;
ListArrayIterator<CD>* iterr=sl->iterator();
	while(iterr->hasNext())
	{
	CD* a=iterr->next();
	a->displayCD();
	}

String* dawords2= new String("Kataklysm");
String* dawords= new String("Dark Tranquillity");

sl->remove(dawords2);
sl->remove(dawords);
cout<<"---------------------------------------------------------"<<endl;

ListArrayIterator<CD>* iterr1=sl->iterator();
	
	while(iterr1->hasNext())
	{	
	CD*as=iterr1->next();
	as->displayCD();
	}
	cout<<"---------------------------------------------------------"<<endl;

String* words= new String("Lay Down Rotten");

CD*funer=sl->get(words);
funer->displayCD();

delete iterr1;

   deleteCDs(cds);
   delete cds;

   return 0;
}

//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "HashTable.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

HashTable::HashTable(void)
{
	int i;

	for (i=0;i<SIZE;i++) Table[i]=NULL;
}

HashTable::~HashTable()
{
	int i;
	
	for (i=0;i<SIZE;i++)
	{
		if (Table[i] != NULL)
		{
			//cout<<Table[i]->name<<endl;
			delete Table[i];
		}
	}
}

int HashTable::hash(String &key)
{
	int temp = 0;
	int i;

	for (i = 1; i<=key.Length() ; i++)
		temp = ((temp << SHIFT) + (unsigned)(key[i])) % SIZE;
	/* use unsigned support Chinese */
	return temp;
}

bool HashTable::insert(String Name, int Address, bool bMode)
{
	int h = hash(Name);
	BucketList *l = Table[h];

	while ((l != NULL) && (Name != l->Name))
		l = l->Next;
	if (l == NULL)
	{			/* variable not yet in table */
		//l = (BucketList) malloc(sizeof(struct BucketListRec));
		l = new BucketList;
		//???if(l==NULL)
		l->Name = Name;
		//???if(l->lines==NULL)
		l->Address = Address;
        l->Relative = bMode;
		l->Next = Table[h];
		Table[h] = l;

		return true;
	}
	else
	{					// found in table, Error!
		return false;
	}
}

int HashTable::lookup(String &Name, bool &bMode)
{
	int h = hash(Name);
	BucketList *l = Table[h];

	while ((l != NULL) && (Name != l->Name))
		l = l->Next;
	if (l == NULL)
		return -1;
	else
    {
        bMode = l->Relative; 
		return l->Address;
    }
}

//---------------------------------------------------------------------------

#ifndef HashTableH
#define HashTableH
//---------------------------------------------------------------------------

// SIZE is the size of the hash table
#define SIZE 211

/* SHIFT is the power of two used as multiplier
 * in hash function
 */
#define SHIFT 4

class HashTable
{
private:
	struct BucketList
    {
		String Name;
		int Address;    // Address Info
        bool Relative;
		BucketList *Next;
	} *Table[SIZE];

	int hash(String &);

public:
	HashTable(void);
	~HashTable();

	bool insert(String, int, bool);
	int lookup(String &, bool &);
};
//---------------------------------------------------------------------------
#endif

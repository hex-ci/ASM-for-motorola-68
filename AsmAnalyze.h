//---------------------------------------------------------------------------

#ifndef AsmAnalyzeH
#define AsmAnalyzeH
//---------------------------------------------------------------------------
#include <ComCtrls.hpp>
#include <fstream>
#include "HashTable.h"

/* BUFLEN = length of the input buffer for source code lines */
#define BUFLEN 256

/* MAXTOKENLEN is the maximum size of a token */
#define MAXTOKENLEN 255

#define MAXRESERVED 108

typedef enum
{
/* book-keeping tokens */
	ENDFILE=0, TOKENERROR,
/* Line End */
	ENDLINE,
/* reserved words */
	KEYWORDS,
/* multicharacter tokens */
	ID, HEXNUM,
/* specical symbols */
	SHARP, XCHAR, COLON, EQUAL, ATCHAR, STRING
} AsmTokenType;

/* states in scanner DFA */
typedef enum
{
	START=10, INADDRESS, INCOMMENT, INCOMMENT_SINGLE, INHEXNUM, INID,
    INSHARP, INXCHAR, INEQUAL, INATCHAR, INSTRING, DONE
} StateType;					/* used INLT INGT to scan <= >= and <> Larry */

typedef enum
{
	SYNTAX_ERROR, KEYWORD_ERROR, ID_NOFOUND, ID_DEFINED,
    LINK_ERROR, ADDRESS_ERROR
} AsmErrorType;

//using namespace std;

class TAsmAnalyze
{
// 结构成员
private:
    class IDListStruct : public TObject
    {
     public:
        int Address;
        int Line;
        bool Relative; 
        IDListStruct(int Addr, int Lineno)
        {
            Address=Addr;
            Line = Lineno;
            Relative=true;
        }
    };
    
    // Addressing mode
    struct Addressing
    {
        unsigned char Code;
        int Bytes;
    };

    // lookup table of reserved words
    // Addressing Mode:
    //	1. Immediate Addressing
    //	2. Direct Addressing
    //  3. Indirect Addressing
    //	4. Extended Addressing
    //	5. Implied Addressing
    //	6. Relative Addressing
    struct Keywords
    {
        String str;
        AsmTokenType tok;
        Addressing Mode[6];
        void set(String ID, AsmTokenType t,
                 unsigned char Code1, int Byte1,
                 unsigned char Code2, int Byte2,
                 unsigned char Code3, int Byte3,
                 unsigned char Code4, int Byte4,
                 unsigned char Code5, int Byte5,
                 unsigned char Code6, int Byte6)
        {
            str = ID;
            tok = t;
            Mode[0].Code  = Code1;
            Mode[0].Bytes = Byte1;

            Mode[1].Code  = Code2;
            Mode[1].Bytes = Byte2;

            Mode[2].Code  = Code3;
            Mode[2].Bytes = Byte3;

            Mode[3].Code  = Code4;
            Mode[3].Bytes = Byte4;

            Mode[4].Code  = Code5;
            Mode[4].Bytes = Byte5;

            Mode[5].Code  = Code6;
            Mode[5].Bytes = Byte6;
        }
    } reservedWords[MAXRESERVED];

// 数据成员
private:
    /* lexeme of identifier or reserved word */
    String tokenString;

    int BaseAddress;
    int DebugAddress;
    int CurrentAddress;
    int CurrentKeyWords;
    bool DebugMode;
    AsmTokenType CurrentToken;

    std::ifstream SourceFile;    // declare input and output streams
    std::ofstream DestFile;      // declare input and output streams
    std::ofstream LinkFile;

    char lineBuf[BUFLEN];	/* holds the current line */
    int linepos;			/* current position in lineBuf */
    int bufsize;			/* current size of buffer string */
    int lineno;

    String DestFileName;
    String LinkFileName;
    
    int TokenPos;
    int CodeError;
    int TotalSize;

    HashTable *pHash;
    TStringList *IDList;
    //TList *IDList;
    TListView *ErrorList;

// 成员函数
private:
    AsmTokenType getToken(void);
    char getNextChar(void);
    void ungetNextChar(void);

    AsmTokenType reservedLookup(String &);

    void Analyze(void);
    void AnalyzeStatement(int);
    void AnalyzeCode(void);

    int HexStr2Int(String &);

    int IsHex(String &);
    void __fastcall FoundError(AsmErrorType Error, int Lineno, String str);
    void LinkCode(void);
    bool inline __fastcall IsName(unsigned char c);

public:
    TAsmAnalyze(void);
    ~TAsmAnalyze();

    bool Open(String);
    bool Make(String, TListView *);
    int Error(void) {return CodeError;}
    int LineNum(void) {return lineno;}
    int BeginAddress(void) {return BaseAddress;}
    int Size(void) {return TotalSize;}
};

//---------------------------------------------------------------------------
#endif

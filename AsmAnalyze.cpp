//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "AsmAnalyze.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

TAsmAnalyze::TAsmAnalyze(void)
{
    reservedWords[0].set("ABA",  KEYWORDS, 0,0, 0,0, 0,0, 0,0, 0x1b,1, 0,0);
	reservedWords[1].set("ADCA", KEYWORDS, 0x89,2, 0x99,2, 0xa9,2, 0xb9,3, 0,0, 0,0);
	reservedWords[2].set("ADCB", KEYWORDS, 0xc9,2, 0xd9,2, 0xe9,2, 0xf9,3, 0,0, 0,0);
	reservedWords[3].set("ADDA", KEYWORDS, 0x8b,2, 0x9b,2, 0xab,2, 0xbb,3, 0,0, 0,0);
	reservedWords[4].set("ADDB", KEYWORDS, 0xcb,2, 0xdb,2, 0xeb,2, 0xfb,3, 0,0, 0,0);
	reservedWords[5].set("ANDA", KEYWORDS, 0x84,2, 0x94,2, 0xa4,2, 0xb4,3, 0,0, 0,0);
	reservedWords[6].set("ANDB", KEYWORDS, 0xc4,2, 0xd4,2, 0xe4,2, 0xf4,3, 0,0, 0,0);
	reservedWords[7].set("ASL",  KEYWORDS, 0,0, 0,0, 0x68,2, 0x78,3, 0,0, 0,0);
	reservedWords[8].set("ASLA", KEYWORDS, 0,0, 0,0, 0,0, 0,0, 0x48,1, 0,0);
	reservedWords[9].set("ASLB", KEYWORDS, 0,0, 0,0, 0,0, 0,0, 0x58,1, 0,0);
	reservedWords[10].set("ASR",  KEYWORDS, 0,0, 0,0, 0x67,2, 0x77,3, 0,0, 0,0);
	reservedWords[11].set("ASRA", KEYWORDS, 0,0, 0,0, 0,0, 0,0, 0x47,1, 0,0);
	reservedWords[12].set("ASRB", KEYWORDS, 0,0, 0,0, 0,0, 0,0, 0x57,1, 0,0);
	reservedWords[13].set("ATPA", KEYWORDS, 0,0, 0,0, 0,0, 0,0, 0x07,1, 0,0);

	reservedWords[14].set("BCC",  KEYWORDS, 0,0, 0,0, 0,0, 0,0, 0,0, 0x24,2);
	reservedWords[15].set("BCS",  KEYWORDS, 0,0, 0,0, 0,0, 0,0, 0,0, 0x25,2);
	reservedWords[16].set("BEQ",  KEYWORDS, 0,0, 0,0, 0,0, 0,0, 0,0, 0x27,2);
	reservedWords[17].set("BGE",  KEYWORDS, 0,0, 0,0, 0,0, 0,0, 0,0, 0x2c,2);
	reservedWords[18].set("BGT",  KEYWORDS, 0,0, 0,0, 0,0, 0,0, 0,0, 0x2e,2);
	reservedWords[19].set("BHI",  KEYWORDS, 0,0, 0,0, 0,0, 0,0, 0,0, 0x22,2);
	reservedWords[20].set("BITA", KEYWORDS, 0x85,2, 0x95,2, 0xa5,2, 0xb5,3, 0,0, 0,0);
	reservedWords[21].set("BITB", KEYWORDS, 0xc5,2, 0xd5,2, 0xe5,2, 0xf5,3, 0,0, 0,0);
	reservedWords[22].set("BLE",  KEYWORDS, 0,0, 0,0, 0,0, 0,0, 0,0, 0x2f,2);
	reservedWords[23].set("BLS",  KEYWORDS, 0,0, 0,0, 0,0, 0,0, 0,0, 0x23,2);
	reservedWords[24].set("BLT",  KEYWORDS, 0,0, 0,0, 0,0, 0,0, 0,0, 0x2d,2);
	reservedWords[25].set("BMI",  KEYWORDS, 0,0, 0,0, 0,0, 0,0, 0,0, 0x2b,2);
	reservedWords[26].set("BNE",  KEYWORDS, 0,0, 0,0, 0,0, 0,0, 0,0, 0x26,2);
	reservedWords[27].set("BPL",  KEYWORDS, 0,0, 0,0, 0,0, 0,0, 0,0, 0x2a,2);
	reservedWords[28].set("BRA",  KEYWORDS, 0,0, 0,0, 0,0, 0,0, 0,0, 0x20,2);
	reservedWords[29].set("BSR",  KEYWORDS, 0,0, 0,0, 0,0, 0,0, 0,0, 0x8d,2);
	reservedWords[30].set("BVC",  KEYWORDS, 0,0, 0,0, 0,0, 0,0, 0,0, 0x28,2);
	reservedWords[31].set("BVS",  KEYWORDS, 0,0, 0,0, 0,0, 0,0, 0,0, 0x29,2);

	reservedWords[32].set("CBA",  KEYWORDS, 0,0, 0,0, 0,0, 0,0, 0x11,1, 0,0);
	reservedWords[33].set("CLC",  KEYWORDS, 0,0, 0,0, 0,0, 0,0, 0x0c,1, 0,0);
	reservedWords[34].set("CLI",  KEYWORDS, 0,0, 0,0, 0,0, 0,0, 0x0e,1, 0,0);
	reservedWords[35].set("CLR",  KEYWORDS, 0,0, 0,0, 0x6f,2, 0x7f,3, 0,0, 0,0);
	reservedWords[36].set("CLRA", KEYWORDS, 0,0, 0,0, 0,0, 0,0, 0x4f,1, 0,0);
	reservedWords[37].set("CLRB", KEYWORDS, 0,0, 0,0, 0,0, 0,0, 0x5f,1, 0,0);
	reservedWords[38].set("CLV",  KEYWORDS, 0,0, 0,0, 0,0, 0,0, 0x0a,1, 0,0);
	reservedWords[39].set("CMPA", KEYWORDS, 0x81,2, 0x91,2, 0xa1,2, 0xb1,3, 0,0, 0,0);
	reservedWords[40].set("CMPB", KEYWORDS, 0xc1,2, 0xd1,2, 0xe1,2, 0xf1,3, 0,0, 0,0);
	reservedWords[41].set("COM",  KEYWORDS, 0,0, 0,0, 0x63,2, 0x73,3, 0,0, 0,0);
	reservedWords[42].set("COMA", KEYWORDS, 0,0, 0,0, 0,0, 0,0, 0x43,1, 0,0);
	reservedWords[43].set("COMB", KEYWORDS, 0,0, 0,0, 0,0, 0,0, 0x53,1, 0,0);
	reservedWords[44].set("CPX",  KEYWORDS, 0x8c,3, 0x9c,2, 0xac,2, 0xbc,3, 0,0, 0,0);

	reservedWords[45].set("DAA",  KEYWORDS, 0,0, 0,0, 0,0, 0,0, 0x19,1, 0,0);
	reservedWords[46].set("DEC",  KEYWORDS, 0,0, 0,0, 0x6a,2, 0x7a,3, 0,0, 0,0);
	reservedWords[47].set("DECA", KEYWORDS, 0,0, 0,0, 0,0, 0,0, 0x4a,1, 0,0);
	reservedWords[48].set("DECB", KEYWORDS, 0,0, 0,0, 0,0, 0,0, 0x5a,1, 0,0);
	reservedWords[49].set("DES",  KEYWORDS, 0,0, 0,0, 0,0, 0,0, 0x34,1, 0,0);
	reservedWords[50].set("DEX",  KEYWORDS, 0,0, 0,0, 0,0, 0,0, 0x09,1, 0,0);

	reservedWords[51].set("EORA", KEYWORDS, 0x88,2, 0x98,2, 0xa8,2, 0xb8,3, 0,0, 0,0);
	reservedWords[52].set("EORB", KEYWORDS, 0xc8,2, 0xd8,2, 0xe8,2, 0xf8,3, 0,0, 0,0);

	reservedWords[53].set("FCB", KEYWORDS, 0,0, 0,0, 0,0, 0,0, 0x00,1, 0,0);

	reservedWords[54].set("INC",  KEYWORDS, 0,0, 0,0, 0x6c,2, 0x7c,3, 0,0, 0,0);
	reservedWords[55].set("INCA", KEYWORDS, 0,0, 0,0, 0,0, 0,0, 0x4c,1, 0,0);
	reservedWords[56].set("INCB", KEYWORDS, 0,0, 0,0, 0,0, 0,0, 0x5c,1, 0,0);
	reservedWords[57].set("INS",  KEYWORDS, 0,0, 0,0, 0,0, 0,0, 0x31,1, 0,0);
	reservedWords[58].set("INX",  KEYWORDS, 0,0, 0,0, 0,0, 0,0, 0x08,1, 0,0);

	reservedWords[59].set("JMP",  KEYWORDS, 0,0, 0,0, 0,0, 0,0, 0,0, 0x7e,3);
	reservedWords[60].set("JSR",  KEYWORDS, 0,0, 0,0, 0,0, 0,0, 0,0, 0xbd,3);

	reservedWords[61].set("LDAA", KEYWORDS, 0x86,2, 0x96,2, 0xa6,2, 0xb6,3, 0,0, 0,0);
	reservedWords[62].set("LDAB", KEYWORDS, 0xc6,2, 0xd6,2, 0xe6,2, 0xf6,3, 0,0, 0,0);
	reservedWords[63].set("LDS",  KEYWORDS, 0x8e,3, 0x9e,2, 0xae,2, 0xbe,3, 0,0, 0,0);
	reservedWords[64].set("LDX",  KEYWORDS, 0xce,3, 0xde,2, 0xee,2, 0xfe,3, 0,0, 0,0);
	reservedWords[65].set("LSR",  KEYWORDS, 0,0, 0,0, 0x64,2, 0x74,3, 0,0, 0,0);
	reservedWords[66].set("LSRA", KEYWORDS, 0,0, 0,0, 0,0, 0,0, 0x44,1, 0,0);
	reservedWords[67].set("LSRB", KEYWORDS, 0,0, 0,0, 0,0, 0,0, 0x54,1, 0,0);

	reservedWords[68].set("NEG",  KEYWORDS, 0,0, 0,0, 0x60,2, 0x70,3, 0,0, 0,0);
	reservedWords[69].set("NEGA", KEYWORDS, 0,0, 0,0, 0,0, 0,0, 0x40,1, 0,0);
	reservedWords[70].set("NEGB", KEYWORDS, 0,0, 0,0, 0,0, 0,0, 0x50,1, 0,0);
	reservedWords[71].set("NOP",  KEYWORDS, 0,0, 0,0, 0,0, 0,0, 0x01,1, 0,0);

	reservedWords[72].set("ORAA", KEYWORDS, 0x8a,2, 0x9a,2, 0xaa,2, 0xba,3, 0,0, 0,0);
	reservedWords[73].set("ORAB", KEYWORDS, 0xca,2, 0xda,2, 0xea,2, 0xfa,3, 0,0, 0,0);

	reservedWords[74].set("PSHA", KEYWORDS, 0,0, 0,0, 0,0, 0,0, 0x36,1, 0,0);
	reservedWords[75].set("PSHB", KEYWORDS, 0,0, 0,0, 0,0, 0,0, 0x37,1, 0,0);
	reservedWords[76].set("PULA", KEYWORDS, 0,0, 0,0, 0,0, 0,0, 0x32,1, 0,0);
	reservedWords[77].set("PULB", KEYWORDS, 0,0, 0,0, 0,0, 0,0, 0x33,1, 0,0);

	reservedWords[78].set("ROL",  KEYWORDS, 0,0, 0,0, 0x69,2, 0x79,3, 0,0, 0,0);
	reservedWords[79].set("ROLA", KEYWORDS, 0,0, 0,0, 0,0, 0,0, 0x49,1, 0,0);
	reservedWords[80].set("ROLB", KEYWORDS, 0,0, 0,0, 0,0, 0,0, 0x59,1, 0,0);
	reservedWords[81].set("ROR",  KEYWORDS, 0,0, 0,0, 0x66,2, 0x76,3, 0,0, 0,0);
	reservedWords[82].set("RORA", KEYWORDS, 0,0, 0,0, 0,0, 0,0, 0x46,1, 0,0);
	reservedWords[83].set("RORB", KEYWORDS, 0,0, 0,0, 0,0, 0,0, 0x56,1, 0,0);
	reservedWords[84].set("RTI",  KEYWORDS, 0,0, 0,0, 0,0, 0,0, 0x3b,1, 0,0);
	reservedWords[85].set("RTS",  KEYWORDS, 0,0, 0,0, 0,0, 0,0, 0x39,1, 0,0);

	reservedWords[86].set("SBA",  KEYWORDS, 0,0, 0,0, 0,0, 0,0, 0x10,1, 0,0);
	reservedWords[87].set("SBCA", KEYWORDS, 0x82,2, 0x92,2, 0xa2,2, 0xb2,3, 0,0, 0,0);
	reservedWords[88].set("SBCB", KEYWORDS, 0xc2,2, 0xd2,2, 0xe2,2, 0xf2,3, 0,0, 0,0);
	reservedWords[89].set("SEC",  KEYWORDS, 0,0, 0,0, 0,0, 0,0, 0x0d,1, 0,0);
	reservedWords[90].set("SEI",  KEYWORDS, 0,0, 0,0, 0,0, 0,0, 0x0f,1, 0,0);
	reservedWords[91].set("SEV",  KEYWORDS, 0,0, 0,0, 0,0, 0,0, 0x0b,1, 0,0);
	reservedWords[92].set("STAA", KEYWORDS, 0,0, 0x97,2, 0xa7,2, 0xb7,3, 0,0, 0,0);
	reservedWords[93].set("STAB", KEYWORDS, 0,0, 0xd7,2, 0xe7,2, 0xf7,3, 0,0, 0,0);
	reservedWords[94].set("STS",  KEYWORDS, 0,0, 0x9f,2, 0xaf,2, 0xbf,3, 0,0, 0,0);
	reservedWords[95].set("STX",  KEYWORDS, 0,0, 0xdf,2, 0xef,2, 0xff,3, 0,0, 0,0);
	reservedWords[96].set("SUBA", KEYWORDS, 0x80,2, 0x90,2, 0xa0,2, 0xb0,3, 0,0, 0,0);
	reservedWords[97].set("SUBB", KEYWORDS, 0xc0,2, 0xd0,2, 0xe0,2, 0xf0,3, 0,0, 0,0);
	reservedWords[98].set("SWI",  KEYWORDS, 0,0, 0,0, 0,0, 0,0, 0x3f,1, 0,0);

	reservedWords[99].set("TAB",  KEYWORDS, 0,0, 0,0, 0,0, 0,0, 0x16,1, 0,0);
	reservedWords[100].set("TAC",  KEYWORDS, 0,0, 0,0, 0,0, 0,0, 0x06,1, 0,0);
	reservedWords[101].set("TBA",  KEYWORDS, 0,0, 0,0, 0,0, 0,0, 0x17,1, 0,0);
	reservedWords[102].set("TST",  KEYWORDS, 0,0, 0,0, 0x6d,2, 0x7d,3, 0,0, 0,0);
	reservedWords[103].set("TSTA", KEYWORDS, 0,0, 0,0, 0,0, 0,0, 0x4d,1, 0,0);
	reservedWords[104].set("TSTB", KEYWORDS, 0,0, 0,0, 0,0, 0,0, 0x5d,1, 0,0);
	reservedWords[105].set("TSX",  KEYWORDS, 0,0, 0,0, 0,0, 0,0, 0x30,1, 0,0);
	reservedWords[106].set("TXS",  KEYWORDS, 0,0, 0,0, 0,0, 0,0, 0x35,1, 0,0);

	reservedWords[107].set("WAI",  KEYWORDS, 0,0, 0,0, 0,0, 0,0, 0x3e,1, 0,0);


    BaseAddress = 0xE000;
    DebugAddress = 0xC000;
    DebugMode = false;
    CurrentAddress = 0;
    linepos = 0;
    bufsize = 0;
    lineno = 0;

    TokenPos = 0;
    CodeError = 0;
    TotalSize = 0;
}

TAsmAnalyze::~TAsmAnalyze()
{
    SourceFile.close();
    DestFile.close();
}

bool TAsmAnalyze::Open(String Name)
{
    SourceFile.open(Name.c_str(),std::ios_base::in);    // declare input streams
    return true;
}

bool TAsmAnalyze::Make(String Name, TListView *Box)
{
    DestFileName = Name;
    DestFile.open(Name.c_str(),std::ios_base::out | std::ios_base::binary);    // declare input and output streams

	pHash = new HashTable;
    IDList = new TStringList;
    //IDList = new TList;

    ErrorList = Box;

	Analyze();

	AnalyzeCode();

    if (CodeError == 0) LinkCode();

    delete IDList;
    //delete IDList;
	delete pHash;

    return true;
}


/* getNextChar fetches the next non-blank character
 * from lineBuf, reading in a new line if lineBuf is
 * exhausted
 */
char TAsmAnalyze::getNextChar(void)
{
	//int Temp;

	if (linepos >= bufsize)
	{
		lineno++;
		if (SourceFile.getline(lineBuf, BUFLEN - 1,'\n'))
		{
			//Source.seekg(1,ios::cur);
			bufsize = strlen(lineBuf);
			lineBuf[bufsize]='\n';
			lineBuf[bufsize+1]=0;
			bufsize++;
            //DestFile.write("PineBuf",6);
            //DestFile<<lineBuf;
			//cout<<lineno<<": "<<lineBuf;
			//Temp=getch();
			//if (Temp==27) exit(0);
			linepos = 0;
			TokenPos = 0;
			return toupper(lineBuf[linepos++]);
		}
		else
		{
			return EOF;
		}
	}
	else
	{
		return toupper(lineBuf[linepos++]);
	}
}

/* ungetNextChar backtracks one character in lineBuf */
void TAsmAnalyze::ungetNextChar(void)
{
	linepos--;
}


/* lookup an identifier to see if it is a reserved word */
AsmTokenType TAsmAnalyze::reservedLookup(String &s)
{
	int i;

	for (i = 0; i < MAXRESERVED; i++)
		if (s == reservedWords[i].str)
		{
			CurrentKeyWords=i;
			return reservedWords[i].tok;
		}

	return ID;
}

/* the primary function of the scanner */

/* function getToken returns the
 * next token in source file
 */
AsmTokenType TAsmAnalyze::getToken(void)
{
	int tokenStrIdx = 0;		/* index for storing into tokenString */
    tokenString = "";
	AsmTokenType curToken;			/* holds current token to be returned */
	StateType state = START;	/* current state - always begins at START */
	int save;					/* flag to indicate save to tokenString */

	//linepos=0;
	//bufsize=0;
	//cout<<linepos<<endl;
	while (state != DONE)
	{
		char c = getNextChar();

		save = TRUE;
		switch (state)
		{
			case START:
				 if (IsName(c))        // Is Name
   					  state = INID;
				 else if (isdigit(c))    // Is Hex Number
					  state = INHEXNUM;
				 else if (c == '#')
					  state = INSHARP;
				 else if (c == ',')
					  state = INXCHAR;
				 else if ((c == ' ') || (c == '\t'))
					  save = FALSE;
				 else if (c == '[')
                 {
                      save = FALSE;
					  state = INSTRING;
                 }
				 else if (c == '{')
				 {
					  save = FALSE;
					  state = INCOMMENT;
				 }
				 else if (c == ';')
				 {
					  save = FALSE;
					  state = INCOMMENT_SINGLE;
				 }
				 else
				 {
					  state = DONE;
					  switch (c)
					  {
						case EOF:
							save = FALSE;
							curToken = ENDFILE;
						break;
						case ':':
							curToken = COLON;
						break;
						case '=':
							curToken = EQUAL;
						break;
						case '@':
							curToken = ATCHAR;
						break;
						case '\n':
							curToken = ENDLINE;
						break;
						default:
							curToken = TOKENERROR;
					  }
				 }
			break;

			case INCOMMENT:
				save = FALSE;
                if (c == EOF)
                    state = DONE;
				else if (c == '}')
					state = START;
			break;

			case INCOMMENT_SINGLE:
				save = FALSE;
				if (c == '\n')
				{
                	state = DONE;
 				    curToken = ENDLINE;
                }
			break;

			case INXCHAR:
				state = DONE;
				if (c == 'X')
					curToken = XCHAR;
				else
				{
					ungetNextChar();	/* backup in the input */
					save = FALSE;
					curToken = TOKENERROR;
				}
			break;

			case INSHARP:
				if (!isxdigit(c))
				{
					ungetNextChar();	/* backup in the input */
					save = FALSE;
					state = DONE;
                    if (tokenStrIdx > 1)
					    curToken = SHARP;
                    else
					    curToken = TOKENERROR;
				}
			break;

			case INSTRING:
                save = TRUE;
				if (c == ']')
                {
					ungetNextChar();	/* backup in the input */
					save = FALSE;
					state = DONE;
                    curToken = STRING;
                }
			break;

			case INID:
				if (!IsName(c) && !isdigit(c))
				{
					ungetNextChar();	/* backup in the input */
					save = FALSE;
					state = DONE;
					curToken = ID;
				}
			break;

			case INHEXNUM:
				if (!isxdigit(c))
				{
					ungetNextChar();	/* backup in the input */
					save = FALSE;
					state = DONE;
					curToken = HEXNUM;
				}
			break;

			case DONE:
			default:
				//cout<<"Scanner Bug: state= "<<state<<endl;
				state = DONE;
				curToken = TOKENERROR;
			break;
		}
		if ((save) && (tokenStrIdx <= MAXTOKENLEN))
		{
			//tokenString[tokenStrIdx++] = c;
            tokenString+=c;
            tokenStrIdx++;
			//cout<<tokenStrIdx<<" "<<c<<"\n";
		}

		if (state == DONE)
		{
			//tokenString[tokenStrIdx++] = '\0';
			if (curToken == ID) curToken = reservedLookup(tokenString);
			/*if (curToken == ID)
			{
				if (IsHex(tokenString))
					curToken = HEXNUM;
				else
					curToken = ID;
			}*/
		}
	}

	TokenPos++;
	//cout<<"\t"<<lineno<<": ";
	//cout<<tokenString<<" "<<TokenPos<<endl;
	//printToken(curToken, tokenString);

	CurrentToken = curToken;
	return curToken;
}

int TAsmAnalyze::HexStr2Int(String &str)
{
	int i,j;
	long k;
	int Length;
	long int IntValue=0;
	char c;

	Length = str.Length();

	for (i=0;i<Length;i++)
	{
		k=1;
		for (j=1;j<(Length-i);j++) k*=16;
		c=toupper(str[i+1]);
		if (isdigit(c))
		{
			IntValue+=(c-48)*k;
		}
		if (c>='A' && c<='F')
		{
			IntValue+=(c-55)*k;
		}
	}

	return IntValue;
}

int TAsmAnalyze::IsHex(String &str)
{
	int Length;
	int i,j=0;

	Length = str.Length();
	if (str[1] == '#') j=1;
	for (i=j;i<Length;i++)
	{
		if (!isxdigit(str[i+1])) return 0;
	}
	return 1;
}

void TAsmAnalyze::Analyze(void)
{
	AsmTokenType Token = TOKENERROR;
	AsmTokenType TokenTemp;
	String TokenID;
    int TempHex;

	pHash = new HashTable;

	while (Token!=ENDFILE)
	{
		Token=getToken();
		if (Token==ENDFILE) break;
		//cout<<"Debug: "<<tokenString<<endl;

		if (TokenPos == 1)
		{
			switch (Token)
			{
				case KEYWORDS:
					AnalyzeStatement(CurrentKeyWords);
					// 转到相应处理函数。
				break;

				case ID:
					TokenID = tokenString;
                    TokenTemp = getToken();
					if (TokenTemp == COLON)
					{
						// 发现一个相对地址标示符，存储到符号表中。
						//cout<<"ID - "<<TokenID<<" - "<<hex<<(unsigned int)(BaseAddress+CurrentAddress)<<endl;
						if (!pHash->insert(TokenID,CurrentAddress,true))
						{
							//cout<<"ID Existed!"<<endl;
                            FoundError(ID_DEFINED,lineno,"标示符已存在！");
						}
						//if (getToken()==ENDLINE) break;
						getToken();
						AnalyzeStatement(CurrentKeyWords);
						//cout<<lineno;
						// 转到相应处理函数。
					}
					else if (TokenTemp == EQUAL)
                    {
                        getToken();
                        if (IsHex(tokenString))
                        {
                            // 发现一个绝对标示符，存储到符号表中。
                            if (DebugMode)
                                TempHex = HexStr2Int(tokenString) - DebugAddress;
                            else
                                TempHex = HexStr2Int(tokenString);
                            if (!pHash->insert(TokenID, TempHex, false))
                            {
                                //cout<<"ID Existed!"<<endl;
                                FoundError(ID_DEFINED,lineno,"标示符已存在！");
                            }
                        }
                        else
                        {
                            FoundError(SYNTAX_ERROR,lineno,"语法错误！");
                            //cout<<"Line Error - "<<lineno<<endl;
                        }
                    }
                    else
					{
                        FoundError(SYNTAX_ERROR,lineno,"语法错误！");
						//cout<<"Line Error - "<<lineno<<endl;
					}

				break;

				case ATCHAR:
                    TokenTemp = getToken();
                    if (TokenTemp == TOKENERROR)
                    {
                        FoundError(SYNTAX_ERROR,lineno,"语法错误！");
                    }
                    else if (TokenTemp == STRING)
                    {
                        LinkFileName = tokenString;
                    }
                    else if (TokenTemp == SHARP && IsHex(tokenString))
					{
						// 设置调试模式
                        DebugMode = true;
						// 设置起始地址
                        BaseAddress = HexStr2Int(tokenString);
					}
                    else if (IsHex(tokenString))
					{
						// 设置起始地址
                        BaseAddress = HexStr2Int(tokenString);
					}
                    else
					{
                        FoundError(SYNTAX_ERROR,lineno,"语法错误！");
						//cout<<"Line Error - "<<lineno<<endl;
					}
				break;

				case ENDLINE:
				break;

				default:
                    FoundError(SYNTAX_ERROR,lineno,"语法错误！");
    				//cout<<"Line Error - "<<lineno<<endl;
			}
		}
	}

    // 获取本次汇编的字节数
    TotalSize = CurrentAddress;
}

void TAsmAnalyze::AnalyzeStatement(int KeyWords)
{
	unsigned char HexCode;
	int HexData;
	String NameID;

	int i;
	int TempHex;
	AsmTokenType Token = TOKENERROR;
	int AddressMode,Bytes;
	int LastPos;
	int Error;

	//reservedLookup(TokenString);
	//cout<<KeyWords<<" - "<<TokenString<<" - "<<CurrentKeyWords<<endl;
    if (CurrentToken == ENDLINE) return;
	if (CurrentToken != KEYWORDS)
	{
        FoundError(SYNTAX_ERROR,lineno,"语法错误！");
		return;
	}

	i = 0;
    Error = 0;
    Bytes = 0;
	while (Token != ENDLINE && Error == 0)
	{
		Token=getToken();
		i++;
        if (Bytes > 0 && Token != ENDLINE)  // 已经处理过了
        {
            Error = 1;
            break;
        }
		//cout<<Token<<" ";
		switch (Token)
		{
			case SHARP:
                if (tokenString == "#")
                {
                    Error = 1;
                    break;
                }
				TempHex=HexStr2Int(tokenString);
				if (TempHex>=0x00 && TempHex<=0xff)
				{
					Bytes=2;
					HexData = TempHex;
					AddressMode=1;
				}
				else
				{
					if (TempHex>0xff && TempHex<=0xffff)
					{
						Bytes=3;
						HexData = TempHex;
						AddressMode=1;
					}
					else
					{
						Error = 1;
					}
				}
				//cout<<Bytes<<endl;
			break;

			case HEXNUM:
				TempHex=HexStr2Int(tokenString);
				if (TempHex>=0x00 && TempHex<=0xff)
				{
					Bytes=2;
					HexData = TempHex;
					LastPos=linepos;
					if (getToken()==XCHAR)
					{
						AddressMode=3;
						//cout<<Mode<<" "<<lineno<<endl;
					}
					else
					{
						linepos=LastPos;
						AddressMode=2;
					}
					//cout<<Mode;
				}
				else
				{
					if (TempHex>0xff && TempHex<=0xffff)
					{
						Bytes=3;
						HexData = TempHex;
						AddressMode=4;
					}
					else
					{
						Error = 1;
					}
				}
			break;

			case ID:
				if (reservedWords[KeyWords].Mode[5].Code != 0)
				{
					Bytes = reservedWords[KeyWords].Mode[5].Bytes;
					AddressMode = 6;
					NameID = tokenString;
				}
				else
				{
					if (IsHex(tokenString))
					{
						TempHex=HexStr2Int(tokenString);
						if (TempHex>=0x00 && TempHex<=0xff)
						{
							Bytes=2;
							HexData = TempHex;
							LastPos=linepos;
							if (getToken()==XCHAR)
							{
								AddressMode=3;
								//cout<<Mode<<" "<<lineno<<endl;
							}
							else
							{
								linepos=LastPos;
								AddressMode=2;
							}
							//cout<<Mode;
						}
						else
						{
							if (TempHex>0xff && TempHex<=0xffff)
							{
								Bytes=3;
								HexData = TempHex;
								AddressMode=4;
							}
							else
							{
								Error = 1;
							}
						}
					}
					else
					{
						Error = 1;
					}
				}
			break;

			case ENDLINE:
				if (i==1)
				{
					AddressMode = 5;
					HexData = 0;
					Bytes = 1;
				}
				//cout<<"End Line"<<endl;
			break;

			default:
				Error = 1;
                FoundError(SYNTAX_ERROR,lineno,"语法错误！");
				//cout<<"Error -- "<<tokenString<<endl;
			break;
		}
	}

	if (Error==1)
	{
        FoundError(SYNTAX_ERROR,lineno,"语法错误！");
		//cout<<"Error -- "<<lineno<<endl;
		return;
	}

	//if ((reservedWords[KeyWords].Mode[5].Code != 0) && (AddressMode == 2))
	//{
	//	AddressMode=6;
	//}

	if ((reservedWords[KeyWords].Mode[AddressMode-1].Bytes == 3) && (Bytes == 2))
	{
		Bytes = 3;
	}

	if ((reservedWords[KeyWords].Mode[1].Code == 0) && (reservedWords[KeyWords].Mode[3].Code != 0) && (Bytes == 2))
	{
		AddressMode = 4;
		Bytes = 3;
	}

	if ((AddressMode == 2) && (Bytes == 2) && (reservedWords[KeyWords].Mode[4].Code == 0) && (reservedWords[KeyWords].Mode[4].Bytes == 1))
    {
        Bytes = 1;
    }
    else if ((reservedWords[KeyWords].Mode[AddressMode-1].Code == 0)
             || (reservedWords[KeyWords].Mode[AddressMode-1].Bytes != Bytes))
	{
        FoundError(SYNTAX_ERROR,lineno,"语法错误！");
		//cout<<"Line: "<<lineno<<"  Don't Addressing!"<<endl;
		return;
	}

	HexCode = reservedWords[KeyWords].Mode[AddressMode-1].Code;
	
    // 特殊寻址则不写指令代码
    if ((reservedWords[KeyWords].Mode[4].Code != 0) || (reservedWords[KeyWords].Mode[4].Bytes != 1))
        DestFile.put(HexCode);

	switch (Bytes)
	{
        case 1:
            if ((reservedWords[KeyWords].Mode[4].Code == 0) && (reservedWords[KeyWords].Mode[4].Bytes == 1))
                DestFile.put(HexData);
        break;
		case 2:
			if (reservedWords[KeyWords].Mode[5].Code != 0)
			{
				// 执行相对转移
                DestFile.put(0);
                IDListStruct *Address = new IDListStruct(CurrentAddress,lineno);
                IDList->AddObject(NameID, Address);
                //IDList->Add(Address);
 				//cout<<NameID<<endl;
			}
			else
			{
                DestFile.put(HexData);
                //DestFile.put(HexData);
				//cout<<HexData<<endl;
			}
		break;
		case 3:
			if (reservedWords[KeyWords].Mode[5].Code != 0)
			{
				// 执行绝对转移
                DestFile.put(0);
                DestFile.put(0);
                IDListStruct *Address = new IDListStruct(CurrentAddress,lineno);
                Address->Relative = false;
                IDList->AddObject(NameID, Address);
                //IDList->Add(Address);
 				//cout<<NameID<<endl;
			}
            else
            {
                if (HexData <= 0xff)
                {
                    DestFile.put(0);
                    DestFile.put(HexData);
                    //cout<<"00 "<<HexData<<endl;
                }
                else
                {
                    DestFile.put(HexData/0x100);
                    DestFile.put(HexData & 0xff);
                    //cout<<(HexData/0x100)<<" "<<(HexData & 0xff)<<endl;
                }
            }
		break;
		//default:
			//cout<<endl;
	}

	CurrentAddress += Bytes;
}

void TAsmAnalyze::AnalyzeCode(void)
{
    String ID;
    int i;
    int Address;
    int SourceAddress;
    int DestAddress;
    bool bRelativeMode;
    int Temp;
    int ListCount;
    IDListStruct *List;

    ListCount = IDList->Count;

    for (i=0;i<ListCount;i++)
    {
        //IDStrList->
        List = dynamic_cast<IDListStruct *>(IDList->Objects[i]);
        ID = IDList->Strings[i];
        
        Temp = pHash->lookup(ID, bRelativeMode);
        
        if (Temp == -1)
        {
            FoundError(ID_NOFOUND, List->Line, "标示符未找到！-- '"+ID+"'");
            // Error!!
        }
        else
        {
            SourceAddress = List->Address;
            DestAddress = Temp;
            // 标示符列表
            if (List->Relative)
            {
                if (!bRelativeMode)
                {
                    FoundError(ADDRESS_ERROR, List->Line, "转移地址错误！请使用相对标示符！");
                    continue;
                }
                Address = DestAddress - (SourceAddress + 2);
                if ((Address >127) || (Address < -128))
                {
                    FoundError(ADDRESS_ERROR, List->Line, "转移地址超出范围！");
                    continue;
                }
                DestFile.seekp(SourceAddress + 1);
                DestFile.put(Address);
            }
            else
            {
                if (bRelativeMode)
                {
                    if (DebugMode)
                        Address = BaseAddress + DestAddress - DebugAddress;
                    else
                        Address = BaseAddress + DestAddress;
                }
                else
                {
                    Address = DestAddress;
                }
                DestFile.seekp(SourceAddress + 1);
                DestFile.put(Address/0x100);
                DestFile.put(Address & 0xff);
            }
        }
    }
}

void __fastcall TAsmAnalyze::FoundError(AsmErrorType Error, int Lineno, String str)
{
    //TODO: Add your source code here
    //ErrorList->AddItem(IntToStr(Lineno) + ": " + str, NULL);
    TListItem *pItem;

    pItem = ErrorList->Items->Add();
    pItem->Caption = IntToStr(Lineno);
    pItem->SubItems->Add(str);

    CodeError++;
}

void TAsmAnalyze::LinkCode(void)
{
    //TODO: Add your source code here
    std::ifstream in;
    char *Buffers;

    DestFile.close();

    Buffers = new char[TotalSize+1];

    if (Buffers == NULL)
    {
        FoundError(LINK_ERROR, 0, "连接错误！缓冲区错误！");
        return;
    }

    if (ExtractFilePath(LinkFileName) == "")
    {
        LinkFileName = ExtractFilePath(DestFileName) + LinkFileName;
    }
    if (!FileExists(LinkFileName))
    {
        FoundError(LINK_ERROR, 0, "连接错误！文件没找到！-- "+LinkFileName);
        return;
    }

    LinkFile.open(LinkFileName.c_str(),std::ios_base::out | std::ios_base::in | std::ios_base::binary);
    in.open(DestFileName.c_str() ,std::ios_base::in | std::ios_base::binary);
    if (!in.is_open() || !LinkFile.is_open())
    {
        FoundError(LINK_ERROR, 0, "连接错误！无法打开文件！");
        return;
    }

    LinkFile.seekp(BaseAddress - (int)0xE000);
    in.read(Buffers, TotalSize);
    LinkFile.write(Buffers, TotalSize);

    //LinkFile.close();
    //in.close();

    delete Buffers;
}

bool inline __fastcall TAsmAnalyze::IsName(unsigned char c)
{
    //TODO: Add your source code here
    return (((c>='a') && (c<='z'))
		    || ((c>='A') && (c<='Z'))
		    || (c=='_')
		    || ((c>=0xA1) && (c<=0xFE)));
}


// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Syn68AsmSyn.pas' rev: 6.00

#ifndef Syn68AsmSynHPP
#define Syn68AsmSynHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <SynEditHighlighter.hpp>	// Pascal unit
#include <SynEditTypes.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Syn68asmsyn
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TtkTokenKind { tkBaseAddress, tkComment, tkIdentifier, tkKey, tkNull, tkNumber, tkSpace, tkString, tkUnknown, tkXChar };
#pragma option pop

#pragma option push -b-
enum TRangeState { rsUnKnown, rsBraceComment, rsSingleComment, rsString };
#pragma option pop

typedef void __fastcall (__closure *TProcTableProc)(void);

typedef TtkTokenKind __fastcall (__closure *TIdentFuncTableFunc)(void);

typedef TIdentFuncTableFunc *PIdentFuncTableFunc;

class DELPHICLASS TSyn68AsmSyn;
class PASCALIMPLEMENTATION TSyn68AsmSyn : public Synedithighlighter::TSynCustomHighlighter 
{
	typedef Synedithighlighter::TSynCustomHighlighter inherited;
	
private:
	char *fLine;
	int fLineNumber;
	TProcTableProc fProcTable[256];
	TRangeState fRange;
	int Run;
	int fStringLen;
	char *fToIdent;
	int fTokenPos;
	TtkTokenKind fTokenID;
	TIdentFuncTableFunc fIdentFuncTable[64];
	Synedithighlighter::TSynHighlighterAttributes* fBaseAddressAttri;
	Synedithighlighter::TSynHighlighterAttributes* fCommentAttri;
	Synedithighlighter::TSynHighlighterAttributes* fIdentifierAttri;
	Synedithighlighter::TSynHighlighterAttributes* fKeyAttri;
	Synedithighlighter::TSynHighlighterAttributes* fNumberAttri;
	Synedithighlighter::TSynHighlighterAttributes* fSpaceAttri;
	Synedithighlighter::TSynHighlighterAttributes* fStringAttri;
	Synedithighlighter::TSynHighlighterAttributes* fXCharAttri;
	int __fastcall KeyHash(char * ToHash);
	bool __fastcall KeyComp(const AnsiString aKey);
	TtkTokenKind __fastcall Func4(void);
	TtkTokenKind __fastcall Func6(void);
	TtkTokenKind __fastcall Func8(void);
	TtkTokenKind __fastcall Func9(void);
	TtkTokenKind __fastcall Func10(void);
	TtkTokenKind __fastcall Func11(void);
	TtkTokenKind __fastcall Func12(void);
	TtkTokenKind __fastcall Func13(void);
	TtkTokenKind __fastcall Func14(void);
	TtkTokenKind __fastcall Func18(void);
	TtkTokenKind __fastcall Func19(void);
	TtkTokenKind __fastcall Func20(void);
	TtkTokenKind __fastcall Func21(void);
	TtkTokenKind __fastcall Func22(void);
	TtkTokenKind __fastcall Func23(void);
	TtkTokenKind __fastcall Func24(void);
	TtkTokenKind __fastcall Func25(void);
	TtkTokenKind __fastcall Func26(void);
	TtkTokenKind __fastcall Func27(void);
	TtkTokenKind __fastcall Func28(void);
	TtkTokenKind __fastcall Func29(void);
	TtkTokenKind __fastcall Func30(void);
	TtkTokenKind __fastcall Func31(void);
	TtkTokenKind __fastcall Func32(void);
	TtkTokenKind __fastcall Func33(void);
	TtkTokenKind __fastcall Func34(void);
	TtkTokenKind __fastcall Func35(void);
	TtkTokenKind __fastcall Func36(void);
	TtkTokenKind __fastcall Func37(void);
	TtkTokenKind __fastcall Func38(void);
	TtkTokenKind __fastcall Func39(void);
	TtkTokenKind __fastcall Func40(void);
	TtkTokenKind __fastcall Func41(void);
	TtkTokenKind __fastcall Func42(void);
	TtkTokenKind __fastcall Func43(void);
	TtkTokenKind __fastcall Func44(void);
	TtkTokenKind __fastcall Func45(void);
	TtkTokenKind __fastcall Func46(void);
	TtkTokenKind __fastcall Func47(void);
	TtkTokenKind __fastcall Func49(void);
	TtkTokenKind __fastcall Func50(void);
	TtkTokenKind __fastcall Func51(void);
	TtkTokenKind __fastcall Func52(void);
	TtkTokenKind __fastcall Func53(void);
	TtkTokenKind __fastcall Func57(void);
	TtkTokenKind __fastcall Func58(void);
	TtkTokenKind __fastcall Func59(void);
	TtkTokenKind __fastcall Func60(void);
	TtkTokenKind __fastcall Func61(void);
	TtkTokenKind __fastcall Func63(void);
	void __fastcall BaseAddressProc(void);
	void __fastcall IdentProc(void);
	void __fastcall NumberProc(void);
	void __fastcall XCharProc(void);
	void __fastcall UnknownProc(void);
	TtkTokenKind __fastcall AltFunc(void);
	void __fastcall InitIdent(void);
	TtkTokenKind __fastcall IdentKind(char * MayBe);
	void __fastcall MakeMethodTables(void);
	void __fastcall NullProc(void);
	void __fastcall SpaceProc(void);
	void __fastcall CRProc(void);
	void __fastcall LFProc(void);
	void __fastcall BraceCommentOpenProc(void);
	void __fastcall BraceCommentProc(void);
	void __fastcall SingleCommentOpenProc(void);
	void __fastcall SingleCommentProc(void);
	void __fastcall StringOpenProc(void);
	void __fastcall StringProc(void);
	
protected:
	virtual Synedittypes::TSynIdentChars __fastcall GetIdentChars();
	virtual AnsiString __fastcall GetSampleSource();
	virtual bool __fastcall IsFilterStored(void);
	
public:
	__fastcall virtual TSyn68AsmSyn(Classes::TComponent* AOwner);
	/* virtual class method */ virtual AnsiString __fastcall GetLanguageName(TMetaClass* vmt);
	virtual void * __fastcall GetRange(void);
	virtual void __fastcall ResetRange(void);
	virtual void __fastcall SetRange(void * Value);
	virtual Synedithighlighter::TSynHighlighterAttributes* __fastcall GetDefaultAttribute(int Index);
	virtual bool __fastcall GetEol(void);
	AnsiString __fastcall GetKeyWords();
	TtkTokenKind __fastcall GetTokenID(void);
	virtual void __fastcall SetLine(AnsiString NewValue, int LineNumber);
	virtual AnsiString __fastcall GetToken();
	virtual Synedithighlighter::TSynHighlighterAttributes* __fastcall GetTokenAttribute(void);
	virtual int __fastcall GetTokenKind(void);
	virtual int __fastcall GetTokenPos(void);
	virtual void __fastcall Next(void);
	
__published:
	__property Synedithighlighter::TSynHighlighterAttributes* BaseAddressAttri = {read=fBaseAddressAttri, write=fBaseAddressAttri};
	__property Synedithighlighter::TSynHighlighterAttributes* CommentAttri = {read=fCommentAttri, write=fCommentAttri};
	__property Synedithighlighter::TSynHighlighterAttributes* IdentifierAttri = {read=fIdentifierAttri, write=fIdentifierAttri};
	__property Synedithighlighter::TSynHighlighterAttributes* KeyAttri = {read=fKeyAttri, write=fKeyAttri};
	__property Synedithighlighter::TSynHighlighterAttributes* NumberAttri = {read=fNumberAttri, write=fNumberAttri};
	__property Synedithighlighter::TSynHighlighterAttributes* SpaceAttri = {read=fSpaceAttri, write=fSpaceAttri};
	__property Synedithighlighter::TSynHighlighterAttributes* StringAttri = {read=fStringAttri, write=fStringAttri};
	__property Synedithighlighter::TSynHighlighterAttributes* XCharAttri = {read=fXCharAttri, write=fXCharAttri};
public:
	#pragma option push -w-inl
	/* TSynCustomHighlighter.Destroy */ inline __fastcall virtual ~TSyn68AsmSyn(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
static const Shortint MaxKey = 0x3f;

}	/* namespace Syn68asmsyn */
using namespace Syn68asmsyn;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Syn68AsmSyn

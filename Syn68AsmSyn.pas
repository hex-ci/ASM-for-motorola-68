{-------------------------------------------------------------------------------
The contents of this file are subject to the Mozilla Public License
Version 1.1 (the "License"); you may not use this file except in compliance
with the License. You may obtain a copy of the License at
http://www.mozilla.org/MPL/

Software distributed under the License is distributed on an "AS IS" basis,
WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License for
the specific language governing rights and limitations under the License.

Code template generated with SynGen.
The original code is: Syn68AsmSyn.pas, released 2003-03-05.
Description: 68 ª„±‡œµÕ≥
The initial author of this file is ’‘≥©.
Copyright (c) 2003, all rights reserved.

Contributors to the SynEdit and mwEdit projects are listed in the
Contributors.txt file.

Alternatively, the contents of this file may be used under the terms of the
GNU General Public License Version 2 or later (the "GPL"), in which case
the provisions of the GPL are applicable instead of those above.
If you wish to allow use of your version of this file only under the terms
of the GPL and not to allow others to use your version of this file
under the MPL, indicate your decision by deleting the provisions above and
replace them with the notice and other provisions required by the GPL.
If you do not delete the provisions above, a recipient may use your version
of this file under either the MPL or the GPL.

$Id: $

You may retrieve the latest version of this file at the SynEdit home page,
located at http://SynEdit.SourceForge.net

-------------------------------------------------------------------------------}

unit Syn68AsmSyn;

{$I SynEdit.inc}

interface

uses
  SysUtils,
  Classes,
{$IFDEF SYN_CLX}
  QControls,
  QGraphics,
{$ELSE}
  Windows,
  Controls,
  Graphics,
{$ENDIF}
  SynEditTypes,
  SynEditHighlighter;

type
  TtkTokenKind = (
    tkBaseAddress,
    tkComment,
    tkIdentifier,
    tkKey,
    tkNull,
    tkNumber,
    tkSpace,
    tkString,
    tkUnknown,
    tkXChar);

  TRangeState = (rsUnKnown, rsBraceComment, rsSingleComment, rsString);

  TProcTableProc = procedure of object;

  PIdentFuncTableFunc = ^TIdentFuncTableFunc;
  TIdentFuncTableFunc = function: TtkTokenKind of object;

const
  MaxKey = 63;

type
  TSyn68AsmSyn = class(TSynCustomHighlighter)
  private
    fLine: PChar;
    fLineNumber: Integer;
    fProcTable: array[#0..#255] of TProcTableProc;
    fRange: TRangeState;
    Run: LongInt;
    fStringLen: Integer;
    fToIdent: PChar;
    fTokenPos: Integer;
    fTokenID: TtkTokenKind;
    fIdentFuncTable: array[0 .. MaxKey] of TIdentFuncTableFunc;
    fBaseAddressAttri: TSynHighlighterAttributes;
    fCommentAttri: TSynHighlighterAttributes;
    fIdentifierAttri: TSynHighlighterAttributes;
    fKeyAttri: TSynHighlighterAttributes;
    fNumberAttri: TSynHighlighterAttributes;
    fSpaceAttri: TSynHighlighterAttributes;
    fStringAttri: TSynHighlighterAttributes;
    fXCharAttri: TSynHighlighterAttributes;
    function KeyHash(ToHash: PChar): Integer;
    function KeyComp(const aKey: string): Boolean;
    function Func4: TtkTokenKind;
    function Func6: TtkTokenKind;
    function Func8: TtkTokenKind;
    function Func9: TtkTokenKind;
    function Func10: TtkTokenKind;
    function Func11: TtkTokenKind;
    function Func12: TtkTokenKind;
    function Func13: TtkTokenKind;
    function Func14: TtkTokenKind;
    function Func18: TtkTokenKind;
    function Func19: TtkTokenKind;
    function Func20: TtkTokenKind;
    function Func21: TtkTokenKind;
    function Func22: TtkTokenKind;
    function Func23: TtkTokenKind;
    function Func24: TtkTokenKind;
    function Func25: TtkTokenKind;
    function Func26: TtkTokenKind;
    function Func27: TtkTokenKind;
    function Func28: TtkTokenKind;
    function Func29: TtkTokenKind;
    function Func30: TtkTokenKind;
    function Func31: TtkTokenKind;
    function Func32: TtkTokenKind;
    function Func33: TtkTokenKind;
    function Func34: TtkTokenKind;
    function Func35: TtkTokenKind;
    function Func36: TtkTokenKind;
    function Func37: TtkTokenKind;
    function Func38: TtkTokenKind;
    function Func39: TtkTokenKind;
    function Func40: TtkTokenKind;
    function Func41: TtkTokenKind;
    function Func42: TtkTokenKind;
    function Func43: TtkTokenKind;
    function Func44: TtkTokenKind;
    function Func45: TtkTokenKind;
    function Func46: TtkTokenKind;
    function Func47: TtkTokenKind;
    function Func49: TtkTokenKind;
    function Func50: TtkTokenKind;
    function Func51: TtkTokenKind;
    function Func52: TtkTokenKind;
    function Func53: TtkTokenKind;
    function Func57: TtkTokenKind;
    function Func58: TtkTokenKind;
    function Func59: TtkTokenKind;
    function Func60: TtkTokenKind;
    function Func61: TtkTokenKind;
    function Func63: TtkTokenKind;
    procedure BaseAddressProc;
    procedure IdentProc;
    procedure NumberProc;
    procedure XCharProc;
    procedure UnknownProc;
    function AltFunc: TtkTokenKind;
    procedure InitIdent;
    function IdentKind(MayBe: PChar): TtkTokenKind;
    procedure MakeMethodTables;
    procedure NullProc;
    procedure SpaceProc;
    procedure CRProc;
    procedure LFProc;
    procedure BraceCommentOpenProc;
    procedure BraceCommentProc;
    procedure SingleCommentOpenProc;
    procedure SingleCommentProc;
    procedure StringOpenProc;
    procedure StringProc;
  protected
    function GetIdentChars: TSynIdentChars; override;
    function GetSampleSource: string; override;
    function IsFilterStored: Boolean; override;
  public
    constructor Create(AOwner: TComponent); override;
    {$IFNDEF SYN_CPPB_1} class {$ENDIF}
    function GetLanguageName: string; override;
    function GetRange: Pointer; override;
    procedure ResetRange; override;
    procedure SetRange(Value: Pointer); override;
    function GetDefaultAttribute(Index: integer): TSynHighlighterAttributes; override;
    function GetEol: Boolean; override;
    function GetKeyWords: string;
    function GetTokenID: TtkTokenKind;
    procedure SetLine(NewValue: String; LineNumber: Integer); override;
    function GetToken: String; override;
    function GetTokenAttribute: TSynHighlighterAttributes; override;
    function GetTokenKind: integer; override;
    function GetTokenPos: Integer; override;
    procedure Next; override;
  published
    property BaseAddressAttri: TSynHighlighterAttributes read fBaseAddressAttri write fBaseAddressAttri;
    property CommentAttri: TSynHighlighterAttributes read fCommentAttri write fCommentAttri;
    property IdentifierAttri: TSynHighlighterAttributes read fIdentifierAttri write fIdentifierAttri;
    property KeyAttri: TSynHighlighterAttributes read fKeyAttri write fKeyAttri;
    property NumberAttri: TSynHighlighterAttributes read fNumberAttri write fNumberAttri;
    property SpaceAttri: TSynHighlighterAttributes read fSpaceAttri write fSpaceAttri;
    property StringAttri: TSynHighlighterAttributes read fStringAttri write fStringAttri;
    property XCharAttri: TSynHighlighterAttributes read fXCharAttri write fXCharAttri;
  end;

implementation

uses
  SynEditStrConst;

{$IFDEF SYN_COMPILER_3_UP}
resourcestring
{$ELSE}
const
{$ENDIF}
  SYNS_Filter = '68 ª„±‡Œƒº˛ (*.asm)|*.asm';
  SYNS_Lang = '68 ª„±‡”Ô—‘';
  SYNS_AttrBaseAddress = 'BaseAddress';
  SYNS_AttrXChar = 'XChar';

var
  Identifiers: array[#0..#255] of ByteBool;
  mHashTable : array[#0..#255] of Integer;

procedure MakeIdentTable;
var
  I, J: Char;
begin
  for I := #0 to #255 do
  begin
    case I of
      '_', 'a'..'z', 'A'..'Z': Identifiers[I] := True;
    else
      Identifiers[I] := False;
    end;
    J := UpCase(I);
    case I in ['_', 'A'..'Z', 'a'..'z'] of
      True: mHashTable[I] := Ord(J) - 64
    else
      mHashTable[I] := 0;
    end;
  end;
end;

procedure TSyn68AsmSyn.InitIdent;
var
  I: Integer;
  pF: PIdentFuncTableFunc;
begin
  pF := PIdentFuncTableFunc(@fIdentFuncTable);
  for I := Low(fIdentFuncTable) to High(fIdentFuncTable) do
  begin
    pF^ := AltFunc;
    Inc(pF);
  end;
  fIdentFuncTable[4] := Func4;
  fIdentFuncTable[6] := Func6;
  fIdentFuncTable[8] := Func8;
  fIdentFuncTable[9] := Func9;
  fIdentFuncTable[10] := Func10;
  fIdentFuncTable[11] := Func11;
  fIdentFuncTable[12] := Func12;
  fIdentFuncTable[13] := Func13;
  fIdentFuncTable[14] := Func14;
  fIdentFuncTable[18] := Func18;
  fIdentFuncTable[19] := Func19;
  fIdentFuncTable[20] := Func20;
  fIdentFuncTable[21] := Func21;
  fIdentFuncTable[22] := Func22;
  fIdentFuncTable[23] := Func23;
  fIdentFuncTable[24] := Func24;
  fIdentFuncTable[25] := Func25;
  fIdentFuncTable[26] := Func26;
  fIdentFuncTable[27] := Func27;
  fIdentFuncTable[28] := Func28;
  fIdentFuncTable[29] := Func29;
  fIdentFuncTable[30] := Func30;
  fIdentFuncTable[31] := Func31;
  fIdentFuncTable[32] := Func32;
  fIdentFuncTable[33] := Func33;
  fIdentFuncTable[34] := Func34;
  fIdentFuncTable[35] := Func35;
  fIdentFuncTable[36] := Func36;
  fIdentFuncTable[37] := Func37;
  fIdentFuncTable[38] := Func38;
  fIdentFuncTable[39] := Func39;
  fIdentFuncTable[40] := Func40;
  fIdentFuncTable[41] := Func41;
  fIdentFuncTable[42] := Func42;
  fIdentFuncTable[43] := Func43;
  fIdentFuncTable[44] := Func44;
  fIdentFuncTable[45] := Func45;
  fIdentFuncTable[46] := Func46;
  fIdentFuncTable[47] := Func47;
  fIdentFuncTable[49] := Func49;
  fIdentFuncTable[50] := Func50;
  fIdentFuncTable[51] := Func51;
  fIdentFuncTable[52] := Func52;
  fIdentFuncTable[53] := Func53;
  fIdentFuncTable[57] := Func57;
  fIdentFuncTable[58] := Func58;
  fIdentFuncTable[59] := Func59;
  fIdentFuncTable[60] := Func60;
  fIdentFuncTable[61] := Func61;
  fIdentFuncTable[63] := Func63;
end;

function TSyn68AsmSyn.KeyHash(ToHash: PChar): Integer;
begin
  Result := 0;
  while ToHash^ in ['_', 'a'..'z', 'A'..'Z'] do
  begin
    inc(Result, mHashTable[ToHash^]);
    inc(ToHash);
  end;
  fStringLen := ToHash - fToIdent;
end;

function TSyn68AsmSyn.KeyComp(const aKey: String): Boolean;
var
  I: Integer;
  Temp: PChar;
begin
  Temp := fToIdent;
  if Length(aKey) = fStringLen then
  begin
    Result := True;
    for i := 1 to fStringLen do
    begin
      if mHashTable[Temp^] <> mHashTable[aKey[i]] then
      begin
        Result := False;
        break;
      end;
      inc(Temp);
    end;
  end
  else
    Result := False;
end;

function TSyn68AsmSyn.Func4: TtkTokenKind;
begin
  if KeyComp('ABA') then Result := tkKey else Result := tkIdentifier;
end;

function TSyn68AsmSyn.Func6: TtkTokenKind;
begin
  if KeyComp('CBA') then Result := tkKey else
    if KeyComp('DAA') then Result := tkKey else Result := tkIdentifier;
end;

function TSyn68AsmSyn.Func8: TtkTokenKind;
begin
  if KeyComp('BCC') then Result := tkKey else Result := tkIdentifier;
end;

function TSyn68AsmSyn.Func9: TtkTokenKind;
begin
  if KeyComp('ADCA') then Result := tkKey else Result := tkIdentifier;
end;

function TSyn68AsmSyn.Func10: TtkTokenKind;
begin
  if KeyComp('ADCB') then Result := tkKey else
    if KeyComp('ADDA') then Result := tkKey else Result := tkIdentifier;
end;

function TSyn68AsmSyn.Func11: TtkTokenKind;
begin
  if KeyComp('FCB') then Result := tkKey else
    if KeyComp('ADDB') then Result := tkKey else Result := tkIdentifier;
end;

function TSyn68AsmSyn.Func12: TtkTokenKind;
begin
  if KeyComp('DEC') then Result := tkKey else Result := tkIdentifier;
end;

function TSyn68AsmSyn.Func13: TtkTokenKind;
begin
  if KeyComp('DECA') then Result := tkKey else Result := tkIdentifier;
end;

function TSyn68AsmSyn.Func14: TtkTokenKind;
begin
  if KeyComp('DECB') then Result := tkKey else
    if KeyComp('BGE') then Result := tkKey else Result := tkIdentifier;
end;

function TSyn68AsmSyn.Func18: TtkTokenKind;
begin
  if KeyComp('LDAA') then Result := tkKey else
    if KeyComp('CLC') then Result := tkKey else Result := tkIdentifier;
end;

function TSyn68AsmSyn.Func19: TtkTokenKind;
begin
  if KeyComp('BHI') then Result := tkKey else
    if KeyComp('LDAB') then Result := tkKey else
      if KeyComp('BLE') then Result := tkKey else Result := tkIdentifier;
end;

function TSyn68AsmSyn.Func20: TtkTokenKind;
begin
  if KeyComp('ANDA') then Result := tkKey else Result := tkIdentifier;
end;

function TSyn68AsmSyn.Func21: TtkTokenKind;
begin
  if KeyComp('BRA') then Result := tkKey else
    if KeyComp('ANDB') then Result := tkKey else
      if KeyComp('BNE') then Result := tkKey else Result := tkIdentifier;
end;

function TSyn68AsmSyn.Func22: TtkTokenKind;
begin
  if KeyComp('SBA') then Result := tkKey else Result := tkIdentifier;
end;

function TSyn68AsmSyn.Func23: TtkTokenKind;
begin
  if KeyComp('TBA') then Result := tkKey else
    if KeyComp('TAB') then Result := tkKey else Result := tkIdentifier;
end;

function TSyn68AsmSyn.Func24: TtkTokenKind;
begin
  if KeyComp('CLI') then Result := tkKey else
    if KeyComp('BEQ') then Result := tkKey else
      if KeyComp('BCS') then Result := tkKey else
        if KeyComp('TAC') then Result := tkKey else
          if KeyComp('BMI') then Result := tkKey else Result := tkIdentifier;
end;

function TSyn68AsmSyn.Func25: TtkTokenKind;
begin
  if KeyComp('SBCA') then Result := tkKey else Result := tkIdentifier;
end;

function TSyn68AsmSyn.Func26: TtkTokenKind;
begin
  if KeyComp('INC') then Result := tkKey else
    if KeyComp('SBCB') then Result := tkKey else
      if KeyComp('NEG') then Result := tkKey else Result := tkIdentifier;
end;

function TSyn68AsmSyn.Func27: TtkTokenKind;
begin
  if KeyComp('INCA') then Result := tkKey else
    if KeyComp('NEGA') then Result := tkKey else
      if KeyComp('BVC') then Result := tkKey else
        if KeyComp('SEC') then Result := tkKey else Result := tkIdentifier;
end;

function TSyn68AsmSyn.Func28: TtkTokenKind;
begin
  if KeyComp('NEGB') then Result := tkKey else
    if KeyComp('INCB') then Result := tkKey else
      if KeyComp('DES') then Result := tkKey else Result := tkIdentifier;
end;

function TSyn68AsmSyn.Func29: TtkTokenKind;
begin
  if KeyComp('BGT') then Result := tkKey else Result := tkIdentifier;
end;

function TSyn68AsmSyn.Func30: TtkTokenKind;
begin
  if KeyComp('BPL') then Result := tkKey else Result := tkIdentifier;
end;

function TSyn68AsmSyn.Func31: TtkTokenKind;
begin
  if KeyComp('COM') then Result := tkKey else Result := tkIdentifier;
end;

function TSyn68AsmSyn.Func32: TtkTokenKind;
begin
  if KeyComp('BITA') then Result := tkKey else
    if KeyComp('ASL') then Result := tkKey else
      if KeyComp('COMA') then Result := tkKey else Result := tkIdentifier;
end;

function TSyn68AsmSyn.Func33: TtkTokenKind;
begin
  if KeyComp('WAI') then Result := tkKey else
    if KeyComp('CLR') then Result := tkKey else
      if KeyComp('BLS') then Result := tkKey else
        if KeyComp('SEI') then Result := tkKey else
          if KeyComp('BITB') then Result := tkKey else
            if KeyComp('DEX') then Result := tkKey else
              if KeyComp('COMB') then Result := tkKey else
                if KeyComp('CMPA') then Result := tkKey else
                  if KeyComp('ASLA') then Result := tkKey else Result := tkIdentifier;
end;

function TSyn68AsmSyn.Func34: TtkTokenKind;
begin
  if KeyComp('CMPB') then Result := tkKey else
    if KeyComp('ASLB') then Result := tkKey else
      if KeyComp('CLRA') then Result := tkKey else
        if KeyComp('BLT') then Result := tkKey else Result := tkIdentifier;
end;

function TSyn68AsmSyn.Func35: TtkTokenKind;
begin
  if KeyComp('LDS') then Result := tkKey else
    if KeyComp('ORAA') then Result := tkKey else
      if KeyComp('CLRB') then Result := tkKey else Result := tkIdentifier;
end;

function TSyn68AsmSyn.Func36: TtkTokenKind;
begin
  if KeyComp('ORAB') then Result := tkKey else Result := tkIdentifier;
end;

function TSyn68AsmSyn.Func37: TtkTokenKind;
begin
  if KeyComp('CLV') then Result := tkKey else Result := tkIdentifier;
end;

function TSyn68AsmSyn.Func38: TtkTokenKind;
begin
  if KeyComp('ATPA') then Result := tkKey else
    if KeyComp('ASR') then Result := tkKey else Result := tkIdentifier;
end;

function TSyn68AsmSyn.Func39: TtkTokenKind;
begin
  if KeyComp('ASRA') then Result := tkKey else
    if KeyComp('EORA') then Result := tkKey else
      if KeyComp('JMP') then Result := tkKey else
        if KeyComp('BSR') then Result := tkKey else Result := tkIdentifier;
end;

function TSyn68AsmSyn.Func40: TtkTokenKind;
begin
  if KeyComp('EORB') then Result := tkKey else
    if KeyComp('ASRB') then Result := tkKey else
      if KeyComp('LDX') then Result := tkKey else Result := tkIdentifier;
end;

function TSyn68AsmSyn.Func41: TtkTokenKind;
begin
  if KeyComp('STAA') then Result := tkKey else Result := tkIdentifier;
end;

function TSyn68AsmSyn.Func42: TtkTokenKind;
begin
  if KeyComp('STAB') then Result := tkKey else
    if KeyComp('INS') then Result := tkKey else Result := tkIdentifier;
end;

function TSyn68AsmSyn.Func43: TtkTokenKind;
begin
  if KeyComp('SUBA') then Result := tkKey else
    if KeyComp('BVS') then Result := tkKey else
      if KeyComp('CPX') then Result := tkKey else Result := tkIdentifier;
end;

function TSyn68AsmSyn.Func44: TtkTokenKind;
begin
  if KeyComp('PSHA') then Result := tkKey else
    if KeyComp('SUBB') then Result := tkKey else Result := tkIdentifier;
end;

function TSyn68AsmSyn.Func45: TtkTokenKind;
begin
  if KeyComp('ROL') then Result := tkKey else
    if KeyComp('PSHB') then Result := tkKey else
      if KeyComp('NOP') then Result := tkKey else Result := tkIdentifier;
end;

function TSyn68AsmSyn.Func46: TtkTokenKind;
begin
  if KeyComp('SEV') then Result := tkKey else
    if KeyComp('ROLA') then Result := tkKey else Result := tkIdentifier;
end;

function TSyn68AsmSyn.Func47: TtkTokenKind;
begin
  if KeyComp('INX') then Result := tkKey else
    if KeyComp('JSR') then Result := tkKey else
      if KeyComp('ROLB') then Result := tkKey else
        if KeyComp('RTI') then Result := tkKey else Result := tkIdentifier;
end;

function TSyn68AsmSyn.Func49: TtkTokenKind;
begin
  if KeyComp('LSR') then Result := tkKey else Result := tkIdentifier;
end;

function TSyn68AsmSyn.Func50: TtkTokenKind;
begin
  if KeyComp('PULA') then Result := tkKey else
    if KeyComp('LSRA') then Result := tkKey else Result := tkIdentifier;
end;

function TSyn68AsmSyn.Func51: TtkTokenKind;
begin
  if KeyComp('SWI') then Result := tkKey else
    if KeyComp('PULB') then Result := tkKey else
      if KeyComp('ROR') then Result := tkKey else
        if KeyComp('LSRB') then Result := tkKey else Result := tkIdentifier;
end;

function TSyn68AsmSyn.Func52: TtkTokenKind;
begin
  if KeyComp('RORA') then Result := tkKey else Result := tkIdentifier;
end;

function TSyn68AsmSyn.Func53: TtkTokenKind;
begin
  if KeyComp('RORB') then Result := tkKey else Result := tkIdentifier;
end;

function TSyn68AsmSyn.Func57: TtkTokenKind;
begin
  if KeyComp('RTS') then Result := tkKey else Result := tkIdentifier;
end;

function TSyn68AsmSyn.Func58: TtkTokenKind;
begin
  if KeyComp('STS') then Result := tkKey else Result := tkIdentifier;
end;

function TSyn68AsmSyn.Func59: TtkTokenKind;
begin
  if KeyComp('TST') then Result := tkKey else Result := tkIdentifier;
end;

function TSyn68AsmSyn.Func60: TtkTokenKind;
begin
  if KeyComp('TSTA') then Result := tkKey else Result := tkIdentifier;
end;

function TSyn68AsmSyn.Func61: TtkTokenKind;
begin
  if KeyComp('TSTB') then Result := tkKey else Result := tkIdentifier;
end;

function TSyn68AsmSyn.Func63: TtkTokenKind;
begin
  if KeyComp('STX') then Result := tkKey else
    if KeyComp('TXS') then Result := tkKey else
      if KeyComp('TSX') then Result := tkKey else Result := tkIdentifier;
end;

function TSyn68AsmSyn.AltFunc: TtkTokenKind;
begin
  Result := tkIdentifier;
end;

function TSyn68AsmSyn.IdentKind(MayBe: PChar): TtkTokenKind;
var
  HashKey: Integer;
begin
  fToIdent := MayBe;
  HashKey := KeyHash(MayBe);
  if HashKey <= MaxKey then
    Result := fIdentFuncTable[HashKey]
  else
    Result := tkIdentifier;
end;

procedure TSyn68AsmSyn.MakeMethodTables;
var
  I: Char;
begin
  for I := #0 to #255 do
    case I of
      #0: fProcTable[I] := NullProc;
      #10: fProcTable[I] := LFProc;
      #13: fProcTable[I] := CRProc;
      '{': fProcTable[I] := BraceCommentOpenProc;
      ';': fProcTable[I] := SingleCommentOpenProc;
      '[': fProcTable[I] := StringOpenProc;
      #1..#9,
      #11,
      #12,
      #14..#32 : fProcTable[I] := SpaceProc;
      '@' : fProcTable[I] := BaseAddressProc;
      'A'..'Z', 'a'..'z', '_': fProcTable[I] := IdentProc;
      '#' : fProcTable[I] := NumberProc;
      ',': fProcTable[I] := XCharProc;
    else
      fProcTable[I] := UnknownProc;
    end;
end;

procedure TSyn68AsmSyn.SpaceProc;
begin
  fTokenID := tkSpace;
  repeat
    inc(Run);
  until not (fLine[Run] in [#1..#32]);
end;

procedure TSyn68AsmSyn.NullProc;
begin
  fTokenID := tkNull;
end;

procedure TSyn68AsmSyn.CRProc;
begin
  fTokenID := tkSpace;
  inc(Run);
  if fLine[Run] = #10 then
    inc(Run);
end;

procedure TSyn68AsmSyn.LFProc;
begin
  fTokenID := tkSpace;
  inc(Run);
end;

procedure TSyn68AsmSyn.BraceCommentOpenProc;
begin
  Inc(Run);
  fRange := rsBraceComment;
  BraceCommentProc;
  fTokenID := tkComment;
end;

procedure TSyn68AsmSyn.BraceCommentProc;
begin
  case fLine[Run] of
     #0: NullProc;
    #10: LFProc;
    #13: CRProc;
  else
    begin
      fTokenID := tkComment;
      repeat
        if (fLine[Run] = '}') then
        begin
          Inc(Run, 1);
          fRange := rsUnKnown;
          Break;
        end;
        if not (fLine[Run] in [#0, #10, #13]) then
          Inc(Run);
      until fLine[Run] in [#0, #10, #13];
    end;
  end;
end;

procedure TSyn68AsmSyn.SingleCommentOpenProc;
begin
  Inc(Run);
  fRange := rsSingleComment;
  SingleCommentProc;
  fTokenID := tkComment;
end;

procedure TSyn68AsmSyn.SingleCommentProc;
begin
  fTokenID := tkComment;
  repeat
    if (fLine[Run] in [#0, #10, #13]) then
    begin
      Inc(Run, 0);
      fRange := rsUnKnown;
      Break;
    end;
    if not (fLine[Run] in [#0, #10, #13]) then
      Inc(Run);
  until fLine[Run] in [#0, #10, #13];
end;

procedure TSyn68AsmSyn.StringOpenProc;
begin
  Inc(Run);
  fRange := rsString;
  StringProc;
  fTokenID := tkString;
end;

procedure TSyn68AsmSyn.StringProc;
begin
  fTokenID := tkString;
  repeat
    if (fLine[Run] = ']') then
    begin
      Inc(Run, 1);
      fRange := rsUnKnown;
      Break;
    end;
    if not (fLine[Run] in [#0, #10, #13]) then
      Inc(Run);
  until fLine[Run] in [#0, #10, #13];
end;

constructor TSyn68AsmSyn.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  fBaseAddressAttri := TSynHighLighterAttributes.Create(SYNS_AttrBaseAddress);
  fBaseAddressAttri.Style := [fsBold];
  fBaseAddressAttri.Foreground := clBlack;
  AddAttribute(fBaseAddressAttri);

  fCommentAttri := TSynHighLighterAttributes.Create(SYNS_AttrComment);
  fCommentAttri.Style := [];
  fCommentAttri.Foreground := clGreen;
  AddAttribute(fCommentAttri);

  fIdentifierAttri := TSynHighLighterAttributes.Create(SYNS_AttrIdentifier);
  AddAttribute(fIdentifierAttri);

  fKeyAttri := TSynHighLighterAttributes.Create(SYNS_AttrReservedWord);
  fKeyAttri.Style := [];
  fKeyAttri.Foreground := clBlue;
  AddAttribute(fKeyAttri);

  fNumberAttri := TSynHighLighterAttributes.Create(SYNS_AttrNumber);
  fNumberAttri.Style := [];
  fNumberAttri.Foreground := clFuchsia;
  AddAttribute(fNumberAttri);

  fSpaceAttri := TSynHighLighterAttributes.Create(SYNS_AttrSpace);
  AddAttribute(fSpaceAttri);

  fStringAttri := TSynHighLighterAttributes.Create(SYNS_AttrString);
  fStringAttri.Foreground := clRed;
  AddAttribute(fStringAttri);

  fXCharAttri := TSynHighLighterAttributes.Create(SYNS_AttrXChar);
  fXCharAttri.Style := [fsBold];
  fXCharAttri.Foreground := clRed;
  AddAttribute(fXCharAttri);

  SetAttributesOnChange(DefHighlightChange);
  InitIdent;
  MakeMethodTables;
  fDefaultFilter := SYNS_Filter;
  fRange := rsUnknown;
end;

procedure TSyn68AsmSyn.SetLine(NewValue: String; LineNumber: Integer);
begin
  fLine := PChar(NewValue);
  Run := 0;
  fLineNumber := LineNumber;
  Next;
end;

procedure TSyn68AsmSyn.BaseAddressProc;
begin
  inc(Run);
  fTokenID := tkBaseAddress;
  while FLine[Run] in ['0'..'9', 'a'..'f', 'A'..'F'] do
    Inc(Run);
end;

procedure TSyn68AsmSyn.IdentProc;
begin
  fTokenID := IdentKind((fLine + Run));
  inc(Run, fStringLen);
  while Identifiers[fLine[Run]] do
    Inc(Run);
end;

procedure TSyn68AsmSyn.NumberProc;
begin
  inc(Run);
  fTokenID := tkNumber;
  while FLine[Run] in ['0'..'9', 'a'..'f', 'A'..'F'] do
    Inc(Run);
end;

procedure TSyn68AsmSyn.XCharProc;
begin
  case FLine[Run + 1] of
    'x','X':
      begin
        inc(Run, 2);
        fTokenID := tkXChar;
      end;
  else
    begin
      inc(Run);
      fTokenID := tkIdentifier;
    end;
  end;
end;

procedure TSyn68AsmSyn.UnknownProc;
begin
{$IFDEF SYN_MBCSSUPPORT}
  if FLine[Run] in LeadBytes then
    Inc(Run,2)
  else
{$ENDIF}
  inc(Run);
  fTokenID := tkUnknown;
end;

procedure TSyn68AsmSyn.Next;
begin
  fTokenPos := Run;
  case fRange of
    rsBraceComment: BraceCommentProc;
  else
    begin
      fRange := rsUnknown;
      fProcTable[fLine[Run]];
    end;
  end;
end;

function TSyn68AsmSyn.GetDefaultAttribute(Index: integer): TSynHighLighterAttributes;
begin
  case Index of
    SYN_ATTR_COMMENT    : Result := fCommentAttri;
    SYN_ATTR_IDENTIFIER : Result := fIdentifierAttri;
    SYN_ATTR_KEYWORD    : Result := fKeyAttri;
    SYN_ATTR_STRING     : Result := fStringAttri;
    SYN_ATTR_WHITESPACE : Result := fSpaceAttri;
  else
    Result := nil;
  end;
end;

function TSyn68AsmSyn.GetEol: Boolean;
begin
  Result := fTokenID = tkNull;
end;

function TSyn68AsmSyn.GetKeyWords: string;
begin
  Result := 
    'ABA,ADCA,ADCB,ADDA,ADDB,ANDA,ANDB,ASL,ASLA,ASLB,ASR,ASRA,ASRB,ATPA,BC' +
    'C,BCS,BEQ,BGE,BGT,BHI,BITA,BITB,BLE,BLS,BLT,BMI,BNE,BPL,BRA,BSR,BVC,BV' +
    'S,CBA,CLC,CLI,CLR,CLRA,CLRB,CLV,CMPA,CMPB,COM,COMA,COMB,CPX,DAA,DEC,DE' +
    'CA,DECB,DES,DEX,EORA,EORB,FCB,INC,INCA,INCB,INS,INX,JMP,JSR,LDAA,LDAB,' +
    'LDS,LDX,LSR,LSRA,LSRB,NEG,NEGA,NEGB,NOP,ORAA,ORAB,PSHA,PSHB,PULA,PULB,' +
    'ROL,ROLA,ROLB,ROR,RORA,RORB,RTI,RTS,SBA,SBCA,SBCB,SEC,SEI,SEV,STAA,STA' +
    'B,STS,STX,SUBA,SUBB,SWI,TAB,TAC,TBA,TST,TSTA,TSTB,TSX,TXS,WAI';
end;

function TSyn68AsmSyn.GetToken: String;
var
  Len: LongInt;
begin
  Len := Run - fTokenPos;
  SetString(Result, (FLine + fTokenPos), Len);
end;

function TSyn68AsmSyn.GetTokenID: TtkTokenKind;
begin
  Result := fTokenId;
end;

function TSyn68AsmSyn.GetTokenAttribute: TSynHighLighterAttributes;
begin
  case GetTokenID of
    tkBaseAddress: Result := fBaseAddressAttri;
    tkComment: Result := fCommentAttri;
    tkIdentifier: Result := fIdentifierAttri;
    tkKey: Result := fKeyAttri;
    tkNumber: Result := fNumberAttri;
    tkSpace: Result := fSpaceAttri;
    tkString: Result := fStringAttri;
    tkXChar: Result := fXCharAttri;
    tkUnknown: Result := fIdentifierAttri;
  else
    Result := nil;
  end;
end;

function TSyn68AsmSyn.GetTokenKind: integer;
begin
  Result := Ord(fTokenId);
end;

function TSyn68AsmSyn.GetTokenPos: Integer;
begin
  Result := fTokenPos;
end;

function TSyn68AsmSyn.GetIdentChars: TSynIdentChars;
begin
  Result := ['_', 'a'..'z', 'A'..'Z'];
end;

function TSyn68AsmSyn.GetSampleSource: string;
begin
  Result := 'Sample source for: '#13#10 +
            '68 ª„±‡œµÕ≥';
end;

function TSyn68AsmSyn.IsFilterStored: Boolean;
begin
  Result := fDefaultFilter <> SYNS_Filter;
end;

{$IFNDEF SYN_CPPB_1} class {$ENDIF}
function TSyn68AsmSyn.GetLanguageName: string;
begin
  Result := SYNS_Lang;
end;

procedure TSyn68AsmSyn.ResetRange;
begin
  fRange := rsUnknown;
end;

procedure TSyn68AsmSyn.SetRange(Value: Pointer);
begin
  fRange := TRangeState(Value);
end;

function TSyn68AsmSyn.GetRange: Pointer;
begin
  Result := Pointer(fRange);
end;

initialization
  MakeIdentTable;
{$IFNDEF SYN_CPPB_1}
  RegisterPlaceableHighlighter(TSyn68AsmSyn);
{$ENDIF}
end.

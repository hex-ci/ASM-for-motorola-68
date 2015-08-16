object AsmForm: TAsmForm
  Left = 205
  Top = 137
  BorderIcons = [biSystemMenu]
  BorderStyle = bsDialog
  Caption = #27719#32534
  ClientHeight = 184
  ClientWidth = 374
  Color = clBtnFace
  Font.Charset = GB2312_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = #23435#20307
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 12
  object Label2: TLabel
    Left = 40
    Top = 55
    Width = 30
    Height = 12
    Caption = #34892#25968':'
  end
  object Label3: TLabel
    Left = 16
    Top = 87
    Width = 54
    Height = 12
    Caption = #36215#22987#22320#22336':'
  end
  object Label4: TLabel
    Left = 184
    Top = 87
    Width = 54
    Height = 12
    Caption = #32467#26463#22320#22336':'
  end
  object Label1: TLabel
    Left = 16
    Top = 23
    Width = 54
    Height = 12
    Caption = #27719#32534#25991#20214':'
  end
  object Label5: TLabel
    Left = 208
    Top = 56
    Width = 30
    Height = 12
    Caption = #22823#23567':'
  end
  object Label6: TLabel
    Left = 40
    Top = 119
    Width = 30
    Height = 12
    Caption = #38169#35823':'
  end
  object Label7: TLabel
    Left = 208
    Top = 119
    Width = 30
    Height = 12
    Caption = #35686#21578':'
  end
  object txtLine: TEdit
    Left = 72
    Top = 52
    Width = 105
    Height = 20
    Color = clBtnFace
    ReadOnly = True
    TabOrder = 1
    Text = '0'
  end
  object CancelButton: TButton
    Left = 136
    Top = 152
    Width = 105
    Height = 25
    Caption = #21462#28040'(&C)'
    Default = True
    TabOrder = 7
    OnClick = CancelButtonClick
  end
  object txtAsmFile: TEdit
    Left = 72
    Top = 20
    Width = 273
    Height = 20
    Color = clBtnFace
    ReadOnly = True
    TabOrder = 0
  end
  object txtWarning: TEdit
    Left = 240
    Top = 116
    Width = 105
    Height = 20
    Color = clBtnFace
    ReadOnly = True
    TabOrder = 6
    Text = '0'
  end
  object txtError: TEdit
    Left = 72
    Top = 116
    Width = 105
    Height = 20
    Color = clBtnFace
    ReadOnly = True
    TabOrder = 5
    Text = '0'
  end
  object txtSize: TEdit
    Left = 240
    Top = 52
    Width = 105
    Height = 20
    Color = clBtnFace
    ReadOnly = True
    TabOrder = 2
    Text = '0'
  end
  object txtBegin: TEdit
    Left = 72
    Top = 84
    Width = 105
    Height = 20
    Color = clBtnFace
    ReadOnly = True
    TabOrder = 3
    Text = '0'
  end
  object txtEnd: TEdit
    Left = 240
    Top = 84
    Width = 105
    Height = 20
    Color = clBtnFace
    ReadOnly = True
    TabOrder = 4
    Text = '0'
  end
end

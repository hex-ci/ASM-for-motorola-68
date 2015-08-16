object FormSearch: TFormSearch
  Left = 239
  Top = 135
  BorderStyle = bsDialog
  Caption = #25628#32034
  ClientHeight = 179
  ClientWidth = 332
  Color = clBtnFace
  Font.Charset = GB2312_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = #23435#20307
  Font.Style = []
  OldCreateOrder = False
  Position = poOwnerFormCenter
  OnCloseQuery = FormCloseQuery
  PixelsPerInch = 96
  TextHeight = 12
  object Label1: TLabel
    Left = 14
    Top = 12
    Width = 48
    Height = 12
    Caption = #25628#32034'(&S):'
    FocusControl = cbSearchText
  end
  object cbSearchText: TComboBox
    Left = 64
    Top = 8
    Width = 260
    Height = 20
    ItemHeight = 12
    TabOrder = 0
  end
  object gbSearchOptions: TGroupBox
    Left = 8
    Top = 40
    Width = 154
    Height = 109
    Caption = #36873#39033
    TabOrder = 1
    object cbSearchCaseSensitive: TCheckBox
      Left = 8
      Top = 17
      Width = 140
      Height = 17
      Caption = #21306#20998#22823#23567#20889'(&A)'
      TabOrder = 0
    end
    object cbSearchWholeWords: TCheckBox
      Left = 8
      Top = 39
      Width = 140
      Height = 17
      Caption = #20840#23383#21305#37197'(&W)'
      TabOrder = 1
    end
    object cbSearchFromCursor: TCheckBox
      Left = 8
      Top = 61
      Width = 140
      Height = 17
      Caption = #20174#20809#26631#22788#25628#32034'(&C)'
      TabOrder = 2
    end
    object cbSearchSelectedOnly: TCheckBox
      Left = 8
      Top = 83
      Width = 140
      Height = 17
      Caption = #25628#32034#36873#23450#25991#26412'(&T)'
      TabOrder = 3
    end
  end
  object rgSearchDirection: TRadioGroup
    Left = 170
    Top = 40
    Width = 154
    Height = 65
    Caption = #26041#21521
    ItemIndex = 0
    Items.Strings = (
      #21521#19979'(&F)'
      #21521#19978'(&B)')
    TabOrder = 2
  end
  object btnOK: TButton
    Left = 170
    Top = 149
    Width = 75
    Height = 23
    Caption = #30830#23450
    Default = True
    ModalResult = 1
    TabOrder = 3
  end
  object btnCancel: TButton
    Left = 249
    Top = 149
    Width = 75
    Height = 23
    Cancel = True
    Caption = #21462#28040
    ModalResult = 2
    TabOrder = 4
  end
end

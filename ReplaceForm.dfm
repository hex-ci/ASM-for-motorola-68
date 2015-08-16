inherited FormReplace: TFormReplace
  Left = 276
  Top = 172
  Caption = #26367#25442
  ClientHeight = 210
  OldCreateOrder = True
  PixelsPerInch = 96
  TextHeight = 12
  object Label2: TLabel [1]
    Left = 14
    Top = 41
    Width = 48
    Height = 12
    Caption = #26367#25442'(&R):'
    FocusControl = cbReplaceText
  end
  inherited gbSearchOptions: TGroupBox
    Top = 70
    TabOrder = 2
  end
  inherited rgSearchDirection: TRadioGroup
    Top = 70
    TabOrder = 3
  end
  inherited btnOK: TButton
    Top = 179
    TabOrder = 4
  end
  inherited btnCancel: TButton
    Top = 179
    TabOrder = 5
  end
  object cbReplaceText: TComboBox
    Left = 64
    Top = 37
    Width = 260
    Height = 20
    ItemHeight = 12
    TabOrder = 1
  end
end

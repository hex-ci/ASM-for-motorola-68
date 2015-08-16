object FormConfirmReplace: TFormConfirmReplace
  Left = 134
  Top = 204
  BorderStyle = bsDialog
  Caption = #30830#35748#26367#25442
  ClientHeight = 98
  ClientWidth = 328
  Color = clBtnFace
  Font.Charset = GB2312_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = #23435#20307
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 12
  object lblConfirmation: TLabel
    Left = 60
    Top = 12
    Width = 261
    Height = 44
    AutoSize = False
    WordWrap = True
  end
  object Image1: TImage
    Left = 16
    Top = 16
    Width = 32
    Height = 32
  end
  object btnReplace: TButton
    Left = 8
    Top = 67
    Width = 75
    Height = 23
    Caption = #26159'(&Y)'
    Default = True
    ModalResult = 6
    TabOrder = 0
  end
  object btnSkip: TButton
    Left = 87
    Top = 67
    Width = 75
    Height = 23
    Caption = #21542'(&N)'
    ModalResult = 7
    TabOrder = 1
  end
  object btnCancel: TButton
    Left = 166
    Top = 67
    Width = 75
    Height = 23
    Cancel = True
    Caption = #21462#28040
    ModalResult = 2
    TabOrder = 2
  end
  object btnReplaceAll: TButton
    Left = 245
    Top = 67
    Width = 75
    Height = 23
    Caption = #20840#37096#26367#25442'(&A)'
    ModalResult = 10
    TabOrder = 3
  end
end

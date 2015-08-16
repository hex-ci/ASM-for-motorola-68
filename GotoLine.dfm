object GotoForm: TGotoForm
  Left = 464
  Top = 261
  ActiveControl = txtLine
  BorderIcons = [biSystemMenu]
  BorderStyle = bsDialog
  Caption = #36716#21040#26576#34892
  ClientHeight = 79
  ClientWidth = 220
  Color = clBtnFace
  Font.Charset = GB2312_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = #23435#20307
  Font.Style = []
  OldCreateOrder = False
  Position = poOwnerFormCenter
  PixelsPerInch = 96
  TextHeight = 12
  object Label1: TLabel
    Left = 8
    Top = 16
    Width = 48
    Height = 12
    Caption = #34892#21495'(&L):'
    FocusControl = txtLine
  end
  object txtLine: TEdit
    Left = 60
    Top = 12
    Width = 149
    Height = 20
    AutoSize = False
    TabOrder = 0
  end
  object OKButton: TButton
    Left = 94
    Top = 48
    Width = 57
    Height = 25
    Caption = #30830#23450'(&O)'
    Default = True
    TabOrder = 1
    OnClick = OKButtonClick
  end
  object CancelButton: TButton
    Left = 152
    Top = 48
    Width = 57
    Height = 25
    Cancel = True
    Caption = #21462#28040'(&C)'
    ModalResult = 2
    TabOrder = 2
  end
end

object LibrarianInsDel: TLibrarianInsDel
  Left = 241
  Top = 200
  Width = 744
  Height = 384
  Caption = #39302#21592#20449#24687#30340#28155#21152#19982#21024#38500
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsMDIChild
  OldCreateOrder = False
  Position = poDefault
  Visible = True
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBox1: TGroupBox
    Left = 35
    Top = 24
    Width = 289
    Height = 289
    Caption = #39302#21592#20449#24687#28155#21152
    TabOrder = 0
    object Label1: TLabel
      Left = 16
      Top = 49
      Width = 81
      Height = 33
      AutoSize = False
      Caption = #39302#21592#32534#21495#65306
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label2: TLabel
      Left = 22
      Top = 131
      Width = 81
      Height = 33
      AutoSize = False
      Caption = #22995'        '#21517#65306
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object LibrarianIdEdit: TEdit
      Left = 112
      Top = 45
      Width = 121
      Height = 21
      TabOrder = 0
    end
    object NameEdit: TEdit
      Left = 112
      Top = 127
      Width = 121
      Height = 21
      TabOrder = 1
    end
    object BitBtn1: TBitBtn
      Left = 160
      Top = 216
      Width = 75
      Height = 25
      Caption = #28155#21152
      TabOrder = 2
      OnClick = BitBtn1Click
      Kind = bkOK
    end
  end
  object GroupBox2: TGroupBox
    Left = 362
    Top = 24
    Width = 337
    Height = 289
    Caption = #39302#21592#20449#24687#21024#38500
    TabOrder = 1
    object DBGrid1: TDBGrid
      Left = 10
      Top = 25
      Width = 313
      Height = 176
      DataSource = DataSource1
      TabOrder = 0
      TitleFont.Charset = DEFAULT_CHARSET
      TitleFont.Color = clWindowText
      TitleFont.Height = -11
      TitleFont.Name = 'MS Sans Serif'
      TitleFont.Style = []
      Columns = <
        item
          Expanded = False
          FieldName = 'LibrarianId'
          Title.Caption = #32534#21495
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'Name'
          Title.Caption = #22995#21517
          Width = 87
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'Password'
          Title.Caption = #23494#30721
          Visible = True
        end>
    end
    object BitBtn2: TBitBtn
      Left = 232
      Top = 240
      Width = 75
      Height = 25
      Caption = #21024#38500
      TabOrder = 1
      OnClick = BitBtn2Click
      Kind = bkAbort
    end
  end
  object DataSource1: TDataSource
    DataSet = LibrarianInsDelTable
    Left = 488
    Top = 168
  end
  object LibrarianInsDelTable: TTable
    Active = True
    DatabaseName = 'MyCBuilderOdbc'
    TableName = 'dbo.LibrarianTable'
    Left = 440
    Top = 168
  end
end

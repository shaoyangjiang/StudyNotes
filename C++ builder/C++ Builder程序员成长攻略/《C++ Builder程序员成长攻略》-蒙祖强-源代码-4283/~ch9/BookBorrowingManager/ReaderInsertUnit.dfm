object ReaderInsert: TReaderInsert
  Left = 182
  Top = 33
  Width = 752
  Height = 651
  Caption = #35835#32773#20449#24687#24405#20837
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
    Left = 22
    Top = 24
    Width = 683
    Height = 361
    Caption = #36755#20837#35835#32773#20449#24687#65306
    TabOrder = 0
    object Label1: TLabel
      Left = 48
      Top = 43
      Width = 81
      Height = 25
      AutoSize = False
      Caption = #35835#32773#26465#30721#65306
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label2: TLabel
      Left = 47
      Top = 91
      Width = 81
      Height = 25
      AutoSize = False
      Caption = #35835#32773#22995#21517#65306
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label3: TLabel
      Left = 55
      Top = 137
      Width = 65
      Height = 25
      AutoSize = False
      Caption = #24615'        '#21035#65306
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label4: TLabel
      Left = 351
      Top = 43
      Width = 89
      Height = 25
      AutoSize = False
      Caption = #24037#20316#21333#20301#65306
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label5: TLabel
      Left = 351
      Top = 91
      Width = 89
      Height = 25
      AutoSize = False
      Caption = #35835#32773#36523#20221#65306
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label7: TLabel
      Left = 56
      Top = 184
      Width = 81
      Height = 25
      AutoSize = False
      Caption = #22791#27880#65306
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object ReaderIdEdit: TEdit
      Left = 136
      Top = 40
      Width = 121
      Height = 21
      TabOrder = 0
      Text = 'ReaderIdEdit'
    end
    object NameEdit: TEdit
      Left = 136
      Top = 88
      Width = 121
      Height = 21
      TabOrder = 1
      Text = 'NameEdit'
    end
    object GenderEdit: TEdit
      Left = 136
      Top = 136
      Width = 121
      Height = 21
      TabOrder = 2
      Text = 'GenderEdit'
    end
    object UnitEdit: TEdit
      Left = 445
      Top = 40
      Width = 121
      Height = 21
      TabOrder = 3
      Text = 'UnitEdit'
    end
    object IdentEdit: TEdit
      Left = 445
      Top = 88
      Width = 121
      Height = 21
      TabOrder = 4
      Text = 'IdentEdit'
    end
    object RemarkMemo: TMemo
      Left = 56
      Top = 208
      Width = 513
      Height = 81
      Lines.Strings = (
        'Memo1')
      TabOrder = 5
    end
    object BitBtn1: TBitBtn
      Left = 565
      Top = 314
      Width = 75
      Height = 25
      Caption = #25552#20132
      TabOrder = 6
      OnClick = BitBtn1Click
      Kind = bkOK
    end
  end
  object DBGrid1: TDBGrid
    Left = 40
    Top = 416
    Width = 665
    Height = 169
    DataSource = DataSource1
    TabOrder = 1
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'MS Sans Serif'
    TitleFont.Style = []
    OnCellClick = DBGrid1CellClick
  end
  object ReaderInsertTable: TTable
    Active = True
    DatabaseName = 'MyCBuilderOdbc'
    TableName = 'dbo.ReaderTable'
    Left = 72
    Top = 552
  end
  object DataSource1: TDataSource
    DataSet = ReaderInsertTable
    Left = 120
    Top = 552
  end
end

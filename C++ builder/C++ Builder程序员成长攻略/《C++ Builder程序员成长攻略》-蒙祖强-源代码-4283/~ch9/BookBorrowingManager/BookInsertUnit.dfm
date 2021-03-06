object BookInsert: TBookInsert
  Left = 195
  Top = 113
  Width = 750
  Height = 562
  Caption = #26032#20070#20837#24211
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
  object DBGrid1: TDBGrid
    Left = 32
    Top = 276
    Width = 673
    Height = 225
    Ctl3D = False
    DataSource = DataSource1
    ParentCtl3D = False
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'MS Sans Serif'
    TitleFont.Style = []
  end
  object GroupBox1: TGroupBox
    Left = 32
    Top = 24
    Width = 673
    Height = 237
    Caption = #35774#32622#36755#20837#25968#25454#65306
    TabOrder = 1
    object Label1: TLabel
      Left = 64
      Top = 32
      Width = 73
      Height = 17
      AutoSize = False
      Caption = #20070#21495#65306
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label2: TLabel
      Left = 64
      Top = 80
      Width = 73
      Height = 17
      AutoSize = False
      Caption = #20070#21517#65306
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label3: TLabel
      Left = 64
      Top = 130
      Width = 73
      Height = 17
      AutoSize = False
      Caption = #32534#32773#65306
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label4: TLabel
      Left = 354
      Top = 32
      Width = 73
      Height = 17
      AutoSize = False
      Caption = #20986#29256#31038#65306
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label5: TLabel
      Left = 338
      Top = 80
      Width = 73
      Height = 17
      AutoSize = False
      Caption = #20986#29256#26085#26399#65306
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label6: TLabel
      Left = 371
      Top = 130
      Width = 73
      Height = 17
      AutoSize = False
      Caption = #20215#26684#65306
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label7: TLabel
      Left = 49
      Top = 179
      Width = 73
      Height = 17
      AutoSize = False
      Caption = #32034#20070#21495#65306
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object ISBNEdit: TEdit
      Left = 120
      Top = 32
      Width = 121
      Height = 19
      Ctl3D = False
      ParentCtl3D = False
      TabOrder = 0
      Text = 'ISBNEdit'
    end
    object BookNameEdit: TEdit
      Left = 120
      Top = 80
      Width = 177
      Height = 19
      Ctl3D = False
      ParentCtl3D = False
      TabOrder = 1
      Text = 'BookNameEdit'
    end
    object EditorEdit: TEdit
      Left = 120
      Top = 128
      Width = 121
      Height = 19
      Ctl3D = False
      MaxLength = 8
      ParentCtl3D = False
      TabOrder = 2
      Text = 'EditorEdit'
    end
    object PublisherEdit: TEdit
      Left = 425
      Top = 32
      Width = 185
      Height = 19
      Ctl3D = False
      ParentCtl3D = False
      TabOrder = 3
      Text = 'PublisherEdit'
    end
    object PubDateEdit: TEdit
      Left = 425
      Top = 80
      Width = 121
      Height = 19
      Ctl3D = False
      ParentCtl3D = False
      TabOrder = 4
      Text = 'PubDateEdit'
    end
    object PriceEdit: TEdit
      Left = 425
      Top = 130
      Width = 121
      Height = 19
      Ctl3D = False
      ParentCtl3D = False
      TabOrder = 5
      Text = 'PriceEdit'
    end
    object BitBtn1: TBitBtn
      Left = 544
      Top = 185
      Width = 75
      Height = 25
      TabOrder = 6
      OnClick = BitBtn1Click
      Kind = bkOK
    end
    object BookIndexEdit: TEdit
      Left = 120
      Top = 176
      Width = 177
      Height = 19
      Ctl3D = False
      ParentCtl3D = False
      TabOrder = 7
      Text = 'BookIndexEdit'
    end
  end
  object BookInsertQuery: TQuery
    Active = True
    DatabaseName = 'MyCBuilderOdbc'
    SQL.Strings = (
      'Select * from BookTable;')
    Left = 184
    Top = 352
  end
  object DataSource1: TDataSource
    DataSet = BookInsertQuery
    OnDataChange = DataSource1DataChange
    Left = 224
    Top = 352
  end
end

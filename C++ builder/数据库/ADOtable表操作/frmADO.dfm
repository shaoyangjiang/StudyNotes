object Form1: TForm1
  Left = 786
  Top = 100
  Width = 554
  Height = 484
  Caption = 'Form1'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object DBGrid1: TDBGrid
    Left = 8
    Top = 41
    Width = 521
    Height = 192
    DataSource = DataSource1
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'MS Sans Serif'
    TitleFont.Style = []
  end
  object PageControl1: TPageControl
    Left = 16
    Top = 232
    Width = 513
    Height = 193
    ActivePage = TabSheet3
    TabIndex = 2
    TabOrder = 1
    object TabSheet1: TTabSheet
      Caption = #28155#21152#35760#24405' '
      object Label1: TLabel
        Left = 0
        Top = 32
        Width = 27
        Height = 13
        Caption = #23398#21495' '
      end
      object Label2: TLabel
        Left = 176
        Top = 32
        Width = 30
        Height = 13
        Caption = #22995#21517'  '
      end
      object Label3: TLabel
        Left = 344
        Top = 32
        Width = 30
        Height = 13
        Caption = #24180#40836'  '
      end
      object Label4: TLabel
        Left = 0
        Top = 96
        Width = 30
        Height = 13
        Caption = #24037#36164'  '
      end
      object Label5: TLabel
        Left = 176
        Top = 96
        Width = 30
        Height = 13
        Caption = #24615#21035'  '
      end
      object ID: TEdit
        Left = 40
        Top = 32
        Width = 121
        Height = 21
        TabOrder = 0
      end
      object Name: TEdit
        Left = 216
        Top = 32
        Width = 121
        Height = 21
        TabOrder = 1
      end
      object Age: TEdit
        Left = 384
        Top = 32
        Width = 121
        Height = 21
        TabOrder = 2
      end
      object Salary: TEdit
        Left = 40
        Top = 96
        Width = 121
        Height = 21
        TabOrder = 3
      end
      object Sex: TEdit
        Left = 216
        Top = 96
        Width = 121
        Height = 21
        TabOrder = 4
      end
      object Add: TButton
        Left = 360
        Top = 96
        Width = 75
        Height = 25
        Caption = #28155#21152'  '
        TabOrder = 5
        OnClick = AddClick
      end
    end
    object TabSheet2: TTabSheet
      Caption = #26597#25214#19982#21024#38500'  '
      ImageIndex = 1
      object Label6: TLabel
        Left = 8
        Top = 16
        Width = 51
        Height = 13
        Caption = #36873#25321#23383#27573' '
      end
      object Label7: TLabel
        Left = 8
        Top = 64
        Width = 42
        Height = 13
        Caption = #23383#27573#20540'  '
      end
      object Find: TButton
        Left = 224
        Top = 16
        Width = 75
        Height = 25
        Caption = #26597#25214
        TabOrder = 0
        OnClick = FindClick
      end
      object Delete: TButton
        Left = 224
        Top = 56
        Width = 75
        Height = 25
        Caption = #21024#38500' '
        TabOrder = 1
        OnClick = DeleteClick
      end
      object FindValue: TEdit
        Left = 72
        Top = 64
        Width = 121
        Height = 21
        TabOrder = 2
      end
      object ComboBox1: TComboBox
        Left = 64
        Top = 16
        Width = 145
        Height = 21
        ItemHeight = 13
        TabOrder = 3
        Text = #35831#36873#25321'  '
      end
    end
    object TabSheet3: TTabSheet
      Caption = #31579#36873'  '
      ImageIndex = 2
      object Label8: TLabel
        Left = 24
        Top = 24
        Width = 51
        Height = 13
        Caption = #23383#27573#21517#31216' '
      end
      object Label9: TLabel
        Left = 24
        Top = 64
        Width = 54
        Height = 13
        Caption = #26465#20214#31526#21495'  '
      end
      object Label10: TLabel
        Left = 272
        Top = 32
        Width = 42
        Height = 13
        Caption = #26465#20214#20540'  '
      end
      object ComboBox2: TComboBox
        Left = 80
        Top = 24
        Width = 145
        Height = 21
        ItemHeight = 13
        TabOrder = 0
        Text = #35831#36873#25321'  '
      end
      object ComboBox3: TComboBox
        Left = 80
        Top = 64
        Width = 145
        Height = 21
        ItemHeight = 13
        TabOrder = 1
        Text = #35831#36873#25321'  '
        Items.Strings = (
          '>'
          '<'
          '>='
          '<='
          '=='
          '!=')
      end
      object FilterValue: TEdit
        Left = 272
        Top = 56
        Width = 121
        Height = 21
        TabOrder = 2
      end
      object Filter: TButton
        Left = 32
        Top = 120
        Width = 75
        Height = 25
        Caption = #31579#36873
        TabOrder = 3
        OnClick = FilterClick
      end
      object Prior: TButton
        Left = 144
        Top = 120
        Width = 75
        Height = 25
        Caption = #19978#19968#26465
        TabOrder = 4
        OnClick = PriorClick
      end
      object Next: TButton
        Left = 256
        Top = 120
        Width = 75
        Height = 25
        Caption = #19979#19968#26465
        TabOrder = 5
        OnClick = NextClick
      end
      object ShowAll: TButton
        Left = 368
        Top = 120
        Width = 89
        Height = 25
        Caption = #26174#31034#20840#37096#35760#24405' '
        TabOrder = 6
        OnClick = ShowAllClick
      end
    end
  end
  object ADOTable1: TADOTable
    ConnectionString = 
      'Provider=Microsoft.Jet.OLEDB.4.0;Data Source=F:\C++ builder\'#25968#25454#24211'\' +
      'ADOtable'#34920#25805#20316'\student.mdb.mdb;Persist Security Info=False'
    OnFilterRecord = ADOTable1FilterRecord
    TableName = 'stduent'
    Left = 16
    Top = 8
  end
  object DataSource1: TDataSource
    DataSet = ADOTable1
    Left = 88
    Top = 8
  end
end

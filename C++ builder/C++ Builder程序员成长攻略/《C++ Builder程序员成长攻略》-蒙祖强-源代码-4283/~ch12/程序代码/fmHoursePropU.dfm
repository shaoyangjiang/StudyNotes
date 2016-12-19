object fmHourseProp: TfmHourseProp
  Left = 259
  Top = 128
  BorderStyle = bsNone
  Caption = #26356#26032#25151#23627#20449#24687
  ClientHeight = 430
  ClientWidth = 645
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 645
    Height = 430
    Align = alClient
    TabOrder = 0
    object panPaperNo: TPanel
      Left = 1
      Top = 1
      Width = 643
      Height = 32
      Align = alTop
      Caption = #26690#25151#35777#23383#31532#65306
      Color = clBlue
      Font.Charset = GB2312_CHARSET
      Font.Color = clWhite
      Font.Height = -16
      Font.Name = #23435#20307
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 0
    end
    object Panel5: TPanel
      Left = 1
      Top = 33
      Width = 35
      Height = 396
      Align = alLeft
      TabOrder = 1
      object Label16: TLabel
        Left = 14
        Top = 78
        Width = 12
        Height = 13
        Caption = #25151
      end
      object Label17: TLabel
        Left = 14
        Top = 118
        Width = 12
        Height = 13
        Caption = #23627
      end
      object Label18: TLabel
        Left = 14
        Top = 158
        Width = 12
        Height = 13
        Caption = #29366
      end
      object Label19: TLabel
        Left = 14
        Top = 198
        Width = 12
        Height = 13
        Caption = #20917
      end
    end
    object Panel2: TPanel
      Left = 36
      Top = 33
      Width = 608
      Height = 396
      Align = alClient
      TabOrder = 2
      object Panel3: TPanel
        Left = 1
        Top = 1
        Width = 606
        Height = 394
        Align = alClient
        TabOrder = 0
        object QRShape19: TQRShape
          Left = 47
          Top = 61
          Width = 2
          Height = 33
          Frame.Color = clBlack
          Frame.DrawTop = False
          Frame.DrawBottom = False
          Frame.DrawLeft = False
          Frame.DrawRight = False
          Size.Values = (
            87.3125
            124.354166666667
            161.395833333333
            5.29166666666667)
          Pen.Width = 2
          Shape = qrsRectangle
        end
        object Panel6: TPanel
          Left = 1
          Top = 1
          Width = 604
          Height = 334
          Align = alTop
          TabOrder = 0
          object Label37: TLabel
            Left = 16
            Top = 8
            Width = 24
            Height = 13
            Caption = #26635#21495
          end
          object Label38: TLabel
            Left = 64
            Top = 8
            Width = 24
            Height = 13
            Caption = #25151#21495
          end
          object Label39: TLabel
            Left = 120
            Top = 8
            Width = 24
            Height = 13
            Caption = #38388#25968
          end
          object Label40: TLabel
            Left = 176
            Top = 8
            Width = 48
            Height = 13
            Caption = #24314#31569#32467#26500
          end
          object Label41: TLabel
            Left = 264
            Top = 8
            Width = 24
            Height = 13
            Caption = #23618#25968
          end
          object Label42: TLabel
            Left = 320
            Top = 8
            Width = 108
            Height = 13
            Caption = #24314#31569#38754#31215#65288#24179#26041#31859#65289
          end
          object Label43: TLabel
            Left = 480
            Top = 8
            Width = 30
            Height = 13
            Caption = #22791'  '#27880
          end
          object gridPropertyHourse: TStringGrid
            Left = 1
            Top = 31
            Width = 602
            Height = 302
            Align = alBottom
            ColCount = 7
            Ctl3D = False
            FixedColor = clWindow
            FixedCols = 0
            RowCount = 12
            FixedRows = 0
            Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing, goTabs]
            ParentCtl3D = False
            TabOrder = 6
            ColWidths = (
              51
              52
              49
              90
              56
              124
              148)
          end
          object QRShape28: TQRShape
            Left = 429
            Top = -9
            Width = 1
            Height = 41
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              108.479166666667
              1135.0625
              -23.8125
              2.64583333333333)
            Pen.Width = 2
            Shape = qrsRectangle
          end
          object QRShape29: TQRShape
            Left = 303
            Top = -9
            Width = 1
            Height = 41
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              108.479166666667
              801.6875
              -23.8125
              2.64583333333333)
            Pen.Width = 2
            Shape = qrsRectangle
          end
          object QRShape30: TQRShape
            Left = 247
            Top = -10
            Width = 1
            Height = 41
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              108.479166666667
              653.520833333333
              -26.4583333333333
              2.64583333333333)
            Pen.Width = 2
            Shape = qrsRectangle
          end
          object QRShape31: TQRShape
            Left = 156
            Top = -9
            Width = 1
            Height = 41
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              108.479166666667
              412.75
              -23.8125
              2.64583333333333)
            Pen.Width = 2
            Shape = qrsRectangle
          end
          object QRShape32: TQRShape
            Left = 106
            Top = -9
            Width = 1
            Height = 41
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              108.479166666667
              280.458333333333
              -23.8125
              2.64583333333333)
            Pen.Width = 2
            Shape = qrsRectangle
          end
          object QRShape33: TQRShape
            Left = 52
            Top = -3
            Width = 1
            Height = 36
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              95.25
              137.583333333333
              -7.9375
              2.64583333333333)
            Pen.Width = 2
            Shape = qrsRectangle
          end
        end
        object Panel8: TPanel
          Left = 1
          Top = 335
          Width = 604
          Height = 58
          Align = alClient
          TabOrder = 2
          object BitBtn1: TBitBtn
            Left = 96
            Top = 8
            Width = 137
            Height = 33
            TabOrder = 0
            OnClick = BitBtn1Click
            Kind = bkOK
          end
          object BitBtn2: TBitBtn
            Left = 328
            Top = 8
            Width = 121
            Height = 33
            TabOrder = 1
            Kind = bkCancel
          end
        end
      end
    end
  end
end

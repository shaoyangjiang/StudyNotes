object AppServer1: TAppServer1
  OldCreateOrder = False
  Left = 447
  Top = 165
  Height = 192
  Width = 284
  object Query1: TQuery
    Active = True
    DatabaseName = 'MyCBuilderOdbc'
    SQL.Strings = (
      'Select * from StuTable;')
    Left = 32
    Top = 24
  end
  object DataSetProvider1: TDataSetProvider
    DataSet = Query1
    Constraints = True
    UpdateMode = upWhereChanged
    Left = 112
    Top = 24
  end
end

object dmData: TdmData
  OldCreateOrder = False
  OnCreate = DataModuleCreate
  Left = 195
  Top = 118
  Height = 150
  Width = 215
  object Conn: TADOConnection
    ConnectionString = 
      'Provider=SQLOLEDB.1;Integrated Security=SSPI;Persist Security In' +
      'fo=False;Initial Catalog=hourseDB;Data Source=(Local)'
    LoginPrompt = False
    Provider = 'SQLOLEDB.1'
    Left = 32
    Top = 24
  end
  object qry: TADOQuery
    Connection = Conn
    Parameters = <>
    Left = 96
    Top = 32
  end
end

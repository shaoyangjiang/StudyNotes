if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[A_Attorney]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
drop table [dbo].[A_Attorney]
GO

if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[A_Checker]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
drop table [dbo].[A_Checker]
GO

if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[A_House]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
drop table [dbo].[A_House]
GO

if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[A_HouseSummary]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
drop table [dbo].[A_HouseSummary]
GO

if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[A_LetHouse]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
drop table [dbo].[A_LetHouse]
GO

if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[A_ManageUnit]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
drop table [dbo].[A_ManageUnit]
GO

if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[A_Marker]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
drop table [dbo].[A_Marker]
GO

if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[A_PropertyRight]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
drop table [dbo].[A_PropertyRight]
GO

if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[A_TaxRace]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
drop table [dbo].[A_TaxRace]
GO

if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[A_TaxType]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
drop table [dbo].[A_TaxType]
GO

if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[Auditing]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
drop table [dbo].[Auditing]
GO

if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[HouseExam]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
drop table [dbo].[HouseExam]
GO

if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[InitFileNo]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
drop table [dbo].[InitFileNo]
GO

if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[K_Checker]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
drop table [dbo].[K_Checker]
GO

if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[Mortagate_Application]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
drop table [dbo].[Mortagate_Application]
GO

if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[Mortagate_Auditing]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
drop table [dbo].[Mortagate_Auditing]
GO

if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[OtherProperty_Paper]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
drop table [dbo].[OtherProperty_Paper]
GO

if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[Owner_Application]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
drop table [dbo].[Owner_Application]
GO

if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[P_Contract_Tax]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
drop table [dbo].[P_Contract_Tax]
GO

if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[P_GroundProperty]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
drop table [dbo].[P_GroundProperty]
GO

if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[P_HousePicture]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
drop table [dbo].[P_HousePicture]
GO

if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[P_HouseProperty]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
drop table [dbo].[P_HouseProperty]
GO

if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[P_OtherProperty]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
drop table [dbo].[P_OtherProperty]
GO

if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[P_Owner]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
drop table [dbo].[P_Owner]
GO

if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[Property_Paper]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
drop table [dbo].[Property_Paper]
GO

if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[ShareProperty_Paper]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
drop table [dbo].[ShareProperty_Paper]
GO

if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[sys_Const]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
drop table [dbo].[sys_Const]
GO

CREATE TABLE [dbo].[A_Attorney] (
	[RID] [int] IDENTITY (1, 1) NOT NULL ,
	[K_Application_NO] [varchar] (10) COLLATE Chinese_PRC_CI_AS NOT NULL ,
	[K_Owner_ID] [int] NOT NULL 
) ON [PRIMARY]
GO

CREATE TABLE [dbo].[A_Checker] (
	[RID] [int] IDENTITY (1, 1) NOT NULL ,
	[K_Checker_ID] [int] NOT NULL ,
	[Checker] [char] (20) COLLATE Chinese_PRC_CI_AS NOT NULL 
) ON [PRIMARY]
GO

CREATE TABLE [dbo].[A_House] (
	[RID] [int] IDENTITY (1, 1) NOT NULL ,
	[RNO] [varchar] (10) COLLATE Chinese_PRC_CI_AS NOT NULL ,
	[K_Application_NO] [varchar] (10) COLLATE Chinese_PRC_CI_AS NOT NULL 
) ON [PRIMARY]
GO

CREATE TABLE [dbo].[A_HouseSummary] (
	[RID] [int] IDENTITY (1, 1) NOT NULL ,
	[K_Application_NO] [varchar] (10) COLLATE Chinese_PRC_CI_AS NOT NULL ,
	[House_Position] [varchar] (64) COLLATE Chinese_PRC_CI_AS NULL ,
	[Picture_Name] [varchar] (16) COLLATE Chinese_PRC_CI_AS NULL ,
	[Picture_NO] [varchar] (10) COLLATE Chinese_PRC_CI_AS NULL 
) ON [PRIMARY]
GO

CREATE TABLE [dbo].[A_LetHouse] (
	[RID] [int] IDENTITY (1, 1) NOT NULL ,
	[K_Application_NO] [varchar] (10) COLLATE Chinese_PRC_CI_AS NOT NULL ,
	[Lessee_name] [varchar] (32) COLLATE Chinese_PRC_CI_AS NULL 
) ON [PRIMARY]
GO

CREATE TABLE [dbo].[A_ManageUnit] (
	[RID] [int] IDENTITY (1, 1) NOT NULL ,
	[K_ManageUnit_ID] [int] NOT NULL ,
	[ManageUnit] [char] (40) COLLATE Chinese_PRC_CI_AS NOT NULL 
) ON [PRIMARY]
GO

CREATE TABLE [dbo].[A_Marker] (
	[RID] [int] IDENTITY (1, 1) NOT NULL ,
	[K_Marker_ID] [int] NOT NULL ,
	[Marker] [char] (20) COLLATE Chinese_PRC_CI_AS NOT NULL 
) ON [PRIMARY]
GO

CREATE TABLE [dbo].[A_PropertyRight] (
	[RID] [int] IDENTITY (1, 1) NOT NULL ,
	[K_PropertyRight_ID] [int] NOT NULL ,
	[PropertyRight] [char] (20) COLLATE Chinese_PRC_CI_AS NOT NULL 
) ON [PRIMARY]
GO

CREATE TABLE [dbo].[A_TaxRace] (
	[RID] [int] IDENTITY (1, 1) NOT NULL ,
	[K_TaxRace_ID] [int] NOT NULL ,
	[TaxRace] [char] (20) COLLATE Chinese_PRC_CI_AS NOT NULL 
) ON [PRIMARY]
GO

CREATE TABLE [dbo].[A_TaxType] (
	[RID] [int] IDENTITY (1, 1) NOT NULL ,
	[K_TaxType_ID] [int] NOT NULL ,
	[TaxType] [char] (20) COLLATE Chinese_PRC_CI_AS NOT NULL 
) ON [PRIMARY]
GO

CREATE TABLE [dbo].[Auditing] (
	[RID] [int] IDENTITY (1, 1) NOT NULL ,
	[K_Application_NO] [varchar] (50) COLLATE Chinese_PRC_CI_AS NOT NULL ,
	[Apply] [varchar] (50) COLLATE Chinese_PRC_CI_AS NULL 
) ON [PRIMARY]
GO

CREATE TABLE [dbo].[HouseExam] (
	[RID] [int] IDENTITY (1, 1) NOT NULL ,
	[K_Application_NO] [varchar] (10) COLLATE Chinese_PRC_CI_AS NOT NULL ,
	[Picture4] [image] NULL ,
	[PictureF] [image] NULL ,
	[Exam] [varchar] (32) COLLATE Chinese_PRC_CI_AS NULL ,
	[Recheck] [varchar] (32) COLLATE Chinese_PRC_CI_AS NULL ,
	[ExamDate] [datetime] NULL 
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]
GO

CREATE TABLE [dbo].[InitFileNo] (
	[RID] [int] IDENTITY (1, 1) NOT NULL ,
	[FileNoLength] [int] NOT NULL ,
	[FileNoStart] [char] (10) COLLATE Chinese_PRC_CI_AS NOT NULL 
) ON [PRIMARY]
GO

CREATE TABLE [dbo].[K_Checker] (
	[RID] [int] IDENTITY (1, 1) NOT NULL ,
	[K_Value] [varchar] (50) COLLATE Chinese_PRC_CI_AS NOT NULL 
) ON [PRIMARY]
GO

CREATE TABLE [dbo].[Mortagate_Application] (
	[RID] [int] IDENTITY (1, 1) NOT NULL ,
	[K_Application_NO] [varchar] (10) COLLATE Chinese_PRC_CI_AS NULL ,
	[P_Paper_NO] [varchar] (10) COLLATE Chinese_PRC_CI_AS NULL 
) ON [PRIMARY]
GO

CREATE TABLE [dbo].[Mortagate_Auditing] (
	[RID] [int] IDENTITY (1, 1) NOT NULL ,
	[K_Application_NO] [varchar] (10) COLLATE Chinese_PRC_CI_AS NOT NULL ,
	[P_Paper_NO] [varchar] (10) COLLATE Chinese_PRC_CI_AS NULL ,
	[S_Paper_NO] [varchar] (10) COLLATE Chinese_PRC_CI_AS NULL 
) ON [PRIMARY]
GO

CREATE TABLE [dbo].[OtherProperty_Paper] (
	[RID] [int] IDENTITY (1, 1) NOT NULL ,
	[RNO] [varchar] (10) COLLATE Chinese_PRC_CI_AS NOT NULL ,
	[FileHead] [varchar] (10) COLLATE Chinese_PRC_CI_AS NULL ,
	[Paper_NO] [varchar] (10) COLLATE Chinese_PRC_CI_AS NOT NULL ,
	[K_P_Paper_NO] [varchar] (10) COLLATE Chinese_PRC_CI_AS NULL ,
	[K_PropertyType_ID] [int] NULL ,
	[Obligee] [varchar] (32) COLLATE Chinese_PRC_CI_AS NULL ,
	[PropertyType] [char] (10) COLLATE Chinese_PRC_CI_AS NULL ,
	[K_House_NO] [varchar] (10) COLLATE Chinese_PRC_CI_AS NULL ,
	[Building] [varchar] (10) COLLATE Chinese_PRC_CI_AS NULL ,
	[Room] [int] NULL ,
	[Doorplate] [varchar] (10) COLLATE Chinese_PRC_CI_AS NULL ,
	[StructureArea] [decimal](18, 3) NULL ,
	[R_Value] [money] NULL ,
	[Available] [datetime] NULL ,
	[TaxRace] [decimal](18, 4) NULL ,
	[Tax] [money] NULL ,
	[CheckOffDate] [datetime] NULL ,
	[K_Marker_ID] [int] NULL ,
	[K_Check_ID] [int] NULL ,
	[ReceiptDate] [datetime] NULL ,
	[Remark] [varchar] (100) COLLATE Chinese_PRC_CI_AS NULL 
) ON [PRIMARY]
GO

CREATE TABLE [dbo].[Owner_Application] (
	[RID] [int] IDENTITY (1, 1) NOT NULL ,
	[RNO] [varchar] (10) COLLATE Chinese_PRC_CI_AS NOT NULL ,
	[FileHead] [varchar] (10) COLLATE Chinese_PRC_CI_AS NULL ,
	[Apply_Date] [datetime] NULL ,
	[K_Owner_NO] [varchar] (10) COLLATE Chinese_PRC_CI_AS NULL ,
	[K_Investigater_ID] [int] NULL ,
	[Investigation] [varchar] (100) COLLATE Chinese_PRC_CI_AS NULL ,
	[Investigation_Date] [datetime] NULL ,
	[ManageMentUnit_Remark] [varchar] (50) COLLATE Chinese_PRC_CI_AS NULL ,
	[Receit_NO] [varchar] (10) COLLATE Chinese_PRC_CI_AS NULL ,
	[NewPaper_NO] [varchar] (10) COLLATE Chinese_PRC_CI_AS NULL ,
	[Note] [varchar] (100) COLLATE Chinese_PRC_CI_AS NULL ,
	[CheckOff_Date] [datetime] NULL 
) ON [PRIMARY]
GO

CREATE TABLE [dbo].[P_Contract_Tax] (
	[RID] [int] IDENTITY (1, 1) NOT NULL ,
	[RNO] [varchar] (10) COLLATE Chinese_PRC_CI_AS NOT NULL ,
	[Paper_NO] [varchar] (10) COLLATE Chinese_PRC_CI_AS NOT NULL ,
	[StartDate] [datetime] NULL ,
	[Price] [money] NULL ,
	[K_TaxType_ID] [int] NULL ,
	[K_TaxRace_ID] [int] NULL ,
	[Tax] [money] NULL ,
	[Note] [varchar] (100) COLLATE Chinese_PRC_CI_AS NULL 
) ON [PRIMARY]
GO

CREATE TABLE [dbo].[P_GroundProperty] (
	[RID] [int] IDENTITY (1, 1) NOT NULL ,
	[RNO] [varchar] (10) COLLATE Chinese_PRC_CI_AS NOT NULL ,
	[Paper_NO] [varchar] (10) COLLATE Chinese_PRC_CI_AS NOT NULL ,
	[File_NO_Head] [varchar] (10) COLLATE Chinese_PRC_CI_AS NULL ,
	[File_NO] [varchar] (10) COLLATE Chinese_PRC_CI_AS NULL ,
	[UsedAreaM2] [decimal](18, 2) NULL ,
	[UsedArea] [decimal](18, 4) NULL ,
	[SendDate] [datetime] NULL 
) ON [PRIMARY]
GO

CREATE TABLE [dbo].[P_HousePicture] (
	[RID] [int] IDENTITY (1, 1) NOT NULL ,
	[Paper_NO] [varchar] (20) COLLATE Chinese_PRC_CI_AS NOT NULL ,
	[Picture1] [image] NULL ,
	[Picture2] [image] NULL 
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]
GO

CREATE TABLE [dbo].[P_HouseProperty] (
	[RID] [int] IDENTITY (1, 1) NOT NULL ,
	[RNO] [varchar] (10) COLLATE Chinese_PRC_CI_AS NOT NULL ,
	[Paper_NO] [varchar] (10) COLLATE Chinese_PRC_CI_AS NOT NULL ,
	[Building_NO] [varchar] (10) COLLATE Chinese_PRC_CI_AS NULL ,
	[Doorplate_NO] [varchar] (10) COLLATE Chinese_PRC_CI_AS NULL ,
	[Room] [int] NULL ,
	[Structure] [varchar] (20) COLLATE Chinese_PRC_CI_AS NULL ,
	[Floor] [int] NULL ,
	[Structure_Area] [decimal](18, 3) NULL ,
	[Note] [varchar] (50) COLLATE Chinese_PRC_CI_AS NULL 
) ON [PRIMARY]
GO

CREATE TABLE [dbo].[P_OtherProperty] (
	[RID] [int] IDENTITY (1, 1) NOT NULL ,
	[RNO] [varchar] (10) COLLATE Chinese_PRC_CI_AS NOT NULL ,
	[Paper_NO] [varchar] (10) COLLATE Chinese_PRC_CI_AS NOT NULL ,
	[PropertyType] [varchar] (20) COLLATE Chinese_PRC_CI_AS NOT NULL ,
	[Obligee] [varchar] (24) COLLATE Chinese_PRC_CI_AS NULL ,
	[K_House_NO] [varchar] (10) COLLATE Chinese_PRC_CI_AS NULL ,
	[Doorplate] [varchar] (10) COLLATE Chinese_PRC_CI_AS NULL ,
	[Room] [int] NULL ,
	[Structure_Area] [decimal](18, 3) NULL ,
	[Pro_Value] [money] NULL ,
	[Available] [datetime] NULL ,
	[CheckOff] [datetime] NULL 
) ON [PRIMARY]
GO

CREATE TABLE [dbo].[P_Owner] (
	[RID] [int] IDENTITY (1, 1) NOT NULL ,
	[RNO] [int] NOT NULL ,
	[OwnerName] [varchar] (32) COLLATE Chinese_PRC_CI_AS NULL ,
	[Sex] [varchar] (2) COLLATE Chinese_PRC_CI_AS NULL ,
	[Age] [int] NULL ,
	[NativePlace] [varchar] (32) COLLATE Chinese_PRC_CI_AS NULL ,
	[Address] [varchar] (32) COLLATE Chinese_PRC_CI_AS NULL ,
	[Company] [varchar] (32) COLLATE Chinese_PRC_CI_AS NULL ,
	[Employment] [varchar] (32) COLLATE Chinese_PRC_CI_AS NULL ,
	[Relation] [varchar] (10) COLLATE Chinese_PRC_CI_AS NULL ,
	[Share] [decimal](18, 3) NULL ,
	[K_OwnerType_ID] [int] NULL 
) ON [PRIMARY]
GO

CREATE TABLE [dbo].[Property_Paper] (
	[RID] [int] IDENTITY (1, 1) NOT NULL ,
	[FNO] [varchar] (10) COLLATE Chinese_PRC_CI_AS NOT NULL ,
	[NO_Head] [varchar] (10) COLLATE Chinese_PRC_CI_AS NOT NULL ,
	[Paper_NO] [varchar] (10) COLLATE Chinese_PRC_CI_AS NOT NULL ,
	[K_App_NO] [varchar] (10) COLLATE Chinese_PRC_CI_AS NOT NULL ,
	[K_Owner_NO] [varchar] (10) COLLATE Chinese_PRC_CI_AS NOT NULL ,
	[OwnerList] [varchar] (80) COLLATE Chinese_PRC_CI_AS NULL ,
	[House_Position] [varchar] (100) COLLATE Chinese_PRC_CI_AS NULL ,
	[Ground_NO] [varchar] (10) COLLATE Chinese_PRC_CI_AS NULL ,
	[K_PropertyRight_ID] [int] NOT NULL ,
	[K_Status_ID] [int] NULL ,
	[K_ManageUnit_ID] [int] NULL ,
	[K_Maker_ID] [int] NULL ,
	[K_Checker_ID] [int] NULL ,
	[SendOutDate] [datetime] NULL ,
	[AcceptDate] [datetime] NULL ,
	[Remark] [varchar] (128) COLLATE Chinese_PRC_CI_AS NULL 
) ON [PRIMARY]
GO

CREATE TABLE [dbo].[ShareProperty_Paper] (
	[RID] [int] IDENTITY (1, 1) NOT NULL ,
	[RNO] [varchar] (10) COLLATE Chinese_PRC_CI_AS NOT NULL ,
	[K_Paper_NO] [varchar] (10) COLLATE Chinese_PRC_CI_AS NOT NULL ,
	[ShareProperty_Paper_NO] [varchar] (10) COLLATE Chinese_PRC_CI_AS NOT NULL ,
	[K_Owner_NO] [varchar] (10) COLLATE Chinese_PRC_CI_AS NOT NULL ,
	[Share] [decimal](18, 3) NULL ,
	[Building] [int] NULL ,
	[Room] [int] NULL ,
	[Area] [decimal](18, 3) NULL ,
	[K_Maker_ID] [int] NULL ,
	[K_Checker_ID] [int] NULL ,
	[K_ManageUnit_ID] [int] NULL ,
	[SendOutDate] [datetime] NULL ,
	[AcceptDate] [datetime] NULL ,
	[Remark] [char] (50) COLLATE Chinese_PRC_CI_AS NULL 
) ON [PRIMARY]
GO

CREATE TABLE [dbo].[sys_Const] (
	[RID] [int] IDENTITY (1, 1) NOT NULL ,
	[NOLength] [int] NOT NULL ,
	[NOStart] [varchar] (50) COLLATE Chinese_PRC_CI_AS NOT NULL 
) ON [PRIMARY]
GO


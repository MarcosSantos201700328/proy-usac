USE [datawarehouse]
GO
/****** Objeto:  Table [dbo].[DimCliente]    Fecha de la secuencia de comandos: 12/06/2008 02:01:15 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[DimCliente](
	[CustomerID] [int] NOT NULL,
	[Nombre] [nvarchar](200) COLLATE Latin1_General_BIN2 NULL,
	[EmailPromotion] [int] NULL,
	[CustomerType] [nchar](1) COLLATE Latin1_General_BIN2 NULL,
 CONSTRAINT [PK_DimCliente] PRIMARY KEY CLUSTERED 
(
	[CustomerID] ASC
)WITH (IGNORE_DUP_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]

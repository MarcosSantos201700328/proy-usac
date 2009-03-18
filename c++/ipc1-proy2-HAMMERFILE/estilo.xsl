<?xml version='1.0'?>
<xsl:stylesheet
       xmlns:xsl="http://www.w3.org/TR/WD-xsl"
       xmlns="http://www.w3.org/TR/REC-html40"
       result-ns="">
<xsl:template>
<!-- Procesa el nodo raiz para procesarlo -->
<html>
<head>
	<title>Resultado de Busquedas - HammerFile</title>
</head>
<body>
<xsl:apply-templates/>
</body>
</html>

</xsl:template>
<xsl:template match="titulo">
	<STRONG>
		<H1>
			<FONT FACE="VERDANA, ARIAL, HELVETICA, SANS-SERIF">
				<xsl:value-of/>
			</FONT>
 	 	</H1>
	</STRONG>
</xsl:template>
<xsl:template match="subtitulo">
	<H2>
		<FONT FACE="VERDANA, ARIAL, HELVETICA, SANS-SERIF" COLOR="#0000BB">
			<xsl:value-of/>
		</FONT>
 	</H2>
</xsl:template>
<xsl:template match="titulocampo">
    <TH SCOPE="COL"><xsl:value-of/></TH>
</xsl:template>
<xsl:template match="dato">
    <TD><xsl:value-of/></TD>
</xsl:template>
<xsl:template match="registro">
	<TR BGCOLOR="#0099FF">
		<xsl:apply-templates select="dato"/>
	</TR>
</xsl:template>
<xsl:template match="tituloscampo">
	<TR BGCOLOR="#FF6666">
		<xsl:apply-templates select="titulocampo"/>
	</TR>
</xsl:template>
<xsl:template match="tabla">
	<TABLE WIDTH="80%" BORDER="1" CELLPADDING="1" CELLSPACING="1" BORDERCOLOR="#0000CC">
		<xsl:apply-templates select="tituloscampo"/>
		<xsl:apply-templates select="registro"/>
	</TABLE>
</xsl:template>
</xsl:stylesheet>
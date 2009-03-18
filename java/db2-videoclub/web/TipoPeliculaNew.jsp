<?xml version="1.0" encoding="UTF-8"?>
<!-- 
    Document   : ClienteNew
    Created on : 18/02/2008, 09:10:58 PM
    Author     : Erik Giron
-->
<jsp:root version="2.1" xmlns:f="http://java.sun.com/jsf/core" xmlns:h="http://java.sun.com/jsf/html" xmlns:jsp="http://java.sun.com/JSP/Page" xmlns:webuijsf="http://www.sun.com/webui/webuijsf">
    <jsp:directive.page contentType="text/html;charset=UTF-8" pageEncoding="UTF-8"/>
    <f:view>
        <webuijsf:page binding="#{TipoPeliculaNew.page1}" id="page1">
            <webuijsf:html binding="#{TipoPeliculaNew.html1}" id="html1">
                <webuijsf:head binding="#{TipoPeliculaNew.head1}" id="head1">
                    <webuijsf:link binding="#{TipoPeliculaNew.link1}" id="link1" url="/resources/stylesheet.css"/>
                </webuijsf:head>
                <webuijsf:body binding="#{TipoPeliculaNew.body1}" id="body1" style="-rave-layout: grid">
                    <webuijsf:form binding="#{TipoPeliculaNew.form1}" id="form1">
                        <webuijsf:label binding="#{TipoPeliculaNew.label1}" for="t1" id="label1" style="left: 24px; top: 72px; position: absolute" text="Codigo"/>
                        <webuijsf:textField binding="#{TipoPeliculaNew.t1}" id="t1" style="left: 96px; top: 72px; position: absolute" validatorExpression="#{TipoPeliculaNew.doubleRangeValidator1.validate}"/>
                        <webuijsf:textField binding="#{TipoPeliculaNew.t2}" id="t2" style="left: 96px; top: 120px; position: absolute"/>
                        <webuijsf:label binding="#{TipoPeliculaNew.label2}" for="t2" id="label2" style="left: 24px; top: 120px; position: absolute" text="Nombre"/>
                        <webuijsf:label binding="#{TipoPeliculaNew.label3}" for="t3" id="label3" style="left: 24px; top: 168px; position: absolute" text="Precio"/>
                        <webuijsf:textField binding="#{TipoPeliculaNew.t3}" id="t3" style="left: 96px; top: 168px; position: absolute"/>
                        <webuijsf:button actionExpression="#{TipoPeliculaNew.button1_action}" binding="#{TipoPeliculaNew.button1}" id="button1"
                            style="left: 119px; top: 192px; position: absolute" text="Agregar"/>
                        <webuijsf:button actionExpression="#{TipoPeliculaNew.button2_action}" binding="#{TipoPeliculaNew.button2}" id="button2"
                            style="left: 335px; top: 192px; position: absolute" text="Commit"/>
                        <webuijsf:staticText binding="#{TipoPeliculaNew.staticText1}" id="staticText1"
                            style="font-family: 'Arial','Helvetica',sans-serif; font-size: 18px; font-weight: bold; left: 96px; top: 24px; position: absolute; text-align: center; width: 312px" text="Ingreso de Tipo de Pelicula"/>
                        <webuijsf:textArea binding="#{TipoPeliculaNew.tareas}" id="tareas" style="left: 0px; top: 216px; position: absolute"/>
                    </webuijsf:form>
                </webuijsf:body>
            </webuijsf:html>
        </webuijsf:page>
    </f:view>
</jsp:root>

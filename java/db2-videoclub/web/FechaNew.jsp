<?xml version="1.0" encoding="UTF-8"?>
<!-- 
    Document   : ClienteNew
    Created on : 18/02/2008, 09:10:58 PM
    Author     : Erik Giron
-->
<jsp:root version="2.1" xmlns:f="http://java.sun.com/jsf/core" xmlns:h="http://java.sun.com/jsf/html" xmlns:jsp="http://java.sun.com/JSP/Page" xmlns:webuijsf="http://www.sun.com/webui/webuijsf">
    <jsp:directive.page contentType="text/html;charset=UTF-8" pageEncoding="UTF-8"/>
    <f:view>
        <webuijsf:page binding="#{FechaNew.page1}" id="page1">
            <webuijsf:html binding="#{FechaNew.html1}" id="html1">
                <webuijsf:head binding="#{FechaNew.head1}" id="head1">
                    <webuijsf:link binding="#{FechaNew.link1}" id="link1" url="/resources/stylesheet.css"/>
                </webuijsf:head>
                <webuijsf:body binding="#{FechaNew.body1}" id="body1" style="-rave-layout: grid">
                    <webuijsf:form binding="#{FechaNew.form1}" id="form1">
                        <webuijsf:label binding="#{FechaNew.label1}" for="t1" id="label1" style="left: 24px; top: 72px; position: absolute" text="Codigo Tipo Pelicula"/>
                        <webuijsf:textField binding="#{FechaNew.t1}" id="t1" style="left: 168px; top: 72px; position: absolute" validatorExpression="#{FechaNew.doubleRangeValidator1.validate}"/>
                        <webuijsf:textField binding="#{FechaNew.t2}" id="t2" style="left: 168px; top: 120px; position: absolute"/>
                        <webuijsf:label binding="#{FechaNew.label2}" for="t2" id="label2" style="left: 24px; top: 120px; position: absolute" text="Codigo Pelicula"/>
                        <webuijsf:label binding="#{FechaNew.label6}" id="label6" style="left: 120px; top: 168px; position: absolute" text="Fecha Afiliacion:"/>
                        <webuijsf:calendar binding="#{FechaNew.calendar1}" id="calendar1" style="left: 120px; top: 192px; position: absolute"/>
                        <webuijsf:button actionExpression="#{FechaNew.button1_action}" binding="#{FechaNew.button1}" id="button1"
                            style="left: 119px; top: 264px; position: absolute" text="Agregar"/>
                        <webuijsf:button actionExpression="#{FechaNew.button2_action}" binding="#{FechaNew.button2}" id="button2"
                            style="left: 335px; top: 264px; position: absolute" text="Commit"/>
                        <webuijsf:staticText binding="#{FechaNew.staticText1}" id="staticText1"
                            style="font-family: 'Arial','Helvetica',sans-serif; font-size: 18px; font-weight: bold; left: 96px; top: 24px; position: absolute; text-align: center; width: 312px" text="Ingreso de Fecha"/>
                        <webuijsf:textArea binding="#{FechaNew.tareas}" id="tareas" style="left: 0px; top: 288px; position: absolute"/>
                    </webuijsf:form>
                </webuijsf:body>
            </webuijsf:html>
        </webuijsf:page>
    </f:view>
</jsp:root>

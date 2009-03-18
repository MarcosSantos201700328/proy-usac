<?xml version="1.0" encoding="UTF-8"?>
<!-- 
    Document   : ClienteNew
    Created on : 18/02/2008, 09:10:58 PM
    Author     : Erik Giron
-->
<jsp:root version="2.1" xmlns:f="http://java.sun.com/jsf/core" xmlns:h="http://java.sun.com/jsf/html" xmlns:jsp="http://java.sun.com/JSP/Page" xmlns:webuijsf="http://www.sun.com/webui/webuijsf">
    <jsp:directive.page contentType="text/html;charset=UTF-8" pageEncoding="UTF-8"/>
    <f:view>
        <webuijsf:page binding="#{AlquilerNew.page1}" id="page1">
            <webuijsf:html binding="#{AlquilerNew.html1}" id="html1">
                <webuijsf:head binding="#{AlquilerNew.head1}" id="head1">
                    <webuijsf:link binding="#{AlquilerNew.link1}" id="link1" url="/resources/stylesheet.css"/>
                </webuijsf:head>
                <webuijsf:body binding="#{AlquilerNew.body1}" id="body1" style="-rave-layout: grid">
                    <webuijsf:form binding="#{AlquilerNew.form1}" id="form1">
                        <webuijsf:label binding="#{AlquilerNew.label1}" for="t1" id="label1" style="left: 24px; top: 72px; position: absolute" text="Codigo Pelicula"/>
                        <webuijsf:textField binding="#{AlquilerNew.t1}" id="t1" style="left: 120px; top: 72px; position: absolute" validatorExpression="#{AlquilerNew.doubleRangeValidator1.validate}"/>
                        <webuijsf:textField binding="#{AlquilerNew.t2}" id="t2" style="left: 120px; top: 120px; position: absolute"/>
                        <webuijsf:label binding="#{AlquilerNew.label2}" for="t2" id="label2" style="left: 24px; top: 120px; position: absolute" text="Codigo Cliente"/>
                        <webuijsf:label binding="#{AlquilerNew.label6}" id="label6" style="left: 24px; top: 192px; position: absolute" text="Fecha  Alquiler:"/>
                        <webuijsf:calendar binding="#{AlquilerNew.calendar1}" id="calendar1" style="left: 120px; top: 192px; position: absolute"/>
                        <webuijsf:label binding="#{AlquilerNew.label7}" id="label7" style="left: 24px; top: 264px; position: absolute" text="Fecha Devolucion:"/>
                        <webuijsf:calendar binding="#{AlquilerNew.calendar2}" id="calendar2" style="left: 120px; top: 264px; position: absolute"/>
                        <webuijsf:button actionExpression="#{AlquilerNew.button1_action}" binding="#{AlquilerNew.button1}" id="button1"
                            style="position: absolute; left: 120px; top: 336px" text="Agregar"/>
                        <webuijsf:button actionExpression="#{AlquilerNew.button2_action}" binding="#{AlquilerNew.button2}" id="button2"
                            style="left: 335px; top: 336px; position: absolute" text="Commit"/>
                        <webuijsf:staticText binding="#{AlquilerNew.staticText1}" id="staticText1"
                            style="font-family: 'Arial','Helvetica',sans-serif; font-size: 18px; font-weight: bold; left: 96px; top: 24px; position: absolute; text-align: center; width: 312px" text="Ingreso de Alquiler"/>
                        <webuijsf:textArea binding="#{AlquilerNew.tareas}" id="tareas" style="left: 0px; top: 360px; position: absolute"/>
                    </webuijsf:form>
                </webuijsf:body>
            </webuijsf:html>
        </webuijsf:page>
    </f:view>
</jsp:root>

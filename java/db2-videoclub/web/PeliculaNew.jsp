<?xml version="1.0" encoding="UTF-8"?>
<!-- 
    Document   : ClienteNew
    Created on : 18/02/2008, 09:10:58 PM
    Author     : Erik Giron
-->
<jsp:root version="2.1" xmlns:f="http://java.sun.com/jsf/core" xmlns:h="http://java.sun.com/jsf/html" xmlns:jsp="http://java.sun.com/JSP/Page" xmlns:webuijsf="http://www.sun.com/webui/webuijsf">
    <jsp:directive.page contentType="text/html;charset=UTF-8" pageEncoding="UTF-8"/>
    <f:view>
        <webuijsf:page binding="#{PeliculaNew.page1}" id="page1">
            <webuijsf:html binding="#{PeliculaNew.html1}" id="html1">
                <webuijsf:head binding="#{PeliculaNew.head1}" id="head1">
                    <webuijsf:link binding="#{PeliculaNew.link1}" id="link1" url="/resources/stylesheet.css"/>
                </webuijsf:head>
                <webuijsf:body binding="#{PeliculaNew.body1}" id="body1" style="-rave-layout: grid">
                    <webuijsf:form binding="#{PeliculaNew.form1}" id="form1">
                        <webuijsf:label binding="#{PeliculaNew.label1}" for="t1" id="label1" style="left: 24px; top: 72px; position: absolute" text="Codigo"/>
                        <webuijsf:textField binding="#{PeliculaNew.t1}" id="t1" style="left: 96px; top: 72px; position: absolute" validatorExpression="#{PeliculaNew.doubleRangeValidator1.validate}"/>
                        <webuijsf:textField binding="#{PeliculaNew.t2}" id="t2" style="left: 96px; top: 120px; position: absolute"/>
                        <webuijsf:label binding="#{PeliculaNew.label2}" for="t2" id="label2" style="left: 24px; top: 120px; position: absolute" text="Nombre"/>
                        <webuijsf:label binding="#{PeliculaNew.label3}" for="t3" id="label3" style="left: 24px; top: 168px; position: absolute" text="Descripcion"/>
                        <webuijsf:textField binding="#{PeliculaNew.t3}" id="t3" style="left: 96px; top: 168px; position: absolute"/>
                        <webuijsf:label binding="#{PeliculaNew.label4}" for="t4" id="label4" style="left: 24px; top: 216px; position: absolute" text="Conocida Como"/>
                        <webuijsf:textField binding="#{PeliculaNew.t4}" id="t4" style="left: 120px; top: 216px; position: absolute"/>
                        <webuijsf:label binding="#{PeliculaNew.label5}" id="label5" style="position: absolute; left: 24px; top: 264px" text="Clasificacion"/>
                        <webuijsf:textField binding="#{PeliculaNew.t5}" id="t5" style="left: 96px; top: 264px; position: absolute"/>
                        <webuijsf:label binding="#{PeliculaNew.label6}" id="label6" style="left: 264px; top: 72px; position: absolute" text="Fecha Estreno:"/>
                        <webuijsf:calendar binding="#{PeliculaNew.calendar1}" id="calendar1" style="left: 264px; top: 96px; position: absolute"/>
                        <webuijsf:label binding="#{PeliculaNew.label7}" id="label7" style="left: 264px; top: 240px; position: absolute" text="Numero de Ejemplares:"/>
                        <webuijsf:button actionExpression="#{PeliculaNew.button1_action}" binding="#{PeliculaNew.button1}" id="button1"
                            style="position: absolute; left: 120px; top: 336px" text="Agregar"/>
                        <webuijsf:button actionExpression="#{PeliculaNew.button2_action}" binding="#{PeliculaNew.button2}" id="button2"
                            style="left: 335px; top: 336px; position: absolute" text="Commit"/>
                        <webuijsf:staticText binding="#{PeliculaNew.staticText1}" id="staticText1"
                            style="font-family: 'Arial','Helvetica',sans-serif; font-size: 18px; font-weight: bold; left: 96px; top: 24px; position: absolute; text-align: center; width: 312px" text="Ingreso de Peliculas"/>
                        <webuijsf:textArea binding="#{PeliculaNew.tareas}" id="tareas" style="left: 0px; top: 360px; position: absolute"/>
                        <webuijsf:textField binding="#{PeliculaNew.t6}" id="t6" style="position: absolute; left: 288px; top: 264px"/>
                    </webuijsf:form>
                </webuijsf:body>
            </webuijsf:html>
        </webuijsf:page>
    </f:view>
</jsp:root>

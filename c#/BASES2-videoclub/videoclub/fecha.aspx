<%@ Page Language="C#" MasterPageFile="~/MasterPage.master" AutoEventWireup="true" CodeFile="fecha.aspx.cs" Inherits="fecha" Title="Historico" %>
<asp:Content ID="Content1" ContentPlaceHolderID="ContentPlaceHolder1" Runat="Server">
    <h2>
    Ingreso de Historico de Peliculas</h2>
    :<br />
    <table style="width: 80%; text-align: center">
        <tr>
            <td>
                Codigo Pelicula</td>
            <td>
                <asp:TextBox ID="TextBox1" runat="server" ValidationGroup="a"></asp:TextBox></td>
        </tr>
        <tr>
            <td style="height: 26px">
                Codigo Tipo</td>
            <td style="height: 26px">
                <asp:TextBox ID="TextBox2" runat="server"></asp:TextBox></td>
        </tr>
        <tr>
            <td>
                Fecha</td>
            <td>
                <asp:Calendar ID="Calendar1" runat="server"></asp:Calendar>
            </td>
        </tr>
        <tr>
            <td>
                <asp:Button ID="Button1" runat="server" Text="Encolar." OnClick="Button1_Click" /></td>
            <td>
                &nbsp;<asp:Button ID="Button2" runat="server" OnClick="Button2_Click" Text="COMMIT!" /></td>
        </tr>
    </table>
    Tareas:<br />
    <asp:BulletedList ID="BulletedList1" runat="server">
    </asp:BulletedList>
</asp:Content>


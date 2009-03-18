<%@ Page Language="C#" MasterPageFile="~/MasterPage.master" AutoEventWireup="true" CodeFile="tipo_pelicula.aspx.cs" Inherits="tipo_pelicula" Title="Ingreso de Tipo de Pelicula" %>
<asp:Content ID="Content1" ContentPlaceHolderID="ContentPlaceHolder1" Runat="Server">
    <h2>
    Ingreso de Tipo de Pelicula</h2>
    :<br />
    <table style="width: 80%; text-align: center">
        <tr>
            <td>
                Codigo</td>
            <td>
                <asp:TextBox ID="TextBox1" runat="server" ValidationGroup="a"></asp:TextBox></td>
        </tr>
        <tr>
            <td style="height: 26px">
                Nombre</td>
            <td style="height: 26px">
                <asp:TextBox ID="TextBox2" runat="server"></asp:TextBox></td>
        </tr>
        <tr>
            <td>
                Precio</td>
            <td>
                <asp:TextBox ID="TextBox3" runat="server"></asp:TextBox></td>
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


<%@ Page Title="Categories" Language="C#" AutoEventWireup="true" MasterPageFile="~/Site.Master" CodeBehind="Categories.aspx.cs" Inherits="Fullstack_Project.Categories" %>

<asp:Content ID="BodyContent" ContentPlaceHolderID="MainContent" runat="server">
    <link rel="stylesheet" type="text/css" href="css/autoForm.css">
    <br />
    <div class="container" style="width:75%">
        <asp:Label ID="message" runat="server" CssClass="hello"><b>Categories</b></asp:Label><br />
        <hr />
        <div> <!-- CLASS WITH LAYOUT -->
            <asp:PlaceHolder ID="container" runat="server"></asp:PlaceHolder>
        </div>
    </div>
</asp:Content>

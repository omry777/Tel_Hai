<%@ Page Title="Categories" Language="C#" AutoEventWireup="true" MasterPageFile="~/Site.Master" CodeBehind="Categories.aspx.cs" Inherits="Fullstack_Project.Categories" %>

<asp:Content ID="BodyContent" ContentPlaceHolderID="MainContent" runat="server">
        <br />
        <link rel="stylesheet" type="text/css" href="css/autoForm.css">

        <div class="container" style="width:30%">
            <asp:Label ID="message" runat="server" Text="Categories:" CssClass="hello"></asp:Label><br />
            <asp:PlaceHolder ID="container" runat="server"></asp:PlaceHolder>
        </div>
</asp:Content>

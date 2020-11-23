<%@ Page Title="Login" Language="C#" AutoEventWireup="true" MasterPageFile="~/Site.Master" CodeBehind="Login.aspx.cs" Inherits="Fullstack_Project.Login" %>

<asp:Content ID="BodyContent" ContentPlaceHolderID="MainContent" runat="server">
    <link rel="stylesheet" type="text/css" href="css/autoForm.css">
    <br>
    <div class="logo">
        <img src="KOT_logo.jpg">
    </div>
    <br />
    <div class="container" style="width: 30%">
        <asp:Panel ID="DitsPanel" runat="server">
            <asp:Label ID="hello" CssClass="hello" runat="server"><b>Welcome!<br />Please Login:</b></asp:Label>
            <br />
            <hr />
            <asp:TextBox ID="username" runat="server" placeholder="Enter username"></asp:TextBox>
            <asp:TextBox ID="password" runat="server" placeholder="Enter password" TextMode="Password"></asp:TextBox>
            <asp:Button ID="login" runat="server" CssClass="loginButton" Text="Login" OnClick="loginButton" />
            <br />
            <hr />
            <a style="font-size=150%; float: none;" runat="server" href="Signup">Don't have an account yet? SIGN UP FOR FREE!</a>
        </asp:Panel>
        <asp:Label ID="loggedInLabel" runat="server"></asp:Label>
        <asp:Label ID="message" runat="server"></asp:Label>
    </div>
        
        
</asp:Content>

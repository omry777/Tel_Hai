﻿<%@ Page Title="Signup" Language="C#" AutoEventWireup="true" MasterPageFile="~/Site.Master" CodeBehind="Signup.aspx.cs" Inherits="Fullstack_Project.Signup" %>

<asp:Content ID="BodyContent" ContentPlaceHolderID="MainContent" runat="server">
    <link rel="stylesheet" type="text/css" href="css/autoForm.css">
        <br />
        <div class="container" style="width: 30%">
            <asp:Label ID="hello" CssClass="hello" runat="server"><b>Signup</b></asp:Label>
            <br />
            <br />
            <asp:Label ID="explaination" runat="server" CssClass="textHandler2">Please fill in this form to create your account!</asp:Label>
            <br />
            <hr />
            <asp:TextBox ID="username" runat="server" placeholder="Enter username"></asp:TextBox>
            <asp:TextBox ID="password" runat="server" placeholder="Enter password" TextMode="Password"></asp:TextBox>
            <asp:Button ID="signup" runat="server" CssClass="loginButton" Text="Signup" OnClick="insert_user" />
            <br />
            <hr />
            <asp:Button ID="back" CssClass="backBtn" runat="server" Text="Back" PostBackUrl="~/Login.aspx" />
        </div>
        <br />
        <table align="center">
            <tr>
                <td><asp:Label ID="massage" runat="server" CssClass="hello"></asp:Label></td>
            </tr>
        </table>
</asp:Content>

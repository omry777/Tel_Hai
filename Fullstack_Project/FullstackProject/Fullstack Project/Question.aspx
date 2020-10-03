<%@ Page Title="Question" Language="C#" MasterPageFile="~/Site.Master" AutoEventWireup="true" CodeBehind="Question.aspx.cs" Inherits="Fullstack_Project.Question" %>

<asp:Content ID="BodyContent" ContentPlaceHolderID="MainContent" runat="server">
    <br />
    <link rel="stylesheet" type="text/css" href="css/autoForm.css">

    <div class="container" style="width:30%">
        <asp:Panel ID="questionPanel" runat="server" CssClass="container">
            <asp:Label ID="qNum" runat="server" CssClass="hello"></asp:Label><br />
            <asp:Label ID="questionText" runat="server" CssClass="hello" Text="Press any button to start!"></asp:Label>
        </asp:Panel>
        <asp:Panel ID="answersPanel" runat="server">
            <asp:Image ID="Image1" runat="server" ImageUrl="null" Visible="false" style="width:100%;"/> 
            <asp:Button ID="ans0"  runat="server" CssClass="menuButton" Text="Click me!" OnClick="buttonClick"/><br />
            <asp:Button ID="ans1" runat="server" CssClass="menuButton" Text="Click me!" OnClick="buttonClick"/><br />
            <asp:Button ID="ans2" runat="server" CssClass="menuButton" Text="Click me!" OnClick="buttonClick"/><br />
            <asp:Button ID="ans3" runat="server" CssClass="menuButton" Text="Click me!" OnClick="buttonClick"/><br />
            <asp:Label ID="scoreLabel" runat="server"></asp:Label>
        </asp:Panel>
    </div>
    <table align="center">
            <tr>
                <td>
                    <asp:Label ID="massage" runat="server" CssClass="hello"></asp:Label></td>
            </tr>
        </table>

</asp:Content>

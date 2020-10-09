<%@ Page Title="Question" Language="C#" MasterPageFile="~/Site.Master" AutoEventWireup="true" CodeBehind="Question.aspx.cs" Inherits="Fullstack_Project.Question" %>

<asp:Content ID="BodyContent" ContentPlaceHolderID="MainContent" runat="server">
    <br />
    <link rel="stylesheet" type="text/css" href="css/autoForm.css">
    <asp:Timer ID="Timer1" runat="server" Interval="1000" Enabled="false" OnTick="tick"></asp:Timer>
    <div class="container" style="width: 30%">
        <asp:UpdatePanel ID="questionPanel" runat="server" CssClass="container">
            <ContentTemplate>
                <div class="container">
                    <asp:Label ID="qNum" runat="server" Style="float: left; font-size: 200%;"></asp:Label>
                    <asp:Label ID="timerLabel" runat="server" Style="color: red; float: right; font-size: 200%"></asp:Label><br />
                    <asp:Label ID="questionText" runat="server" CssClass="hello" Text="Press any button to start!"></asp:Label>
                    <asp:Image ID="Image1" runat="server" ImageUrl="null" Visible="false" Style="width: 100%;" />
                </div>

                <asp:Button ID="ans0" runat="server" CssClass="menuButton" Text="Click me!" OnClick="buttonClick" /><br />
                <asp:Button ID="ans1" runat="server" CssClass="menuButton" Text="Click me!" OnClick="buttonClick" /><br />
                <asp:Button ID="ans2" runat="server" CssClass="menuButton" Text="Click me!" OnClick="buttonClick" /><br />
                <asp:Button ID="ans3" runat="server" CssClass="menuButton" Text="Click me!" OnClick="buttonClick" /><br />
                <asp:Label ID="scoreLabel" runat="server"></asp:Label>

                <asp:Label ID="massage" runat="server" CssClass="hello"></asp:Label></td>
            </ContentTemplate>
            <Triggers>
                <asp:AsyncPostBackTrigger ControlID="Timer1" EventName="Tick"></asp:AsyncPostBackTrigger>
            </Triggers>
        </asp:UpdatePanel>
    </div>


</asp:Content>

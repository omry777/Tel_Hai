<%@ Page Title="Leaderboard" Language="C#" AutoEventWireup="true" MasterPageFile="~/Site.Master" CodeBehind="Leaderboard.aspx.cs" Inherits="Fullstack_Project.Leaderboard" %>


<asp:Content ID="BodyContent" ContentPlaceHolderID="MainContent" runat="server">
    <link rel="stylesheet" type="text/css" href="css/autoForm.css">
    <br />
    <div class="container" style="width:50%">
        <h1><b>Leaderboard</b></h1>
        <hr />
        <div>
            <asp:TextBox ID="username" runat="server" Width="170" Height="40" placeholder="Search by username"></asp:TextBox>
            <asp:Button ID="search" runat="server" CssClass="searchingButton" Text="Search" OnClick="searchButton"></asp:Button>
        </div>
        <asp:Label ID="message" runat="server"></asp:Label>
        <br />
        <br />
        <asp:Table ID="tableDiv" runat="server" align="center">
            <asp:TableRow BorderWidth="2">
                <asp:TableCell>
                    <asp:GridView ID="table" AutoGenerateColumns="true" runat="server" OnSelectedIndexChanged="table_SelectedIndexChanged"></asp:GridView>
                </asp:TableCell>
            </asp:TableRow>
        </asp:Table>
        <br />
        <hr />
        <asp:Button ID="back" CssClass="backBtn" runat="server" Text="Back" PostBackUrl="~/Login.aspx" />
    </div>
</asp:Content>

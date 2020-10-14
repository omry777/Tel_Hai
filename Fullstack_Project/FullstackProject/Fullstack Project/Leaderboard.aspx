<%@ Page Title="Leaderboard" Language="C#" AutoEventWireup="true" MasterPageFile="~/Site.Master" CodeBehind="Leaderboard.aspx.cs" Inherits="Fullstack_Project.Leaderboard" %>


<asp:Content ID="BodyContent" ContentPlaceHolderID="MainContent" runat="server">
    <link rel="stylesheet" type="text/css" href="css/autoForm.css">
    <br />
    <div class="container" style="width:30%">
        <asp:Table ID="tableDiv" runat="server" align="center">
            <asp:TableRow>
                <asp:TableCell>
                    <h1><u>Leaderboard</u></h1>
                    <asp:GridView ID="table" AutoGenerateColumns="true" runat="server" OnSelectedIndexChanged="table_SelectedIndexChanged"></asp:GridView>
                </asp:TableCell>
            </asp:TableRow>
        </asp:Table>
    </div>
</asp:Content>

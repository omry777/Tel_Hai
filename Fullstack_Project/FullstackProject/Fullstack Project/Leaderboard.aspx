<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Leaderboard.aspx.cs" Inherits="Fullstack_Project.Leaderboard" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>LEADERS!</title>
    <link rel="stylesheet" type="text/css" href="css/autoForm.css">
</head>
<body>
    <form id="form1" runat="server">
        <div style="font-size: 300%;">
            <table align="center" class="container">
                <tr>
                    <td colspan="2" align="center">
                        <u><h1>Leaderboard</h1></u>
                        <asp:TextBox ID="textInput" runat="server" placeholder="Hint"></asp:TextBox>
                        <asp:Button ID="textButton" runat="server" Text="MEGA-BUTTON" OnClick="textButton_OnClick" />
                        <asp:GridView ID="table" AutoGenerateColumns="true" runat="server" OnSelectedIndexChanged="table_SelectedIndexChanged"></asp:GridView>
                        <asp:Label ID="textLabel" runat="server">MASHO</asp:Label>
                        <asp:Button ID="back" CssClass="backBtn" runat="server" Text="Back" PostBackUrl="~/Categories.aspx" />
                    </td>
                </tr>
            </table>

        </div>
    </form>
</body>
</html>

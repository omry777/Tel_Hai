<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Signup.aspx.cs" Inherits="Fullstack_Project.Signup" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Trivia King</title>
    <link rel="stylesheet" type="text/css" href="css/autoForm.css">
</head>
<body>
    <form id="form1" runat="server">
        <div class="container" style="width: 30%">
            <asp:Label ID="hello" CssClass="hello" runat="server">Signup:</asp:Label>
            <asp:Button ID="back" CssClass="backBtn" runat="server" Text="Back" PostBackUrl="~/Login.aspx" />
            <asp:TextBox ID="username" runat="server" placeholder="Enter username"></asp:TextBox>
            <asp:TextBox ID="password" runat="server" placeholder="Enter password" TextMode="Password"></asp:TextBox>
            <asp:Button ID="signup" runat="server" CssClass="loginButton" Text="Signup" OnClick="insert_user" />
        </div>
        <br />
        <table align="center">
            <tr>
                <td>
                    <asp:Label ID="massage" runat="server" CssClass="hello"></asp:Label></td>
            </tr>
        </table>
    </form>
</body>
</html>

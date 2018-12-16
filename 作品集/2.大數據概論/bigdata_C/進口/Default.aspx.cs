using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class _Default : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {

    }

    protected void Button1_Click(object sender, EventArgs e)
    {
        int constant = 1880;
        int row = Convert.ToInt32(TextBox1.Text);
        int result = constant * row + 1;
        Label3.Text = result.ToString();
    }
}
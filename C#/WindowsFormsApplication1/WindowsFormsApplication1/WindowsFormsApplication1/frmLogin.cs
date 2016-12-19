using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Data.SqlClient;
namespace WindowsFormsApplication1
{
    public partial class frmLogin : Form
    {
        public frmLogin()
        {
            InitializeComponent();
        }

        private void BtnClose_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void btnLogin_Click(object sender, EventArgs e)
        {
            if (txtUserName.Text.Trim().Equals(string.Empty))
            {
                MessageBox.Show("请输入用户名","北大青鸟",MessageBoxButtons.OK,MessageBoxIcon.Information);
                txtUserName.Focus();
                return ;
            }
            if (txtPwd.Text.Trim().Equals(string.Empty))
            {
                MessageBox.Show("请输入密码", "北大青鸟", MessageBoxButtons.OK, MessageBoxIcon.Information);
                txtPwd.Focus();
                return;
            }
            string Config = "server=.;database=Myschool;uid=sa;pwd=yywhiter_nb1818";
            SqlConnection con = new SqlConnection();
            SqlCommand cmd = new SqlCommand(); 
            string sql= string.Format("select count(*) from student where StudentNo='{0}' and LoginPwd='{1}'",txtUserName.Text.Trim(),txtPwd.Text.Trim());
            object obj = null;
            try
            {
                con.ConnectionString = Config;
                con.Open();
                cmd.Connection = con;
                cmd.CommandText = sql;
                 obj = cmd.ExecuteScalar();
            }
            catch (Exception ex)
            {

                MessageBox.Show(ex.Message);
            }
            finally {
                cmd.Dispose();
                con.Close();
            }
            if (Convert.ToInt32(obj)>0)
            {
                FrmMain main = new FrmMain();
                main.UserID = txtUserName.Text.Trim();
                main.Show();
                this.Hide();
            }
            else
            {
                MessageBox.Show("此用户不存在", "北大青鸟", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
          
         
        }
    }
}
